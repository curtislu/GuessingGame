//
//   Name:       Lu, Curtis
//   Due:        11/29/12
//   Course:     CSCI-133C
//
//   Description:
//      File name: DecisionTree.h
//      prototypes for Class DecisionTree
//   Compiler: Microsoft Visual Studio 2010 C++ 32-bit
//
#ifndef DECISIONTREE_H
#define DECISIONTREE_H

#include<iostream>
#include <string>

using namespace std;

class DecisionTree
{
   struct Node{
      string data; // questions / answers
      Node *left; // yes
      Node *right; // no
      int answer; // key to move down binary tree
   };
   Node *root;

public:
   DecisionTree() { root = NULL; }
   ~DecisionTree(){  remove(root->answer); }
   bool isEmpty() const { return root == NULL; }
   void remove(int d);
   void insert(string q_and_a, int decide);
   void build_tree();
   void decide(Node* ptr);
   void play();
};

#endif // DECISIONTREE_H
