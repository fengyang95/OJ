/*1058. A+B in Hogwarts (20)*/
#include <iostream>
using namespace std;

int main(){
	int left1,mid1,right1;
	int left2,mid2,right2;
	int left3,mid3,right3;
	scanf("%d.%d.%d %d.%d.%d",&left1,&mid1,&right1,&left2,&mid2,&right2);
	right3=(right1+right2)%29;
	mid3=(mid1+mid2+(right1+right2)/29)%17;
	left3=left1+left2+(mid1+mid2+(right1+right2)/29)/17;
	printf("%d.%d.%d",left3,mid3,right3);
	return 0;
}