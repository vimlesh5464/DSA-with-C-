#include<iostream>
using namespace std;
class TreeNode{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data){
    this->data=data;
    right=left=nullptr;
  }
};
int size(TreeNode* root){
  if(root==NULL){
    return 0;
  }
  return 1 + size(root->left) + size(root->right);
}

int main(){
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << size(root);
    return 0;
}