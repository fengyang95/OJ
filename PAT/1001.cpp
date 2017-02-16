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
