/*1093. Count PAT's (25)*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int> cnt_p,cnt_t;
	int len=s.size();
	cnt_p.resize(len,0);
	cnt_t.resize(len,0);
	for(int i=0;i<len-1;++i){
		if(s[i]=='P')cnt_p[i+1]=cnt_p[i]+1;
		else
			cnt_p[i+1]=cnt_p[i];
	}
	for(int i=len-1;i>0;--i){
		if(s[i]=='T')cnt_t[i-1]=cnt_t[i]+1;
		else 
			cnt_t[i-1]=cnt_t[i];
	}
	int ans=0;
	for(int i=1;i<len-1;++i){
		if(s[i]=='A'){
			ans=(ans+cnt_t[i]*cnt_p[i])%1000000007;
		}
	}
	cout<<ans;
	return 0;
}