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
    
    
    cout << "Binary Tree: ";
    root->printBinaryTree(root);
    cout << std::endl;
    */

    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(5);
    root->left = std::make_shared<TreeNode>(3);
    root->right = std::make_shared<TreeNode>(7);
    root->left->left = std::make_shared<TreeNode>(2);
    root->left->right = std::make_shared<TreeNode>(4);
    root->right->left = std::make_shared<TreeNode>(6);
    root->right->right = std::make_shared<TreeNode>(8);

    std::cout << "Original Tree:" << std::endl;
    root->printBinaryTree(root);

    // Delete a node (e.g., node with value 5)
    int valueToDelete = 5;
    root = root->deleteNode(root, valueToDelete);

    std::cout << "\nTree after deleting node with value " << valueToDelete << ":" << std::endl;
    root->printBinaryTree(root);

    return 0;
    
    return 0;
}
