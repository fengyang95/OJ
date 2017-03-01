/*1029. Median (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v1,v2,v3;
	int n;
	scanf("%d",&n);
	v1.resize(n);
	for(int i=0;i<n;++i)
		scanf("%d",&v1[i]);
	scanf("%d",&n);
	v2.resize(n);
	for(int i=0;i<n;++i)
		scanf("%d",&v2[i]);
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
	printf("%d",v3[(v3.size()-1)/2]);
	return 0;
}