/*1079. Total Sales of Supply Chain (25)*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
double p,r;
struct node{
	vector<int> child;
	int num=0;
};
vector<node> v;
double ret=0;
void dfs(int root,int height){
	if(v[root].child.empty()){
		ret+=p*pow(1+0.01*r,height)*v[root].num;
		return;
	}
	for(int i=0;i<v[root].child.size();++i){
		dfs(v[root].child[i],height+1);
	}
}

int main(){
	cin>>n>>p>>r;
	v.resize(n);
	int n_child,child_id;
	for(int i=0;i<n;++i){
		cin>>n_child;
		if(n_child==0)
			cin>>v[i].num;
		for(int j=0;j<n_child;++j){
			cin>>child_id;
			v[i].child.push_back(child_id);
		}
	}
	dfs(0,0);
	printf("%.1f",ret);
	return 0;
}