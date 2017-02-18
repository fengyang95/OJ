/*1084. Broken Keyboard (20)*/
#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main(){
	string s,out,ret;
	cin>>s>>out;
	map<char,int> flag;
	for(int i=0;i<s.size();++i){
		s[i]=toupper(s[i]);
		flag[s[i]]=-1;
	}
	for(int i=0;i<out.size();++i){
		out[i]=toupper(out[i]);
		flag[out[i]]=1;
	}
	for(int i=0;i<s.size();++i){
		if(flag[s[i]]==-1){
			flag[s[i]]=1;//注意每个字母只能输出一次
			ret+=s[i];
		}
	}
	cout<<ret;
	return 0;
}