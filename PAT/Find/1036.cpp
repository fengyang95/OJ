/*1036. Boys vs Girls (25)*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stu{
	string name;
	char gender;
	string id;
	int grade;
};

int main(){
	int n;
	scanf("%d",&n);
	vector<stu> students(n);
	stu lowest_male,highest_female;
	lowest_male.grade=101;
	highest_female.grade=-1;
	for(int i=0;i<n;++i){
		cin >> students[i].name >> students[i].gender >> students[i].id >> students[i].grade;
		if(students[i].gender=='M'){
			if(students[i].grade<lowest_male.grade){
				lowest_male.grade=students[i].grade;
				lowest_male.name=students[i].name;
				lowest_male.id=students[i].id;
			}
		}
		else{
			if(students[i].grade>highest_female.grade){
				highest_female.grade=students[i].grade;
				highest_female.name=students[i].name;
				highest_female.id=students[i].id;
			}
		}
	}
	if(highest_female.grade!=-1){
		cout << highest_female.name << " " << highest_female.id << endl;
	}
	else{
		cout<<"Absent\n";
	}
	if(lowest_male.grade!=101){
		cout << lowest_male.name << " " << lowest_male.id << endl;
	}
	else{
		cout<<"Absent\n";
	}
	if(lowest_male.grade!=101&&highest_female.grade!=-1){
		cout<<highest_female.grade-lowest_male.grade;
	}
	else{
		cout<<"NA";
	}
	return 0;
}