#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;
void svg_begin(double width, double height);
void svg_end();
string make_info_text(char T = '1');
size_t check_size(size_t text_size);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_text(double left, double baseline, string text);
void show_histogram_svg(const vector<size_t>& bins);

#endif // SVG_H_INCLUDED
