#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> recurce(long long n, unordered_map<int, vector<long long>>& mp) {
    
    if(n == 1) return {};
    if(mp.find(n) != mp.end()) {
        return mp[n];
    }
    
    for(int i=n/2; i>=2; i--) {
        if(n % i == 0) {
            vector<long long> a = recurce(n/i, mp);
            vector<long long> b = recurce(i, mp);
            
            a.reserve(a.size()+b.size());
            a.insert(a.end(), make_move_iterator(b.begin()), make_move_iterator(b.end()));
            
            return mp[n] = a;
        }
    }
    
    return {n};
    
}

int main()
{
    
    long long n = 1;
    
    cout<<"Enter n:";
    cin>>n;
    
    vector<long long> ans;
    unordered_map<int, vector<long long>> mp;
    ans = recurce(n, mp);
    
    for(auto &val: ans) {
        cout<<val<<"\t";
    }

    return 0;
}
