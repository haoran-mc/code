#include<iostream>
using namespace std;

int common_multiple(int mul_1, int mul_2) {
    int temp;
    int mul = mul_1 * mul_2;
    while(mul_2 != 0) {
        temp = mul_2;
        mul_2 = mul_1 % mul_2;
        mul_1 = temp;
    }
    return mul / mul_1;
}

int main()
{
    string str_1,str_2;
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
            int gcd = common_multiple(str_1.length(),str_2.length());
            int i = 0, j = 0, index;
            int flag = 0;
            for(index = 0; index < str_1.length() + str_2.length() - gcd ; i++, j++, index++) {
                while(i == str_1.length()) {
                    i = 0;
                }
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
    }
}