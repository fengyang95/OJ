/*1044. Shopping in Mars (25)*/
/*用二分查找加 scanf printf输入输出才没有超时！！！*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n,total;
int ans_sum=INT_MAX;
vector<int> sum;

void find(int start,int& end,int& temp_sum){
	int left=start,right=n;
	while(left<right){
		int mid=(left+right)/2;
		if(sum[mid]-sum[start-1]>=total){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	end=right;
	temp_sum=sum[end]-sum[start-1];
}

int main(){
	cin>>n>>total;
	sum.resize(n+1,0);
	for(int i=1;i<=n;++i){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	vector<pair<int,int>> ans;
	int end,temp_sum;
	for(int start=1;start<=n;++start){
		find(start,end,temp_sum);
		if(temp_sum>=total){
			if(temp_sum>ans_sum)
				continue;
			else if(temp_sum<ans_sum){
				ans_sum=temp_sum;
				ans.clear();
				ans.push_back(make_pair(start,end));
			}
			else{
				ans.push_back(make_pair(start,end));
			}
		}
	}
	for(int i=0;i<ans.size();++i)
		printf("%d-%d\n",ans[i].first,ans[i].second);
	return 0;
}