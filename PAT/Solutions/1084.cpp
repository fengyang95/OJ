/*1084. Broken Keyboard (20)*/
/*2.4 19.30--19.43*/
/*all passed*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	string src,test;
	getline(cin,src);
	getline(cin,test);
	for (int i = 0; i < src.size(); ++i){
		if (src[i] >= 'a'&&src[i] <= 'z')
			src[i] = src[i] - 'a' + 'A';
	}
	for (int i = 0; i < test.size(); ++i){
		if (test[i] >= 'a'&&test[i] <= 'z')
			test[i] = test[i] - 'a' + 'A';
	}
	bool v[256] = { false };
	bool visit[256] = { false };
	for (int i = 0; i < src.size(); ++i){
		v[src[i]] = true;
	}
	for (int j = 0; j < test.size(); ++j){
		v[test[j]] = false;
	}
	string ret;
	for (int i = 0; i < src.size(); ++i){
		if (v[src[i]] && !visit[src[i]]){
			ret.push_back(src[i]);
			visit[src[i]] = true;
		}
	}
	cout << ret;
	return 0;
}