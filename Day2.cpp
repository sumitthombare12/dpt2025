#include <iostream>
using namespace std;

int main() {
    int n = 0;
    
    //INPUT
    cout<<"Enter n:";
    cin>>n;
    
    long long arr[n-1];
    cout<<"Enter a "<<n-1<<" Element in array(1 to n):"<<endl;
    
    for(int i=0; i<n-1; i++) {
        cin>>arr[i];
    }
    
    //*** MAIN CODE ****
    long long expected_sum = (n*(n+1))/2;
    long long curr_sum = 0;
    
    for(int &val: arr) {
        curr_sum += val;
    }
    
    cout<<"Output:"<<expected_sum-curr_sum;
    return 0;
}
