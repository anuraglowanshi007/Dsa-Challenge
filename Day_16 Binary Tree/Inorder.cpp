#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Inorder Traversal Codee 

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

void printInorder(node*node){
      if(node == NULL){
            return;
      }
      
      //print left 
      printInorder(node->left);
     
      //print data 
      cout<<node->data<<" ";
      
      //print right 
      printInorder(node->right);


}

int main(){
      node*root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);

      printInorder(root);

      /*
           1
         /   \
        2     3
       / \
      4   5

      */

     // Output - Inorder Traversal = 4 2 5 1 3       
}