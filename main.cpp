#include "vector.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;
using std::left;
using std::setw;

int Test(bool condition, const char *message);
bool DoubleEquals(double a, double b, double epsilon = 1e-6);


int main() {
    cout << "LET\'S TEST IT" << endl;
    double d1[] = {1,2,4};
    double d2[] = {5, -1, 0};
    double d3[] = {1,8};
    double d4[] = {1, 2, 4};

    Vector a(3, d1);
    Vector b(3, d2);
    Vector c(0, nullptr);
    Vector d(2, d3);
    Vector e(3, d4);

    Test(a.ToString() == "[1, 2, 4]", "ToString");
    c = a.Sum(b);
    Test(c.ToString() == "", "Sum");

    return 0;
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
bool DoubleEquals(double a, double b, double epsilon){
    return abs(a - b) < epsilon;
}