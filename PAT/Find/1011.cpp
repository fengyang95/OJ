/*1011. World Cup Betting (20)*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
	double w,t,l;
	int index=0;
	double m=0;
};

void find_m(node& a){
	if(a.w>a.m){
		a.m=a.w;
		a.index=0;
	}
	if(a.t>a.m){
		a.m=a.t;
		a.index=1;
	}
	if(a.l>a.m){
		a.m=a.l;
		a.index=2;
	}
}

int main(){
	vector<node> v(3);
	for(int i=0;i<3;++i){
		cin>>v[i].w>>v[i].t>>v[i].l;
		find_m(v[i]);
	}
	char out[4]={'W','T','L'};
	double ans=(v[0].m*v[1].m*v[2].m*0.65-1)*2;
	printf("%c %c %c %.2f",out[v[0].index],out[v[1].index],out[v[2].index],ans);
	return 0;
}