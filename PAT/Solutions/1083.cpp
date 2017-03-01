/*1083. List Grades (25)*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student{
	string name;
	string id;
	int grade;
};

bool cmp(student& l,student& r){
	return l.grade>r.grade;
}
int main(){
	int n;
	cin>>n;
	vector<student> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i].name>>v[i].id>>v[i].grade;
	}
	int grade1,grade2;
	cin>>grade1>>grade2;
	vector<student> ret;
	for(int i=0;i<n;++i){
		if(v[i].grade>=grade1&&v[i].grade<=grade2)
			ret.push_back(v[i]);
	}
	if(ret.empty()){
		cout<<"NONE";
	}
	else{
		sort(ret.begin(),ret.end(),cmp);
		for(int i=0;i<ret.size();++i)
			cout<<ret[i].name<<" "<<ret[i].id<<endl;
	}
	return 0;
}