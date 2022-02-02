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
	

	// if tree empty, value is inserted at root
	if (m_pRoot == nullptr)
	{
		m_pRoot = new TreeNode(a_nValue);			//sets root if null
	}
	else if(m_pRoot != nullptr)
	{//TODO: left right tree implementation

		TreeNode currentNode = TreeNode(m_pRoot->GetData()); //sets currently selected node to root
		currentNode.SetLeft(m_pRoot->GetLeft());
		currentNode.SetRight(m_pRoot->GetRight());

		TreeNode* valueNode = new TreeNode(a_nValue);

		//TODO:temp variables
		bool isNull = false;

		while (!isNull)
		{

			if (a_nValue > currentNode.GetData()) //if value is greater than current node, right side node
			{
				//TODO: debug console
				std::cout << "RightNodeCheck Successful, Value is Higher than current data" << std::endl;

				if (!currentNode.HasRight())
				{

					//TODO: debug console
					std::cout << "entered check" << std::endl;

					currentNode.SetRight(valueNode); //set tree node here
					
				}
				else {
					currentNode = TreeNode(currentNode.GetRight()->GetData()); //sets currently selected node to root
					currentNode.SetLeft(currentNode.GetLeft());
					currentNode.SetRight(currentNode.GetRight());
				}
				
			}
			else if (a_nValue < currentNode.GetData()) //if value is less than current node, left side node
			{
				//TODO: debug console
				std::cout << "LeftNodeCheck Successful, Value is lower than current data" << std::endl;

				if (currentNode.HasLeft())
				{
					currentNode = TreeNode(currentNode.GetLeft()->GetData()); //sets currently selected node to root
					currentNode.SetLeft(currentNode.GetLeft());
					currentNode.SetRight(currentNode.GetRight());
				}
				
			}
			else if (a_nValue == currentNode.GetData()) //if value is same as node, exit
			{
				std::cout << "Value already exists within tree" << std::endl;
				break;
			}

		}

		////TODO: Finish left right node checks
		//if (m_pRoot->GetLeft() == nullptr) //if the nodes left side isnt taken
		//{
		//	m_pRoot->SetLeft(new TreeNode(a_nValue));
		//
		//}
		//else if (m_pRoot->GetRight() == nullptr)
		//{
		//	m_pRoot->SetRight(new TreeNode(a_nValue));
		//
		//}

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


	return false;
}

void BinaryTree::Remove(int a_nValue)
{

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