/*1063. Set Similarity (25)*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
	int n_set,n_query;
	scanf("%d",&n_set);
	vector<set<int>> v(n_set+1);
	int k,elem;
	for(int i=1;i<=n_set;++i){
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%d",&elem);
			v[i].insert(elem);
		}
	}
	scanf("%d",&n_query);
	int left_index,right_index;
	for(int i=0;i<n_query;++i){
		scanf("%d%d",&left_index,&right_index);
		int nc=0;
		for(set<int>::iterator it=v[left_index].begin();it!=v[left_index].end();++it){
			if(v[right_index].find(*it)!=v[right_index].end())
				++nc;
		}
		int nt=v[left_index].size()+v[right_index].size()-nc;
		printf("%.1f%%\n",nc*1.0/nt*100);
	}
	return 0;
}