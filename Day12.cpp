#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    string s;
    cin>>s;
    
    //*** MAIN CODE ***
    stack<char> st;

    for(char &ch: s) {
        if( ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if(!st.empty() && ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}')) ) {
                st.pop();
            } else {
                cout<<"false";
                return 0;
            }
        }
    }
    
    cout<<(st.empty()? "true": "false");

    return 0;
}
