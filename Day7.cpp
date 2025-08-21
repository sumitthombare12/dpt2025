#include <iostream>
#include <vector>
using namespace std;

int main() {
    //INPUT
    int n = 0;
    cout<<"Enter a n:";
    cin>>n;
    
    int height[n];
    cout<<"Enter a elements:";
    for(int i=0; i<n; i++) {
        cin>>height[i];
    }
    
    //*** MAIN CODE ***
    if(n == 0) return 0;

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = height[0];
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1], height[i]);
    }

    right[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1], height[i]);
    }

    int trapped = 0;
    for(int i=0; i<n; i++) {
        trapped += min(left[i], right[i]) - height[i];
    }

    //OUTPUT:
    cout<<"Output:"<<trapped;

    return 0;
}
