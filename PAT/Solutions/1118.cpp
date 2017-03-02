/*1118. Birds in Forest (25)*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int num_bird=INT_MIN;
vector<int> father,isRoot;


int findfather(int id){
	int a=id;
	while(id!=father[id]){
		id=father[id];
	}
	while(a!=father[a]){
		int z = a;
        father[a] = id;
        a = father[z];
	}
	return id;
}

void Union(int a,int b){
	int fa_a=findfather(a);
	int fa_b=findfather(b);
	if(fa_a!=fa_b)
		father[fa_a]=fa_b;
}

int main(){
	int n,n_picture=0;
	cin>>n;
	father.resize(n+1);
	isRoot.resize(n+1,0);
	int birds[10001]={0};
	for(int i=1;i<=n;++i)
		father[i]=i;
	int k,index;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=0;j<k;++j){
			cin>>index;
			if(index>num_bird)
				num_bird=index;
			if(birds[index]==0)
				birds[index]=i;
			Union(i,findfather(birds[index]));
		}
	}
	for(int i=1;i<=n;++i){
		++isRoot[findfather(i)];
	}
	for(int i=1;i<=n;++i){
		if(isRoot[i]!=0)
			++n_picture;
	}
	cout<<n_picture<<" "<<num_bird<<endl;
	int n_query;
	cin>>n_query;
	int lhs,rhs;
	for(int i=0;i<n_query;++i){
		cin>>lhs>>rhs;
		if(findfather(birds[lhs])==findfather(birds[rhs]))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}