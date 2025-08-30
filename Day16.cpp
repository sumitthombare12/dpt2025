#include <iostream>
using namespace std;

long long lcm(long long n, long long m) {
    
    return (m == 0)? n: lcm(m, n % m);
}

int main()
{
    long long n=0, m=0;
    cout<<"N:";
    cin>>n;
    cout<<"M:";
    cin>>m;
    
    long long result = (n/ lcm(n, m)) * m;
    
    cout<<result;
    
    return result;
}
