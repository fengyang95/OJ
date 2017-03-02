#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	vector<int> t(n);
	for(int i=0;i<n;++i){
		cin>>t[i];
	}
	sort(t.begin(),t.end(),cmp);
	int index=0;
	for(int i=0;i<n;++i){
		if(t[i]>i+1){
			++index;
		}
		else 
			break;
	}
	cout<<index;
	return 0;
}