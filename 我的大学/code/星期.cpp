#include<iostream> 
using namespace std;
int main()
{
	int year,month,day;
	int leap,temp;
	char ch;
	cin>>year>>ch>>month>>ch>>day;
	cout<<year<<ch<<month<<ch<<day<<"星期";
	temp=((year-1)/4)*366+(year-1-(year)/4)*365;
	temp%=7;
	switch(month){
		case 12:day+=30;
		case 11:day+=31;
		case 10:day+=30;
		case 9:day+=31;
		case 8:day+=31;
		case 7:day+=30;
		case 6:day+=31;
		case 5:day+=30;
		case 4:day+=31;
		case 3:
			if(((year%100)&&!(year%4))||!(year%400))
			day+=29;
			else 
			day+=28;
		case 2:day+=31;
		default:break;
	}
	day+=temp;
	switch(day%7){
		case 0:cout<<"日";break;
		case 1:cout<<"一";break;
		case 2:cout<<"二";break;
		case 3:cout<<"三";break;
		case 4:cout<<"四";break;
		case 5:cout<<"五";break;
		case 6:cout<<"六";break;
	}
	return 0;
}
