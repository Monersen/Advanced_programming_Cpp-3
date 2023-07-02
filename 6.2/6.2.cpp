#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n = 0, nn;
    set<int> v;

    cout << "[IN]: " << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> nn;
        v.insert(nn);
    }

    vector<int> as(v.begin(), v.end());
    sort(as.begin(), as.end(), [](const int& a, const int& b) {
        return a > b;
        });

    cout << "[OUT]: " << endl;
    for (const auto& i : as)
        cout << i << endl;

    return 0;
}