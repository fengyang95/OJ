/*1086. Tree Traversals Again (25)*/
/*相当于根据中序遍历和前序遍历得到后序遍历*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
vector<int> in,pre,post;

void getpost(int root,int left,int right){
	if(left>right)return;
	int i;
	for(i=left;i<=right&&pre[root]!=in[i];++i);
	getpost(root+1,left,i-1);
	getpost(root+1+i-left,i+1,right);
	post.push_back(pre[root]);
}
int main(){
	int n,data;
	cin>>n;
	string operation;
	stack<int> s;
	for(int i=0;i<2*n;++i){
		cin>>operation;
		if(operation=="Push"){
			cin>>data;
			s.push(data);
			pre.push_back(data);
		}
		else{
			in.push_back(s.top());
			s.pop();
		}
	}
	getpost(0,0,n-1);
	cout<<post[0];
	for(int i=1;i<n;++i)
		cout<<" "<<post[i];
	return 0;
}