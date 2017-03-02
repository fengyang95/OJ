/*1121. Damn Single (25)*/
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
	int n_couple,n_query;
	cin>>n_couple;
	map<int,int> cp;
	set<int> s,single;
	int lhs,rhs,query;
	for(int i=0;i<n_couple;++i){
		cin>>lhs>>rhs;
		cp[lhs]=rhs;
		cp[rhs]=lhs;
	}
	cin>>n_query;
	for(int i=0;i<n_query;++i){
		cin>>query;
		s.insert(query);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		if(s.find(cp[*it])==s.end())
			single.insert(*it);
	}
	cout<<single.size()<<endl;
	for(set<int>::iterator it=single.begin();it!=single.end();++it){
		if(it!=single.begin()){
			printf(" %05d",*it);
		}
		else{
			printf("%05d",*it);
		}
	}
	return 0;
}