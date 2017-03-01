/*1006. Sign In and Sign Out (25)*/


#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct T{
	int hour; 
	int minute;
	int second;
};
struct node{
	string id;
	T in;
	T out;
};
bool lessthan(T& lhs,T& rhs){
	if(lhs.hour==rhs.hour){
		if(lhs.minute==rhs.minute){
			return lhs.second<rhs.second;
		}
		return lhs.minute<rhs.minute;
	}
	return lhs.hour<rhs.hour;
}

int main(){
	int n;
	cin>>n;
	node records;
	T earliest,latest;
	string early,late;
	earliest.hour=earliest.minute=earliest.second=INT_MAX;
	latest.hour=latest.minute=latest.second=0;
	for(int i=0;i<n;++i){
		cin>>records.id;
		scanf("%2d:%2d:%2d",&records.in.hour,&records.in.minute,&records.in.second);
		scanf("%2d:%2d:%2d",&records.out.hour,&records.out.minute,&records.out.second);
		if(lessthan(records.in,earliest)){
			earliest=records.in;
			early=records.id;
		}
		if(lessthan(latest,records.out)){
			latest=records.out;
			late=records.id;
		}
	}
	cout<<early<<" "<<late;
	return 0;
}