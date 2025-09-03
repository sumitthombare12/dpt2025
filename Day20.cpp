#include <iostream>
#include <stack>
using namespace std;

void sort(stack<int>& st) {
    
    if(st.empty()) {
        return;
    }
    
    int val = st.top();
    st.pop();
    sort(st);
    while(!st.empty() && val > st.top()) {
        int tm = st.top();
        st.pop();
        st.push(val);
        val = tm;
        sort(st);
    }
    st.push(val);
}

int main() {
    
    int n = 0, in;
    cout<<"Enter a n:";
    cin>>n;
    
    cout<<"Elements:";
    stack<int> st;
    for(int i=0; i<n; i++) {
        cin>>in;
        st.push(in);
    }
    
    sort(st);
    
    cout<<endl;
    while(!st.empty()) {
        
        cout<<st.top()<<"\t";
        st.pop();
    }

    return 0;
}
