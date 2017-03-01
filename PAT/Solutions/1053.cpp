/*1053. Path of Equal Weight (30)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,n_non_leaf,total;
struct Node{
	vector<int> child;
}node[100];
vector<int> path;
vector<vector<int>> paths;
int value[100];
 bool cmp(int a,int b){
 	return value[a]>value[b];
 }


void dfs(int root,int now_value){
	now_value += value[root];  
 	path.push_back(value[root]);  
 	if ( now_value <total){  
  		for (int i = 0; i <node[root].child.size(); i++)
   			dfs(node[root].child[i],now_value);  
  		if (!path.empty())  
   			path.pop_back();  
  		return;  
 	}  
 	else if (now_value>total){  
  		path.pop_back();  
  		return;  
 	}
 	else if (now_value == total){  
  		if (node[root].child.empty()){  
   			paths.push_back(path);  
  		}  
   		path.pop_back();  
  		return;   
 	}  
}

int main(){
	cin>>n>>n_non_leaf>>total;
	for(int i=0;i<n;++i)
		cin>>value[i];
	int id,k,child_id;
	for(int i=0;i<n_non_leaf;++i){
		cin>>id>>k;
		for(int j=0;j<k;++j){
			cin>>child_id;
			node[id].child.push_back(child_id);
		}
		sort(node[id].child.begin(),node[id].child.end(),cmp);
	}

	dfs(0,0);
	for(int i=0;i<paths.size();++i){
		cout<<paths[i][0];
		for(int j=1;j<paths[i].size();++j)
			cout<<" "<<paths[i][j];
		cout<<endl;
	}
	return 0;
}