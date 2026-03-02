// 我觉得用最小公倍数的方法才是应该的，但会超时
// 或者像梁燕平说的，a、b串里包含c串，但是不好代码实现
// 所以使用这种方法，复制两遍，为的就是防止交接处有问题

#include<iostream>
using namespace std;
int main()
{
    string str_1, str_2;
    while(cin >> str_1 >> str_2) {
        if(str_1.length() == str_2.length()) {
            if(str_1 > str_2) {
                cout << ">" << endl;
            }
            else if(str_1 < str_2) {
                cout << "<" << endl;
            }
            else {
                cout << "=" << endl;
            }
        }
        else {
            str_1 += str_1;
            str_2 += str_2;
            if(str_1.length() > str_2.length()) {
                int flag = 0;
                for(int i = 0, j = 0; i < str_1.length(); i++, j++) {
                    while(j == str_2.length()) {
                        j = 0;
                    }
                    if(str_1[i] > str_2[j]) {
                        flag = 1;
                        cout << ">" << endl;
                        break;
                    }
                    else if(str_1[i] < str_2[j]) {
                        flag = 1;
                        cout << "<" << endl;
                        break;
                    }
                }
                if(flag == 0) {
                    cout << "=" << endl;
                }
            }
            else if(str_1.length() < str_2.length()) {
                int flag = 0;
                for(int i = 0, j = 0; i < str_2.length(); i++, j++) {
                    while(j == str_1.length()) {
                        j = 0;
                    }
                    if(str_1[j] < str_2[i]) {
                        flag =1;
                        cout << "<" << endl;
                        break;
                    }
                    else if(str_1[j] > str_2[i]) {
                        flag = 1;
                        cout << ">" << endl;
                        break;
                    }
                }
                if(flag == 0) {
                    cout << "=" << endl;
                }
            }
        }
    }
}