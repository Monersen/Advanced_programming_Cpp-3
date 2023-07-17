#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

using namespace std;

class node
{
public:
    int m_value;
    weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = make_shared<node>(1);
        if (!node1) {
            cerr << "Unable to create shared ptr\n";
            return -1;
        }

        auto node2 = make_shared<node>(2);
        if (!node2) {
            cerr << "Unable to create shared ptr\n";
            return -1;
        }
    }

    return 0;
}