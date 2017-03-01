/*1077. Kuchiguse (20)*/
#include <iostream>
#include <string>
using namespace std;

string find_common_suffix(string& a,string& b){
	string ret;
	int i,j;
	for(i=b.size()-1,j=a.size()-1;a[j]==b[i]&&i>=0&&j>=0;--i,--j);
	ret=a.substr(j+1);
	return ret;
}

int main(){
	int n;
	cin>>n;
	getchar();
	string ans;
	string src;
	getline(cin,src);
	ans=src;
	for(int i=0;i<n-1;++i){
		getline(cin,src);
		ans=find_common_suffix(ans,src);
	}
	if(!ans.empty())
		cout<<ans;
	else
		cout<<"nai";
	return 0;
}