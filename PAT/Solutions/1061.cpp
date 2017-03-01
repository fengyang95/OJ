/*1061. Dating (20)*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(){
	string s1,s2,s3,s4;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	getline(cin,s4);
	int day,hour,minute;
	bool hasfind_first=false;
	for(int i=0;i<s1.size()&&i<s2.size();++i){
		if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'&&!hasfind_first){
			hasfind_first=true;
			day=s1[i]-'A'+1;
			continue;
		}
		if(s1[i]==s2[i]&&((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='A'&&s1[i]<='N'))){
			if(hasfind_first){
				if(s1[i]<='9')hour=s1[i]-'0';
				else
					hour=s1[i]-'A'+10;
				break;
			}
		}
	}

	for(int i=0;i<s3.size()&&i<s4.size();++i){
		if(s3[i]==s4[i]&&isalpha(s3[i])){
			minute=i;
			break;
		}
	}

	vector<string> d{"","MON","TUE","WED","THU","FRI","STA","SUN"};
	cout<<d[day];
	printf(" %02d:%02d",hour,minute);
	return 0;
}