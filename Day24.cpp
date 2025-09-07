#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
};

class Solution {
    public:
  		void insert(unordered_map<int, Node*>& mp, int i, int data) {
                int prev = (i-1) / 2;
                Node* newNode = new Node(data);
                Node *preNode = mp[prev];
                if(i == 2*prev+1) {
                    preNode->left = new Node(data);
                    Node* currNode = preNode->left;
                    mp[i] = currNode;
                } else {
                    preNode->right = newNode;
                    mp[i] = newNode;
                }
        }


/*class Node {
    int data;
    Node* left;
    Node* right;
};*/
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        
        if(root == nullptr) {
            return nullptr;
        }
        
        if(root->data == v1 || root->data == v2) {
            return root;
        }
        
        Node* to_left = lca(root->left, v1, v2);
        Node* to_right = lca(root->right, v1, v2);
        
        if(to_left != nullptr && to_right != nullptr) {
            return root;
        } else if(to_left != nullptr) {
            return to_left;
        } else if(to_right != nullptr) {
            return to_right;
        }
        
        
        return nullptr;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;
    
    unordered_map<int, Node*> mp;
    cout<<"Ele:";
    cin>>data;
    root = new Node(data);
    root->left = nullptr;
    root->right = nullptr;
    mp[0] = root;
    
    int i = 1;
    while(i < t) {
        std::cin >> data;
        myTree.insert(mp, i, data);
        i++;
    }
  	cout<<"Enter v1, v2:";
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
