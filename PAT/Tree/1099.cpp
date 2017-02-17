#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	vector<int> child;
};

vector<node> v;

void invisit(int root,vector<int>& pre){
	if(v[root].child[0]==-1&&v[root].child[1]==-1){
		pre.push_back(root);
		return;
	}
	if(v[root].child[0]!=-1)
		invisit(v[root].child[0],pre);
	pre.push_back(root);
	if(v[root].child[1]!=-1)
		invisit(v[root].child[1],pre);
}

void levelvisit(int root,vector<int>& level){
	if(root!=-1){
		queue<int> q;
		q.push(root);
		while(!q.empty()){
			int temp=q.front();
			q.pop();
			level.push_back(temp);
			if(v[temp].child[0]!=-1)
				q.push(v[temp].child[0]);
			if(v[temp].child[1]!=-1)
				q.push(v[temp].child[1]);
		}
	}	
}


int main(){
	int n;
	cin>>n;
	v.resize(n);
	int left,right;
	for(int i=0;i<n;++i){
		cin>>left>>right;
		v[i].child.push_back(left);
		v[i].child.push_back(right);
	}
	vector<int> source(n);
	for(int i=0;i<n;++i)
		cin>>source[i];
	sort(source.begin(),source.end());
	vector<int> pre;
	invisit(0,pre);
	vector<int> ret(n);
	for(int i=0;i<pre.size();++i){
		ret[pre[i]]=source[i];
	}

	vector<int> level;
	levelvisit(0,level);
	cout<<ret[level[0]];
	for(int i=1;i<n;++i){
		cout<<" "<<ret[level[i]];
	}
	return 0;
}