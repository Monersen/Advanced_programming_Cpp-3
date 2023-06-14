#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> v{4, 7, 9, 14, 12};

    cout << "Input values:\t";
    for_each(v.begin(), v.end(), [](const int& a) {
        cout << a << " ";
        });

    cout << "\nOutput values:\t";
    for_each(v.begin(), v.end(), [](const int& a) {
        cout << (a % 2 ? a * 3 : a) << " ";
        });

    cout << endl;
    return 0;
}