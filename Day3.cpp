#include <iostream>
using namespace std;

int main() {
    
    //INPUT
    int n = 0;
    cout<<"Enter a n:";
    cin>>n;
    
    long long arr[n+1];
    cout<<"Enter n+1 element from 1 to n:"<<endl;
    for(int i=0; i<=n; i++) {
        cout<<"Element "<<i<<":";
        cin>>arr[i];
    }
    
    // *** MAIN CODE ***
    
    long long slow = arr[0];
    long long fast = arr[0];
    
    slow = arr[slow];
    fast = arr[arr[fast]];
    
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    
    slow = arr[0];
    
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    //OUTPUT
    cout<<"OUTPUT:"<<slow;
    return 0;
}
