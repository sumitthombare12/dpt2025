#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    
    int n = 0;
    cin>>n;
    
    vector<int> coins(n);
    for(int i=0; i<n; i++) {
        cin>>coins[i];
    }
    
    int amount = 0;
    cin>>amount;
    
    vector<int> prev(amount+1, -1), curr(amount+1, -1);

    for(int T=0; T<=amount; T++) {
        if(T % coins[0] == 0) prev[T] = T / coins[0];
        else prev[T] = 1e5;
    }

    for(int i=1; i<n; i++) {
        for(int T=0; T<=amount; T++) {
            int not_take = 0 + prev[T];
            int take = INT_MAX;
            if(coins[i] <= T) {
                take = 1 + curr[T - coins[i]];
            }
            curr[T] = min(not_take, take);
        }
        prev = curr;
    }

    int ans = prev[amount];
    if(ans >= 1e5) cout<<endl<<-1;
    else cout<<endl<<ans;

    return 0;
}
