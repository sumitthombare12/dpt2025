#include <iostream>
#include <regex>
using namespace std;

int main()
{
    
    //INPUT:
    string s;
    cin>>s;
    
    //*** MAIN CODE ***
    if (s.length() <= 1) {
        cout<<s;
        return 0;
    }
    
    int maxLen = 1;
    std::string maxStr = s.substr(0, 1);
    s = "#" + regex_replace(s, regex(""), "#") + "#";
    std::vector<int> dp(s.length(), 0);
    int center = 0;
    int right = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        if (i < right) {
            dp[i] = std::min(right - i, dp[2 * center - i]);
        }
        
        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
            dp[i]++;
        }
        
        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }
        
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
            maxStr.erase(remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
        }
    }
    
    cout<<maxStr;

    return 0;
}
