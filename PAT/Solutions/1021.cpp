/*1021. Deepest Root (25)*/
/*此处用邻接表的形式存储*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
vector<bool> visit;
vector<vector<int>> v;
vector<int> temp;
int max_height=0;

void dfs(int root,int height){
	if(height>max_height){
		max_height=height;
		temp.clear();
		temp.push_back(root);
	}
	else if(height==max_height){
		temp.push_back(root);
	}
	visit[root]=true;
	for(int i=0;i<v[root].size();++i){
		if(!visit[v[root][i]])
			dfs(v[root][i],height+1);
	}
}

int main(){

	cin>>n;
	v.resize(n+1);
	set<int> ret;
	int a,b,s1;
	for(int i=0;i<n-1;++i){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visit.resize(n+1,false);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!visit[i]){
			dfs(i,1);
			++cnt;
			if(i==1){
				for(int j=0;j<temp.size();++j){
					ret.insert(temp[j]);
				}
				s1=temp[0];
			}
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
	}
	else{
		temp.clear();
		fill(visit.begin(),visit.end(),false);
		dfs(s1,1);
		for(int i=0;i<temp.size();++i)
			ret.insert(temp[i]);
		for(set<int>::iterator it=ret.begin();it!=ret.end();++it)
			printf("%d\n",*it);
	}
	return 0;
}