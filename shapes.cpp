#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include "shapes.hpp"
#include "geometry.hpp"
#include "ui.hpp"

using namespace cv;
using namespace std;
using namespace geometry;

vector< vector<Point> > shapes::find_parallelograms(const Mat image) {
	Mat gray_image, edge_image;
	vector< vector<Point> > contours;
	vector<Point> approx;
	vector< vector<Point> > parallelograms;
	Vec4i line1, line2;
	const int allowed_aperture[] = { 3, 5, 7 };

	cvtColor(image, gray_image, CV_BGR2GRAY);
	Canny(gray_image, edge_image, UI::low_threshold, UI::high_threshold, allowed_aperture[UI::aperture_size]);
	imshow(UI::edge_window, edge_image);

	findContours(edge_image, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	for (size_t i = 0; i < contours.size(); i++) {
		approxPolyDP(Mat(contours[i]), approx, (double) UI::epsilon / 5, true);

		if (approx.size() == 4 &&
			// isContourConvex(Mat(approx)) &&
			abs(contourArea(Mat(approx))) > UI::area_size * 500) {

			line1 = points_to_line(approx[0], approx[1]);
			line2 = points_to_line(approx[2], approx[3]);

			if (isParallel(line1, line2) &&
				length_of(line1) == length_of(line2)) {
				parallelograms.push_back(approx);
			}
		}
	}

	return parallelograms;
}

// img2 is the image an area in img is filled with
// pts are the 4 edge points where img2 is placed in
void shapes::fill_with_img(Mat &img, const Point pts[4], Mat &img2) {
	Point2f srcTri[3];
	Point2f dstTri[3];
	Mat warp_mat;

	// upper left corner
	srcTri[0] = Point2f(0,0);
	dstTri[0] = Point2f(pts[0].x, pts[0].y);
	// upper right corner
	srcTri[1] = Point2f(img2.cols - 1, 0);
	dstTri[1] = Point2f(pts[3].x, pts[3].y);
	// lower left corner
	srcTri[2] = Point2f(0, img2.rows - 1);
	dstTri[2] = Point2f(pts[1].x, pts[1].y);

	/// Get the Affine Transform
	warp_mat = getAffineTransform(srcTri, dstTri);	

	/// Apply the Affine Transform just found to the second image
	warpAffine(img2, img, warp_mat, img.size(), INTER_LINEAR, BORDER_TRANSPARENT);
}
