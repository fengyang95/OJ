/*1118. Birds in Forest (25)*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> father,isRoot;
int birds[100010];
int find_father(int id){
	while(id!=father[id]){
		id=father[id];
	}
	return id;
}

void Union(int a,int b){
	int faA=find_father(a);
	int faB=find_father(b);
	if(faA!=faB)
		father[faA]=faB;
}

int main(){
	int n,k,id,cnt=0,num_bird=0;
	scanf("%d",&n);
	father.resize(n+1);
	for(int i=1;i<=n;++i)
		father[i]=i;
	isRoot.resize(n+1,0);
	int birds[10000]={0};
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%d",&id);
			if(id>num_bird)
				num_bird=id;
			if(birds[id]==0)
				birds[id]=i;
			int fid=find_father(birds[id]);
			Union(i,fid);
		}
	}

	for(int i=1;i<=n;++i){
		++isRoot[find_father(birds[i])];
	}
	for(int i=1;i<=n;++i){
		if(isRoot[i]!=0)++cnt;
	}

	int n_query;
	printf("%d %d\n",cnt,num_bird);
	scanf("%d", &n_query);
    int ida, idb;
    for(int i = 0; i < n_query; i++) {
        scanf("%d%d", &ida, &idb);
        if(find_father(birds[ida]) == find_father(birds[idb])) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}