/*1089. Insert or Merge (25)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    int i,j;
    for(i=0;i<n-1&&b[i]<=b[i+1];++i);
    for(j=i+1;j<n&&a[j]==b[j];++j);
    if(j==n){
        cout<<"Insertion Sort\n";
        sort(a.begin(),a.begin()+i+2);
    }
    else{
        cout<<"Merge Sort\n";
        bool is_same=false;
        int k=1;
        while(!is_same){
            is_same=true;
            for(int i=0;i<n;++i)
                if(a[i]!=b[i])
                    is_same=false;
            k*=2;
            for(int i=0;i<n/k;++i)
                sort(a.begin()+i*k,a.begin()+i*k+k);
            sort(a.begin()+n/k*k,a.end());
        }
    }
    cout<<a[0];
    for(int i=1;i<n;++i)
        cout<<" "<<a[i];
    return 0;
}
