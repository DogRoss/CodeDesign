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
		Remove(m_pRoot->GetData());
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

void BinaryTree::TraverseRight(TreeNode* &outStarting, TreeNode* &outParent) { //iterates throught right children of node until end of that node
	TreeNode* parent = outParent;
	TreeNode* current = outStarting;
	while (current->HasRight()) {
		parent = current;
		current = current->GetRight();
	}

	outStarting = current;
	outParent = parent;
}

void BinaryTree::TraverseLeft(TreeNode* &outStarting, TreeNode* &outParent) { //iterates throught left children of node until end of that node
	TreeNode* parent = outParent;
	TreeNode* current = outStarting;
	while (current->HasLeft()) {
		parent = current;
		current = current->GetLeft();
	}

	outStarting = current;
	outParent = parent;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent) //finds node of value and returns as outnode and outparent
{
	/*
	create a current node set to root
	check if value is greater or less than, and iterate based on it
	each iteration, change the parent to current, and current to current->next(based on value)
	when the value is found, return true, if not return fals
	*/
	
	TreeNode* parent = nullptr;
	TreeNode* current = m_pRoot;

	if (current == nullptr) {
		return false;
	}

	while (true) {
		
		if (a_nSearchValue > current->GetData()) { //if going right
			if (current->HasRight()) {
				parent = current;
				current = current->GetRight();
			}
			else {
				return false;
			}
		}
		else if (a_nSearchValue < current->GetData()) { //if going left
			if (current->HasLeft()) {
				parent = current;
				current = current->GetLeft();
			}
			else {
				return false;
			}
		}
		else { //if equal to
			ppOutParent = parent;
			ppOutNode = current;
			return true;
		}
	}

	return false;
}

void BinaryTree::Remove(int a_nSearchValue) {
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

	*/

	TreeNode* nodeToDelete;
	TreeNode* nTDParent;

	if (!FindNode(a_nSearchValue, nodeToDelete, nTDParent)){
		return;
	}

	if (nodeToDelete->HasRight()) {
		TreeNode* nTDRight = nodeToDelete->GetRight();
	}
	if (nodeToDelete->HasLeft()) {
		TreeNode* nTDLeft = nodeToDelete->GetLeft();
	}

	TreeNode* parent = nullptr;
	TreeNode* current = nullptr;

	if (FindNode(a_nSearchValue, current, parent)) { //if the data exists (current set to position of nodeToDelete)

		if (current->GetData() > m_pRoot->GetData()) { //if right of root
			if (current->HasRight()) { //favor right node from root first
				parent = current;
				current = current->GetRight(); //iterate right one

				if (current->HasLeft()) { //we are able to get the left most node from current
					TraverseLeft(current, parent);
					nodeToDelete->SetData(current->GetData());

					if (current->HasRight()) { //if the node we are replacing 
						parent->SetLeft(current->GetRight());
					}
					else {
						parent->SetLeft(nullptr);
					}

					delete current;
				}
				else { //if the current node doesnt have left nodes
					nodeToDelete->SetData(current->GetData());

					if (current->HasRight()) { //if it has a right node
						nodeToDelete->SetRight(current->GetRight());
					}
					else {
						nodeToDelete->SetRight(nullptr);
					}
				}
			}
			else if (current->HasLeft()) { //if right doesnt exist
				parent = current;
				current = current->GetLeft(); //iterate left one

				if (current->HasRight()) { //we are able to get the right most node from current
					TraverseRight(current, parent);
					nodeToDelete->SetData(current->GetData());

					if (current->HasLeft()) { //if the node we are replacing 
						parent->SetRight(current->GetLeft());
					}
					else {
						parent->SetRight(nullptr);
					}
					delete current;
				}
				else { //if the current node doesnt have right nodes
					nodeToDelete->SetData(current->GetData());

					if (current->HasLeft()) { //if it has a left node
						nodeToDelete->SetLeft(current->GetLeft());
					}
					else {
						nodeToDelete->SetLeft(nullptr);
					}
				}
			}
			else {
				if (nodeToDelete->GetData() > nTDParent->GetData()) { //right of parent
					nTDParent->SetRight(nullptr);
				}
				else if (nodeToDelete->GetData() < nTDParent->GetData()) { //left of parent
					nTDParent->SetLeft(nullptr);
				}
			}
		}
		else if (current->GetData() < m_pRoot->GetData()) { //if left of root
			if (current->HasLeft()) { //favor right node from root first
				parent = current;
				current = current->GetLeft(); //iterate right one

				if (current->HasRight()) { //we are able to get the left most node from current
					TraverseRight(current, parent);
					nodeToDelete->SetData(current->GetData());

					if (current->HasLeft()) { //if the node we are replacing 
						parent->SetRight(current->GetLeft());
					}
					else {
						parent->SetRight(nullptr);
					}

					delete current;
				}
				else { //if the current node doesnt have left nodes
					nodeToDelete->SetData(current->GetData());

					if (current->HasLeft()) { //if it has a right node
						nodeToDelete->SetLeft(current->GetLeft());
					}
					else {
						nodeToDelete->SetLeft(nullptr);
					}
				}
			}
			else if (current->HasRight()) { //if right doesnt exist
				parent = current;
				current = current->GetRight(); //iterate left one

				if (current->HasLeft()) { //we are able to get the right most node from current
					TraverseLeft(current, parent);
					nodeToDelete->SetData(current->GetData());

					if (current->HasRight()) { //if the node we are replacing 
						parent->SetLeft(current->GetRight());
					}
					else {
						parent->SetLeft(nullptr);
					}
					delete current;
				}
				else { //if the current node doesnt have right nodes
					nodeToDelete->SetData(current->GetData());

					if (current->HasRight()) { //if it has a left node
						nodeToDelete->SetRight(current->GetRight());
					}
					else {
						nodeToDelete->SetRight(nullptr);
					}
				}
			}
			else {
				if (nodeToDelete->GetData() > nTDParent->GetData()) { //right of parent
					nTDParent->SetLeft(nullptr);
				}
				else if (nodeToDelete->GetData() < nTDParent->GetData()) { //left of parent
					nTDParent->SetRight(nullptr);
				}
			}
		}
		else { //if it is root
			if (current->HasRight()) { //favor right node from root first
				parent = current;
				current = current->GetRight(); //iterate right one
				
				if (current->HasLeft()) { //we are able to get the left most node from current
					TraverseLeft(current, parent);
					m_pRoot->SetData(current->GetData());

					if (current->HasRight()) { //if the node we are replacing 
						parent->SetLeft(current->GetRight());
					}
					else {
						parent->SetLeft(nullptr);
					}

					delete current;
				}
				else { //if the current node doesnt have left nodes
					m_pRoot->SetData(current->GetData());

					if(current->HasRight()){ //if it has a right node
						m_pRoot->SetRight(current->GetRight());
					}
					else {
						m_pRoot->SetRight(nullptr);
					}
				}
			}
			else if(current->HasLeft()){ //if right doesnt exist
				parent = current;
				current = current->GetLeft(); //iterate left one

				if (current->HasRight()) { //we are able to get the right most node from current
					TraverseRight(current, parent);
					m_pRoot->SetData(current->GetData());

					if (current->HasLeft()) { //if the node we are replacing 
						parent->SetRight(current->GetLeft());
					}
					else {
						parent->SetRight(nullptr);
					}
					delete current;
				}
				else { //if the current node doesnt have right nodes
					m_pRoot->SetData(current->GetData());

					if (current->HasLeft()) { //if it has a left node
						m_pRoot->SetLeft(current->GetLeft());
					}
					else {
						m_pRoot->SetLeft(nullptr);
					}
				}
			}
			else { //if neither dont exist
				m_pRoot = nullptr;
			}
		}
	}
	else {
		std::cout << "ERROR: value doesnt exist, returning...";
		return;
	}

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