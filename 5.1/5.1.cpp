#include <iostream>
#include <vector>
using namespace std;


template<typename T>
T power(T n) { return n * n; }

template<typename T>
void power(vector<T>& n) {
    for (auto& v : n) v *= v;
}

template<typename T>
void print(const vector<T>& n)
{
    for (auto it = n.begin(); it < n.end() - 1; ++it)
        cout << *it << ", ";
    cout << *(n.end() - 1) << endl;
}

int main(int argc, char const* argv[])
{
    int n = 4;
    cout << "[IN]: " << n << endl;
    cout << "[OUT]: " << power(n) << endl;

    vector<int> v{-1, 4, 8};
    cout << "[IN]: ";

    print(v);
    power(v);

    cout << "[OUT]: ";
    print(v);

    return 0;
}