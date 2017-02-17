#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,K,P;
vector<int> v;
vector<int> temp_ans,ans;
int max_factsum=-1;

void dfs(int ind,int temp_sum,int temp_K,int fact_sum){
	if(temp_sum==N&&temp_K==K){
		if(fact_sum>max_factsum){
			ans=temp_ans;
			max_factsum=fact_sum;
		}
		return;
	}
	if(temp_sum>N||temp_K>K)
		return;
	if(ind>=1){
		temp_ans.push_back(ind);
		dfs(ind,temp_sum+v[ind],temp_K+1,fact_sum+ind);
		temp_ans.pop_back();
		dfs(ind-1,temp_sum,temp_K,fact_sum);
	}
}


int main(){
	cin>>N>>K>>P;
	int temp=0;
	int index=1;
	while(temp<=N){
		v.push_back(temp);
		temp=pow(index,P);
		++index;
	}
	dfs(v.size()-1,0,0,0);
	if(max_factsum==-1){
		cout<<"Impossible";
		return 0;
	}
	printf("%d = ",N);
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" + ");
        printf("%d^%d", ans[i], P);
    }

	return 0;


}