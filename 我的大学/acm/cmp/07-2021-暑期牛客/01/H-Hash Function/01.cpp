#include<bits/stdc++.h>
typedef long double LD;
using namespace std;

const int N = 1500040;
const LD pi = acos(-1.0);

int len=1<<20;

struct Complex {
    LD r,i;
    Complex(LD r=0,LD i=0):r(r),i(i) {};
    Complex operator+(const Complex &rhs) {
        return Complex(r + rhs.r,i + rhs.i);
    }
    Complex operator-(const Complex &rhs) {
        return Complex(r - rhs.r,i - rhs.i);
    }
    Complex operator*(const Complex &rhs) {
        return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);
    }
} va[N],vb[N];

void rader(Complex F[],int len) { //len = 2^M,reverse F[i] with  F[j] j为i二进制反转
    int j = len >> 1;
    for(int i = 1;i < len - 1;++i) {
        if(i < j) swap(F[i],F[j]);   // reverse
        int k = len>>1;
        while(j>=k) {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void FFT(Complex F[],int len,int t) {
    rader(F,len);
    for(int h=2;h<=len;h<<=1) {
        Complex wn(cos(-t*2*pi/h),sin(-t*2*pi/h));
        for(int j=0;j<len;j+=h) {
            Complex E(1,0); //旋转因子
            for(int k=j;k<j+h/2;++k) {
                Complex u = F[k];
                Complex v = E*F[k+h/2];
                F[k] = u+v;
                F[k+h/2] = u-v;
                E=E*wn;
            }
        }
    }
    if(t==-1)   //IDFT
        for(int i=0;i<len;++i)
            F[i].r/=len;
}

void Conv(Complex a[],Complex b[],int len) { //求卷积
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;++i) 
        a[i] = a[i]*b[i];
    FFT(a,len,-1);
}
int n,limit;
int a[N];
long long num[N];

void solve() {
    scanf("%d",&n);
    int Mx = 0;
    //    limit = N ;
    for(int i=0;i<n;i++) {
        int x; scanf("%d",&a[i]);
        limit = max(limit, a[i]);
        va[a[i]].r+=1;
        vb[500000-a[i]].r+=1;
    }
    //    cout << len << endl;
    Conv(va,vb,len);
    for (int i=0; i<=500000; i++)
        num[i]=(long long)(va[500000+i].r+0.5);
    long long ans1=1e18,ans2=0;
    for (int i=n;i<=limit + 1;i++) {
        long long cnt = 0;
        for (int j=i;j<=len;j+=i)
            cnt+=num[j];
        if (cnt == 0) {
            ans1=cnt;
            ans2=i;
            break;
        }
    }
    cout<<ans2<<endl;
}

int main() {
    solve();
    return 0;
}
