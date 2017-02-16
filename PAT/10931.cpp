#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	int cntp=0;
	int cntt=0;
	for(int i=0;i<len;++i){
		if(s[i]=='T')++cntt;
	}
	int ret=0;
	for(int i=0;i<len;++i){
		if(s[i]=='P')++cntp;
		if(s[i]=='T')--cntt;
		if(s[i]=='A'){
			ret=(ret+cntp*cntt%1000000007)% 1000000007;
		}
	}
	cout<<ret;
	return 0;
}