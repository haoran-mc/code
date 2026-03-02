#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;

int main() {
    string str;
    while (cin >> str)
        vec.push_back(str);

    for (auto it = vec.end() - 1; it != vec.begin(); it--)
        cout << *it << " ";

    auto it = vec.begin();
    cout << *it;
    return 0;
}
