/*1043. Is It a Binary Search Tree (25)*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> post,pre;
bool is_mirror=false;

void getpost(int start,int end){
	if(start>end)return;
	int i,j;
	if(!is_mirror){
		for(i=start+1;i<=end&&pre[i]<pre[start];++i);
		for(j=end;j>start&&pre[j]>=pre[start];--j);
	}
	else{
		for(i=start+1;i<=end&&pre[i]>=pre[start];++i);
		for(j=end;j>start&&pre[j]<pre[start];--j);
	}
	if((i-j)!=1)return;
	getpost(start+1,j);
	getpost(i,end);
	post.push_back(pre[start]);
}

int main(){
	cin>>n;
	pre.resize(n);
	for(int i=0;i<n;++i)
		cin>>pre[i];
	getpost(0,n-1);
	if(post.size()!=n){
		post.clear();
		is_mirror=true;
		getpost(0,n-1);
	}
	if(post.size()==n){
		cout<<"YES\n";
		cout<<post[0];
		for(int i=1;i<n;++i)
			cout<<" "<<post[i];
	}
	else{
		cout<<"NO";
	}
	return 0;
}