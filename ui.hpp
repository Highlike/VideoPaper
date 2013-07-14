#ifndef UI_HPP
#define UI_HPP

using namespace std;

namespace UI {
	extern const string main_window;
	extern const string edge_window;
	extern int low_threshold;
	extern int high_threshold;
	extern int aperture_size;
	extern int area_size;
	extern int epsilon;
	extern int length_precision;
	extern int parallel_precision;

	void create_ui(void);
}

#endif
