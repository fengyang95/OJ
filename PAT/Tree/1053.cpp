/*1053. Path of Equal Weight (30)*/
/*有毒啊啊啊*/
/*搞半天是输入问题 生无可恋。。。*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct node{
	vector<int> child;
	int weight;
};

vector<node> v;
int n,n_nonleaf,total_weight;
vector<int> path;
vector<vector<int>> paths;

void DFS(int root, int sum){  
 	sum += v[root].weight;  
 	path.push_back(v[root].weight);  
 	if (sum <total_weight){  
  		for (int i = 0; i <v[root].child.size(); i++)
   			DFS(v[root].child[i],sum);  
  		if (!path.empty())  
   			path.pop_back();  
  		return;  
 	}  
 	else if (sum >total_weight){  
  		path.pop_back();  
  		return;  
 	}
 	else if (sum == total_weight){  
  		if (v[root].child.empty()){  
   			paths.push_back(path);  
   			path.pop_back();  
   			return;  
  		}  
  		else{  
   			path.pop_back();  
  			return;  
  		}  
 	}  
}  


bool cmp(int a,int b){
	return v[a].weight>v[b].weight;
}

int main(){
	cin>>n>>n_nonleaf>>total_weight;
	v.resize(n);
	for(int i=0;i<n;++i)
		cin>>v[i].weight;
	int id,k;
	for(int i=0;i<n_nonleaf;++i){
		scanf("%2d %d",&id,&k);
		v[id].child.resize(k);
		for(int j=0;j<k;++j){
			scanf("%2d",&v[id].child[j]);
		}
		sort(v[id].child.begin(), v[id].child.end(), cmp);//将id写成i 。。。。
	}

	DFS(0,0);
	for(int i=0;i<paths.size();++i){
		cout<<paths[i][0];
		for(int j=1;j<paths[i].size();++j)
			cout<<" "<<paths[i][j];
		cout<<endl;
	}
	//getchar();
	return 0;
}
