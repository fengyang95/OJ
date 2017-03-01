/*1032. Sharing (25)*/
/*2.26 11:19--*/
/**/
#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int addr;
	char data;
	int next;
	bool flag=false;
}node[100000];


int main(){
	int first_head,second_head,n;
	cin>>first_head>>second_head>>n;
	int address,next;
	char data;
	for(int i=0;i<n;++i){
		scanf("%d %c %d",&address,&data,&next);
		node[address].addr=address;
		node[address].data=data;
		node[address].next=next;
	}
	for(int i=first_head;i!=-1;i=node[i].next){
		node[i].flag=true;
	}
	for(int i=second_head;i!=-1;i=node[i].next){
		if(node[i].flag==true){
			printf("%05d",i);
			return 0;
		}
	}
	printf("-1");
	return 0; 
} 