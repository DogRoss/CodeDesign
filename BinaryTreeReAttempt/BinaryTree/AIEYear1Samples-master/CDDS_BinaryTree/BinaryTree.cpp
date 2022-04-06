/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot);
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	/*
	check if root is nullptr, if so insert and return
	if not:
	check if the value is greater or less than the root node
	if so: iterate right and use a while to continue iterating until a empty node at the correct position is reached. return.
	if not: iterate left and use a while to continue iterating until a empty node at the correct position is reached. return.
	do a final check to see if the value is already in the tree. return;
	*/
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	/*
	
	*/
}

void BinaryTree::Remove(TreeNode* nodeToDelete) {
	/*
	Save the left and right node of the node to delete with a ptr node
	create new nodes for iterating (parent and current)
	set current node to nodeToDelete, and set parent to null

	check if current is root
	if so:
	check if right node exists
		if so:
		set current to right then:
		use a traverse function 
		if not:
	if not:

	*/
}

/*
void BinaryTree::Remove(int a_nValue)
{
	TreeNode* parentNode; //nodes of removal
	TreeNode* valueNode;

	TreeNode* previous; //iterating nodes
	TreeNode* current;

	FindNode(a_nValue, valueNode, parentNode); //finds nodes from value

	current = valueNode; //iterating starting point
	previous = parentNode;
	if (valueNode == GetRoot()) {
		valueNode->SetLeft(GetRoot());
		m_pRoot = valueNode;
		return;
	}
	if (current->HasRight()) {
		previous = previous->GetRight();
		current = current->GetRight();

		while (true) {
			if (current->HasLeft()) {
				previous = current->GetLeft();
				current = current->GetLeft();
			}
			else {
				break;
			}
		}

		valueNode->SetData(current->GetData());

		if (valueNode == parentNode->GetLeft()) {
			parentNode->SetLeft(current->GetRight());
		}
		else if (valueNode == parentNode->GetRight()) {
			parentNode->SetRight(current->GetRight());
		}

	}
	else {
		if (valueNode == parentNode->GetLeft()) {
			parentNode->SetLeft(current->GetLeft());
		}
		else if (valueNode == parentNode->GetRight()) {
			parentNode->SetRight(current->GetLeft());
		}
	}
}
*/

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}