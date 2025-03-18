#include "sort.h"

#include <random>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::endl;
using std::cerr;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::system_clock;
using std::left;
using std::setw;
using std::sort;
using std::reverse;

bool IsSorted(const int array[], int size);
int Test(bool condition, const char *message);
void PrintArray(int array[], int size);

int main(int argc, const char * argv[]) {
    int* data = nullptr;
    int size = -1;
    bool print = false;
    if (argc < 3) {
        size = 10;
        print = true;
    }else if (argc == 3){
        size = atoi(argv[1]);
        print = argv[2][0] == 't';
    }else {
        cerr << "Usage: " << argv[0] << " <size> <print result>" << endl;
        return 1;
    }
    int passedTests = 0;
    data = new int[size];
    default_random_engine generator(system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(0, 10000);
    for (int i = 0; i < size; i++) {
        data[i] = distribution(generator);
    }
    cout << "Test Random Uniform Distribution" << endl;
    if (print) {
        PrintArray(data, size);
    }
    Sort(data, size);
    if (print) {
        PrintArray(data, size);
    }
    // data[size / 2] = 0;
    passedTests = Test(IsSorted(data, size), "Random Uniform Distribution");

    // Sorting the data (in case the previous failed)
    sort(data, data + size); // std::sort

    cout << "Test Sorted Array" << endl;
    if (print) {
        PrintArray(data, size);
    }
    Sort(data, size);
    if (print) {
        PrintArray(data, size);
    }
    passedTests = Test(IsSorted(data, size), "Test Sorted Array");

    // Reversing sorted data
    reverse(data, data + size);

    cout << "Test Reversed Array" << endl;
    if (print) {
        PrintArray(data, size);
    }
    Sort(data, size);
    if (print) {
        PrintArray(data, size);
    }
    passedTests = Test(IsSorted(data, size), "Test Reversed Array");
    delete[] data;

    cout << "Total Tests Passed: " << passedTests << endl;
    return 0;
}

bool IsSorted(const int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
int Test(bool condition, const char *message) {
    static auto passedTests = 0;
    if (condition) {
        cout << "TEST PASSED (" << left << setw(50) << message << ") Total Passed: " << ++passedTests << endl;
    } else {
        cout << "TEST FAILED (" << left << setw(50) << message << ") **************" << endl;
    }
    return passedTests;

}
void PrintArray(int array[], int size) {
    for (auto i = 0; i < size; i++) {
        cout << left << setw(5) << array[i] << " ";
    }
    cout << endl;
}