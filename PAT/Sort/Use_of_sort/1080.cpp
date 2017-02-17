/*1080. Graduate Admission (30)*/
/*刚开始把ge和gi顺序弄反了，注意！！！*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu{
	int id;
	int ge,gi,ga;
	int rank=1;
	vector<int> choice;
};

struct sch{
	int max_size;
	vector<stu> accept;
};

bool cmp(stu& l,stu& r){
	if(l.ga==r.ga){
		return l.ge>r.ge;
	}
	else 
		return l.ga>r.ga;
}

bool cmp1(stu& l,stu& r){
	return l.id<r.id;
}

int main(){
	int n_person,n_school,k;
	scanf("%d%d%d",&n_person,&n_school,&k);
	vector<sch> school(n_school);
	vector<stu> student(n_person);
	for(int i=0;i<n_school;++i)
		scanf("%d",&school[i].max_size);
	int index;
	for(int i=0;i<n_person;++i){
		scanf("%d%d",&student[i].ge,&student[i].gi);
		student[i].id=i;
		student[i].ga=(student[i].gi+student[i].ge)/2;
		for(int j=0;j<k;++j){
			scanf("%d",&index);
			student[i].choice.push_back(index);
		}
	}

	sort(student.begin(),student.end(),cmp);
	for(int i=1;i<student.size();++i){
		student[i].rank=i+1;
		if(student[i].ga==student[i-1].ga&&student[i].ge==student[i-1].ge)
			student[i].rank=student[i-1].rank;
	}

	for(int i=0;i<student.size();++i){
		for(int j=0;j<k;++j){
			int ch=student[i].choice[j];
			if(school[ch].accept.size()<school[ch].max_size){
				school[ch].accept.push_back(student[i]);
				break;
			}
			else{
				if(school[ch].accept.back().rank==student[i].rank){
					school[ch].accept.push_back(student[i]);
					break;
				}
			}
		}
	}

	for(int i=0;i<n_school;++i){
		sort(school[i].accept.begin(),school[i].accept.end(),cmp1);
	}
	for(int i=0;i<n_school;++i){
		if(!school[i].accept.empty())
			printf("%d",school[i].accept[0].id);
		for(int j=1;j<school[i].accept.size();++j)
			printf(" %d",school[i].accept[j].id);
		printf("\n");
	}
	return 0;
}