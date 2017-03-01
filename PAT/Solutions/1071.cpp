/*1071. Speech Patterns (25)*/
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

int main(){
	string s,t;
	getline(cin,s);
	map<string,int> m;
	for(int i=0;i<s.size();++i){
		if(isalnum(s[i])){
			s[i]=tolower(s[i]);
			t+=s[i];
		}
		else{
			if(!t.empty())
				++m[t];
			t="";
		}
	}
	if(!t.empty())
		++m[t];
	int maxn=0;
	string ret;
	for(map<string,int>::iterator it=m.begin();it!=m.end();++it){
		if(it->second>maxn){
			ret=it->first;
			maxn=it->second;
		}
	}
	cout<<ret<<" "<<maxn;
	return 0;
}