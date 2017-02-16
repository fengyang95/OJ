/*1025. PAT Ranking (25)*/
/*比较常规简单*/
/*注意成绩相同时按照id非降序输出*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct node{
	string id;
	int grade;
	int final_rank=1;
	int local_num;
	int local_rank=1;
};

bool cmp(node& l,node& r){
	if(l.grade==r.grade){
		return l.id<r.id;
	}
	return l.grade>r.grade;
} 
int main(){
	int n;
	cin>>n;
	int k;
	vector<node> ret;
	for(int i=1;i<=n;++i){
		cin>>k;
		vector<node> local(k);
		for(int j=0;j<k;++j){	
			cin>>local[j].id>>local[j].grade;
			local[j].local_num=i;
		}
		sort(local.begin(),local.end(),cmp);
		ret.push_back(local[0]);
		for(int j=1;j<k;++j){
			local[j].local_rank=j+1;
			if(local[j].grade==local[j-1].grade)
				local[j].local_rank=local[j-1].local_rank;
			ret.push_back(local[j]);
		}
	}
	sort(ret.begin(),ret.end(),cmp);
	for(int i=1;i<ret.size();++i){
		ret[i].final_rank=i+1;
		if(ret[i].grade==ret[i-1].grade)
			ret[i].final_rank=ret[i-1].final_rank;
	}

	cout<<ret.size()<<endl;
	for(int i=0;i<ret.size();++i){
		cout<<ret[i].id<<" "<<ret[i].final_rank<<" "<<ret[i].local_num<<" "<<ret[i].local_rank<<endl;
	}
	return 0;
}