#include <iostream>
using namespace std;

string fibbo(string prev, string curr) {
    string result = "";
    int carry = 0, i = prev.size()-1, j = curr.size()-1;
    
    while(i >=0 || j >= 0 || carry) {
        int sum = carry;
        
        if(i >= 0) sum += (prev[i--] - '0');
        if(j >= 0) sum += (curr[j--] - '0');
        result = char(sum % 10 + '0')  + result;
        carry = sum / 10;
    }
    return result;
}

int main()
{
    
    int n = 0;
    cin>>n;
    if(n == 0) {
        cout<<endl<<0;
        return 0;
    }
    string prev = "0";
    string curr = "1";
    
    while(n-- > 1) {
        string temp = fibbo(prev, curr);
        prev = curr;
        curr = temp;
    }
    
    cout<<endl<<curr;
    return 0;
}
