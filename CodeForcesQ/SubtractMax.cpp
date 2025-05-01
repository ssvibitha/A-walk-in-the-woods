// Program to display the difference between the element and the maximum element in array
#include <bits/stdc++.h>
using namespace std;

int solve();
int main(){
    cout<<"----Testcases----"<<endl;
    int testCases;
    cin>>testCases;
    while(testCases --){
        solve();
    }
    return 0;
}
// Function to display the difference of element and the maximum element in array
int solve(){
    cout<<"------Inputs------"<<endl;
    int length;
    cin>>length;
    vector<int>arr(length);
    for(int i=0;i<length;i++){
        cin>>arr[i];
    }
    int firstMax = arr[0],secondMax = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax; 
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] != firstMax) {
            secondMax = arr[i];
        }
    }
    cout<<"--------Output-------"<<endl;
    for(int i= 0;i<length;i++){
        if (arr[i] == firstMax){
            cout<<arr[i]-secondMax<<" ";
        }else{
            cout<<arr[i]-firstMax<<" ";
        }
    }
    cout<<endl;
    return 0;
}