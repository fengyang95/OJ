/*1119. Pre- and Post-order Traversals (30)*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre,in,post;
bool unique=true;

int find_from_pre(int value,int l,int r){
	for(int i=l;i<=r;++i){
		if(pre[i]==value)
			return i;
	}
	return -1;
}

void intraversal(int pre_l,int pre_r,int post_l,int post_r){
	if(pre_l==pre_r){
		in.push_back(pre[pre_r]);
		return;
	}
	if(pre[pre_l]==post[post_r]){
		int x=find_from_pre(post[post_r-1],pre_l+1,pre_r);
		if(x-pre_l>1){
			intraversal(pre_l+1,x-1,post_l,x-pre_l+post_l-2);
			in.push_back(pre[pre_l]);
			intraversal(x,pre_r,x-pre_l+post_l-1,post_r-1);
		}
		else{
			unique=false;
			in.push_back(pre[pre_l]);
			intraversal(x,pre_r,post_l,post_r-1);
		}
	}

}
int main(){
	int n;
	cin>>n;
	pre.resize(n);
	post.resize(n);
	for(int i=0;i<n;++i)
		cin>>pre[i];
	for(int i=0;i<n;++i)
		cin>>post[i];
	intraversal(0,n-1,0,n-1);
	if(unique)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cout<<in[0];
	for(int i=1;i<n;++i)
		cout<<" "<<in[i];
	cout<<endl;
	return 0;
}