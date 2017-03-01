/*1055. The World's Richest (25)*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	char name[10];
	int age;
	int wealth;
};

bool cmp(node& lhs,node& rhs){
	if(lhs.wealth==rhs.wealth){
		if(lhs.age==rhs.age){
			return strcmp(lhs.name,rhs.name)<0;
		}
		return lhs.age<rhs.age;
	}
	return lhs.wealth>rhs.wealth;
}

int main(){
	int n,n_query;
	cin>>n>>n_query;
	vector<node> people(n);
	for(int i=0;i<n;++i){
		scanf("%s %d %d",people[i].name,&people[i].age,&people[i].wealth);
	}
	sort(people.begin(),people.end(),cmp);
	int max_cnt,cnt,low,high;
	for(int i=1;i<=n_query;++i){
		scanf("%d %d %d",&max_cnt,&low,&high);
		printf("Case #%d:\n",i);
		cnt=0;
		for(int j=0;j<n&&cnt<max_cnt;++j){
			if(people[j].age>=low&&people[j].age<=high){
				printf("%s %d %d\n",people[j].name,people[j].age,people[j].wealth);
				++cnt;
			}
		}
		if(cnt==0){
			printf("None\n");
		}
	}
	return 0;
}