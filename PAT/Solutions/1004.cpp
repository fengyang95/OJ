/*1004. Counting Leaves (30)*/


/*

#include <iostream>
#include <vector>
using namespace std;

struct node{
	bool valid=false;
	int level=0;
	vector<int> child_id;
};
int max_level=0;
vector<node> nodes(100);
vector<int> cnt;
int main(){
	int total_node,non_leaf_node;
	cin>>total_node>>non_leaf_node;
	int id,k,ch_id;
	nodes[1].level=1;
	for(int i=0;i<non_leaf_node;++i){
		cin>>id>>k;
		nodes[id].valid=true;
		for(int j=0;j<k;++j){
			cin>>ch_id;
			nodes[ch_id].valid=true;
			nodes[id].child_id.push_back(ch_id);
			if(nodes[ch_id].level==0)
				nodes[ch_id].level=nodes[id].level+1;
			if(nodes[ch_id].level>max_level)
				max_level=nodes[ch_id].level;
		}
	}
	cnt.resize(max_level+1,0);
	for(int i=0;i<100;++i){

		if(nodes[i].valid&&nodes[i].child_id.empty())
			++cnt[nodes[i].level];
	}

	cout<<cnt[1];
	for(int i=2;i<=max_level;++i){
		cout<<" "<<cnt[i];
	}
	return 0;
}

//错误分析，没有遍历树，导致计算有误。当输入不是按照一层一层的输入，则计算结果不正确。

*/

//遍历全树的解法
#include <iostream>
#include <vector>
using namespace std;

struct node{
	int h=0;
	vector<int> ch_id;
};
vector<int> cnt;
vector<node> nodes(100);
int max_level=0;
void dfs(int root){
	if(nodes[root].ch_id.empty())return;
	for(int i=0;i<nodes[root].ch_id.size();++i){
		if(nodes[nodes[root].ch_id[i]].h==0){
			nodes[nodes[root].ch_id[i]].h=nodes[root].h+1;
			if(nodes[nodes[root].ch_id[i]].h>max_level)
				max_level=nodes[nodes[root].ch_id[i]].h;
		}
		dfs(nodes[root].ch_id[i]);
	}
}
int main(){
	int n,n_non_leaf;
	int id,k,child_id;
	cin>>n>>n_non_leaf;
	for(int i=0;i<n_non_leaf;++i){
		cin>>id>>k;
		for(int j=0;j<k;++j){
			cin>>child_id;
			nodes[id].ch_id.push_back(child_id);
		}
	}
	nodes[1].h=1;
	dfs(1);
	cnt.resize(max_level+1,0);
	for(int i=0;i<100;++i){
		if(nodes[i].h!=0&&nodes[i].ch_id.empty())
			cnt[nodes[i].h]++;
	}
	cout<<cnt[1];
	for(int i=2;i<=max_level;++i)
		cout<<" "<<cnt[i];
	return 0;

}
