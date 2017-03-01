/*1067. Sort with Swap(0,*) (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		scanf("%d",&v[i]);
	int cnt=0;
	int index=1;
	bool finished=false;
	while(!finished){
		while(v[0]!=0){
			swap(v[v[0]],v[0]);
			++cnt;
		}
		finished=true;
		while(index<n){
			if(v[index]!=index){
				swap(v[index],v[0]);
				++cnt;
				finished=false;
				break;
			}
			++index;
		}
	}
	cout<<cnt;
	return 0;

}