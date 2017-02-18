/*1063. Set Similarity (25)*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

double solve(set<int>& l,set<int>& r){
	double ret;
	int common=0;
	for(set<int>::iterator it=l.begin();it!=l.end();++it){
		if(r.find(*it)!=r.end())
			++common;
	}
	ret=common*1.0/(l.size()-common+r.size());
	return ret;
}


int main(){
	int n;
	cin>>n;
	vector<set<int>> v(n+1);
	int num,key;
	for(int i=1;i<=n;++i){
		cin>>num;
		for(int j=0;j<num;++j){
			cin>>key;
			v[i].insert(key);
		}
	}
	int n_query;
	cin>>n_query;
	vector<double> ret(n_query);
	int index1,index2;
	for(int i=0;i<n_query;++i){
		cin>>index1>>index2;
		ret[i]=solve(v[index1],v[index2]);
	}
	for(int i=0;i<n_query;++i){
		printf("%.1f%%\n",ret[i]*100);
	}
	return 0;
}