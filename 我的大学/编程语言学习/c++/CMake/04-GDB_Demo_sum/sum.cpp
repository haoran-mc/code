#include <iostream>
using namespace std;

int main(int argc,char **argv) {
    int N = 100;
    int sum = 0;

    // calculate sum from 1 to 100
    for (int i = 0; i <= N; ++i)
        sum += i;

    cout << "sum = " << sum << endl;
    cout << "The program is over."   << endl;

    return 0;
}
