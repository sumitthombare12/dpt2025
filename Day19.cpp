#include <iostream>
#include <stack>
using namespace std;
long long M = 1e9;

long long power(int a, int b) {
    if(b == 0) return 1;
    
    long long result = power(a, b/2);
    result = (result * result) % M;
    
    if(b % 2 != 0) {
        result = result * a;
    }
    
    return result;
}

string performOp(int a, int b, char ch) {
    
    switch(ch) {
        case '*':
            return to_string(a*b);
        case '/':
            if(b == 0) return "1";
            return to_string(a/b);
        case '+':
            return to_string(a+b);
        case '-':
            return to_string(a-b);
        case '^':
            return to_string(power(a, b));
        default:
            cout<<"Error";
    }
    return "1";
}

int main() {
    
    //INPUT
    string str;
    cout<<"String:";
    getline(cin, str);

    //*** MAIN CODE ***
    stack<string> st;
    string s = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '+' || (str[i] == '-' && (i+1 == str.length() || str[i+1] == ' '))) {
            int b = stoi( st.top());
            st.pop();
            int a = stoi( st.top());
            st.pop();
            string c = performOp(a, b, str[i]);
            st.push(c);
                
        } else if(str[i] == ' ') {
            if(s != "") {
                st.push(s);
                s = "";
            }
        } else{
            s += str[i];
        }
    }
    if(s != "" && st.empty()) st.push(s);

    //OUTPUT:
    cout<<endl<<st.top();
    return 0;
}
