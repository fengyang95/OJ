/*1101. Quick Sort (25)*/
/*注意结果为空的情况*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> src(n);
    vector<int> sorted;
	for(int i=0;i<n;++i){
		cin>>src[i];
	}
	sorted=src;
	sort(sorted.begin(),sorted.end());
    int max =INT_MIN;
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        if(src[i] ==sorted[i] &&src[i]>max) {
            ret.push_back(src[i]);
        }
        if (src[i]>max)
            max =src[i];
    }
    cout<<ret.size()<<endl;
    if(!ret.empty())
        cout<<ret[0];
    for(int i=1;i<ret.size();++i)
    	cout<<" "<<ret[i];
    return 0;
}