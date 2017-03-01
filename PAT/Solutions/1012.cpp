/*1012. The Best Rank (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	string id;
	vector<int> grade;
	vector<int> rank;
	int best_index;
};

int k;
bool cmp(node& lhs,node& rhs){
	return lhs.grade[k]>rhs.grade[k];
}


int main(){
	int n,n_query;
	cin>>n>>n_query;
	vector<node> stu(n);
	string id;
	for(int i=0;i<n;++i){
		cin>>id;
		stu[i].id=id;
		stu[i].grade.resize(4);
		stu[i].rank.resize(4);
		cin>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
		stu[i].grade[0]=(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3;
	}

	for(int i=0;i<4;++i){
		k=i;
		sort(stu.begin(),stu.end(),cmp);
		stu[0].rank[i]=1;
		for(int j=1;j<n;++j){
			stu[j].rank[i]=j+1;
			if(stu[j].grade[i]==stu[j-1].grade[i])
				stu[j].rank[i]=stu[j-1].rank[i];
		}
	}

	for(int i=0;i<n;++i){
		stu[i].best_index=0;
		for(int j=1;j<4;++j){
			if(stu[i].rank[j]<stu[i].rank[stu[i].best_index])
				stu[i].best_index=j;
		}
	}

	string query;
	char out[5]={'A','C','M','E'};
	for(int i=0;i<n_query;++i){
		cin>>query;
		int j;
		for(j=0;j<n;++j){
			if(stu[j].id==query){
				cout<<stu[j].rank[stu[j].best_index]<<" "<<out[stu[j].best_index]<<endl;
				break;
			}
		}
		if(j>=n){
			cout<<"N/A\n";
		}
	}
	return 0;
}