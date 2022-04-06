/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

class TreeNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool IsEmpty() const;
	void Insert(int a_nValue);
	void Remove(TreeNode* nodeToRemove);
	TreeNode* Find(int a_nValue);
	void TraverseRight(TreeNode* &outStarting, TreeNode*& outParent);
	void TraverseLeft(TreeNode* &outStarting, TreeNode* &outParent);

	void PrintOrdered();
	void PrintUnordered();

	void Draw(TreeNode* selected = nullptr);

private:
	//Find the node with the specified value.
	bool FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent);

	void Draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	//The root node of the tree
	TreeNode* m_pRoot;
};

#endif //_BINARYTREE_H_