#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    map<int, vector<int>> mp;
    mp[1].push_back(1);
    mp[1].push_back(2);
    mp[1].push_back(3);
    mp[2].push_back(4);
    mp[2].push_back(5);
    mp[2].push_back(6);
    mp[3].push_back(7);
    mp[3].push_back(8);
    mp[3].push_back(9);
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it -> first << " " << it -> second[1] << endl;
    }
    return 0;
}
