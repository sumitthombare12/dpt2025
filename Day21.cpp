#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int val) {
    if(st.empty()) {
        st.push(val);
        return;
    }
    int tm = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(tm);
}
void reverseStack(stack<int>& st) {
    if(st.empty()) return;
    
    int val = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, val);
}

int main() {
    
    int n = 0, in;
    cout<<"Enter a n:";
    cin>>n;
    
    stack<int> st;
    cout<<"Enter a element:";
    for(int i=0; i<n; i++) {
        cin>>in;
        st.push(in);
    }
    
    reverseStack(st);
    
    while(!st.empty()) {
        cout<<st.top()<<"\t";
        st.pop();
    }
    
    return 0;
}
