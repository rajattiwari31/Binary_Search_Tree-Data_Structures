#include<bits/stdc++.h>
using namespace std;
//To find the lowest common ancestor of any two nodes which is prsent in the tree;
//for more about LOWEST COMMON ANCESTOR- https://en.wikipedia.org/wiki/Lowest_common_ancestor;
struct Tnode{
  int data;
  struct Tnode* left;
  struct Tnode* right;
};
struct Tnode* createT(int key){
  struct Tnode* t= (struct Tnode* )malloc(sizeof(struct Tnode));
  t->data = key;
  t->left=NULL;
  t->right = NULL;
  return t;
}
struct Tnode* insert(struct Tnode* root , int key)
{
  if (root==NULL)
      return createT(key);
  else if(root->data > key)
            root->left = insert(root->left , key);
  else if(root->data < key)
            root->right = insert(root->right , key);
  return root; // unchanged pointer
}

struct Tnode* lowestCommon(struct Tnode* root, int n1 , int n2)
{
  if(root==NULL)
      return root;
  if(root->data>n1 && root->data > n2)
        return(lowestCommon(root->left , n1 ,n2));
  else if(root->data < n1 && root->data < n2)
        return (lowestCommon(root->right , n1, n2));
  return root;
}
int main(){
  struct Tnode* root= insert(root , 20);
  insert(root,22);
  insert(root,8);
  insert(root,12);
  insert(root,10);
  insert(root,14);
  insert(root,4);
  
  int n1=10; int n2=14;
  struct Tnode* temp = lowestCommon(root , n1,n2);
  printf("LOWEST COMMON ANCESTOR of %d and %d is : %d\n", n1,n2,temp->data);

  n1=4;n2=10;
  temp = lowestCommon(root , n1,n2);
  printf("LOWEST COMMON ANCESTOR of %d and %d is : %d\n", n1,n2,temp->data);

  n1=8;  n2=14;
  temp = lowestCommon(root , n1,n2);
  printf("LOWEST COMMON ANCESTOR of %d and %d is : %d\n", n1,n2,temp->data);

   n1=22;  n2=20;
  temp = lowestCommon(root , n1,n2);
  printf("LOWEST COMMON ANCESTOR of %d and %d is : %d\n", n1,n2,temp->data);
  return 0;
}
