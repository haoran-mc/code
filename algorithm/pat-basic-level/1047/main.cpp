#include <iostream>
#include <map>
#include <string>
using namespace std;
map<int, int> mp;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        int score;
        cin >> str >> score;
        int pos = str.find("-");
        int team = stoi(str.substr(0, pos));
        int stu = stoi(str.substr(pos + 1, str.length()));
        mp[team] += score;
    }
    int maxscore = 0, maxteam = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > maxscore) {
            maxteam = it->first;
            maxscore = it->second;
        }
    }
    cout << maxteam << " " << maxscore << endl;
    return 0;
}
