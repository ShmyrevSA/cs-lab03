#include "histogram.h"
#include "SVG.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void
test_equal() {
    double min = 0;
    double max = 0;
    find_minmax({2, 2, 2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void
test_one() {
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void
test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void
test_size_high(){
    size_t text_size = 55;
    text_size = check_size(text_size);
    assert(text_size == 0);

}

void
test_size_low(){
    size_t text_size = 2;
    text_size = check_size(text_size);
    assert(text_size == 0);

}

void
test_size_normal(){
    size_t text_size = 24;
    text_size = check_size(text_size);
    assert(text_size == 24);

}

int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_one();
    test_empty();
    test_size_normal();
    test_size_high();
    test_size_low();
}
