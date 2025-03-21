#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void max(vector<int>&a, int n){
    for(int i=0;i<n;i++){
        if(a[i]>a[0]){
            int transfer = (a[i]-a[0]+1)/2;
            a[0]+=transfer;
            a[i]-=transfer;
        }
    }
}
int main(){
    int t;
    cout<<"Enter number of test cases:"<<" ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter no of towers:"<<" ";
        cin>>n;
        vector<int>a(n);
        cout<<"Enter no of blocks in each tower"<<" ";
        for(int i =0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        max(a,n);
        cout<<"Output:"<<a[0]<<endl;
    }
    return 0;
}