/*1075. PAT Judge (25)*/
/*注意对编译未通过和未提交的区分*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	bool isvalid=false;
	int rank=1;
	int id;
	int total=0;
	int num_perfect=0;
	vector<int> score;
};

bool cmp(node& l,node& r){
	if(l.total==r.total){
		if(l.num_perfect==r.num_perfect){
			return l.id<r.id;
		}
		else return l.num_perfect>r.num_perfect;
	}
	else 
		return l.total>r.total;
}

int main(){
	int n,n_question,n_submittions;
	scanf("%d%d%d",&n,&n_question,&n_submittions);
	vector<int> total_score(n_question+1);
	for(int i=1;i<=n_question;++i)
		scanf("%d",&total_score[i]);
	vector<node> person(n+1);
	for(int i=1;i<=n;++i){
		person[i].score.resize(n_question+1,-2);
		person[i].id=i;
	}

	int id,index,s;
	for(int i=0;i<n_submittions;++i){
		scanf("%d%d%d",&id,&index,&s);
		if(person[id].score[index]<s)
			person[id].score[index]=s;
		if(s>=0)
			person[id].isvalid=true;
	}

	vector<node> ret;
	for(int i=1;i<=n;++i){
		if(person[i].isvalid){
			for(int j=1;j<=n_question;++j){
				if(person[i].score[j]==-1)
					person[i].score[j]=0;
				if(person[i].score[j]!=-2)
					person[i].total+=person[i].score[j];
				if(person[i].score[j]==total_score[j])
					++person[i].num_perfect;
			}
			ret.push_back(person[i]);
		}
	}

	sort(ret.begin(),ret.end(),cmp);
	for(int i=1;i<ret.size();++i){
		ret[i].rank=i+1;
		if(ret[i].total==ret[i-1].total)
			ret[i].rank=ret[i-1].rank;
	}

	for(int i=0;i<ret.size();++i){
		printf("%d %05d %d",ret[i].rank,ret[i].id,ret[i].total);
		for(int j=1;j<=n_question;++j){
			if(ret[i].score[j]!=-2)
				printf(" %d",ret[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}

	return 0;
}