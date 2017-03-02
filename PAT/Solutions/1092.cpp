/*1092. To Buy or Not to Buy (20)*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int cnt[256]={0};
	char src[1000];
	char target[1000];
	scanf("%s%s",src,target);

	for(int i=0;i<strlen(src);++i)
		cnt[int(src[i])]++;
	for(int i=0;i<strlen(target);++i)
		cnt[int(target[i])]--;
	bool yes=true;
	int ans_less=0;
	int ans_more=0;
	for(int i=0;i<256;++i){
		if(cnt[i]<0){
			yes=false;
		}
		if(cnt[i]>0)
			ans_more+=cnt[i];
		else
			ans_less-=cnt[i];
	}
	if(yes){
		cout<<"Yes "<<ans_more;
	}
	else
		cout<<"No "<<ans_less;
	return 0;
}