/*1031. Hello World for U (20)*/
/*2.26 11:02---11:09 7min ac*/
/*1 submition*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n=s.size();
	int n1=(n+2)/3-1;
	int space=n-2*n1-2;
	int left=0,right=s.size()-1;
	for(int i=0;i<n1;++i){
		cout<<s[left++];
		for(int j=0;j<space;++j)
			cout<<" ";
		cout<<s[right--]<<endl;
	}
	for(int k=left;k<=right;++k)
		cout<<s[k];
	return 0;
}