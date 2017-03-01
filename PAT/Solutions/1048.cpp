/*1048. Find Coins (25)*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,sum;
	cin>>n>>sum;
	map<int,int> cnt;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
		++cnt[v[i]];
	}
	sort(v.begin(),v.end());
	bool has_found=false;
	for(int i=0;i<n;++i){
		if(cnt[v[i]]>0){
			--cnt[v[i]];
			if(cnt[sum-v[i]]>0){
				cout<<v[i]<<" "<<sum-v[i];
				has_found=true;
				break;
			}
			++cnt[v[i]];
		}
	}
	if(!has_found){
		cout<<"No Solution";
	}
	return 0;
}