#include<bits/stdc++.h>
using namespace std;;

struct Tnode {
  int data;
struct Tnode* left;
struct Tnode* right;
};
struct Tnode* createT(int key)
{
  struct Tnode* t = (struct Tnode*)malloc(sizeof(struct Tnode));
  t->data= key;
  t->left=NULL;
  t->right=NULL;
  return t;
}
struct Tnode* insert(struct Tnode* root, int key)
{
  if(root==NULL)
      return createT(key);
  if(root->data > key)
      root->left=insert(root->left , key);
  else if(root->data < key)
      root->right=insert(root->right , key);
  return root;
}
struct Tnode* minimumValue(struct Tnode* root)
{
  struct Tnode* temp = root;
  while(temp->right!=NULL)
  {
       temp=temp->right;
  }
  return (temp);
}
struct Tnode* inorderSuccessor(struct Tnode* root , struct Tnode* n)
{
  struct Tnode* succ=NULL;
  if(root==NULL)
      return root;
  if(n->right!=NULL)
  {
     return minimumValue(n->right);
    //printf("The inorder Successor of %d id : = %d\n", key , x);
  }

  else
  {
    while(root!=NULL)
    {
      if(root->data > n->data)
      {
        succ = root;
        root=root->left;
      }
      else if(root->data < n->data){
        root = root->right;
      }
      else
          break;
    }
    return succ;
  }
}
void inorder(struct Tnode* root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf("%d \t", root->data);
  inorder(root->right);
}
int main()
{
  struct Tnode* root=NULL, *y, *x;
  root = insert(root, 20);
  insert(root, 8);
  insert(root, 22);
  insert(root, 4);
  insert(root, 12);
  insert(root, 10);
  insert(root, 14);
  inorder(root);
  x = root->left->right->right;
  y = inorderSuccessor(root , x);
  if(y!=NULL)
        printf("\nThe inorder Successor of %d is : %d\n ", x->data , y->data );
  else
        printf("There is no succeesor");
  return 0;
}
