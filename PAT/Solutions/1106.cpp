/*1106. Lowest Price in Supply Chain (25)*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int cnt;
int min_deep=INT_MAX;
struct node{
	vector<int> child;
};
vector<node> v;
void dfs(int root,int deep){
	if(v[root].child.empty()){
		if(deep<min_deep){
			cnt=1;
			min_deep=deep;
		}
		else if(deep==min_deep){
			++cnt;
		}
		return;
	}
	for(int i=0;i<v[root].child.size();++i){
			dfs(v[root].child[i],deep+1);
	}
}

int main(){
	int n;
	double price,rate;
	cin>>n>>price>>rate;
	v.resize(n);
	int num_child;
	int child_index;
	for(int i=0;i<n;++i){
		cin>>num_child;
		for(int j=0;j<num_child;++j){
			cin>>child_index;
			v[i].child.push_back(child_index);
		}
	}

	dfs(0,1);
	double ret;
	ret=price*pow(1+rate*0.01,min_deep-1);
	printf("%.4f %d",ret,cnt);
	return 0;
}