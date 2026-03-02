
# Table of Contents



*/ 260302 15:03 Mon  
\#include <algorithm>  
/* #include <iostream>  
using namespace std;  

int gcd(int a, int b) {  
    return b ? gcd(b, a % b) : a;  
}  

int lcm(int a, int b, int c) {  
    int m1 = a / gcd(a, b) \* b;  
    int m2 = b / gcd(b, c) \* c;  
    return m1 / gcd(m1, m2) \* m2;  
}  

int main() {  
    int N1, M1, N2, M2, K;  
    scanf(&ldquo;%d/%d %d/%d %d&rdquo;, &N1, &M1, &N2, &M2, &K);  
    if (N1 \* M2 > N2 \* M1) {  
        swap(N1, N2);  
        swap(M1, M2);  
    }  

// 分母最小公倍数  
int M\_lcm = lcm(M1, M2, k);  

// 整理成同分母  
int N1\_ = M\_lcm / M1 \* N1;  
int N2\_ = M\_lcm / M2 \* N2;  

bool isFirst = true;  

for (int i = N1\_ + 1; i < N2\_; i++) {  
    // i / M\_lcm  
    int k = gcd(i, M\_lcm);  

    if (M\_lcm / k == K) {  
        if (isFirst) {  
            printf(&ldquo;%d/%d&rdquo;, i / k, K);  
            isFirst = false;  
        } else {  
            printf(&ldquo; %d/%d&rdquo;, i / k, K);  
        }  
    }  
}  
printf(&ldquo;\n&rdquo;);  

    return 0;  
}  

