/*1038. Recover the Smallest Number (30)*/
/**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string& lhs,string& rhs){
	return lhs+rhs<rhs+lhs;
}

int main(){
	int n;
	cin>>n;
	string ans="";
	vector<string> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i)
		ans+=v[i];
	int i;
	for(i=0;i<ans.size()&&ans[i]=='0';++i);
	if(i==ans.size())
		cout<<"0";
	else
		cout<<ans.substr(i);
	return 0;
}