#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
using namespace std;

template<typename T>
void print_container(const T& cnt) {

    for (auto it = cnt.begin(); it != cnt.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main(int argc, char const* argv[])
{
    set<string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    list<string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    vector<string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

    return 0;
}