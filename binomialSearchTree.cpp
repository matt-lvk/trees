//
//  binomialSearchTree.cpp
//  trees
//
//  Created by Matthew liew on 13.11.23.
//

#include "binomialSearchTree.hpp"
using namespace std;

shared_ptr<TreeNode> TreeNode::searchBST(shared_ptr<TreeNode> root, const int& val) {
    if (root == nullptr || val == root->val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

shared_ptr<TreeNode> TreeNode::insertIntoBST(shared_ptr<TreeNode> root, int val) {
    if (root == nullptr) {
        return std::make_shared<TreeNode>(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

shared_ptr<TreeNode> deleteNode(std::shared_ptr<TreeNode> root, int val) {
    if (root == nullptr) return root;

    if (val == root->val) {
        if (root->right == nullptr) {
            return root->left;
        }
        else {
            std::shared_ptr<TreeNode> minValueNode = root->right;
            while (minValueNode->left != nullptr) {
                minValueNode = minValueNode->left;
            }
            root->val = minValueNode->val;
            root->right = deleteNode(root->right, minValueNode->val);
        }
    }
    else if (val < root->val) {
        root->left = deleteNode(root->left, val);
    }
    else {
        root->right = deleteNode(root->right, val);
    }

    return root;
}

void TreeNode::printBinaryTree(shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return;
    };
    
    printBinaryTree(root->left);
    
    cout << root->val << " ";
    
    printBinaryTree(root->right);
}
