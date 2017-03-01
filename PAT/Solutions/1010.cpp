/*1010. Radix (25)*/
/*2.24 15:59--16:18  19min 16points*/
/*16:24 22points*/

/*I have no idea.....what happend???*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

long long parse(string s,int radix){
	long long ret=0;
	for(int i=0;i<s.size();++i){
		if(isdigit(s[i])){
			ret=(ret*radix+s[i]-'0');
		}
		else{
			ret=(ret*radix+s[i]-'a'+10);
		}
	}
	return ret;
}

int main(){
	string s1,s2;
	int index,radix;
	int ans=0;
	cin>>s1>>s2>>index>>radix;
	long long num;
	if(index==1){
		num=parse(s1,radix);
		for(int i=2;i<=1000;++i){
			if(parse(s2,i)==num){
				ans=i;
				break;
			}
		}
	}
	else{
		num=parse(s2,radix);
		for(int i=2;i<=1000;++i){
			if(parse(s1,i)==num){
				ans=i;
				break;
			}
		}
	}
	if(ans==0)
		cout<<"Impossible";
	else 
		cout<<ans;
	return 0;
}