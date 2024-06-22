#include<iostream>
using namespace std;

// Code for the post order Traversal 

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

void printPostOrder(node*node){
      
      if(node== NULL){
            return;
      }

      // for left side 
      printPostOrder(node->left);

      //for right side 
      printPostOrder(node->right);

      //for root data 
      cout<<node->data<<" ";
}

int main(){
      node*root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);

      printPostOrder(root);

      /* 
        1
        / \
       2   3 
      / \
      4  5
      
      */

//      outPut PostOrder  = 4 5 2 3 1

}