/*1050. String Subtraction (20)*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string src,s;
	getline(cin,src);
	getline(cin,s);
	vector<bool> flag(256,false);
	for(int i=0;i<src.size();++i)
		flag[src[i]]=true;
	for(int i=0;i<s.size();++i)
		flag[s[i]]=false;
	for(int i=0;i<src.size();++i)
		if(flag[src[i]]==true)
			cout<<src[i];
	return 0;
}