#include<bits/stdc++.h>
using namespace std;

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
/*this is for finding the minimum value of the right subtree of that node
 it is basically INORDER SUCESSOR of that node*/
struct Tnode* minimumValue(struct Tnode* root)
{
  struct Tnode* curr=root;
  while(curr->left!=NULL)
      curr = curr->left;
  return curr;
}
struct Tnode* deleteBST(struct Tnode* root , int key)
{
  if(root==NULL)
      return root;
  else if (root->data > key)
    root->left = deleteBST(root->left, key);
  else if(root->data<key)
    root->right =  deleteBST(root->right, key);
  else{
      if(root->left == NULL){
        struct Tnode* temp = root->right;
          free(root);
          return temp;
       }
      else if(root->right==NULL){
        struct Tnode* temp = root->left;
        free(root);
        return temp;
      }
      else{
        struct Tnode* temp = minimumValue(root->right);
        root->data=temp->data;//copy temp data to the root node and then delete the temp node
        root->right=deleteBST(temp, temp->data);
      }
  }
  return root;
}
void inorder(struct Tnode* root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d \t", root->data);
  inorder(root->right);
}
int main(){
  struct Tnode* root=insertBST(root ,20);
  insertBST(root ,30);
  insertBST(root ,99);
  insertBST(root,90);
  insertBST(root,60);
  insertBST(root,70);
  insertBST(root,40);
  insertBST(root,21);
  inorder(root);

  root=deleteBST(root,20);
  printf("\n20 is deleted from the tree\n");
  inorder(root);
  printf("\n");
  root=deleteBST(root,99);
  printf("\n99 is deleted from the tree\n");
  inorder(root);
  printf("\n");
  root=deleteBST(root,70);
  printf("\n70 is deleted from the tree\n");
  inorder(root);
  printf("\n");
  root=deleteBST(root,60);
  printf("\n60 is deleted from the tree\n");
  inorder(root);
  printf("\n");
  root=deleteBST(root,21);
  printf("\n21 is deleted from the tree\n");
  inorder(root);
  printf("\n");
  return 0;
}
