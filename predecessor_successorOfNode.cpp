#include<bits/stdc++.h>
using namespace std;
//You need to find the inorder successor and predecessor of a given key.
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

struct Tnode* insertBST(struct Tnode* root , int key){
  if(root==NULL)
    return createT(key);
  else if(root->data > key)
        root->left = insertBST(root->left , key);
  else if(root->data < key)
        root->right = insertBST(root->right , key);
  return root; // unchanged pointer
}
int maxvaluePredecessor(struct Tnode* root)
{
  struct Tnode* temp=root;
  while(temp->right!=NULL){
    temp= temp->right;
  }
  return (temp->data);
}
int minvalueSuccessor(struct Tnode* root)
{
  struct Tnode* temp=root;
  while(temp->left!=NULL)
  {
    temp= temp->left;
  }
  return (temp->data);
}
struct Tnode* search(struct Tnode* root, int key)
{
  if(root==NULL || root->data==key)
      return root;
    if(root->data > key)
       search(root->left,key);
  else if(root->data < key)
       search(root->right, key);
}
void  predecessorSuccessor(struct Tnode* root, int key)
{
  struct Tnode* curr=search(root,key);
  int x = maxvaluePredecessor(curr->left);
  int y = minvalueSuccessor(curr->right);
  printf("Predecessor of %d is :\t%d\n", key, x);
  printf("Successor of %d is :\t%d\n", key, y);
}
void inorder(struct Tnode* root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d \t\n", root->data);
  inorder(root->right);
}
int main(){
  struct Tnode* root=insertBST(root ,20);
  insertBST(root ,30);
  insertBST(root ,10);
  insertBST(root,25);
  insertBST(root,40);
  insertBST(root,5);
  insertBST(root,15);
  inorder(root);
  predecessorSuccessor(root,10);
  predecessorSuccessor(root,20);

  return 0;
}
