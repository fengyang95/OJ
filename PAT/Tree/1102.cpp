#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct node{
	vector<int> child;
};

vector<node> v;
int parse(string& src){
	int ret=0;
	for(int i=0;i<src.size();++i){
		ret=ret*10+src[i]-'0';
	}
	return ret;
}

void levelvisit(int root,vector<int>& level){
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

void invisit(int root,vector<int>& in){
	if(v[root].child[0]==-1&&v[root].child[1]==-1){
		in.push_back(root);
		return;
	}
	if(v[root].child[0]!=-1)
		invisit(v[root].child[0],in);
	in.push_back(root);
	if(v[root].child[1]!=-1)
		invisit(v[root].child[1],in);
}

void print(vector<int>& src){
	if(!src.empty()){
		cout<<src[0];
		for(int i=1;i<src.size();++i)
			cout<<" "<<src[i];
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	v.resize(n);
	vector<bool> used(n,false);
	string left,right;
	for(int i=0;i<n;++i){

		cin>>right>>left;
		if(left!="-"){
			v[i].child.push_back(parse(left));
			used[parse(left)]=true;
		}
		else{
			v[i].child.push_back(-1);
		}
		if(right!="-"){
			v[i].child.push_back(parse(right));
			used[parse(right)]=true;
		}
		else{
			v[i].child.push_back(-1);
		}
	}
	int root=0;
	for(int i=0;i<n;++i){
		if(!used[i]){
			root=i;
			break;
		}
	}
	vector<int> level;
	vector<int> in;
	levelvisit(root,level);
	print(level);
	invisit(root,in);
	print(in);
	return 0;
}