/*1022. Digital Library (30)*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
using namespace std;

struct node{
	string id;
	string title;
	string author;
	vector<string> keywords;
	string publisher;
	string publish_year;
};

int main(){
	//ifstream cin("test.txt");
	int n;
	cin>>n;
	getchar();
	vector<node> books(n);
	string keys;
	for(int i=0;i<n;++i){
		getline(cin,books[i].id);
		getline(cin,books[i].title);
		getline(cin,books[i].author);
		getline(cin,keys);
		getline(cin,books[i].publisher);
		getline(cin,books[i].publish_year);
		string keyword="";
		for(int j=0;j<keys.size();++j){
			if(keys[j]!=' ')
				keyword+=keys[j];
			else{
				books[i].keywords.push_back(keyword);
				keyword="";
			}
		}
		books[i].keywords.push_back(keyword);
		keyword="";
	}

	int n_query;
	cin>>n_query;
	getchar();
	string query;
	for(int i=0;i<n_query;++i){
		set<string> ret;
		getline(cin,query);
		char type=query[0];
		string content=query.substr(3);
		if(type=='1'){
			for(int j=0;j<n;++j){
				if(books[j].title==content){
					ret.insert(books[j].id);
				}
			}
		}
		if(type=='2'){
			for(int j=0;j<n;++j){
				if(books[j].author==content){
					ret.insert(books[j].id);
				}
			}
		}
		if(type=='3'){
			for(int j=0;j<n;++j){
				for(int k=0;k<books[j].keywords.size();++k){
					if(content==books[j].keywords[k])
						ret.insert(books[j].id);
				}
			}
		}
		if(type=='4'){
			for(int j=0;j<n;++j){
				if(content==books[j].publisher){
					ret.insert(books[j].id);
				}
			}
		}
		if(type=='5'){
			for(int j=0;j<n;++j){
				if(content==books[j].publish_year){
					ret.insert(books[j].id);
				}
			}
		}
		cout<<query<<endl;
		if(!ret.empty()){
			for(set<string>::iterator it=ret.begin();it!=ret.end();++it){
				cout<<*it<<endl;
			}
		}
		else{
			cout<<"Not Found\n";
		}
	}
	return 0;
}