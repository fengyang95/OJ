/*1071. Speech Patterns (25)*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	string word;
	map<string,int> cnt;
	int maxn=0;
	string ret;
	for(int i=0;i<s.size();++i){
		s[i]=tolower(s[i]);
		if(isalnum(s[i])){
			
			word+=s[i];
		}
		else{
			if(!word.empty()){//当word不为空的时候才计数！！！
				++cnt[word];
				if(cnt[word]>maxn){
				maxn=cnt[word];
				ret=word;
				}
			}
			word="";
		}
	}
	if(!word.empty()){
		++cnt[word];
		if(cnt[word]>maxn){
			maxn=cnt[word];
			ret=word;
		}
	}
	cout<<ret<<" "<<maxn;
	cout<<endl;
	return 0;
}