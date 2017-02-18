/*1092. To Buy or Not to Buy (20)*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	string src,dst;
	cin>>src>>dst;
	map<char,int> cnt;
	for(int i=0;i<src.size();++i)
		++cnt[src[i]];
	for(int i=0;i<dst.size();++i)
		--cnt[dst[i]];

	bool is_enough=true;
	int more=0;
	int less=0;
	for(int i=0;i<src.size();++i){
		if(cnt[src[i]]<0){
			less-=cnt[src[i]];
			is_enough=false;
			cnt[src[i]]=0;
		}
		else{
			more+=cnt[src[i]];
			cnt[src[i]]=0;
		}
	}
	for(int i=0;i<dst.size();++i){
		if(cnt[dst[i]]<0){
			is_enough=false;
			less-=cnt[dst[i]];
			cnt[dst[i]]=0;
		}
	}

	if(is_enough){
		cout<<"Yes "<<more;
	}
	else{
		cout<<"No "<<less;
	}
	return 0;
}