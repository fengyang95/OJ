/*1044. Shopping in Mars (25)*/
/*二分法*/
/*输入输出用cin都会超时。。。*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int n,total;
	cin>>n>>total;
	vector<int> v(n+1),sum(n+1);
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
		sum[i]=sum[i-1]+v[i];
	}

	int minsum=INT_MAX;
	vector<pair<int,int>> ans;
	int left,right,mid;
	for(int i=1;i<=n;++i){
		left=i,right=n;
		int temp_sum;
		while(left<right){
			mid=(left+right)/2;
			temp_sum=sum[mid]-sum[i-1];
			if(temp_sum>=total){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		temp_sum=sum[right]-sum[i-1];
		if(temp_sum>minsum)
			continue;
		if(temp_sum>=total){
			if(temp_sum<minsum){
				minsum=temp_sum;
				ans.clear();
			}
			ans.push_back(make_pair(i,right));
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		printf("%d-%d\n", ans[i].first, ans[i].second);
	return 0;
}