#include<iostream>
using namespace std;

// PreOrder Traversal code 

struct node{
      int data;
      node*left;
      node*right;
};

node*newNode(int data){
      node*element = new node();
      element->data = data;
      element->left = NULL;
      element->right = NULL;
      
      return element;
}

void printPreorder(node*node){
      if (node == NULL)
         return;

         //print Root 
         cout<<node->data<<" ";

         // left side 
         printPreorder(node->left);

         //right side 
         printPreorder(node->right);
}


int main(){
      node*root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);

      printPreorder(root);

      /*
          1
         / \
       2    3
      / \
     4   5

      */
//      outPut  PreOrder = 1 2 4 5 3

}