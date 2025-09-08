#include <iostream>
#include <unordered_map>
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

class Solution {
    public:
  		
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

    std::cin >> t;
    
    string data;
    cin>>data;
    root = new Node(stoi(data));
    t--;
    while(t > 0) {
        cin>>data;
        myTree.BFS(root, data);
            
        t--;
    }
	
  	cout<<"Enter v1, v2:";
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
