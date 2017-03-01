/*1011. World Cup Betting (20)*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<char> out{'W','T','L'};
	vector<int> ans(3);
	double ret=1.0;
	double w,t,l;
	for(int i=0;i<3;++i){
		cin>>w>>t>>l;
		if(w>t&&w>l){
			ans[i]=0;
			ret*=w;
		}
		else if(t>l){
			ans[i]=1;
			ret*=t;
		}
		else{
			ans[i]=2;
			ret*=l;
		}
	}
	ret=(ret*0.65-1)*2.0;
	printf("%c %c %c %.2f",out[ans[0]],out[ans[1]],out[ans[2]],ret);
	return 0;
}