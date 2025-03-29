// Program to display the winners after repeated elimination of players
#include <bits/stdc++.h>
using namespace std;

int solve();
int main(){
    int testCases;
    cin>>testCases;
    while(testCases --){
        solve();
    }
    return 0;
}
// Function to display the winners
int solve(){
    int k,q;
    cin>>k>>q;
    vector<int>a(k);
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    while(q--){
        int n;
        cin>>n;
        if(n>=a[0]){
            cout<<a[0]-1<<" ";
        }else{
            cout<<n<<" ";
        }
    }
    cout<<endl;
    return 0;
}