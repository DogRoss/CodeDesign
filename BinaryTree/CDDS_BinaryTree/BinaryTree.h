/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "TreeNode.h"

class TreeNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	TreeNode* GetRoot();

	bool IsEmpty() const;
	void Insert(int a_nValue);
	//void Remove(int a_nValue);
	void Remove(TreeNode*& nodeToRemove);
	TreeNode* Find(int a_nValue);

	void TraverseRight(TreeNode* &startingPoint, TreeNode* &startingParent);
	void TraverseLeft(TreeNode* &startingPoint, TreeNode* &startingParent);

	void PrintOrdered();
	void PrintUnordered();

	void Draw(TreeNode* selected = nullptr);

	//The root node of the tree
	TreeNode* m_pRoot;


private:
	//Find the node with the specified value.
	bool FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent);

	//Used to recurse through the nodes in value order and print their values.
	void PrintOrderedRecurse(TreeNode*);
	void PrintUnorderedRecurse(TreeNode*);


	void Draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

};

#endif //_BINARYTREE_H_