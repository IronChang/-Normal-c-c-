/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *arr = NULL;
int size = 0;

void _postorderTraversal(struct TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    
    //µÝ¹é±éÀú×óÓÒ×ÓÊ÷
    _postorderTraversal(root->left);
    _postorderTraversal(root->right);
    
    arr[size++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    arr = (int*)malloc(sizeof(int)*10000);
    size = 0;
    
    _postorderTraversal(root);
    
    *returnSize = size;
    return arr;
}


