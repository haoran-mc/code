#include <cstdio>
int a[]{1, 3, 5, 7, 9};
int b[]{2, 4, 6, 8, 10};

double findarrmid(int la, int ra, int lb, int rb) {
    int ma = (la + ra) >> 1;
    int mb = (lb + rb) >> 1;

    double mid = 0.0;
    if (a[ma] == b[mb])
        mid = (double)a[ma];
    else if (la == ra && lb == rb)
        mid = ((double)a[ma] + (double)b[mb]) / 2;
    else if (a[ma] < b[mb]) {
        if ((ra - la + 1) % 2 == 0) {
            la = ma + 1;
            rb = mb;
        } 
        else {
            la = ma;
            rb = mb;
        }
        mid = findarrmid(la, ra, lb, rb);
    }
    else if (a[ma] > b[mb]) {
        if ((ra - la + 1) % 2 == 0) {
            ra = ma;
            lb = mb + 1;
        } 
        else {
            ra = ma;
            lb = mb;
        }
        mid = findarrmid(la, ra, lb, rb);
    }
    return mid;
}

int main() {
    double res = findarrmid(0, 4, 0, 4);
    printf("%.1f\n", res);
    return 0;
}
