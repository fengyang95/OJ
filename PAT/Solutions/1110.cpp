/*1110. Complete Binary Tree (25)*/
/*做的时候居然把NO的O写成小写，很久没有看出来。。。。。*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node{
	int left=-1;
	int right=-1;
};
vector<Node> node;
vector<int> level;

void getlevel(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		level.push_back(temp);
		if(node[temp].left==-1)break;
		q.push(node[temp].left);
		if(node[temp].right==-1)break;
		q.push(node[temp].right);
	}
	while(!q.empty()){
		level.push_back(q.front());
		q.pop();
	}
}

int main(){
	int n;
	cin>>n;
	node.resize(n);
	string l,r;
	vector<int> flag(n,false);
	for(int i=0;i<n;++i){
		cin>>l>>r;
		if(l!="-"){
			node[i].left=stoi(l);
			flag[stoi(l)]=true;
		}
		if(r!="-"){
			node[i].right=stoi(r);
			flag[stoi(r)]=true;
		}
	}
	int root;
	for(int i=0;i<n;++i){
		if(flag[i]==false){
			root=i;
			break;
		}
	}
	getlevel(root);
	if(level.size()==n)
		cout<<"YES "<<level.back();
	else
		cout<<"NO "<<root;
	return 0;
}