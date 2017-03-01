/*1028. List Sorting (25)*/
/*2.26 9:53--10:06 13min ac*/
/*2 submitions 用cin cout 超时了！！*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,c;
struct node{
	int id;
	char name[10];
	int grade;
};

bool cmp(node& lhs,node& rhs){
	if(c==1){
		return lhs.id<rhs.id;
	}
	if(c==2){
		if(strcmp(lhs.name,rhs.name)==0){
			return lhs.id<rhs.id;
		}
		else
			return strcmp(lhs.name,rhs.name)<0;
	}
	if(c==3){
		if(lhs.grade==rhs.grade){
			return lhs.id<rhs.id;
		}
		else
			return lhs.grade<rhs.grade;
	}
}

int main(){
	scanf("%d %d",&n,&c);
	vector<node> v(n);
	for(int i=0;i<n;++i){
		scanf("%d %s %d",&v[i].id,v[i].name,&v[i].grade);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i)
		printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
	return 0;
}

