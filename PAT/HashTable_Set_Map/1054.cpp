/*1054. The Dominant Color (20)*/
/*用scanf输入才没有超时*/
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int num=m*n;
	map<int,int> cnt;
	int data;
	int ret;
	int maxn=0;
	for(int i=0;i<num;++i){
		scanf("%d",&data);
		++cnt[data];
		if(cnt[data]>maxn){
			maxn=cnt[data];
			ret=data;
		}
	}
	cout<<ret;
	return 0;
}