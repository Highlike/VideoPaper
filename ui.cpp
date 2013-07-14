#include <opencv2/highgui/highgui.hpp>
#include "ui.hpp"

using namespace cv;

const string UI::main_window = "VideoPaper";
const string UI::edge_window = "Edge Frame";
int UI::low_threshold = 100;
int UI::high_threshold = 300;
int UI::aperture_size = 0;
int UI::epsilon = 3;
int UI::length_precision = 0;
int UI::parallel_precision = 0;
int UI::area_size = 10;

void UI::create_ui(void) {
	namedWindow(main_window, CV_WINDOW_AUTOSIZE);
	namedWindow(edge_window, CV_WINDOW_AUTOSIZE);

	createTrackbar("low threshold", edge_window, &UI::low_threshold, 400);
	createTrackbar("high threshold", edge_window, &UI::high_threshold, 900);
	createTrackbar("aperture size", edge_window, &UI::aperture_size, 2);
	createTrackbar("area size", main_window, &UI::area_size, 100);
	createTrackbar("epsilon", main_window, &UI::epsilon, 100);
	createTrackbar("length precision", main_window, &UI::length_precision, 100);
	createTrackbar("parallel precision", main_window, &UI::parallel_precision, 100);
}
