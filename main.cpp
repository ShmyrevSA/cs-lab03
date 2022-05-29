#include <iostream>
#include <vector>
#include "histogram.h"
#include "SVG.h"
#include <windows.h>
using namespace std;

vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t>
make_histogram(const vector<double> &numbers, const size_t &bin_count){

    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t> bins(bin_count, 0);
    for (double number : numbers) {
        size_t bin = (size_t)(((number - min) / (max - min)) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return(bins);
}

void
show_histogram_text(const vector <size_t> &bins){
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
    size_t max_count = 0;
    for (size_t bin : bins) {
        if (bin > max_count) {
            max_count = bin;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    for (size_t bin : bins) {
        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }
}
#define INFO_BUFFER_SIZE 20
int
main() {
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD version_minor = version >> 8;
    DWORD version_major = version & 0x0000ff;
    printf("Windows v%u.%u", version_major, version_minor);

    if ((info & 0x40000000) == 0) {
        DWORD build = platform;
        printf(" (build %u)\n", build);
    }

    char  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;
    GetComputerNameA(infoBuf, &bufCharCount);
    printf("Computer name: %s", infoBuf);
    return 0;

    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // Обработка данных
    const auto bins = make_histogram(numbers, bin_count);

    // Вывод данных
    show_histogram_svg(bins);
    return 0;
}
