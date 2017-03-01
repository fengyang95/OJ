/*1041. Be Unique (20)*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	bool isfind=false;
	map<int,int> cnt;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
		++cnt[v[i]];
	}
	for(int i=0;i<n;++i){
		if(cnt[v[i]]==1){
			isfind=true;
			cout<<v[i];
			break;
		}
	}
	if(!isfind){
		cout<<"None";
	}
	return 0;
}