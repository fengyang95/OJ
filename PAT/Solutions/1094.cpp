/*1094. The Largest Generation (25)*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
	int deep=1;
	vector<int> child;
};

vector<node> v(100);
int deep[100]={0};
void bfs(int root){
	if(v[root].child.empty())
		return;
	for(int i=0;i<v[root].child.size();++i){
		v[v[root].child[i]].deep=v[root].deep+1;
		bfs(v[root].child[i]);
	}
}

int main(){
	int n,num_havechild;
	cin>>n>>num_havechild;
	int child_num;
	int index;
	int child_index;
	for(int i=0;i<num_havechild;++i){
		scanf("%2d %d",&index,&child_num);
		for(int j=0;j<child_num;++j){
			scanf("%2d",&child_index);
			v[index].child.push_back(child_index);
		}
	}

	bfs(1);
	int maxdeep_num=0;
	int generation;
	for(int i=1;i<=n;++i){//此处是<=n，不能忘记计算最后一个节点
		++deep[v[i].deep];
		if(deep[v[i].deep]>maxdeep_num){
			maxdeep_num=deep[v[i].deep];
			generation=v[i].deep;
		}
	}
	cout<<maxdeep_num<<" "<<generation;
	return 0;
}
