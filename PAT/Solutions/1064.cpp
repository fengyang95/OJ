/*1064. Complete Binary Search Tree (30)*/
/*题目大意：给一串构成树的序列，已知该树是完全二叉搜索树，
求它的层序遍历的序列
分析：总得概括来说，已知中序，可求root下标，可以求出层序。
1. 因为二叉搜索树的中序满足：是一组序列的从小到大排列，所以
只需排序所给序列即可得到中序
2. 因为根据完全二叉树的结点数，可以求出它的根结点在中序
中对应的下标
3. 如此，已知了中序，又可以根据结点数求出根结点的下标，
就可以递归求出左右子树的根结点的下标
4. i结点的左孩子为2 * i + 1，右孩子2 * i + 2，
就可以根据结点下标和中序数组赋值level数组
5. 最后输出所有结点的层序数组level*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
vector<int> in,level;
void getlevel(int start,int end,int index){
	if(start>end)return;
	int num=end-start+1;
	int l=log(num+1)/log(2);
	int leave=num-(pow(2,l)-1);
	int root=start+pow(2,l-1)-1+min((int)pow(2,l-1),leave);
	level[index]=in[root];
	getlevel(start,root-1,2*index+1);
	getlevel(root+1,end,2*index+2);
}

int main(){
	int n;
	cin>>n;
	in.resize(n);
	level.resize(n);
	for(int i=0;i<n;++i)
		cin>>in[i];
	sort(in.begin(),in.end());
	getlevel(0,n-1,0);
	cout<<level[0];
	for(int i=1;i<n;++i)
		cout<<" "<<level[i];
	return 0;
}