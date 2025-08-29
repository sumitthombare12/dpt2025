#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    //INPUT
    string s;
    cout<<"String:";
    cin>>s;
    
    //*** MAIN CODE ***
    unordered_map<char, int> mp;
    int i=0, j=0, ans = 0;
    
    while(j < s.length()) {
        
        if(mp.find(s[j]) != mp.end()) {
            i = max(i, mp[s[j]]+1);
        }
        mp[s[j]] = j;
        ans = max( ans, j-i+1);
        j++;
    }
    
    //OUTPUT
    cout<<ans;
    return ans;
}
