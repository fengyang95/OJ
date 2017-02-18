/*1039. Course List for Student (25)*/
/*最后一个测试点超时*/
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
	map<char*,set<int>> students;
	int n,num_course;
	char *name;
	scanf("%d%d",&n,&num_course);
	int index,num_students;
	for(int i=0;i<num_course;++i){
		scanf("%d%d",&index,&num_students);
		for(int j=0;j<num_students;++j){
			scanf("%s",name);
			students[name].insert(index);
		}
	}

	vector<char*> out(n);
	for(int i=0;i<n;++i){
		cin>>out[i];
	}

	for(int i=0;i<n;++i){
		cout<<out[i]<<" ";
		cout<<students[out[i]].size();
		for(set<int>::iterator it=students[out[i]].begin();it!=students[out[i]].end();++it){
			cout<<" "<<*it;
		}
		cout<<endl;
	}

	return 0;
}