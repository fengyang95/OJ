/*1083. List Grades (25)*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	char name[11];
	char id[11];
	int grade;
};

bool cmp(node& l,node& r){
	return l.grade<r.grade;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<node> stu(n);
	for(int i=0;i<n;++i){
		scanf("%s%s%d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	int low,high;
	scanf("%d%d",&low,&high);
	vector<node> ret;
	for(int i=0;i<n;++i){
		if(stu[i].grade>=low&&stu[i].grade<=high)
			ret.push_back(stu[i]);
	}
	sort(ret.begin(),ret.end(),cmp);
	if(!ret.empty()){
		for(int i=0;i<ret.size();++i){
			printf("%s %s\n",ret[i].name,ret[i].id);
		}
	}
	else 
		printf("NONE");
	return 0;
}