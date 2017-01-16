#include<bits/stdc++.h>
using namespace std;
struct Tnode
{
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
void minimumBST(struct Tnode* root)
{
  if(root==NULL)
      return ;
  struct Tnode* temp = root;
  while(temp->left!=NULL)
    {
      temp = temp->left;
    }
   printf("%d is the minimum no. in the tree\n", temp->data);
}
int main(){
  struct Tnode* root=insertBST(root ,44);
  insertBST(root ,69);
  insertBST(root ,99);
  insertBST(root,90);
  insertBST(root,58);
  insertBST(root,70);
  insertBST(root,57);
  insertBST(root,911);
  minimumBST(root);
  return 0;
}
