#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //INPUT
    int n = 0;
    cout<<"Enter a n:";
    cin>>n;
    
    vector<string> strs(n, "");
    cout<<"Enter a elements:";
    
    for(int i=0; i<n; i++) {
        cin>>strs[i];
    }
    
    //*** MAIN CODE ***
    sort( begin(strs), end(strs));
    n = n-1;
    string result = "";
    int i = 0;

    while( i < strs[0].size() || i < strs[n].size()) {
        if(strs[0][i] == strs[n][i]) {
            result += strs[0][i];
        } else {
            break;
        }
        i++;
    }
    
    //OUTPUT:
    cout<<result;
    
    return 0;
}
