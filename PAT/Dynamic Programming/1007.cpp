/*1007. Maximum Subsequence Sum (25)*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int left=0,right=0,temp=0,sum=-1,tempindex=0;//leftwei
	bool all_negative=true;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]>=0)
			all_negative=false;
		temp+=v[i];
		if(temp>sum){
			left=tempindex;
			right=i;
			sum=temp;
		}
		else if(temp<0){
			tempindex=i+1;
			temp=0;
		}
	}
	if(all_negative){
		cout<<"0 "<<v[0]<<" "<<v[n-1];
	}
	else{
		cout<<sum<<" "<<v[left]<<" "<<v[right];
	}
	return 0;
}
