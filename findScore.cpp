// Find the number of points earned by ith person in a game
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
// Function to find the score
void solve(){
    int n;
    cin >> n;
    vector<vector<string>> words(3, vector<string>(n));
    unordered_map<string, int> word_count; 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            word_count[words[i][j]]++;
        }
    }

    vector<int> score(3, 0);
    for (int i = 0; i < 3; i++){
        for (const string& word : words[i]){
            if (word_count[word] == 1) score[i] += 3;
            else if (word_count[word] == 2) score[i] += 1;
        }
    }
    cout << score[0] << " " << score[1] << " " << score[2] << "\n";
}