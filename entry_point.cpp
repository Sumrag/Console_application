
// : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream> 
using namespace std; 


class TNode
{
public:
	int data;
	TNode *left;
	TNode *right;
 
	TNode(int n){ data = n; left = right = NULL; } 
	TNode(int n, TNode *left_pointer, TNode *right_pointer){ data = n; left = left_pointer; right = right_pointer; } //3 parameter constructor 

};

// The bstcopy creates a copy of the tree t and returns a pointer to the root of the copy. 
TNode* bstcopy(TNode* t)
{
	if (t == NULL)
	{
		return NULL;
	}
	TNode* root = new TNode(t->data,bstcopy(t->left),bstcopy(t->right));
	
	
	return root;
}


class BST 

{
	private: TNode *root; 

	public: 
		BST () ; //empty constructor 
		BST(BST&); //copy constructor 
		void insert (int) ; 
		void print_BST(); // Prints the BST tree
		 
}; 

//function prototype
// insert_bottom inserts a node a the bottom of the tree by traversing the tree
void insert_bottom(int ,TNode*);
// Print_tree prints the data in each node by traversing the tree from top to bottom
void print_tree(TNode *);

//BST constructor defines root as NULL  
BST::BST() {
	cout << "Regular Constructor Called\n";
	root = NULL;
	} ;

//BST copy constructor that returns either NULL or the copy of the BST tree
BST::BST(BST &oBST){ 

	cout << "Copy Constructor Called\n";
	if (oBST.root == NULL){
		root=NULL; 
		return ; 
	}
	
	else {
	root  = bstcopy(oBST.root) ;

	}

	return ;
} 

// print_BST prints a BST tree by calling print_tree 
void BST::print_BST(){
	print_tree(root); 
}  

// insert method that inserts new data into the tree. if the root is null it creates a new node. 
void BST::insert( int t ) {

	if (root ==NULL){
		root = new TNode(t); 
	}
	else 
		insert_bottom(t,root); 
}

/*If the root is NULL this function creates a new node. If it is not NULL then it seperates it so the left node 
is a smaller value of t and right node is the larger value of t
*/ 
void insert_bottom(int t,TNode* troot){
		if (troot==NULL)
		{ 
			troot = new TNode(t);
				return; 
		}
		if(t < troot->data) 
		{
			if(troot->left == NULL){
				troot->left = new TNode(t);
			}
			else
			insert_bottom(t,troot->left); 
		}
		else {
			if(troot->right == NULL){
				troot->right = new TNode(t);
			}
			else
			insert_bottom(t,troot->right); 
		}

	return;
	};

// Print_tree prints the data in each node by traversing the tree from top to bottom

void print_tree(TNode *ptr_tree)
{
	if (ptr_tree == NULL) return;

	cout << ptr_tree->data;	// Print the node data
	cout << "\n";

	if (ptr_tree->left != NULL)	// Check the left node and if not NULL, recursively call the function to print it
	{
		cout << "Left: ";
		print_tree(ptr_tree->left);
	}

	if (ptr_tree->right != NULL)  //Check the right node and if not NULL, recursively call the function to print it
	{
		cout << "Right: ";
		print_tree(ptr_tree->right);
	}

	
}
/* 
The main fuction inserts data using the insert method
The t.print_BST prints the first BST Object
Then the object is copied to a new object so that copy constructor is invoked
newBST.print_BST prints the new BST tree  
*/

	int main () 
{

	BST t; 
	t.insert(10) ; 
	t.insert(5) ; 
	t.insert (30); 
	t.insert (15); 
	t.insert (21); 
	t.insert (13); 

	t.print_BST(); 

	BST newBST = t;

	newBST.print_BST();
} ;
