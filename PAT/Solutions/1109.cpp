/*1109. Group Photo (25)*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person{
	string name;
	int height;
};

bool cmp(person& lhs,person& rhs){
	if(lhs.height==rhs.height){
		return lhs.name<rhs.name;
	}
	return lhs.height>rhs.height;
}

int main(){
	int n,rows;
	cin>>n>>rows;
	int first_num,other_num;
	other_num=n/rows;
	first_num=n-rows*other_num+other_num;
	vector<person> src(n);
	for(int i=0;i<n;++i){
		cin>>src[i].name>>src[i].height;
	}
	sort(src.begin(),src.end(),cmp);
	int k=0;

	int mid=first_num/2;
	int left=mid-1;
	int right=mid+1;
	vector<string> out(first_num);
	out[mid]=src[k++].name;
	while(k<first_num){
		out[left--]=src[k++].name;
		if(k>=first_num)break;
		out[right++]=src[k++].name;
	}
	cout<<out[0];
	for(int i=1;i<first_num;++i){
		cout<<" "<<out[i];
	}
	cout<<endl;


	while(k<n){
		int max_num=k+other_num;
		vector<string> out1(other_num);
		int mid1=other_num/2;
		int left1=mid1-1;
		int right1=mid1+1;
		out1[mid1]=src[k++].name;
		while(k<max_num){
			out1[left1--]=src[k++].name;
			if(k>=max_num)break;
			out1[right1++]=src[k++].name;
		}
		cout<<out1[0];
		for(int j=1;j<other_num;++j)
			cout<<" "<<out1[j];
		cout<<endl;
	}
	return 0;
}