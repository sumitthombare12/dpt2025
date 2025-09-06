#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    
    int n = 0;
    cout<<"N:";
    cin>>n;
    vector<int> arr(n, 0);
    cout<<"Ele:";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    int k = 1;
    cout<<"K:";
    cin>>k;
    
    //*** MAIN CODE ****
    vector<int> ans;
    int i=0, j=0;
    
    deque<int> dq;
    
    for(int i=0; i<n; i++) {
        if(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }
        
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i >= k-1) ans.push_back(arr[dq.front()]);
    }
    
    //OUTPUT:
    cout<<endl;
    for(int &val: ans) {
        cout<<val<<"\t";
    }
    return 0;
}
