/*1102. Invert a Binary Tree (25)*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node{
	int left=-1;
	int right=-1;
};

vector<Node> node;
vector<int> level,in;
void getlevel(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		level.push_back(temp);
		if(node[temp].left!=-1)
			q.push(node[temp].left);
		if(node[temp].right!=-1)
			q.push(node[temp].right);
	}
}

void getin(int root){
	if(root==-1)return;
	if(node[root].left!=-1)
		getin(node[root].left);
	in.push_back(root);
	if(node[root].right!=-1)
		getin(node[root].right);
}

int main(){
	int n;
	cin>>n;
	string l,r;
	node.resize(n);
	vector<bool> flag(n,false);
	for(int i=0;i<n;++i){
		cin>>r>>l;
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
		if(!flag[i]){
			root=i;
			break;
		}
	}

	getlevel(root);
	getin(root);
	cout<<level[0];
	for(int i=1;i<n;++i)
		cout<<" "<<level[i];
	cout<<endl;
	cout<<in[0];
	for(int i=1;i<n;++i)
		cout<<" "<<in[i];
	cout<<endl;
	return 0;
}
