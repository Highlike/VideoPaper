#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstdlib>
#include <cstdio>
#include "geometry.hpp"
#include "shapes.hpp"
#include "ui.hpp"

#define ESC 27

using namespace cv;
using namespace std;
using namespace geometry;
using namespace shapes;

const char *keys = { 
	"{ h | help    | false | print help message }"
	"{ c | cam     | 0     | camera number }"
	"{ f | file    |       | file to use instead of camera}"
	"{ p | picture |       | a picture }"
	"{ m | movie   |       | movie file}"
};

static VideoCapture cap, cap2;

void tidy_up(void) {
	cap.release();
	cap2.release();
}

int main(int argc, char* argv[]) {
	Mat frame, img;
	vector< vector<Point> > parallelograms;
	int camera_num;
	String file, picture, movie;
	size_t i;
	char c;
	bool help;

	CommandLineParser parser(argc, argv, keys);
	camera_num = parser.get<int>("cam");
	file = parser.get<string>("file");
	picture = parser.get<string>("picture");
	movie = parser.get<string>("movie");
	help = parser.get<bool>("help");

	if (help) {
		parser.printParams();
		return EXIT_SUCCESS;
	}

	atexit(tidy_up);

	if (!file.empty()) cap.open(file.c_str());
	else cap.open(camera_num);

	if (!picture.empty()) img = imread(picture);
	else if (!movie.empty()) cap2.open(movie.c_str());
	else {
		printf("you need to specify a picture or a movie file\n");
		return EXIT_FAILURE;
	}


	if (!cap.isOpened() && !(cap2.isOpened() || img.empty()))
	{
		printf("can not open camera, video file or picture\n");
		return EXIT_FAILURE;
	}

	UI::create_ui();

	while (1) {
		cap >> frame;

		if (frame.empty()) {
			break;
		}

		if (!movie.empty()) {
			cap2 >> img;
			if (img.empty()) {
				break;
			}
		}

		parallelograms = find_parallelograms(frame);

		for (i = 0; i < parallelograms.size(); i++) {
			fill_with_img(frame, &parallelograms[i][0], img);
		}

		imshow(UI::main_window, frame);

		c = waitKey(30);
		switch (c) {
			case ESC: exit(EXIT_SUCCESS);
		}
	}
}
