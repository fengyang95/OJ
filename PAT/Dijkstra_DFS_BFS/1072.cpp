/*1072. Gas Station (30)*/
/*2.15 14:27--*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int n_house,n_station,n_road,serve_range;

vector<vector<int>> road;

void find_mindis(int index,double& min_dis,double& aver_dis){
	vector<double> dis(n_station+n_house+1,INT_MAX);
	vector<bool> visit(n_station+n_house+1,false);
    dis[index+n_house] = 0;
    for(int i = 0; i < n_station +n_house;i++) {
        int u = -1, minn = INT_MAX;
        for(int j = 1; j <= n_station +n_house; j++) {
            if(!visit[j]&& dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n_station +n_house; v++) {
            if(visit[v] == false && dis[v] > dis[u] + road[u][v])
                dis[v] = dis[u] + road[u][v];
       	}
    }

    for(int i = 1; i <= n_house; i++) {
    	if(dis[i]>serve_range){
    		min_dis=INT_MAX;
    		break;
    	}
        if(dis[i] < min_dis) min_dis = dis[i];
        aver_dis += 1.0 * dis[i];
    }
    aver_dis /=n_house;
}


int main(){
	cin>>n_house>>n_station>>n_road>>serve_range;
	vector<int> temp(n_station+n_house+1,INT_MAX);
	road.resize(n_station+n_house+1,temp);
	string st,en;
	int a,b;
	int dis;
	for(int i=0;i<n_road;++i){
		cin>>st>>en>>dis;
		if(st[0]=='G'){
			a=stoi(st.substr(1))+n_house;
		}
		else{
			a=stoi(st);
		}
		if(en[0]=='G'){
			b=stoi(en.substr(1))+n_house;
		}
		else{
			b=stoi(en);
		}
		road[a][b]=road[b][a]=dis;
	}

	vector<double> min_dis(n_station+1,INT_MAX);
	vector<double> aver_dis(n_station+1,0);
	for(int i=1;i<=n_station;++i){
		find_mindis(i,min_dis[i],aver_dis[i]);
	}
	double ans_dis=0,ans_aver=0;
	int index=0;
	for(int i=1;i<=n_station;++i){
		if(min_dis[i]<serve_range){
			if(min_dis[i]>ans_dis){
				index=i;
				ans_dis=min_dis[i];
				ans_aver=aver_dis[i];
			}
			else if(min_dis[i]==ans_dis){
				if(aver_dis[i]<ans_aver){
					ans_aver=aver_dis[i];
					index=i;
				}
			}
		}
	}

	if(index==0){
		cout<<"No Solution";
	}
	else{
		cout<<"G"<<index<<endl;
		printf("%.1f %.1f",ans_dis,ans_aver);
	}
	return 0;
}