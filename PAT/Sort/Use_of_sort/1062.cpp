/*1062. Talent and Virtue (25)*/
/*用cin和cout会有两个测试点超时*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person{
	int name;
	int v;
	int t;
};

bool cmp(person& lhs,person& rhs){
	if(lhs.v+lhs.t==rhs.v+rhs.t){
		if(lhs.v==rhs.v){
			return lhs.name<rhs.name;
		}
		else 
			return lhs.v>rhs.v;
	}
	else 
		return (lhs.v+lhs.t)>(rhs.v+rhs.t);
}

void print(vector<person>& p){
	for(int i=0;i<p.size();++i)
		printf("%d %d %d\n",p[i].name,p[i].v,p[i].t);
}

int main(){
	int n,l,h;
	cin>>n>>l>>h;
	vector<person> sages,noblemen,fool_men,otherman;
	person temp;
	int cnt=n;
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&temp.name,&temp.v,&temp.t);
		if(temp.v<l||temp.t<l){
			--cnt;
			continue;
		}
		else if(temp.v>=h&&temp.t>=h)
			sages.push_back(temp);
		else if(temp.t<h&&temp.v>=h)
			noblemen.push_back(temp);
		else if(temp.t<h&&temp.v<h&&temp.t<=temp.v)
			fool_men.push_back(temp);
		else 
			otherman.push_back(temp);
	}
	cout<<cnt<<endl;
	sort(sages.begin(),sages.end(),cmp);
	sort(noblemen.begin(),noblemen.end(),cmp);
	sort(fool_men.begin(),fool_men.end(),cmp);
	sort(otherman.begin(),otherman.end(),cmp);
	print(sages);
	print(noblemen);
	print(fool_men);
	print(otherman);
	return 0;
}