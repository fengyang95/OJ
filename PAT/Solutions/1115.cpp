/*1115. Counting Nodes in a BST (30)*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
	int val;
	node* left=nullptr;
	node* right=nullptr;
};

node* build_bst(node* root,int val){
	if(!root){
		root=new node();
		root->val=val;
		return root;
	}
	if(root->val>=val){
		root->left=build_bst(root->left,val);
	}
	else
		root->right=build_bst(root->right,val);
	return root;
}

int max_level;
vector<int> num(1000,0);
void find_level(node* root,int level){
	if(!root)return;
	++num[level];
	if(level>max_level)
		max_level=level;
	find_level(root->left,level+1);
	find_level(root->right,level+1);
}

int main(){
	int n;
	cin>>n;
	node* root=nullptr;
	int val;
	for(int i=0;i<n;++i){
		cin>>val;
		root=build_bst(root,val);
	}
	find_level(root,0);
	printf("%d + %d = %d",num[max_level],num[max_level-1],num[max_level]+num[max_level-1]);
	return 0;
}