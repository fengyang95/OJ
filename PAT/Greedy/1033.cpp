/*1033. To Fill or Not to Fill (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct sta{
	double dis;
	double price;
};

bool cmp(sta& lhs,sta& rhs){
	return lhs.dis<rhs.dis;
}

int main(){
	int cmax,distance,per_unit,n;
	cin>>cmax>>distance>>per_unit>>n;
	vector<sta> stations(n+1);
	stations[0].price=0.0;
	stations[0].dis=distance;
	for(int i=1;i<=n;++i){
		cin>>stations[i].price>>stations[i].dis;
	}
	sort(stations.begin(),stations.end(),cmp);
	double now_dis=0.0,max_dis=0.0,now_price=0.0,total_price=0.0,left_dis=0.0;
	if(stations[0].dis!=0){
		cout<<"The maximum travel distance = 0.00";
		return 0;
	}
	else{
		now_price=stations[0].price;
	}

	while(now_dis<distance){
		max_dis=now_dis+cmax*per_unit;
		double min_price_dis=0,min_price=INT_MAX;
		int flag=0;
		for(int i=1;i<=n&&stations[i].dis<=max_dis;++i){
			if(stations[i].dis<=now_dis)continue;
			if(stations[i].price<now_price){
				total_price+=(stations[i].dis-now_dis-left_dis)*now_price/per_unit;
				left_dis=0.0;
				now_price=stations[i].price;
				now_dis=stations[i].dis;
				flag=1;
				break;
			}
			if(stations[i].price<min_price){
				min_price=stations[i].price;
				min_price_dis=stations[i].dis;
			}
		}
		if(flag == 0 && min_price !=INT_MAX) {
            total_price += (now_price * (cmax - left_dis / per_unit));
            left_dis = cmax * per_unit- (min_price_dis - now_dis);
            now_price = min_price;
            now_dis = min_price_dis;
            
        }
        if(flag == 0 && min_price == INT_MAX) {
            now_dis += cmax * per_unit;
            printf("The maximum travel distance = %.2f", now_dis);
            return 0;
        }
	}
	printf("%.2f", total_price);
    return 0;
}