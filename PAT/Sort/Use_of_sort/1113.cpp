#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int data;
	vector<int> s;  
	for(int i=0;i<n;++i){
		cin>>data;
		s.push_back(data);
	}
	int mid=s.size()/2;
	int sum=0;
	int cnt=0;
	int mid_sum=0;
	sort(s.begin(),s.end());
	for(vector<int>::iterator it=s.begin();it!=s.end();++it){
		sum+=*it;
		cnt++;
		if(cnt==mid)
			mid_sum=sum;
	}

	cout<<s.size()-mid*2<<" "<<sum-2*mid_sum;
	return 0;

}
