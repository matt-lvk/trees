//
//  binomialSearchTree.hpp
//  trees
//
//  Created by Matthew liew on 13.11.23.
//

#ifndef binomialSearchTree_hpp
#define binomialSearchTree_hpp

#include <iostream>
#include <memory>
#include <utility>

class TreeNode {
public:
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    std::shared_ptr<TreeNode> searchBST(std::shared_ptr<TreeNode> root, const int& val);
    
    //static std::shared_ptr<TreeNode> insertIntoBST(std::shared_ptr<TreeNode> root, int val);

    void insertIntoBST(int val) {
        insertIntoBSTHelper(*this, val);
    }
    
    template <class T>
    void printBinaryTree(T root);

private:
    static std::shared_ptr<TreeNode> insertIntoBSTHelper(TreeNode& root, int val)
     {
        if (root.val == 0) {
            root.val = val;
            return std::make_shared<TreeNode>(val);
        }

        if (val < root.val) {
            if (root.left == nullptr) {
                root.left = std::make_shared<TreeNode>(val);
                return root.left;
            }
            else {
                return insertIntoBSTHelper(*root.left, val);
            }
        }
        else {
            if (root.right == nullptr) {
                root.right = std::make_shared<TreeNode>(val);
                return root.right;
            } 
            else {
                return insertIntoBSTHelper(*root.right, val);
            }
        }
    }
    
};

#endif /* binomialSearchTree_hpp */
