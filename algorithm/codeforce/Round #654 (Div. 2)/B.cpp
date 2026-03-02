//会超时
//知道规律，尽量推出公式

#include<iostream>
using namespace std;
int main()
{
    long long cnt;
    cin>>cnt;
    long long draw,r,pictures;
    while(cnt--){
        pictures=0;
        cin>>draw>>r;
        if(r>=draw){
            for(int day=draw;day>0;day--){
                if(!(draw%day)){
                    if(draw==day)
                        pictures+=1;
                    else
                        pictures+=day;
                }
                else
                    // pictures+=((day+1)-(draw%day));
                    pictures+=day;
            }
        }
        else{
            for(int day=r;day>0;day--){
            //     if(!(draw%day)){
            //         if(draw==day)
            //             pictures+=1;
            //         else
            //             pictures+=day;
            //     }
            //     else
            //         // pictures+=((day+1)-(draw%day));
                    pictures+=day;
            }
        }
        cout<<pictures<<endl;
    }
    return 0;
}