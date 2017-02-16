/*1055. The World's Richest (25)*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

struct node{
	char name[9];
	int age;
	int w;
};

bool cmp(node& l,node& r){
	if(l.w==r.w){
		if(l.age==r.age){
			return strcmp(l.name,r.name)<=0;
		}
		else 
			return l.age<r.age;
	}
	else 
		return l.w>r.w;
}

int main(){
	int n,n_query;
	//ifstream cin("data.txt");
	cin>>n>>n_query;
	vector<node> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%s %d %d", v[i].name, &v[i].age, &v[i].w);
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n_query;++i){
		int k,low,high;
		cin>>k>>low>>high;
		int cnt=0;
		cout<<"Case #"<<i<<":\n";
		for(int j=0;j<v.size();++j){
			if(v[j].age>=low&&v[j].age<=high){
				printf("%s %d %d\n", v[j].name, v[j].age, v[j].w);
				++cnt;
				if(cnt==k)
					break;
			}
		}
		if(cnt==0)
			cout<<"None\n";
	}
	//getchar();
	return 0;
}
