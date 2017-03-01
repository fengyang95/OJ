/*1080. Graduate Admission (30)*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct stu{
	int id;
	int ge,gi,aver;
	int rank;
	vector<int> apply;
};

struct sch{
	int max_size;
	int rank;
	vector<int> accept;
};

bool cmp(stu& lhs,stu& rhs){
	if(lhs.aver==rhs.aver)
		return lhs.ge>rhs.ge;
	else
		return lhs.aver>rhs.aver;
}

int main(){
	int n_stu,n_sch,k;
	cin>>n_stu>>n_sch>>k;
	vector<stu> students(n_stu);
	vector<sch> schools(n_sch);
	for(int i=0;i<n_sch;++i)
		cin>>schools[i].max_size;
	for(int i=0;i<n_stu;++i){
		students[i].apply.resize(k);
		students[i].id=i;
		cin>>students[i].ge>>students[i].gi;
		students[i].aver=(students[i].ge+students[i].gi)/2;
		for(int j=0;j<k;++j)
			cin>>students[i].apply[j];
	}

	sort(students.begin(),students.end(),cmp);
	students[0].rank=1;
	for(int i=1;i<n_stu;++i){
		students[i].rank=i+1;
		if(students[i].aver==students[i-1].aver&&
			students[i].ge==students[i-1].ge)
			students[i].rank=students[i-1].rank;
	}

	for(int i=0;i<n_stu;++i){
		for(int j=0;j<k;++j){
			int index=students[i].apply[j];
			if(schools[index].max_size>schools[index].accept.size()){
				schools[index].accept.push_back(students[i].id);
				schools[index].rank=students[i].rank;
				break;
			}
			else{
				if(schools[index].rank==students[i].rank){
					schools[index].accept.push_back(students[i].id);
					break;
				}
			}
		}  
	}

	for(int i=0;i<n_sch;++i){
		if(!schools[i].accept.empty()){
			sort(schools[i].accept.begin(),schools[i].accept.end());
			cout<<schools[i].accept[0];
			for(int j=1;j<schools[i].accept.size();++j)
				cout<<" "<<schools[i].accept[j];
		}
		cout<<endl;
	}
	return 0;
}