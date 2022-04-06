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

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* iCurrent;
	TreeNode* newNode = new TreeNode(a_nValue);
	TreeNode* iParent = nullptr;

	iCurrent = m_pRoot;

	if (BinaryTree::IsEmpty()) {
		m_pRoot = newNode;
		return;
	}
	while (iCurrent != nullptr) {
		if (a_nValue < iCurrent->GetData()) {
			std::cout<< "went left" <<std::endl;
			iParent = iCurrent;
			iCurrent = iCurrent->GetLeft();
		}
		else if (a_nValue > iCurrent->GetData()) {
			std::cout << "went right" << std::endl;

			iParent = iCurrent;
			iCurrent = iCurrent->GetRight();
		}
		else if (a_nValue == iCurrent->GetData()) {
			std::cout << "already exists" << std::endl;

			iParent = iCurrent;
			return;
		}

	}
	
	if (iParent->GetData() > a_nValue) {
		iParent->SetLeft(newNode);
		return;
	}
	else {
		iParent->SetRight(newNode);
		return;
	}

}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr; 
}

void BinaryTree::TraverseRight(TreeNode* &startingPoint, TreeNode*& startingParent)
{
	while (true) {
		if (startingPoint->HasRight()) {
			startingParent = startingPoint;
			startingPoint = startingPoint->GetRight();
		}
		else {
			break;
		}
	}
}

void BinaryTree::TraverseLeft(TreeNode* &startingPoint, TreeNode*& startingParent)
{
	
	while (true) {
		if (startingPoint->HasLeft()) {
			startingParent = startingPoint;
			startingPoint = startingPoint->GetLeft();
		}
		else {
			break;
		}
	}
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	TreeNode* current = m_pRoot;
	TreeNode* parent = nullptr;

	while (current != nullptr) {
		if (a_nSearchValue == current->GetData()) {
			ppOutNode = current;
			ppOutParent = parent;

			return true;
		}
		else {
			if (a_nSearchValue < current->GetData()) {
				parent = current;
				current = current->GetLeft();
			}
			else {
				parent = current;
				current = current->GetRight();
			}
		}
	}
	return false;
}

/*
void BinaryTree::Remove(int a_nValue)
{
	TreeNode* rCurrent = nullptr;
	TreeNode* rParent = nullptr;

	bool run = FindNode(a_nValue, rCurrent, rParent);
	TreeNode* current;


	current = rCurrent;

	if (run == false) {
		return;
	}
	else {
		if (rCurrent == m_pRoot) {
			if (m_pRoot->HasLeft()) {
				if (m_pRoot->GetLeft() != nullptr) {
					//m_pRoot = m_pRoot->GetLeft();
					m_pRoot->SetData(m_pRoot->GetLeft()->GetData());

					if (m_pRoot->GetLeft()->HasLeft()) {
						m_pRoot->SetLeft(m_pRoot->GetLeft()->GetLeft());
					}

				}
			}
			else if(m_pRoot->HasRight()){
				if (m_pRoot->GetRight() != nullptr) {
					//m_pRoot = m_pRoot->GetRight();
					m_pRoot->SetData(m_pRoot->GetRight()->GetData());

					if (m_pRoot->GetRight()->HasRight()) {
						m_pRoot->SetRight(m_pRoot->GetRight()->GetRight());
					}

				}
			}
			else {
				m_pRoot = nullptr;
			}

		}
		else if (rCurrent->HasRight()) {

			while (current->HasLeft()) { //finds minimum node
				if (current->HasLeft()) {
					current = current->GetLeft();
				}
			}

			current = current->GetLeft();
			if (rParent != nullptr && rParent->GetLeft() == rCurrent) {
				rParent->SetLeft(current);
				current->SetLeft(nullptr);
			}
			else {
				
				rParent->SetRight(current);
				
				current->SetLeft(nullptr);
			}
		}
		else if (rParent->GetLeft() == current) {
			rParent->SetLeft(current->GetRight());
		}
		else if (rParent->GetRight() == current) {
			rParent->SetRight(current->GetLeft());
		}
		
		
	}
	

}

//
TreeNode* rCurrent = nullptr;
	TreeNode* rParent = nullptr;

	bool run = FindNode(a_nValue, rCurrent, rParent);
	TreeNode* current;
	TreeNode* parent = nullptr;


	current = rCurrent;

	if (current == m_pRoot) { //if root
		cout << "is root" << std::endl;
		if (current->HasRight()) { //if a right node exists
			cout << "is going right" << std::endl;
			current = current->GetRight();
			TraverseLeft(current, parent);
			m_pRoot->SetData(current->GetData());

			//if (m_pRoot->HasRight() && m_pRoot->GetRight()->HasRight()) {
			//	m_pRoot->SetRight(m_pRoot->GetRight()->GetRight());
			//}
			//else {
			//	m_pRoot->SetRight(nullptr);
			//}
			//
			//if (current->HasRight() && parent != nullptr) {
			//	parent->SetRight(current->GetRight());
			//}
			//else if(parent != nullptr) {
			//	parent->SetRight(nullptr);
			//}
		}
		else if(current->HasLeft()){
			cout << "is going right" << std::endl;
			current = current->GetLeft();
			TraverseRight(current, parent);
			m_pRoot->SetData(current->GetData());
			if (current->HasLeft() && parent != nullptr) {
				parent->SetLeft(current->GetLeft());
			}
			else if (parent != nullptr) {
				parent->SetLeft(nullptr);
			}
		}
		else {
			cout << "is going neither" << std::endl;
			m_pRoot = nullptr;
		}
	}

	//cout << m_pRoot->GetData() << " <-Root data" << std::endl;
	//cout << m_pRoot->HasRight() << " <-HasRight? || " << m_pRoot->HasLeft() << " <-HasLeft?" << std::endl;
//

Jeff's Method:
pass in a pointer reference node(PRnode)
save its right and left to a pointer, this directly points to those values rather than just the PRnode
use 'delete' to delete that current node, then replace its values

*/

void BinaryTree::Remove(TreeNode* &nodeToRemove) {
	TreeNode* leftSave = nodeToRemove->HasLeft() ? nodeToRemove->GetLeft() : nullptr;
	TreeNode* rightSave = nodeToRemove->HasRight() ? nodeToRemove->GetRight() : nullptr;



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