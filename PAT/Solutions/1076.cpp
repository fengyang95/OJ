/*1076. Forwards on Weibo (30)*/
/*bfs*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,max_layer;
struct node{
	vector<int> child;
	int layer;
};
vector<node> v;

int bfs(int root){
	for(int j=1;j<=n;++j)
		v[j].layer=0;
	bool inq[1010] = {false};
    queue<int> q;
    q.push(root);
    inq[root] = true;
    int cnt = 0;
    while(!q.empty()) {
        int  top = q.front();
        q.pop();
        for(int i = 0; i < v[top].child.size(); i++) {
            int nextid = v[top].child[i];
            if(inq[nextid] == false &&v[top].layer<max_layer) {
                v[nextid].layer= v[top].layer + 1;
                q.push(nextid);
                inq[nextid] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
	cin>>n>>max_layer;
	v.resize(n+1);
	int k,id;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=0;j<k;++j){
			cin>>id;
			v[id].child.push_back(i);
		}
	}
	int n_query;
	cin>>n_query;
	vector<int> query(n_query);
	for(int i=0;i<n_query;++i){
		cin>>query[i];
	}

	for(int i=0;i<n_query;++i){
		cout<<bfs(query[i])<<endl;
	}
	return 0;
}
