#include<bits/stdc++.h>
using namespace std;
//To find whether a given binary tree is a BST or not.
//Time complexity O(n)
struct Tnode{
  int data;
  struct Tnode* left;
  struct Tnode* right;
};

struct Tnode* createT(int data)
{
  struct Tnode* t = (struct Tnode*)malloc(sizeof(struct Tnode));
  t->data=data;
  t->left=t->right=NULL;
  return t;
}
int isBSTmain(struct Tnode* root, int min , int max)
{
  if(root==NULL)
    return 1;
  if(root->data< min || root->data > max)
    return 0;
  return(isBSTmain(root->left , min , root->data -1) && isBSTmain(root->right, root->data +1, max));
}
int isBST(struct Tnode* root){
  return(isBSTmain(root,INT_MIN,INT_MAX));
}
int main(){
  struct Tnode* root=createT(5);
  root->left=createT(2);
  root->right=createT(8);
  root->left->left=createT(1);
  root->left->right=createT(4);
  root->right->left=createT(3);
  if(isBST(root))
      printf("Tree is BST!!\n");
  else
      printf("Tree is NOT BST!!\n");
  return 0;
}
