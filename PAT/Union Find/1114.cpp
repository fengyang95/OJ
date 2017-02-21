/*1114. Family Property (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data{
	int id,fid,mid,child_num,area;
	int cid[6];
}data[1005];


struct node{
	int id,people;
	double aver_set,aver_area;
	bool flag=false;
}ans[10000];

int father[10000];
bool visit[10000];
 
int find_father(int x){
	while(x!=father[x])
		x=father[x];
	return x;
}

void Union(int a,int b){
	int faA=find_father(a);
	int faB=find_father(b);
	if(faA>faB){
		father[faA]=faB;
	}
	else if(faB>faA){
		father[faB]=faA;
	} 
}

int cmp(node& a,node& b){
	if(a.aver_area==b.aver_area){
		return a.id<b.id;
	}
	return a.aver_area>b.aver_area;
}

int main(){
	int n,k,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<10000;++i)
		father[i]=i;
	for(int i=0;i<n;++i){
		scanf("%d %d %d %d",&data[i].id,&data[i].fid,&data[i].mid,&k);
		visit[data[i].id]=true;
		if(data[i].fid!=-1){
			visit[data[i].fid]=true;
			Union(data[i].fid,data[i].id);
		}
		if(data[i].mid!=-1){
			visit[data[i].mid]=true;
			Union(data[i].mid,data[i].id);
		}
		for(int j=0;j<k;++j){
			scanf("%d",&data[i].cid[j]);
			visit[data[i].cid[j]]=true;
			Union(data[i].id,data[i].cid[j]);
		}
		scanf("%d %d",&data[i].child_num,&data[i].area);
	}

	for(int i=0;i<n;++i){
		int id=find_father(data[i].id);
		ans[id].id=id;
		ans[id].aver_set+=data[i].child_num;
		ans[id].aver_area+=data[i].area;
		ans[id].flag=true;
	}
	for(int i=0;i<10000;++i){
		if(visit[i])
			++ans[find_father(i)].people;
		if(ans[i].flag)
			++cnt;
	}
	for(int i=0;i<10000;++i){
		if(ans[i].flag){
			ans[i].aver_set/=(1.0*ans[i].people);
			ans[i].aver_area/=(1.0*ans[i].people);
		}
	}
	sort(ans,ans+10000,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;++i){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].aver_set,ans[i].aver_area);
	}
	return 0;
}