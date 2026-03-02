/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1033 To Fill or Not to Fill.cpp
 *   创建日期：2020年08月27日 ---- 14时04分
 *   结束日期：2020年08月27日 ---- 19时52分
 *   题    目：To Fill or Not to Fill
 *   算    法：贪心
 *   描    述：目的是找到最近较便宜的油，如果在行车范围内能找到，
 *             就前往，否则仍然是每个加油站都开一次
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct gasStation {
    double price;
    double position;
    gasStation(double _price, double _position): price(_price), position(_position){}
};
vector<gasStation> station;
double Cmax, D, Davg, N;
bool cmp(gasStation A, gasStation B) {
    return A.position < B.position;
}

int main() {
    scanf("%lf", &Cmax);
    scanf("%lf", &D);
    scanf("%lf", &Davg);
    scanf("%lf", &N);
    int n = N;
    while (n--) {
        double a;
        double b;
        scanf("%lf", &a);
        scanf("%lf", &b);
        station.push_back(gasStation(a, b));
    }

    sort(station.begin(), station.end(), cmp);
    station.push_back(gasStation(0, D));

    if (station[0].position != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else {
        int nowindex = 0;
        double maxreach = Cmax * Davg;
        double nowtank  = 0;
        double cost = 0;

        while (nowindex < N) {
            double lessprice = -1;
            int lessindex;
            if (station[nowindex+1].position > station[nowindex].position + maxreach) {
                printf("The maximum travel distance = %.2f\n", station[nowindex].position + maxreach);
                return 0;
            }
            else {
                for (int i = nowindex+1; station[i].position <= station[nowindex].position + maxreach; i++) {
                    if (station[i].price <= station[nowindex].price) {
                        lessprice = station[i].price;
                        lessindex = i;
                        break;
                    }
                }
                if (lessprice != -1) {
                    double needoil = (station[lessindex].position - station[nowindex].position) / Davg;
                    if (nowtank < needoil) {
                        cost += (needoil - nowtank) * station[nowindex].price;
                    }
                    nowindex = lessindex;
                    nowtank = 0;
                }
                else {
                    double needoil = (station[nowindex+1].position - station[nowindex].position) / Davg;
                    cost += (Cmax - nowtank) * station[nowindex].price;
                    nowtank = Cmax - needoil;
                    nowindex++;
                }
            }
        }
        printf("%.2f\n", cost);
        return 0;
    }
}
