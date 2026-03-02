#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<string> All; /*存放的是所有参赛队员*/
    set<string> loser; /*存放的是有入度的参赛队员*/
    string str1;
    string str2;
    while(n--) {
        cin >> str1 >> str2;
        All.insert(str1);
        loser.insert(str2);
        All.insert(str2);
    }
    /*如果只有一个人没有入度，显然他是冠军*/
    cout << (All.size() - loser.size() == 1 ? "Yes" : "No");
    return 0;
}
