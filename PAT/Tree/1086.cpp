/*1086. Tree Traversals Again (25)*/
/*2.4 20.00--20.40 all passed*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct node{
	vector<int> child;
	bool isroot = false;
};
vector<node> v;
vector<int> path;
void postvisit(int root){
	if (v[root].child[1] == 0&&v[root].child[0]==0){
		path.push_back(root);
	}
	else{
		if (v[root].child[0]!=0)
			postvisit(v[root].child[0]);
		if (v[root].child[1] != 0)
			postvisit(v[root].child[1]);
		path.push_back(root);
	}
}

int main(){
	int n;
	cin >> n;
	getchar();
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i){
		v[i].child.resize(2);
	}
	stack<int> s;
	string p;
	int prefix;
	bool is_leftchild = true;
	for (int i = 0; i < 2 * n; ++i){
		getline(cin, p);
		if (p == "Pop"){
			prefix = s.top();
			s.pop();
			is_leftchild = false;
		}
		else{
			int sum = 0;
			for (int j = 5; j < p.size(); ++j){
				sum = sum * 10 + p[j] - '0';
			}
			if (!s.empty() && is_leftchild){
				v[s.top()].child[0] =sum;
			}
			else if (!is_leftchild){
				v[prefix].child[1] = sum;
			}
			else{
				v[sum].isroot = true;
			}
			is_leftchild = true;
			s.push(sum);
		}
	}

	int root;
	for (int i = 1; i <= n; ++i){
		if (v[i].isroot){
			root = i;
			break;
		}
	}

	postvisit(root);
	cout << path[0];
	for (int i = 1; i < path.size(); ++i){
		cout << " " << path[i];
	}
	return 0;
}