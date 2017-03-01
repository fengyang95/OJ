/*1027. Colors in Mars (20)*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string parse(int src){
	string ret="";
	int low=src%13;
	int high=src/13;
	if(high>9)
		ret+=high-10+'A';
	else 
		ret+=high+'0';
	if(low>9)
		ret+=low-10+'A';
	else
		ret+=low+'0';
	return ret;
}
int main(){
	int r,g,b;
	cin>>r>>g>>b;
	string ans="#";
	ans+=parse(r);
	ans+=parse(g);
	ans+=parse(b);
	cout<<ans;
	return 0;
}