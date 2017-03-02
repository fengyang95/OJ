#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	double sum=0;
	double data;
	for(int i=0;i<n;++i){
		cin>>data;
		sum+=data*(n-i)*(i+1);
	}
	printf("%.2f",sum);
	return 0;
}