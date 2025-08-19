#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    //INPUT:
    long long n = 0, rightLarge = LLONG_MIN;
    cout<<"Enter a n:";
    cin>>n;
    
    long long arr[n];
    
    cout<<"Enter a elements:";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    //**** MAIN CODE ***
    vector<long long> ans;
    for(int i=n-1; i>=0; i--) {
        if(rightLarge < arr[i]) {
            ans.push_back(arr[i]);
            rightLarge = arr[i];
        }
    }
    
    //OUTPUT:
    reverse( begin(ans), end(ans));
    cout<<"Output:"<<endl;
    for(long long& val: ans) {
        cout<<val<<" ";
    }

    return 0;
}
