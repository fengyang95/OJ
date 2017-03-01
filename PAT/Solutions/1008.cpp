/*1008. Elevator (20)*/
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int total_time=0;
	int now_request,pre_request=0;
	for(int i=0;i<n;++i){
		cin>>now_request;
		if(now_request>pre_request)
			total_time+=(now_request-pre_request)*6+5;
		else
			total_time+=(pre_request-now_request)*4+5;
		pre_request=now_request;
	}
	cout<<total_time;
	return 0;
}