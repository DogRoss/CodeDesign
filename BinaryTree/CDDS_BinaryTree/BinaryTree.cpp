/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
//#include "TreeNode.h"
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
	while(m_pRoot != NULL)
	{
		Remove(m_pRoot->GetData());
	}
}

TreeNode* BinaryTree::GetRoot() {
	return m_pRoot;
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
	

	// if tree empty, value is inserted at root
	if (m_pRoot == nullptr)
	{
		m_pRoot = new TreeNode(a_nValue);			//sets root if null
	}
	else if(m_pRoot != nullptr)
	{//TODO: left right tree implementation

		TreeNode* currentNode = m_pRoot; //sets currently selected node to root
		//currentNode.SetLeft(m_pRoot->GetLeft());
		//currentNode.SetRight(m_pRoot->GetRight());

		TreeNode* valueNode = new TreeNode(a_nValue);

		//TODO:temp variables
		bool isNull = false;

		while (!isNull)
		{
			std::cout << "entered while state" << std::endl;
			if (a_nValue > currentNode->GetData()) //if value is greater than current node, right side node
			{
				std::cout << "entered first conditional" << std::endl;

				if (!currentNode->HasRight())
				{

					//TODO: debug console
					std::cout << "entered right check first conditional, break here (Success)" << std::endl;



					currentNode->SetRight(valueNode); //set tree node here
					break;
					
				}
				else {
					std::cout << "entered right check second conditional, check next one (Success)" << std::endl;
					currentNode = currentNode->GetRight(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());
				}
				
				
			}
			else if (a_nValue < currentNode->GetData()) //if value is less than current node, left side node
			{
				std::cout << "entered second conditional" << std::endl;

				if (!currentNode->HasLeft())
				{
					std::cout << "entered left check first conditional, break here (Success)" << std::endl;
					currentNode->SetLeft(valueNode); //set tree node here
					break;
				}
				else {
					std::cout << "entered right check second conditional, break here (Success)" << std::endl;
					currentNode = currentNode->GetLeft(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());
				}
				
			}
			else if (a_nValue == currentNode->GetData()) //if value is same as node, exit
			{
				std::cout << "entered third conditional, value already exists" << std::endl;
				currentNode->SetData(a_nValue);
				break;
			}

		}

		
	}
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
			if(a_nSearchValue == currentNode->GetData()) 
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

		std::cout << "before while called" << std::endl;

		while (!isNull)
		{
			std::cout << "entered while state" << std::endl;
			if (a_nValue > currentNode->GetData()) //if value is greater than current node, right side node
			{
				std::cout << "entered first conditional" << std::endl;

				if (!currentNode->HasRight())
				{

					//TODO: debug console
					std::cout << "error: number isnt present in tree" << std::endl;

					break;

				}
				else {
					std::cout << "entered right check second conditional, check next one (Success)" << std::endl;
					currentNode = currentNode->GetRight(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());

				}


			}
			else if (a_nValue < currentNode->GetData()) //if value is less than current node, left side node
			{
				std::cout << "entered second conditional" << std::endl;

				if (!currentNode->HasLeft())
				{
					std::cout << "entered left check first conditional, break here (Success)" << std::endl;
					break;
				}
				else {
					std::cout << "entered right check second conditional, break here (Success)" << std::endl;
					currentNode = currentNode->GetLeft(); //sets currently selected node to root
					currentNode->SetLeft(currentNode->GetLeft());
					currentNode->SetRight(currentNode->GetRight());
				}

			}


			else if (a_nValue == currentNode->GetData()) //if value is same as node, delete node
			{
				std::cout << "entered third conditional, begin deletion process" << std::endl;


				/*//if the value on the right is greater than the left, it gains priority
				if (currentNode->GetRight()->GetData() > currentNode->GetLeft()->GetData()) {
					//right side priority
					currentNode = currentNode->GetRight();
				}
				else {
					//left side priority
					currentNode = currentNode->GetLeft();
				}*/

				TreeNode* temp = currentNode;

				if (currentNode->HasLeft()) {
					currentNode = currentNode->GetLeft(); //sets the left side node to the removed node
					//if multiple right side nodes you might run into a problem 

					std::cout << "left node set, iterate through left-right nodes" << std::endl;
					
					bool shouldStop = false;
					int i = 0;
					while (!shouldStop) {
						i++;
						std::cout << "entering while loop, " << i << " loops" << std::endl;
						
						if (currentNode->GetRight()) { //TODO: get this to not break and throw a read access violation
							currentNode = currentNode->GetRight();
						}
						else if (currentNode->GetLeft()) {
							currentNode = currentNode->GetLeft();
						}
						else {
							std::cout << "neither left nor right node exist, breaking... (BinaryTree.cpp, line 278)" << std::endl;
							break;
						}


						
					}

				}
				else if(currentNode->HasRight()) { //if no left side

					currentNode = currentNode->GetRight(); //sets the left side node to the removed node
					//if multiple right side nodes you might run into a problem 

					std::cout << "left node set, iterate through left-right nodes" << std::endl;

					bool shouldStop = false;
					int i = 0;
					while (!shouldStop) {
						i++;
						std::cout << "entering while loop, " << i << " loops" << std::endl;

						if (currentNode->GetRight()) { //TODO: get this to not break and throw a read access violation
							currentNode = currentNode->GetRight();
						}
						else if (currentNode->GetLeft()) {
							currentNode = currentNode->GetLeft();
						}
						else {
							std::cout << "neither left nor right node exist, breaking... (BinaryTree.cpp, line 309)" << std::endl;
							break;
						}



					}
				}
				else {
					std::cout << "before break" << std::endl;
					delete currentNode;
					break;
				}
				
			}

			

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
	TreeNode* current = pNode;
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		//if (pNode->HasLeft())
		//{
		//	DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
		//	
		//	Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		//}
		//else if (pNode->HasRight())
		//{
		//	DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
		//
		//	Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		//}
		
		if (selected && pNode->m_value == selected->m_value) {
			pNode->Draw(x, y, (selected == pNode));
			return;
		}
		if (pNode->HasLeft()) {
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		if (pNode->HasRight()) {
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		

		pNode->Draw(x, y, (selected == pNode));



	}
}