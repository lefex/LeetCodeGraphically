//
//  LEFTreeSubject.hpp
//  LeetCodeGraphically
//
//  Created by wsy on 2019/6/2.
//  Copyright © 2019 WSY. All rights reserved.
//

#ifndef LEFTreeSubject_hpp
#define LEFTreeSubject_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LEFTreeSubject {
public:
    vector<int> result;

    // 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return result;
        }
        // 递归遍历左子树
        inorderTraversal(root->left);
        result.push_back(root->val);
        // 递归遍历右子树
        inorderTraversal(root->right);
        return result;
    }
    // 前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return result;
        }
        result.push_back(root->val);
        // 递归遍历左子树
        preorderTraversal(root->left);
        // 递归遍历右子树
        preorderTraversal(root->right);
        return result;
    }
    // 后续遍历
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return result;
        }
        // 递归遍历左子树
        postorderTraversal(root->left);
        // 递归遍历右子树
        postorderTraversal(root->right);
        result.push_back(root->val);
        return result;
    }
    // 层次遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelResult;
        // 用来暂存数据
        queue<TreeNode *> q;
        
        if (root == NULL) {
            return levelResult;
        }
        // 先存储根节点，每一层的结束用 NULL 分割
        q.push(root);
        q.push(NULL);
        // 当前层的节点
        vector<int> cur_vec;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL) {
                // 一层遍历结束了
                levelResult.push_back(cur_vec);
                // 重置 cur_vec
                cur_vec.resize(0);
                if (q.size() > 0) {
                    // 插入层的分割
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(cur->val);
                // 当前节点的左右节点入队
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        
        return levelResult;
    }
    // 之字形遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelResult;
        // 用来暂存数据
        queue<TreeNode *> q;
        
        if (root == NULL) {
            return levelResult;
        }
        // 先存储根节点，每一层的结束用 NULL 分割
        q.push(root);
        q.push(NULL);
        // 当前层的节点
        vector<int> cur_vec;
        bool isLeft = true;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL) {
                // 一层遍历结束了
                levelResult.push_back(cur_vec);
                // 重置 cur_vec
                cur_vec.resize(0);
                if (q.size() > 0) {
                    // 插入层的分割
                    q.push(NULL);
                    isLeft = !isLeft;
                }
            } else {
                if (isLeft) {
                    cur_vec.push_back(cur->val);
                } else {
                    cur_vec.insert(cur_vec.begin(), cur->val);
                }
                // 当前节点的左右节点入队
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        
        return levelResult;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};




class PrintTree {
public:
    vector<vector<string>> printTree(TreeNode* root){
        
        vector<vector<string>> res;
        
        //
        // create table of empty strings ""
        // based on the tree height/width
        //
        int depth = maxDepth(root);
        int width = pow(2, depth+1) - 1;
        vector<string> row (width, "");
        for (int i=0; i <= depth; i++){
            res.push_back(row);
        }
        
        //
        // traverse the tree and fill in table values for non-NULL nodes
        //
        fillTable(root, 0, 0, width-1, res);
        return res;
    }
    
private:
    int maxDepth(TreeNode* node){
        if (!node) {
            return -1;
        }
        
        int leftDepth = -1;
        if (node->left) {
            leftDepth = maxDepth(node->left);
        }
        
        int rightDepth = -1;
        if (node->right) {
            rightDepth = maxDepth(node->right);
        }
        
        return 1 + max( leftDepth, rightDepth );
    }
    
    void fillTable(TreeNode* node, int depth, int start, int end, vector<vector<string>>& table){
        if (!node) { return; }
        
        int mid = (int)(start+end)/2;
        table[depth][mid] = to_string(node->val);
        
        if (node->left)  { fillTable(node->left,  depth+1, start, mid-1, table); }
        if (node->right) { fillTable(node->right, depth+1, mid+1, end,   table); }
    }
    
    
};



#endif /* LEFTreeSubject_hpp */
