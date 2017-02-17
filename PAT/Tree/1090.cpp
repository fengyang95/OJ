/*1090. Highest Price in Supply Chain (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
	vector<int> child;
};
int cnt=0;
int max_deep=0;
vector<node> v;

void dfs(int begin,int deep){
	if(v[begin].child.empty()){
		if(deep==max_deep){
			cnt++;
		}
		else if(deep>max_deep){
			cnt=1;
			max_deep=deep;
		}
		return;
	}
	for(int i=0;i<v[begin].child.size();++i){
		dfs(v[begin].child[i],deep+1);
	}
}



int main(){
	int n;
	double price,rate;
	cin>>n>>price>>rate;
	int parent_index;
	v.resize(n);
	int root_index;
	for(int i=0;i<n;++i){
		cin>>parent_index;
		if (parent_index == -1)
			root_index = i;
		else
			v[parent_index].child.push_back(i);
		
	}
	dfs(root_index,1);
	double ret=price*pow((1+rate*0.01),max_deep-1);
	printf("%.2f %d",ret,cnt);
	return 0;
}