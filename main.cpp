//
//  main.cpp
//  trees
//
//  Created by Matthew liew on 13.11.23.
//

#include <iostream>
#include <memory>
#include "binomialSearchTree.hpp"
using namespace std;



int main() {

    TreeNode root(5);
    root.insertIntoBST(2);
    root.insertIntoBST(6);

    cout << "Binary Tree: ";
    root.printBinaryTree(root);
    cout << endl;


    /*
    shared_ptr<TreeNode> root = make_shared<TreeNode>(5);
    root->left = make_shared<TreeNode>(2);
    root->right = make_shared<TreeNode>(6);

    root = TreeNode::insertIntoBST(root, 3);

    auto result = root->searchBST(root, 2);

    if (result != nullptr) {
        cout << "Value found: " << result->val << endl;
    } else {
        cout << "Value not found." << endl;
    }
    
    
    std::cout << "Binary Tree: ";
    root->printBinaryTree(root);
    std::cout << std::endl;
    */
    return 0;
}
