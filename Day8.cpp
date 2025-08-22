#include <iostream>
using namespace std;

int main() {
    //INPUT:
    string s = "";
    
    cout<<"Enter a string:";
    getline(cin, s);
    
    //*** MAIN CODE ***
    string str1 = "";
    string result = "";

    for(char &ch: s) {
        if(ch == ' ') {
            if(result != "" && str1 != "") {
                result = ' ' + result;
            }
            result = str1 + result;
            str1 = "";
        } else {
            str1 = str1 + ch;
        }
    }
    if(str1 != "")
        result = str1 + (result == ""? "": " ") + result;
    
    //OUTPUT:
    cout<<result;

    return 0;
}
