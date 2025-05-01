// Minimum number of elements to be removed from the array
#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    int testCases;
    cin>>testCases;
    while(testCases--){
        solve();
    }
    return 0;
}
// Function to find the minimum number of elements to be removed
void solve(){
    int length;
    cin>>length;
    vector<int>seq(length);
    for(int i =0;i<length;i++){
        cin>>seq[i];
    }
    unordered_set<int> seen;
    int start_index = 0;

    for (int i = 0; i < length; i++) {
        while (seen.count(seq[i])) { 
            seen.erase(seq[start_index]);
            start_index++;
        }
        seen.insert(seq[i]); 
    }
    
    cout << start_index << endl;
}