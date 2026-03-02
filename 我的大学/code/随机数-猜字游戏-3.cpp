//模拟文曲星上的猜数游戏，先由计算机随机生成一个各位相异的4位数字，由用户来猜，根据用户猜测的结果给出提示：xAyB
//其中，A前面的数字表示有几位数字不仅数字猜对了，而且位置也正确，B前面的数字表示有几位数字猜对了，但是位置不正确。
//最多允许用户猜的次数由用户从键盘输入。如果猜对，则提示“Congratulations!”；如果在规定次数以内仍然猜不对，则给出提示“Sorry, you haven't guess the right number!”。程序结束之前，在屏幕上显示这个正确的数字。


#include<iostream>
#include<cstdlib>
#include<ctime>
#define max 9999
#define min 1000
using namespace std;
int* num_dismantle(int number)//将一个四位数各位的数拆解出来
{
	static int num[4];
	num[3]=number%10;num[2]=(number/10)%10;
	num[1]=(number/100)%10;num[0]=number/1000;
	return num;
}
int main()
{
	int random_num;
	srand(100000*time(0));
	random_num=rand()%(max-min)+min;
	int* p;
	int Random[4];//将随机数拆解并存入到一个一维数组中
	p=num_dismantle(random_num);//调用函数，拆解开始
	for (int i=0;i<4;++i)
		Random[i]=*(p+i);
	cout<<"Input the number of guesses : ";
	int num;cin>>num;cout<<endl;//输入猜测的次数
	int Guess_num;
	for(int i=0;i<num;++i)//开始猜测
	{cout<<"Input the number(1000~9999) you guess : ";
	 cin>>Guess_num;int Guess[4];//输入猜测的数
	 p=num_dismantle(Guess_num);//将猜测的数拆解
	 for(int j=0; j<4;++j)//将猜测的数储存
		 Guess[j]=*(p+j);
	 if (Guess_num==random_num)//猜测正确，给出提示
	  {cout<<endl<<"Congratulations!"<<endl;
	   break;
	  }
	 else
	 {
		 int A=0,B=0;
		 for(int j=0;j<4;++j)
			 if(Guess[j]==Random[j])
				 A++;
		 if(Guess[0]==Random[1]||Guess[0]==Random[2]||Guess[0]==Random[3])
			 B++;
		 if(Guess[1]==Random[0]||Guess[1]==Random[2]||Guess[1]==Random[3])
			 B++;
		 if(Guess[2]==Random[0]||Guess[2]==Random[1]||Guess[2]==Random[3])
			 B++;
		 if(Guess[3]==Random[0]||Guess[3]==Random[1]||Guess[3]==Random[2])
			 B++;
		 cout<<A<<"A"<<B<<"B"<<endl;
		 if(i==num-1)
		 cout<<endl<<"Sorry, you haven't guess the right number!"<<endl;
	 }
	}
	cout<<random_num<<endl;
//	system("pause");
	return 0;
}
