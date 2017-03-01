/*1024. Palindromic Number (25)*/
/*两个测试点没通过 可能是溢出 看来得用字符串的方法做*/
#include <iostream>
#include <vector>
using namespace std;

long long  onestep(long long src){
	if(src==0)return 0;
	long  ret=0;
	long  temp=src;
	while(temp){
		ret=ret*10+temp%10;
		temp/=10;
	}
	return src+ret;
}

bool is_palindromic(long long  src){
	if(onestep(src)==2*src)
		return true;
	else 
		return false;
}

int main(){
	long long  src,max_step;
	cin>>src>>max_step;
	long long step=0;
	while(step<max_step){
		if(is_palindromic(src))
			break;
		src=onestep(src);
		++step;
	}
	cout<<src<<endl<<step;
	return 0;
}