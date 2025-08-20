#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main() {
    
    //INPUT:
    int n = 0;
    cout<<"Enter a n:";
    cin>>n;
    
    long long arr[n];
    
    cout<<"Enter a element:";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    //*** MAIN CODE ***
    unordered_map<long long, vector<int>> mp;
    long long sum = 0;
    vector<pair<int, int>> result;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
        
        if(sum == 0) {
            result.push_back({0, i});
        }
        if(mp.find(sum) != mp.end()) {
            for(int &idx: mp[sum]) {
                result.push_back({ idx+1, i});
            }
        }
        mp[sum].push_back(i);
    }
    
    //OUTPUT:
    for(auto &pairs: result) {
        cout<<pairs.first<<" "<<pairs.second<<endl;
    }

    return 0;
}
