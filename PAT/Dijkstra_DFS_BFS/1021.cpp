/*内存超限*/
/*邻接矩阵太浪费空间？*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n;
int max_height=0;
bool visit[10001];
vector<vector<int>> road;
set<int> ret;
vector<int> t;
void dfs(int beg,int height){
	if(height>max_height){
		t.clear();
		t.push_back(beg);
		max_height=height;
	}
	else if(height==max_height){
		t.push_back(beg);
	}
	visit[beg]=true;
	for(int i=1;i<=n;++i){
		if(!visit[i]&&road[beg][i]==1){
			dfs(i,height+1);
		}
	}
}


int main(){
	cin>>n;
	vector<int> temp(n+1,0);
	road.resize(n+1,temp);
	int l,r;
	for(int i=0;i<n-1;++i){
		cin>>l>>r;
		road[l][r]=road[r][l]=1;
	}

	int x;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!visit[i]){
			dfs(i,1);
			++cnt;
			if(i==1){
				for(int j=0;j<t.size();++j){
					ret.insert(t[j]);
				}
				x=t[0];
			}
		}
	}
	if(cnt>1){
		cout<<"Error: "<<cnt<<" components";
	}
	else{
		fill(visit,visit+10001,false);
		dfs(x,1);
		for(int i=0;i<t.size();++i){
			ret.insert(t[i]);
		}
		for(set<int>::iterator it=ret.begin();it!=ret.end();++it){
			cout<<*it<<endl;
		}
	}
	return 0;
}