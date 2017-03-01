/*1020. Tree Traversals (25)*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> post,in,level;
void getlevel(int root,int begin,int end,int index){
	if(begin>end)return;
	level[index]=post[root];
	int i;
	for(i=begin;i<end&&in[i]!=post[root];++i);
	getlevel(root-1-end+i,begin,i-1,2*index+1);
	getlevel(root-1,i+1,end,2*index+2);
}
int main(){
	int n;
	cin>>n;
	post.resize(n);
	in.resize(n);
	level.resize(10000,-1);
	for(int i=0;i<n;++i)
		cin>>post[i];
	for(int i=0;i<n;++i)
		cin>>in[i];
	getlevel(n-1,0,n-1,0);
	bool is_first=true;
	for(int i=0;i<10000;++i){
		if(level[i]!=-1){
			if(is_first){
				cout<<level[i];
				is_first=false;
			}
			else{
				cout<<" "<<level[i];
			}
		}
	}
	return 0;
}