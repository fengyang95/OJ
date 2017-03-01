/*1005. Spell It Right (20)*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();++i)
		sum+=s[i]-'0';
	stack<int> stk;
	if(sum==0)stk.push(0);
	while(sum){
		stk.push(sum%10);
		sum/=10;
	}
	vector<string> v{"zero","one","two","three","four","five","six","seven","eight","nine"};
	cout<<v[stk.top()];
	stk.pop();
	while(!stk.empty()){
		cout<<" "<<v[stk.top()];
		stk.pop();
	}
	return 0;

}