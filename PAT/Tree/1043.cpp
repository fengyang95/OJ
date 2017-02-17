/*1043. Is It a Binary Search Tree (25)*/
/*分析：假设它是二叉搜索树，一开始isMirror为FALSE，根据二叉搜索树的性质将
已知的前序转换为后序，转换过程中，如果发现最后输出的后序数组长度不为n，
那就设isMirror为true，然后清空后序数组，重新再转换一次（根据镜面二叉搜索树的
性质），如果依旧转换后数组大小不等于n，就输出no否则输出yes*/
#include <iostream>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre;
vector<int> post;

void getpost(int root,int tail){
	if(root>tail)return;
	int i=root+1;
	int j=tail;
	if(!isMirror){
		while(i<=tail&&pre[root]>pre[i])++i;
		while(j>root&&pre[root]<=pre[j])--j;
	}
	else{
		while(i<=tail&&pre[root]<=pre[i])++i;
		while(j>root&&pre[root]>pre[j])--j;
	}
	if(i-j!=1)return;
	getpost(root+1,j);
	getpost(i,tail);
	post.push_back(pre[root]);
}
int main(){
	int n;
	cin>>n;
	pre.resize(n);
	for(int i=0;i<n;++i){
		cin>>pre[i];
	}
	isMirror=false;
	getpost(0,n-1);
	if(post.size()!=n){
		isMirror=true;
		post.clear();
		getpost(0,n-1);
	}
	if(post.size()==n){
		cout<<"YES\n";
		cout<<post[0];
		for(int i=1;i<n;++i){
			cout<<" "<<post[i];
		}
	}
	else 
		cout<<"NO";
	return 0;
} 