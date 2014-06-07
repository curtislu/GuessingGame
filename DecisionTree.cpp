//
//   Name:       Lu, Curtis
//   Due:        11/29/12
//   Course:     CSCI-133C
//
//   Description:
//      File name: DecisionTree.cpp
//      This file holds the following member functions:
//      remove, insert, build_tree, decide, and play
//      
//   Compiler: Microsoft Visual Studio 2010 C++ 32-bit
//
#include "decisiontree.h"

void DecisionTree::remove(int d)
{
   bool found = false;
   if(isEmpty())
   {
      cout << "This Tree is empty! " << endl;
      return;
   }

   Node *curr;
   Node* parent;
   curr = root;
   while(curr != NULL)
   {
      if(curr->answer == d)
      {
         found = true;
         break;
      }
      else
      {
         parent = curr;
         if(d > curr->answer) curr = curr->right;
         else curr = curr->left;
      }
   }
   if(!found)
   {
      cout << "Data not found! " << endl;
      return;
   }

   if((curr->left == NULL && curr->right != NULL) ||
      (curr->left != NULL && curr->right == NULL))
   {
      if(curr->left == NULL && curr->right != NULL)
      {
          if(parent->left == curr)
          {
             parent->left = curr->right;
             delete curr;
          }
          else
          {
             parent->right = curr->right;
             delete curr;
          }
      }
      else
      {
         if(parent->left == curr)
         {
            parent->left = curr->left;
            delete curr;
         }
         else
         {
            parent->right = curr->left;
            delete curr;
         }
      }
      return;
   }

   if(curr->left == NULL && curr->right == NULL)
   {
      if(curr->left == curr)
         parent->left = NULL;
      else
         parent->right = NULL;
      delete curr;
      return;
   }

   if(curr->left != NULL && curr->right != NULL)
   {
      Node *check;
      check = curr->right;
      if((curr->left == NULL) && (check->right == NULL))
      {
         curr = check;
         delete check;
         curr->right = NULL;
      }
      else
      {
         if((curr->right)->left != NULL)
         {
            Node *lcurr;
            Node *lcurrp;
            lcurrp = curr->right;
            lcurr = (curr->right)->left;
            while(lcurr->left != NULL)
            {
               lcurrp = lcurr;
               lcurr = lcurr->left;
            }
            curr->data = lcurr->data;
            delete lcurr;
            lcurrp->left = NULL;
         }
         else
         {
            Node *temp;
            temp = curr->right;
            curr->data = temp->data;
            curr->right = temp->right;
            delete temp;
         }
      }
      return;
   }
}

void DecisionTree::insert(string q_and_a, int decide)
{
   Node *tree = new Node;
   Node *parent;
   tree->data = q_and_a;
   tree->left = NULL; 
   tree->right = NULL;
   tree->answer = decide;
   parent = NULL;

   if(isEmpty())
   {
      root = tree;
   }
   else
   {
	  //Entries are as leaf nodes
      Node *current_ptr;
      current_ptr = root;
      while(current_ptr) //Find Node parent
      {
         parent = current_ptr; //Update parent node
         if(tree->answer > current_ptr->answer)
            current_ptr = current_ptr->right;
         else
            current_ptr = current_ptr->left;
      }

	  if(tree->answer < parent->answer)
         parent->left = tree;
      else
         parent->right = tree;
   }
}

void DecisionTree::build_tree()
{
   string question[] = {"It's a \"Monkey\"", "Is it closely related to the human race? (y/n): ",
                        "It's a \"Rabbit\"", "Is hopping required for mobility? (y/n): ", 
                        "It's a \"Dog\"", "Is it a domestic animal? (y/n): ", 
                        "It's a \"Tigger\"", "Does it have fur? (y/n): ", 
                        "It's a \"Dragon\"", "Does it have scales? (y/n): ",
                        "It's a \"Lady Bug\"", "Can it fly? (y/n): ",
                       "It's a \"Chicken\"", "Does it have wings? (y/n): ",
                        "It's a \"Horse\"", "Does it have hooves? (y/n): ",
                        "It's a \"Cow\"", "Does it have utters? (y/n): ",
                        "It's a \"Pig\"", "Does it have legs? (y/n): ",
                        "It's a \"Whale\"", "Does it appear large in mass? (y/n): ",
                        "It's a \"Flying Fish\"", "Can it fly? (y/n): ",
                        "It's a \"Crab\"", "Can it swim? (y/n): ", "It's a \"Snake\"", 
                        "Does it use its sense of smell to see? (y/n): ",
                        "It's a \"Worm\"" };
   int key[] = { 20, 8, 26, 4, 14, 22, 28, 2, 6, 10, 16, 21, 24, 27, 29, 
	             1, 3, 5 , 7, 9, 12, 15, 18, 23, 25, 11, 13, 17, 19 };

   for(int i = 0 ; i < (sizeof(question)/sizeof(string)); i++)
   {
      insert(question[key[i]-1], key[i]);
   }
   return;
}

void DecisionTree::decide(Node* ptr)
{
	char input;	
	if(ptr->left == NULL && ptr->right == NULL)
	   cout << ptr->data;
	else
	{
		cout << ptr->data;
		input = cin.get();
		while(input != 'y' && input != 'n')
		   input = cin.get();
		cin.sync(); //flush input 
		if (input == 'n')
			decide(ptr->right);
		else
			decide(ptr->left);
	}
	return;
}
void DecisionTree::play()
{
	decide(root);
}