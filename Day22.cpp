#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    
    int n = 0;
    cout<<"Enter size:";
    cin>>n;
    
    long long arr[n];
    
    cout<<"Enter element:";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    long long k;
    cout<<"Enter k:";
    cin>>k;
    
    unordered_map<long, long> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    
    for(auto [a, b]: mp) {
        if(b == k) {
            cout<<a;
            return 0;
        }
    }
    
    cout<<-1;
    return 0;
}
