/*1006. Sign In and Sign Out (25)*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct t{
	int hour;
	int minute;
	int second;
};

bool operator<(t& lhs,t& rhs){
	if(lhs.hour==rhs.hour){
		if(lhs.minute==rhs.minute){
			return lhs.second<rhs.second;
		}
		else 
			return lhs.minute<rhs.minute;
	}	
	return lhs.hour<rhs.hour;
}

bool operator==(t& lhs,t& rhs){
	return lhs.hour==rhs.hour&&
	lhs.minute==rhs.minute&&
	lhs.second==rhs.second;
}

bool operator>(t& lhs,t& rhs){
	return !(lhs==rhs||lhs<rhs);
}

struct record{
	string id;
	t in,out;
};


int main(){
	int n;
	cin>>n;
	t first,last;
	first.hour=first.minute=first.second=60;
	last.hour=last.minute=last.second=0;
	string first_id,last_id;

	record temp;
	for(int i=0;i<n;++i){
		cin>>temp.id;
		scanf("%d:%d:%d",&temp.in.hour,&temp.in.minute,&temp.in.second);
		scanf("%d:%d:%d",&temp.out.hour,&temp.out.minute,&temp.out.second);
		if(temp.in<first){
			first=temp.in;
			first_id=temp.id;
		}
		if(temp.out>last){
			last=temp.out;
			last_id=temp.id;
		}
	}
	cout<<first_id<<" "<<last_id;
	return 0;
}