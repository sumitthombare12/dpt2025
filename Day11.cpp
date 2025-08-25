#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void permuteString( vector<int> mp, vector<string> &ans, string curr) {
    bool flag = true;
    
    for(int i=0; i<26; i++) {
        char ch = 'a'+i;
        int count = mp[i];
        if(count != 0) {
            flag = false;
            mp[i]--;
            permuteString(mp, ans, curr+ch);
            mp[i]++;
        }
    }
    if(flag) {
        ans.push_back(curr);
    }
}

int main() {
    //INPUT
    string str;
    
    cin>>str;
    sort( begin(str), end(str));
    
    vector<int> mp(26, 0);
    for(char &ch: str) {
        mp[ch-'a']++;
    }
    vector<string> ans;
    
    permuteString( mp, ans, "");
    
    for(string &st: ans) {
        cout<<st<<"\t";
    }

    return 0;
}
