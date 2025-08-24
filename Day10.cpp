#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    //INPUT
    int n = 0;
    cin>>n;
    
    vector<string> strs(n, "");
    for(int i=0; i<n; i++) {
        cin>>strs[i];
    }
    
    //*** MAIN CODE ***
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    int j=0;

    for(int i=0; i<strs.size(); i++) {
        string temp = strs[i];
        sort( begin(temp), end(temp));
        if(mp.find(temp) != mp.end()) {
            int idx = mp[temp];
            ans[idx].push_back(strs[i]);
        } else {
            ans.push_back({strs[i]});
            mp[temp] = j;
            j++;
        }
    }
    
    //OUTPUT:
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
