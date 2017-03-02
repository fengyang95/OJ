/*1114. Family Property (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int id;
	int num_people=0;
	double aver_set=0.0;
	double aver_area=0.0;
}node[10000],ans[10000];

vector<int> father(10000),visit(10000,false);

int findfather(int id){
	int a=id;
	while(id!=father[id])
		id=father[id];
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=id;
	}
	return id;
}

void Union(int a,int b){
	int fa_a=findfather(a);
	int fa_b=findfather(b);
	if(fa_a>fa_b)
		father[fa_a]=fa_b;
	else if(fa_b>fa_a)
		father[fa_b]=fa_a;
}

bool cmp(Node& lhs,Node& rhs){
	if(lhs.aver_area==rhs.aver_area)
		return lhs.id<rhs.id;
	return lhs.aver_area>rhs.aver_area;
}

int main(){
	int n;
	for(int i=0;i<10000;++i)
		father[i]=i;
	cin>>n;
	int id,fa,mo,k,ch_id;
	for(int i=0;i<n;++i){
		cin>>id>>fa>>mo>>k;
		visit[id]=true;
		if(fa!=-1){
			visit[fa]=true;
			Union(id,fa);
		}
		if(mo!=-1){
			visit[mo]=true;
			Union(id,mo);
		}
		for(int j=0;j<k;++j){
			cin>>ch_id;
			visit[ch_id]=true;
			Union(id,ch_id);
		}
		cin>>node[id].aver_set>>node[id].aver_area;
	}

	for(int i=0;i<10000;++i){
		if(visit[i]){
			int root=findfather(i);
			ans[root].id=root;
			ans[root].num_people++;
			ans[root].aver_set+=node[i].aver_set;
			ans[root].aver_area+=node[i].aver_area;
		}
	}

	vector<Node> ret;
	for(int i=0;i<10000;++i){
		if(ans[i].num_people!=0){
			ret.push_back(ans[i]);
		}
	}
	for(int i=0;i<ret.size();++i){
		ret[i].aver_set/=(ret[i].num_people*1.0);
		ret[i].aver_area/=(ret[i].num_people*1.0);
	}
	sort(ret.begin(),ret.end(),cmp);
	cout<<ret.size()<<endl;
	for(int i=0;i<ret.size();++i){
		printf("%04d %d %.3f %.3f\n",ret[i].id,ret[i].num_people,ret[i].aver_set,ret[i].aver_area);
	}
	return 0;
}