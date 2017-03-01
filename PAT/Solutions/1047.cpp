/*1047. Student List for Course (25)*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char name[40000][5];
vector<vector<char*>> course;
bool cmp(char* a,char* b){
	return strcmp(a,b)<0;
}
int main(){
	int n_stu,n_course;
	cin>>n_stu>>n_course;
	course.resize(n_course+1);
	int k;
	int index;
	for(int i=0;i<n_stu;++i){
		scanf("%s%d",name[i],&k);
		for(int j=0;j<k;++j){
			scanf("%d",&index);
			course[index].push_back(name[i]);
		}
	}

	for(int i=1;i<=n_course;++i){
		sort(course[i].begin(),course[i].end(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(int j=0;j<course[i].size();++j)
			printf("%s\n",course[i][j]);
	}
	return 0;
}