#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n; 
    vector<long long> l1(n), l2(n); 
    
    for (long long i = 0; i < n; i++) {
        cin >> l1[i]; 
    }
    for (long long i = 0; i < n; i++) {
        cin >> l2[i]; 
    }

    vector<vector<long long>> dp(2, vector<long long>(n, 0));
    dp[0][0] = l1[0]; 
    dp[1][0] = l2[0]; 
    
    for (long long i = 1; i < n; i++) {
        dp[0][i] = max(dp[1][i-1] + l1[i], dp[0][i-1]);  
        dp[1][i] = max(dp[0][i-1] + l2[i], dp[1][i-1]);  
    }

    long long res = max(dp[0][n], dp[1][n]);
    cout << res;
    return 0;
}
