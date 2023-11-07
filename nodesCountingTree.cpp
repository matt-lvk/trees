

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left, *right;
    Node() : val(0), left(nullptr), right(nullptr) {};
    Node(int x) : val(x), left(nullptr), right(nullptr) {};
    Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {};
};

class BST {
public:
    Node* createNode() {
        return new Node();
    }
    
    Node* createNode(int val) {
        return new Node(val);
    }
    
    Node* insert(Node* root, int val) {
        if (root == nullptr) {
            root = createNode(val);
        } else if (val <= root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    
    Node* countNodes(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = countNodes(root->left);
        root->right = countNodes(root->right);
        count++;
        return root;
    }
    
    int count{0};
    
};

int main () {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 3);
    root = bst.insert(root, 2);
    root = bst.insert(root, 1);
    root = bst.insert(root, 4);
    root = bst.insert(root, 5);
    root = bst.countNodes(root);
    cout << "Number of node is " << bst.count << endl;
    return 0;

}
