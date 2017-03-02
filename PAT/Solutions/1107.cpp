/*1107. Social Clusters (30)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> father,isRoot;

bool cmp(int a,int b){
	return a>b;
}

int findfather(int i){
	while(i!=father[i])
		i=father[i];
	return i;
}

void Union(int a,int b){
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
		father[faA]=faB;
}

int main(){
	int n,cnt=0;
	cin>>n;
	int h[10001]={-1};
	father.resize(n);
	isRoot.resize(n,0);
	for(int i=0;i<n;++i)
		father[i]=i;
	int k,index;
	for(int i=0;i<n;++i){
		scanf("%d:",&k);
		for(int j=0;j<k;++j){
			cin>>index;
			if(h[index]==-1)
				h[index]=i;
			Union(i,findfather(h[index]));
		}
	}

	for(int i=0;i<n;++i){
		++isRoot[findfather(i)];
	}

	for(int i=0;i<n;++i){
		if(isRoot[i]!=0)
			++cnt;
	}
	sort(isRoot.begin(),isRoot.end(),cmp);
	cout<<cnt<<endl;
	if(cnt!=0)
		cout<<isRoot[0];
	for(int i=1;i<cnt;++i)
		cout<<" "<<isRoot[i];
	cout<<endl;
	return 0;
}