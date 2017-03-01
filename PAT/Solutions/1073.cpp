/*1073. Scientific Notation (20)*/
/*all passed*/
/*56min*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void parse(string& src,char& sign,vector<char>& dst,bool& is_expon_positive,int& expon){
	sign=src[0];
	int i;
	for(i=1;src[i]!='E';++i){
		if(src[i]=='.')continue;
		else
			dst.push_back(src[i]);
	}
	is_expon_positive=true;
	if(src[++i]=='-')is_expon_positive=false;
	vector<int> expon_s;
	for(int j=i+1;j<src.size();++j){
		expon_s.push_back(src[j]-'0');
	}
	for (int i = 0; i < expon_s.size(); ++i){
		expon = expon * 10 + expon_s[i];
	}
}

int main(){
	string src;
	cin>>src;
	char sign;
	vector<char> dst;
	int expon=0;
	bool is_expon_positive;
	int point_position=1;
	parse(src, sign, dst, is_expon_positive, expon);
	if(is_expon_positive){//正指数
		point_position+=expon;
		if(point_position>=dst.size()){
			int k=expon - dst.size() + 1;
			for(int i=0;i<k;++i){
				dst.push_back('0');
			}
		}
		else{
			dst.insert(dst.begin()+point_position,'.');
		}
	}
	else{
		for(int i=0;i<expon;++i){
			dst.insert(dst.begin(),'0');
		}
		dst.insert(dst.begin()+1,'.');
	}

	if(sign=='-')cout<<sign;
	for(int i=0;i<dst.size();++i)
		cout<<dst[i];
	return 0;
}