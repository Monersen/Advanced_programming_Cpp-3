#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<typename T>
void uniqme(vector<T>& v) {
    set<T> sTemp(v.begin(), v.end());
    v.assign(sTemp.begin(), sTemp.end());
}

template<typename T>
void print(const vector<T>& v) noexcept {
    for (const auto& i : v)
        cout << i << " ";
    cout << endl;
}

int main(int argc, char const* argv[])
{
    vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };

    cout << "[IN]: ";
    print(v);

    uniqme(v);
    cout << "[OUT]: ";
    print(v);

    return 0;
}