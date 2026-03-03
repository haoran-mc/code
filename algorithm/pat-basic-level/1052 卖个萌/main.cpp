#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> face[3]; // face[0] 手、face[1] 眼、face[2] 口
map<string, int> handMap, eyeMap, mouthMap;

int main() {
    for (int i = 0; i < 3; i++) {
        string str;
        getline(cin, str);

        for (int j = 0; j < str.size(); j++) {
            string temp;
            if (str[j] == '[') {
                while (str[++j] != ']' && j < str.size())
                    temp += str[j];

                face[i].push_back(temp);
                if (i == 0)
                    handMap[temp] = 1;
                if (i == 1)
                    eyeMap[temp] = 1;
                if (i == 2)
                    mouthMap[temp] = 1;
            }
        }
    }

    int k = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e; // 左手 左眼 口 右眼 右手

        a--, b--, c--, d--, e--;
        if (a < face[0].size() && b < face[1].size() && c < face[2].size() && d < face[1].size() && e < face[0].size()) {         // 用户选择的序号存在
            if (handMap[face[0][a]] && eyeMap[face[1][b]] && mouthMap[face[2][c]] && eyeMap[face[1][d]] && handMap[face[0][e]]) { // 用户选择的表情存在
                printf("%s(%s%s%s)%s\n", face[0][a].c_str(), face[1][b].c_str(), face[2][c].c_str(), face[1][d].c_str(), face[0][e].c_str());
            } else {
                printf("Are you kidding me? @\\/@\n");
            }
        } else {
            printf("Are you kidding me? @\\/@\n");
        }
    }
    return 0;
}
