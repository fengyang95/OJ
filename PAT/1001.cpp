/*
1001. A+B Format (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	long a,b;
	cin>>a>>b;
	long ret=a+b;
	bool positive=true;
	if(ret<0){
		positive=false;
		ret=-ret;
	}
	int first=0;
	int second=0;
	int third=0;
	if(ret<1000)first=ret;
	else if(ret<1000000){
		first=ret/1000;
		second=ret%1000;
	}
	else{
		first=ret/1000000;
		second=(ret-first*1000000)/1000;
		third=ret%1000;
	}
	if(!positive)printf("-");
	cout<<first;
	cout<<second<<setw(3)<<setfill("0")<<third<<setw(3)<<setfill("0");
	return 0;
}
