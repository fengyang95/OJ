/*1038. Recover the Smallest Number (30)*/
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
	vector<string> s(n);
	for(int i=0;i<n;++i)
		cin>>s[i];
	sort(s.begin(),s.end(),cmp);
	string ret;
	for(int i=0;i<s.size();++i){
		ret+=s[i];
	}
	while(!ret.empty()&&ret.front()=='0')
		ret.erase(ret.begin());
	if(ret.empty())
		cout<<"0";
	else
		cout<<ret;
	return 0;
}