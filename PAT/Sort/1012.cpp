/*1012. The Best Rank (25)*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct stu{
	int id;
	int best;
	int grade[4];
	int rank[4];
};
int flag;
//map<int, int> exist;
int exist[1000000];
bool cmp(stu& l, stu& r){
	return l.grade[flag]>r.grade[flag];
}

int main(){
	int n, n_query;
	cin >> n >> n_query;
	vector<stu> students(n);
	for (int i = 0; i<n; ++i){
		cin >> students[i].id >> students[i].grade[1] >> students[i].grade[2] >> students[i].grade[3];
		students[i].grade[0] = (students[i].grade[1] + students[i].grade[2] + students[i].grade[3]) / 3 + 0.5;
	}

	for (flag = 0; flag <= 3; ++flag){
		sort(students.begin(), students.end(), cmp);
		students[0].rank[flag] = 1;
		for (int i = 1; i<n; ++i){
			students[i].rank[flag] = i + 1;
			if (students[i].grade[flag] == students[i - 1].grade[flag])
				students[i].rank[flag] = students[i - 1].rank[flag];
		}
	}


	for (int i = 0; i < n; i++) {
		exist[students[i].id] = i + 1;
		students[i].best = 0;
		int minn = students[i].rank[0];
		for (int j = 1; j <= 3; j++) {
			if (students[i].rank[j] < minn) {
				minn = students[i].rank[j];
				students[i].best = j;
			}
		}
	}
	char c[5] = { 'A', 'C', 'M', 'E' };
	int id;
	for (int i = 0; i < n_query; i++) {
		scanf("%d", &id);
		int temp = exist[id];
		if (temp) {
			int best = students[temp - 1].best;
			printf("%d %c\n", students[temp - 1].rank[best], c[best]);
		}
		else {
			printf("N/A\n");
		}
	}
	return 0;
}
