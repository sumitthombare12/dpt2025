#include <iostream>
using namespace std;

int main() {

    //INPUT
    int n = 0;
    cout<<"Enter a size of array:";
    cin>>n;
    
    int arr[n];
    cout<<"Enter values(0's, 1's or 2's) of array one by one:\n";
    
    for(int i=0; i<n; i++) {
        cout<<"Element "<<i<<":";
        cin>>arr[i];
    }
    
    // ***  MIAIN SORTING CODE ***
    int l = 0, m = 0, r = n-1;
    
    while(m <= r) {
        if(arr[m] == 0) {
            swap(arr[m], arr[l]);
            l++;
            m++;
        } else if( arr[m] == 1) {
            m++;
        } else {
            swap( arr[m], arr[r]);
            r--;
        }
    }

    //OUTPUT
    cout<<"Ouput: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<"\t";
    }
    return 0;
}
