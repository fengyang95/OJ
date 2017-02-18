/*1050. String Subtraction (20)*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	map<char,int> cnt;
	for(int i=0;i!=a.size();++i){
		cnt[a[i]]=1;
	}
	for(int i=0;i!=b.size();++i){
		cnt[b[i]]=0;
	}
	for(int i=0;i!=a.size();++i){
		if(cnt[a[i]]!=0)
			cout<<a[i];
	}
	return 0;
}