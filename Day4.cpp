#include <iostream>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int idx1, int idx2) {
    if(arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}

int main() {
    
    //INPUT
    int n = 0, m = 0, i;
    
    cout<<"Enter a length of arr1:";
    cin>>n;
    cout<<"Enter a length of arr2:";
    cin>>m;
    
    long long arr1[n];
    long long arr2[m];
    
    cout<<"Enter a arr1 element:";
    for(i=0; i<n; i++) {
        cin>>arr1[i];
    }
    
    cout<<"Enter a arr2 element:";
    for(i=0; i<m; i++) {
        cin>>arr2[i];
    }
    //*** MAIN CODE ***
    int len = (n+m);
    int gap = (len / 2) + (len % 2);
    
    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        while(right < len) {
            if( left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right-n);
            } else if(left >= n) {
                swapIfGreater(arr2, arr2, left-n, right-n);
            } else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap%2);
    }
    
    //OUTPUT:
    cout<<"\narray 1: ";
    for(i=0; i<n; i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<"\narray 2: ";
    for(i=0; i<m; i++) {
        cout<<arr2[i]<<" ";
    }

    return 0;
}
