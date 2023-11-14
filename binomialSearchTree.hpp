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
    
    static std::shared_ptr<TreeNode> insertIntoBST(std::shared_ptr<TreeNode> root, int val);

    std::shared_ptr<TreeNode> deleteNode(std::shared_ptr<TreeNode> root, int val);
    
    void printBinaryTree(std::shared_ptr<TreeNode> root);
    
};

#endif /* binomialSearchTree_hpp */
