#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void move_vectors(vector<T>& dst, vector<T>& src) {
    dst = move(src);
}

int main(int argc, char const* argv[])
{
    vector<int> v1{10, 20, 30, 40, 50}, v2;

    move_vectors(v2, v1);

    for (const auto& n : v2)
        cout << n << endl;

    return 0;
}