/*1110. Complete Binary Tree (25)*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct node{
	vector<int> child;
};

int parse(string& s){
	int ret=0;
	if(s=="-")
		ret=-1;
	else{
		for(int i=0;i<s.size();++i)
			ret=ret*10+s[i]-'0';
	}
	return ret;
}

vector<node> v;
vector<bool> visit;

void levelvisit(int root,vector<int>& level){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		level.push_back(temp);
		if(v[temp].child[0]==-1)break;
		else{
			q.push(v[temp].child[0]);
			if(v[temp].child[1]==-1)
				break;
			else{
				q.push(v[temp].child[1]);
			}
		}
	}
	while(!q.empty()){
		level.push_back(q.front());
		q.pop();
	}
}

int main(){
	int n;
	cin>>n;
	v.resize(n);
	visit.resize(n);
	string left,right;
	for(int i=0;i<n;++i){
		cin>>left>>right;
		int l=parse(left);
		int r=parse(right);
		v[i].child.push_back(l);
		v[i].child.push_back(r);
		if(l!=-1)visit[l]=true;
		if(r!=-1)visit[r]=true;
	}
	int root;
	for(int i=0;i<n;++i){
		if(!visit[i]){
			root=i;
			break;
		}
	}

	vector<int> level;
	levelvisit(root,level);
	if(level.size()==n){
		cout<<"YES "<<level.back();
	}
	else{
		cout<<"NO "<<root;
	}
	return 0;
}