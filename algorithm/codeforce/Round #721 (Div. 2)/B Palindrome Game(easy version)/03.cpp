/*----------------------------------------------------------------
 *   
 *   文件名称：03.cpp
 *   创建日期：2021年05月21日 星期五 20时51分12秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：题解
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void solve(){
	int n;
	string str;
	cin >> n >> str;
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		cnt += str[i]=='0';
	if (cnt == 1) {
		cout << "BOB\n";
		return;
	}
	if (cnt % 2) {
		cout << "ALICE\n";
		return;
	}
	cout << "BOB\n";
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
		solve();
    return 0;
}
