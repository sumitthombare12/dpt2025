#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
    
       int data;
       Node* left;
       Node* right;
       bool have_left;
       bool have_right;
       
       Node(int x) {
           data = x;
           left = nullptr;
           right = nullptr;
           have_right = true;
           have_left = true;
       }
};

class Solution {
    public:
    
    void traverse(Node* root) {
        if(root == nullptr) {
            cout<<"NULL ";
            return;
        }
        
        cout<<root->data<<" ";
        
        cout<<"Left:";
        traverse(root->left);
        cout<<"Right:";
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
                Node* newNode = new Node(stoi(data));
                currNode->left = newNode;
                return;
                
            } else if(currNode->have_right && currNode->right == nullptr) {
                if(data == "null" || data == "NULL" || data == "nullptr") {
                    currNode->have_right = false;
                    return;
                }
                Node* newNode = new Node(stoi(data));
                currNode->right = newNode;
                return;
            }
            
            if(currNode->left != nullptr)
                que.push(currNode->left);
            if(currNode->right != nullptr)
                que.push(currNode->right);
        }
    }
    
    bool isDuplicate(Node* leftNode, Node* rightNode) {
        if(leftNode == nullptr && rightNode == nullptr) {
            return true;
        } else if(leftNode == nullptr || rightNode == nullptr) {
            return false;
        }
        
        if(leftNode->data != rightNode->data) {
            return false;
        }
        
        bool flag = true;
        
        flag = flag && isDuplicate(leftNode->left, rightNode->right);
        flag = flag && isDuplicate(leftNode->right, rightNode->left);
        
        return flag;
    }
};

int main()
{
    int t = 0;
    cin>>t;
    if(t == 0) cout<<0<<endl;
    
    Node* root = NULL;
    string data;
    
    Solution myTree;
    
    while(t-- > 0) {
        if(root == NULL) {
            cin>>data;
            root = new Node(stoi(data));
        } else {
            cin>>data;
            myTree.BFS(root, data);
        }
    }
    
    //myTree.traverse(root);
    
    cout<<endl<<endl;
    
    cout<<myTree.isDuplicate(root->left, root->right);

    return 0;
}
