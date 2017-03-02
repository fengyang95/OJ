/*1097. Deduplication on a Linked List (25)*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int addr;
	int key;
	int next;
}node[100000];
bool flag[10000]={false};
int main(){
	int first_addr,n;
	cin>>first_addr>>n;
	int addr,key,next;
	for(int i=0;i<n;++i){
		cin>>addr>>key>>next;
		node[addr].addr=addr;
		node[addr].key=key;
		node[addr].next=next;
	}
	vector<Node> remained,removed;
	for(int i=first_addr;i!=-1;i=node[i].next){
		if(flag[abs(node[i].key)])
			removed.push_back(node[i]);
		else{
			remained.push_back(node[i]);
			flag[abs(node[i].key)]=true;
		}
	}
	if(!remained.empty()){
		for(int i=0;i<remained.size()-1;++i)
			printf("%05d %d %05d\n",remained[i].addr,remained[i].key,remained[i+1].addr);
		printf("%05d %d -1\n",remained.back().addr,remained.back().key);
	}
	if(!removed.empty()){
		for(int i=0;i<removed.size()-1;++i)
			printf("%05d %d %05d\n",removed[i].addr,removed[i].key,removed[i+1].addr);
		printf("%05d %d -1\n",removed.back().addr,removed.back().key);
	}
	
	return 0;
}