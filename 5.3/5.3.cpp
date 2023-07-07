#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class functor {

    int sum, count;
public:
    functor() : sum(0), count(0) {};

    void operator()(int elem) {
        if (!(elem % 3)) {
            sum += elem;
            ++count;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main(int argc, char const* argv[])
{

    vector<int> arr{4, 1, 3, 6, 25, 54};
    cout << "[IN]: ";
    for (const auto& n : arr)
        cout << n << " ";

    cout << endl;

    auto zf = for_each(arr.begin(), arr.end(), functor());
    cout << "[OUT]: get_sum() = " << zf.get_sum() << endl;
    cout << "[OUT]: get_count() = " << zf.get_count() << endl;
    return 0;
}