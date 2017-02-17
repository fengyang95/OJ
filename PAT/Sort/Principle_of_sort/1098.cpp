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
        cout<<"Heap Sort\n";
        bool is_same=false;
        for (int i = n-1; i>=0; i--){//进行堆排，使用原来的函数进行堆排
            make_heap(a.begin(),a.begin()+i+1);
            for(int j=0;j<a.size();++j)
                cout<<a[j]<<" ";
            cout<<endl;
            if (a==b)
                is_same=true;
            else if (is_same)
                break;
        swap(a[0],a[i]);//建立好堆之后最大值在第一个，要将其摞到最后
        }
    }
    cout<<a[0];
    for(int i=1;i<n;++i)
        cout<<" "<<a[i];
    return 0;
}