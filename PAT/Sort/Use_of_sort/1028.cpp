/*1028. List Sorting (25)*/
/*有一个测试点超时*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,c;
struct node{
	string id;
	string name;
	int grade;
};

bool cmp(node& l,node& r){
	if(c==1){
		return l.id<r.id;
	}
	else if(c==2){
		if(l.name==r.name){
			return l.id<r.id;
		}
		else 
			return l.name<r.name;
	}
	else{
		if(l.grade==r.grade){
			return l.id<r.id;
		}
		else 
			return l.grade<r.grade;
	}
}
int main(){
	cin>>n>>c;
	vector<node> src(n);
	for(int i=0;i<n;++i)

		cin>>src[i].id>>src[i].name>>src[i].grade;
	sort(src.begin(),src.end(),cmp);
	for(int i=0;i<n;++i)
		cout<<src[i].id<<" "<<src[i].name<<" "<<src[i].grade<<endl;
	return 0;
}