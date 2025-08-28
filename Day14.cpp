#include <iostream>
#include <unordered_map>
using namespace std;

int findSubStr(string s, int k) {
    int l=0, r=0, count = 0;
    unordered_map<char, int> mp;
    
    while(r < s.length()) {
        mp[s[r]]++;
        
        while(l <= r && mp.size() > k) {
            mp[s[l]]--;
            if(mp[s[l]] <= 0) {
                mp.erase(s[l]);
            }
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}

int main()
{
    string s;
    int k;
    cout<<"String:";
    cin>>s;
    cout<<"K:";
    cin>>k;
    
    int result = findSubStr(s, k) - findSubStr(s, k-1);
    cout<<result;
    
    return result;
}
