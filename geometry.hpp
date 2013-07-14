#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <opencv2/core/core.hpp>

using namespace cv;

namespace geometry {
	enum coordinates {x_1, y_1, x_2, y_2};

	int length_of(Vec4i);
	bool isParallel(Vec4i, Vec4i);
	float calc_m_of(Vec4i);
	Vec4i points_to_line(Point2i, Point2i);
}

#endif
