/*1040. Longest Symmetric String (25)*/
//动态规划的方式求解
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestPalindrome(string &s){
	int len=s.length();
	vector<bool> temp(len,false);
	vector<vector<bool>> dp(len,temp);
	int maxlen=1;
	dp[0][0]=true;
	for(int i=1;i<len;++i){
		dp[i][i]=true;
		if(s[i]==s[i-1]){
			dp[i-1][i]=true;
			maxlen=2;
		}
	}

	for(int Len=3;Len<=len;++Len){
		for(int i=0;i<=len-Len;++i){
			int j=i+Len-1;
			if(s[i]==s[j]&&dp[i+1][j-1]){
				maxlen=Len;
				dp[i][j]=true;
			}
		}
	}
	return maxlen;
}
int main(){
	string s;
	getline(cin,s);
	cout<<longestPalindrome(s);
}