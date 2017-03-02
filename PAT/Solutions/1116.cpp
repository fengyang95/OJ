#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct person{
	int rank;
	int ID;
	string award;
	bool is_checked=false;
};

struct out{
	int id;
	string infor;
};
bool isprime(int src){
	if(src==1)return false;
	else if(src==2||src==3)return true;
	for(int i=2;i<sqrt(src)+1;++i){
		if(src%i==0)return false;
	}
	return true;
}


int main(){
	int n;
	cin>>n;
	vector<person> s(n);
	for(int i=0;i<n;++i){
		scanf("%4d",&s[i].ID);
		s[i].rank=i+1;
		if(i==0)s[i].award="Mystery Award";
		else if(isprime(i+1)){
			s[i].award="Minion";
		}
		else{
			s[i].award="Chocolate";
		}
	}
	int num_query;
	cin>>num_query;
	vector<out> ret(num_query);
	for(int i=0;i<num_query;++i){
		cin>>ret[i].id;
		for(int j=0;j<n;++j){
			if(s[j].ID==ret[i].id){
				if(!s[j].is_checked){
					ret[i].infor=s[j].award;
					s[j].is_checked=true;
				}
				else{
					ret[i].infor="Checked";
				}
				break;
			}
		}
		if(ret[i].infor.empty()){
			ret[i].infor="Are you kidding?";
		}
	}

	for(int i=0;i<num_query;++i){
		printf("%04d: ",ret[i].id);
		cout<<ret[i].infor<<endl;
	}
	return 0;
}
