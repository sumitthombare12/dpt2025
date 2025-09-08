// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
class Node {
    public:
    long long data;
    Node* left;
    Node* right;
    bool have_left;
    bool have_right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
        have_left = true;
        have_right = true;
        
    }
};

void traverse(Node* root) {
    if(root == nullptr) {
        cout<<"NULL";
        return;
    }
    
    cout<<root->data;
    
    cout<<" Left:";
    traverse(root->left);
    cout<<" Right:";
    traverse(root->right);
}

    
void BFS(Node* root, string data) {
    queue<Node*> que;
    que.push(root);
    
    while(!que.empty()) {
        
        Node* currNode = que.front();
        
        que.pop();
        
        if(currNode->have_left && currNode->left == nullptr) {
            if(data == "null" || data == "NULL" || data == "nullptr") {
                currNode->have_left = false;
                return;
            }
            int val = stoi(data);
            Node* newNode = new Node(val);
            currNode->left = newNode;
            return;
        } else if(currNode->have_right && currNode->right == nullptr) {
            if(data == "null" || data == "NULL" || data == "nullptr") {
                currNode->have_right = false;
                return;
            }
            int val = stoi(data);
            Node* newNode = new Node(val);
            currNode->right = newNode;
            return;
        }
        
        if(currNode->left != nullptr)
            que.push(currNode->left);
        if(currNode->right != nullptr)
            que.push(currNode->right);
    }
}

bool isValidBST(Node* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if(root == nullptr) {
        return true;
    }

    if(root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    bool left_node = isValidBST(root->left, minVal, root->data);
    bool right_node = isValidBST(root->right, root->data, maxVal);

    return (left_node && right_node);
}

int main() {
    // Write C++ code here
    
    Node *root;
    int t;
    cin>>t;

    string data;
    cin>>data;
    root = new Node(stoi(data));
    t--;
    while(t > 0) {
        cin>>data;
        BFS(root, data);
            
        t--;
    }
    
    //traverse(root)
    
    cout<<endl<<isValidBST(root);

    return 0;
}
