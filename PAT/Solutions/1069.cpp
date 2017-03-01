/*1069. The Black Hole of Numbers (20)*/
/*2.15 13:25--13:48  20points*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

void solve(vector<int>& src){
	sort(src.begin(),src.end(),cmp);
	int left=src[0]*1000+src[1]*100+src[2]*10+src[3];
	if(src[0]==src[1]&&src[0]==src[2]&&src[0]==src[3]){
		printf("%04d - %04d = 0000",left,left);
		return;
	}

	int right=src[0]+src[1]*10+src[2]*100+src[3]*1000;
	int ret=left-right;
	//getchar();
	printf("%04d - %04d = %04d\n",left,right,ret);
	if(ret==6174)return;
	else{
		src[0]=(ret/1000)%10;
		src[1]=(ret/100)%10;
		src[2]=(ret/10)%10;
		src[3]=(ret%10);
		solve(src);
	}
}
int main(){
	int n;
	vector<int> src(4);
	scanf("%4d",&n);
	src[3]=n%10;
	src[2]=(n/10)%10;
	src[1]=(n/100)%10;
	src[0]=(n/1000)%10;
	solve(src);
	return 0;
}
