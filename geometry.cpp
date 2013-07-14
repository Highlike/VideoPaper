#include <opencv2/core/core.hpp>
#include <cmath>
#include "geometry.hpp"
#include "ui.hpp"

using namespace cv;

int geometry::length_of(Vec4i line) {
	int xd, yd;
	float distance;
	float precision;

	xd = line[x_2] - line[x_1];
	yd = line[y_2] - line[y_1];

	// pythagoras: c = sqrt(a² + b²)
	// since we only want to compare the distance
	// we can skip calculating the square root
	distance = (xd * xd) + (yd * yd);

	precision = (float) UI::length_precision / 100000;
	distance *= precision;

	return (int) distance;
}

bool geometry::isParallel(Vec4i line1, Vec4i line2) {
	float m1, m2;
	int precision;

	m1 = calc_m_of(line1);
	m2 = calc_m_of(line2);

	precision = UI::parallel_precision / 100;
	m1 *= precision;
	m2 *= precision;

	// if m1 = m2 lines are parallel
	return (cvRound(m1) == cvRound(m2)) ? true : false;
}

float geometry::calc_m_of(Vec4i line) {
	float m;

	// make division by zero impossible
	if (line[x_2] - line[x_1] == 0) line[x_2] += 1;

	// linear equation: y = m * x + b
	// m = (y_2 - y_1) / (x_2 - x_1)
	m = (float) (line[y_2] - line[y_1]) / (line[x_2] - line[x_1]);

	return m;
}

Vec4i geometry::points_to_line(Point2i pt1, Point2i pt2) {
	Vec4i line;

	line[x_1] = pt1.x;
	line[y_1] = pt1.y;
	line[x_2] = pt2.x;
	line[y_2] = pt2.y;

	return line;
}
