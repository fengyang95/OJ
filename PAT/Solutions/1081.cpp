/*1081. Rational Sum (20)*/
/*注意输出的特殊情况*/
#include <iostream>
using namespace std;

long long  gcd(long long  a,long long  b){
	if(b==0)
		return abs(a);
	else
		return gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	long long  a,b;
	long long  value_a=0,value_b=1;
	for(int i=0;i<n;++i){
		scanf("%lld/%lld",&a,&b);
		long long temp=gcd(a,b);
		a/=temp;
		b/=temp;
		value_a=b*value_a+a*value_b;
		value_b=b*value_b;
		temp=gcd(value_a,value_b);
		value_a=value_a/temp;
		value_b=value_b/temp;
	}
	long long intger=value_a/value_b;
	value_a=abs(value_a-value_b*intger);
	if(intger!=0){
		printf("%lld",intger);
		if(value_a!=0)
			printf(" ");
	}
	if(value_a!=0){
		printf("%lld/%lld",value_a,value_b);
	}
	if(intger==0&&value_a==0)
		printf("0");
	return 0;
}
