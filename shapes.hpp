#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

namespace shapes {
	vector< vector<Point> > find_parallelograms(const Mat);
	void fill_with_img(Mat&, const Point[], Mat&);
}

#endif
