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
	
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	// if tree empty, value is inserted at root
	if (m_pRoot == nullptr)
	{
		std::cout << "no numbers present on tree" << std::endl;
	}
	else if (m_pRoot != nullptr)
	{//TODO: left right tree implementation

		TreeNode* currentNode = m_pRoot; //sets currently selected node to root

		//TODO:temp variables
		bool isNull = false;

		while (!isNull)
		{
			std::cout << "entered while state" << std::endl;
			if (a_nSearchValue == currentNode->GetData())
			{
				ppOutNode = currentNode;
				break;
			}
			else if (a_nSearchValue > currentNode->GetData()) {
				if (currentNode->HasRight()) {
					currentNode = currentNode->GetRight(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());
				}
				else {
					std::cout << "error: number isnt present in tree" << std::endl;

					break;
				}
			}
			else if (a_nSearchValue < currentNode->GetData()) {
				if (currentNode->HasRight()) {
					currentNode = currentNode->GetLeft(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());
				}
				else {
					std::cout << "error: number isnt present in tree" << std::endl;

					break;
				}
			}
		}


	}

	return false;
}

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

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

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