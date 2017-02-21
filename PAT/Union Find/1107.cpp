/*1107. Social Clusters (30)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> father,isRoot;
int cmp(int a,int b){
	return a>b;
}

int findFather(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}

void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	}
}

int main(){
	int n,k,t,cnt=0;
	int course[1001]={0};
	scanf("%d",&n);
	father.resize(n+1);
	isRoot.resize(n+1);
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1;i<=n;++i){
		scanf("%d:",&k);
		for(int j=0;j<k;++j){
			scanf("%d",&t);
			if(course[t]==0)
				course[t]=i;
			Union(i,findFather(course[t]));
		}
	}
	for(int i=1;i<=n;++i){
		++isRoot[findFather(i)];
	}
	for(int i=1;i<=n;++i){
		if(isRoot[i]!=0)
			++cnt;
	}
	printf("%d\n",cnt);
	sort(isRoot.begin(),isRoot.end(),cmp);
	printf("%d",isRoot[0]);
	for(int i=1;i<cnt;++i)
		printf(" %d",isRoot[i]);
	return 0;
}