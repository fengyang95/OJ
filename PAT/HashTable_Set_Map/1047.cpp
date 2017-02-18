/*1047. Student List for Course (25)*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
	int n,n_course;
	cin>>n>>n_course;
	vector<set<string>> course(n_course+1);
	string name;
	int k;
	int index;
	for(int i=0;i<n;++i){
		cin>>name;
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%d",&index);
			course[index].insert(name);
		}
	}

	for(int i=1;i<=n_course;++i){
		cout<<i<<" "<<course[i].size()<<endl;
		for(set<string>::iterator it=course[i].begin();it!=course[i].end();++it){
			cout<<*it<<endl;
		}
	}
	return 0;
}