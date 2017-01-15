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
int searchBST(struct Tnode* root , int key)
{
  if(root==NULL )
    return 0;
  else if(root->data==key )
    return 1;
  else if(root->data > key)
      return searchBST(root->left , key);
  else if(root->data < key)
      return searchBST(root->right, key);

  }
  void BSTsearch(struct Tnode* root , int key){
    int x = searchBST(root , key);
    printf("\nSearching for the %d............\n",key);
    if(x==1)
    {
      printf("Congrates!! ,%d is prsent in the Tree!\n",key);
    }
    else{
       printf("Sorry!!! ,%d Is not Prsent in the TREE. Try Again!\n", key);
    }
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

    BSTsearch(root , 20);
    BSTsearch(root , 333);
    BSTsearch(root , 70);
    BSTsearch(root , 43);

    return 0;
}
