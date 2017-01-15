//Insertion in Binary_Search_tree is done using Inorder
// as inorder traversal always gives sorted value
#include<bits/stdc++.h>
using namespace std;
struct Tnode{
  int data;
  struct Tnode* left;
  struct Tnode* right;
};
struct Tnode* CreateT(int data){
    struct Tnode* t = (struct Tnode*)malloc(sizeof(struct Tnode));
    t->data = data;
    t->left=t->right = NULL;
    return t;
}

struct Tnode*  insert(struct Tnode* root, int key){
    if(root==NULL)
      return CreateT(key);
    else if(root!=NULL && root->data > key )
        root->left = insert(root->left,key);
    else if(root!=NULL && root->data < key)
        root->right = insert(root->right, key);
     return root; //unchanged pointer
}
void inorder(struct Tnode* root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d \n", root->data);
  inorder(root->right);
}

int main(){
  struct Tnode* root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  inorder(root);
  return 0;
}
