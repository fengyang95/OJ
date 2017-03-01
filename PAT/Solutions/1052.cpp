/*1052. Linked List Sorting (25)*/
/*注意链表为空的情况*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int addr;
	int data;
	int next;
}node[100000];

bool cmp(Node& lhs,Node& rhs){
	return lhs.data<rhs.data;
}

int main(){
	int n,first_addr;
	cin>>n>>first_addr;
	int addr,data,next;
	for(int i=0;i<n;++i){
		cin>>addr>>data>>next;
		node[addr].addr=addr;
		node[addr].data=data;
		node[addr].next=next;
	}
	vector<Node> v;
	for(int i=first_addr;i!=-1;i=node[i].next){
		v.push_back(node[i]);
	}
	sort(v.begin(),v.end(),cmp);
	if(v.empty()){
		printf("0 -1\n");
		return 0;
	}
	printf("%d %05d\n",v.size(),v[0].addr);
	for(int i=0;i<v.size()-1;++i){
		printf("%05d %d %05d\n",v[i].addr,v[i].data,v[i+1].addr);
	}
	printf("%05d %d -1",v.back().addr,v.back().data);
	return 0;
}
