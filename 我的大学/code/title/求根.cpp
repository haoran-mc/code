#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    float a,b,c;
    float x1,x2,x;
    cin>>a>>b>>c;
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(5);
    if(b*b==4*a*c){
    	x=(-b+sqrt(b*b-4*a*c))/(2*a);
        if(fabs(x)<0.000001)
            x=fabs(x);
        else
            cout<<"x1=x2="<<(-b+sqrt(b*b-4*a*c))/(2*a);
	} 
    else if(b*b>4*a*c){
        x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        if(fabs(x1)<0.000001)
            x1=fabs(x1);
        else
            x1=x1;
        x2=(-b-sqrt(b*b-4*a*c))/(2*a);
        if(fabs(x2)<0.000001)
            x2=fabs(x2);
        else
            x2=x2;
        if(x1>x2)
            cout<<"x1="<<x1<<";"<<"x2="<<x2;
        else
            cout<<"x1="<<x2<<";"<<"x2="<<x1;
    }
    else if(b*b<4*a*c){
        if(a>0){
            if(b==0){
                cout<<"x1="<<fabs(-b/(2*a))<<"+"<<sqrt(4*a*c-b*b)/(2*a)<<"i";
                cout<<";";
                cout<<"x2="<<fabs(-b/(2*a))<<"-"<<sqrt(4*a*c-b*b)/(2*a)<<"i";
            }
            else{
                cout<<"x1="<<-b/(2*a)<<"+"<<sqrt(4*a*c-b*b)/(2*a)<<"i";
                cout<<";";
                cout<<"x2="<<-b/(2*a)<<"-"<<sqrt(4*a*c-b*b)/(2*a)<<"i";
            }
        }
        else{
            if(b==0){
                cout<<"x1="<<fabs(-b/(2*a))<<"+"<<-sqrt(4*a*c-b*b)/(2*a)<<"i";
                cout<<";";
                cout<<"x2="<<fabs(-b/(2*a))<<"-"<<-sqrt(4*a*c-b*b)/(2*a)<<"i";
            }
            else{
                cout<<"x1="<<-b/(2*a)<<"+"<<-sqrt(4*a*c-b*b)/(2*a)<<"i";
                cout<<";";
                cout<<"x2="<<-b/(2*a)<<"-"<<-sqrt(4*a*c-b*b)/(2*a)<<"i";
            }
        }
    }
}

/*
描述

    利用公式x1 = (-b + sqrt(b*b-4*a*c))/(2*a), x2 = (-b - sqrt(b*b-4*a*c))/(2*a)求一元二次方程ax2+ bx + c =0的根，其中a不等于0。
输入
    输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），分别表示方程ax2 + bx + c =0的系数。
输出
    输出一行，表示方程的解。
    若b2 = 4 * a * c,则两个实根相等，则输出形式为：x1=x2=...。
    若b2 > 4 * a * c,则两个实根不等，则输出形式为：x1=...;x2 = ...，其中x1>x2。
    若b2 < 4 * a * c，则有两个虚根，则输出：x1=实部+虚部i; x2=实部-虚部i，即x1的虚部系数大于等于x2的虚部系数，实部为0时不可省略。实部 = -b / (2*a), 虚部 = sqrt(4*a*c-b*b) / (2*a)

    所有实数部分要求精确到小数点后5位，数字、符号之间没有空格。
*/ 
