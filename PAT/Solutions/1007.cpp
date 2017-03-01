/*1007. Maximum Subsequence Sum (25)*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	int max_sum=-1,now_sum=0,left=0,right=0,now_left=0;
	bool allnegative=true;
	for(int i=0;i<n;++i){
		cin>>v[i];
		if(v[i]>=0)allnegative=false;
		now_sum+=v[i];
		if(now_sum>max_sum){
			max_sum=now_sum;
			left=now_left;
			right=i;
		}
		else if(now_sum<0){
			now_sum=0;
			now_left=i+1;
		}
	}
	if(allnegative)cout<<"0 "<<v[0]<<" "<<v[n-1];
	else
		cout<<max_sum<<" "<<v[left]<<" "<<v[right];
	return 0;
}