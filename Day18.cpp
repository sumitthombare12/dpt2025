#include <iostream>
using namespace std;

int main() {
    
    long long n = 0;
    long long count = 0;
    
    cout<<"N:";
    cin>>n;
    cout<<endl;
    
    for(long long i=1; i*i<=n; i++) {
        if(n % i == 0) {
            count++;
            if(n/i != i) {
                count++;
            }
        }
    }
    
    cout<<count;
    return count;
}
