/*1082. Read Number in Chinese (25)*/
/*分情况讨论太麻烦*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> num{"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

vector<string> parse(int n){
	vector<string> ret;
	int ge=n%10;
	int shi=n/10%10;
	int bai=n/100%10;
	int qian=n/1000%10;
	bool q_zero=false;
	bool b_zero=false;
	bool s_zero=false;
	bool g_zero=false;
	if(qian==0)q_zero=true;
	if(bai==0)b_zero=true;
	if(shi==0)s_zero=true;
	if(ge==0)g_zero=true;
	if(!q_zero){
		ret.push_back(num[qian]);
		ret.push_back("Qian");
	}
	else if((!b_zero)||(!s_zero)||(!g_zero)){
		ret.push_back("ling");
	}
	if(!b_zero){
		ret.push_back(num[bai]);
		ret.push_back("Bai");
	}
	else if((!g_zero)||(!s_zero)){
		if(ret.back()!="ling")
			ret.push_back("ling");
	}
	if(!s_zero){
		ret.push_back(num[shi]);
		ret.push_back("Shi");
	}
	else if(!g_zero){
		if(ret.back()!="ling")
			ret.push_back("ling");
	}
	if(!g_zero){
		ret.push_back(num[ge]);
	}
	return ret;
}


int main(){
	int n;
	cin>>n;
	if(n<0)cout<<"Fu ";
	n=abs(n);
	int di=n%10000;
	int gao=n/10000%10000;
	int yi=n/100000000%10;
	vector<string> out1=parse(gao);
	vector<string> out2=parse(di);
	if(yi!=0){
		cout<<num[yi]<<" "<<"Yi";
		if(gao!=0){
			for(int i=0;i<out1.size();++i)
				cout<<" "<<out1[i];
			cout<<" "<<"Wan";
		}
		else{
			cout<<" "<<"ling";
		}
		if(out2[0]!="ling"||gao!=0){
			cout<<" "<<out2[0];
		}
		for(int i=1;i<out2.size();++i)
			cout<<" "<<out2[i];
	}
	else{
		if(gao!=0){
			int begin=1;
			if(out1[0]!="ling"){
				cout<<out1[0];
				begin=1;
			}
			else{
				cout<<out1[1];
				begin=2;
			}
			for(int i=begin;i<out1.size();++i){
				cout<<" "<<out1[i];
			}
			cout<<" Wan";
			for(int i=0;i<out2.size();++i)
				cout<<" "<<out2[i];
		}
		else{
			if(di!=0){
				int begin;
				if(out2[0]=="ling"){
					cout<<out2[1];
					begin=2;
				}
				else{
					cout<<out2[0];
					begin=1;
				}
				for(int i=begin;i<out2.size();++i){
					cout<<" "<<out2[i];
				}
			}
			else{
				cout<<"ling";
			}
		}
	}
	return 0;
}