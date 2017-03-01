/*1001. A+B Format (20)*/
#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int sum=a+b;
	bool negative=false;
	if(sum<0)negative=true;
	sum=abs(sum);
	int right=sum%1000;
	int mid=sum/1000%1000;
	int left=sum/1000000%1000;
	if(negative)cout<<"-";
	if(left!=0){
		printf("%d,%03d,%03d",left,mid,right);
	}
	else if(mid!=0){
		printf("%d,%03d",mid,right);
	}
	else{
		printf("%d",right);
	}
	return 0;
}