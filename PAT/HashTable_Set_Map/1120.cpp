/*1120. Friend Numbers (20)*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int sum(int num){
	int ret=0;
	while(num){
		ret+=num%10;
		num/=10;
	}
	return ret;
}
int main(){
	int n,num;
	cin>>n;
	set<int> s;
	for(int i=0;i<n;++i){
		cin>>num;
		s.insert(sum(num));
	}
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		if(it!=s.begin()){
			cout<<" "<<*it;
		}
		else
			cout<<*it;
	}
	return 0;
}