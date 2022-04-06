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
	TreeNode* insertNode = new TreeNode(a_nValue);

	TreeNode* current = nullptr;

	/*
	check if root is nullptr, if so insert and return
	if not:
	check if the value is greater or less than the root node
	if so: iterate right and use a while to continue iterating until a empty node at the correct position is reached. return.
	if not: iterate left and use a while to continue iterating until a empty node at the correct position is reached. return.
	do a final check to see if the value is already in the tree. return;
	*/
	if (m_pRoot == nullptr) { //checks if root doesnt exist, if so, insert and return
		m_pRoot = insertNode;
		return;
	}
	else {
		current = m_pRoot;
		if (insertNode->GetData() == m_pRoot->GetData()) { //if its the root, return as the value is existant
			std::cout << "ERROR: number exists in tree, returning..." << std::endl;
			return;
		}
		else if (insertNode->GetData() > m_pRoot->GetData()) { //if right of root
			current = current->GetRight();
			while (true) { //iterates through until correct position is reached
				if (insertNode->GetData() == current->GetData()) {
					std::cout << "ERROR: number exists in tree, returning..." << std::endl;
					return;
				}
				else if (insertNode->GetData() > current->GetData()) { //if right of current
					if (current->HasRight()) {		//if it has a right, iterate, if not then break
						current = current->GetRight();
					}
					else {
						break;
					}
				}
				else { //if left of current
					if (current->HasLeft()) {		//if it has a left, iterate, if not then break
						current = current->GetLeft();
					}
					else {
						break;
					}
				}
			} 
		}
		else { //if to the left
			current = current->GetLeft();
			while (true) { //iterates through until correct position is reached
				if (insertNode->GetData() == current->GetData()) {
					std::cout << "ERROR: number exists in tree, returning..." << std::endl;
					return;
				}
				else if (insertNode->GetData() > current->GetData()) { //if right of current
					if (current->HasRight()) {		//if it has a right, iterate, if not then break
						current = current->GetRight();
					}
					else {
						break;
					}
				}
				else { //if left of current
					if (current->HasLeft()) {		//if it has a left, iterate, if not then break
						current = current->GetLeft();
					}
					else {
						break;
					}
				}
			}
		}

		if (insertNode->GetData() > current->GetData()) {
			current->SetRight(insertNode);
		}
		else {
			current->SetLeft(insertNode);
		}
	}

}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

TreeNode* BinaryTree::TraverseRight(TreeNode* startingPoint) { //iterates throught right children of node until end of that node
	TreeNode* current = startingPoint;
	while (current->HasRight()) {
		current = current->GetRight();
	}

	return current;
}

TreeNode* BinaryTree::TraverseLeft(TreeNode* startingPoint) { //iterates throught left children of node until end of that node
	TreeNode* current = startingPoint;
	while (current->HasLeft()) {
		current = current->GetLeft();
	}

	return current;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	/*
	
	*/
	return false;
}

void BinaryTree::Remove(TreeNode* nodeToDelete) {
	/*
	Save the left and right node of the node to delete with a ptr node
	create new nodes for iterating (parent and current, as well as currentLeft and currentRight)
	set current node to nodeToDelete, and set parent to null

	(1)check if current is root
	if so:
		(2)check if right node exists
		if so:
			set current to right then:
				(3)check if left node exists
				if so:
					use a traverse function to go to the left most node
					save that nodes left and right as well as itself(in current,currentLeft,currentRight)

				if not:
		if not:
	if not:






	else if (insertNode->GetData() > m_pRoot->GetData()) { //if right of root
			current = current->GetRight(); //iterates right one
			while (!current->HasLeft() && current->HasRight()) { //checks if there ISNT a left node and IS a right node, as long as the check returns true, iterate right
				if (current->HasRight()) {
					current = current->GetRight();
				}

			} //when a left is found or no more right exists, leave loop

			current = TraverseLeft(current); //traverse all the way to the left

		}
		else { //if to the left
			current = current->GetLeft(); //iterate left one
			while (!current->HasRight() && current->HasLeft()) { //checks if there ISNT a right node and IS a left node, as long as the check returns true, iterate left
				if (current->HasLeft()) {
					current = current->GetLeft();
				}
			} //when right is found or no more left exists, leave loop

			current = TraverseRight(current); //traverse all the way to the right
		}
	*/

	TreeNode* nTDRight = nodeToDelete->GetRight();
	TreeNode* nTDLeft = nodeToDelete->GetLeft();
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