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

void BinaryTree::RightInsert(TreeNode*& iterator, TreeNode*& NodeToInsert)
{
	while (true) { //iterates through until correct position is reached
		if (NodeToInsert->GetData() == iterator->GetData()) {
			delete NodeToInsert;
			std::cout << "ERROR: number exists in tree, returning..." << std::endl;
			return;
		}
		else if (NodeToInsert->GetData() > iterator->GetData()) { //if right of current
			if (iterator->HasRight()) {		//if it has a right, iterate, if not then break
				iterator = iterator->GetRight();
			}
			else {
				break;
			}
		}
		else { //if left of current
			if (iterator->HasLeft()) {		//if it has a left, iterate, if not then break
				iterator = iterator->GetLeft();
			}
			else {
				break;
			}
		}
	}
}

void BinaryTree::LeftInsert(TreeNode*& iterator, TreeNode*& NodeToInsert)
{
	while (true) { //iterates through until correct position is reached
		if (NodeToInsert->GetData() == iterator->GetData()) {
			delete NodeToInsert;
			std::cout << "ERROR: number exists in tree, returning..." << std::endl;
			return;
		}
		else if (NodeToInsert->GetData() > iterator->GetData()) { //if right of current
			if (iterator->HasRight()) {		//if it has a right, iterate, if not then break
				iterator = iterator->GetRight();
			}
			else {
				break;
			}
		}
		else { //if left of current
			if (iterator->HasLeft()) {		//if it has a left, iterate, if not then break
				iterator = iterator->GetLeft();
			}
			else {
				break;
			}
		}
	}
}

//removes node and replaces with closest value to the right
void BinaryTree::RightRemove(TreeNode*& iterator, TreeNode*& iteratorParent, TreeNode*& nodeToDelete, TreeNode* nTDParent)
{
	if (iterator->HasRight()) { //check if it has a right (right is favored)
		iteratorParent = iterator;
		iterator = iterator->GetRight(); //iterate right by one

		if (iterator->HasLeft()) { //we are able to get the left most node from current
			TraverseLeft(iterator, iteratorParent); //Get left most node
			nodeToDelete->SetData(iterator->GetData()); //copy node data to nodeToDelete

			if (iterator->HasRight()) { //if the node we are moving has a right node, set that to parents left, breaks off current node
				iteratorParent->SetLeft(iterator->GetRight());
			}
			else { //if there is no left
				iteratorParent->SetLeft(nullptr); //break off current
			}

			delete iterator; //deletes current
		}
		else { //if the current node doesnt have left nodes
			nodeToDelete->SetData(iterator->GetData()); //sets data to node right of nodeToDelete.

			if (iterator->HasRight()) { //if current has a right node
				nodeToDelete->SetRight(iterator->GetRight()); //moves up nodes, breaking off current
			}
			else { //if there is no right
				nodeToDelete->SetRight(nullptr); //break off current
			}
		}
	}
	else if (iterator->HasLeft()) { //if right doesnt exist
		iteratorParent = iterator;
		iterator = iterator->GetLeft(); //iterate left by one

		if (iterator->HasRight()) { //if we are able to get the right most node from current
			TraverseRight(iterator, iteratorParent); //iterate to right most node
			nodeToDelete->SetData(iterator->GetData()); //copy node data to nodeToDelete

			if (iterator->HasLeft()) { //if the node we are replacing 
				iteratorParent->SetRight(iterator->GetLeft());
			}
			else {
				iteratorParent->SetRight(nullptr);
			}
			delete iterator;
		}
		else { //if the current node doesnt have right nodes
			nodeToDelete->SetData(iterator->GetData());

			if (iterator->HasLeft()) { //if current has a left node
				nodeToDelete->SetLeft(iterator->GetLeft());
			}
			else {//if there is no left
				nodeToDelete->SetLeft(nullptr);//break off current
			}
		}
	}
	else { //if iterator doesnt have right or left, then cut off the iterators node;
		if (nodeToDelete->GetData() > nTDParent->GetData()) { //right of parent
			nTDParent->SetRight(nullptr);
		}
		else if (nodeToDelete->GetData() < nTDParent->GetData()) { //left of parent
			nTDParent->SetLeft(nullptr);
		}
	}
}

//removes node and replaces with closest value to the left
void BinaryTree::LeftRemove(TreeNode*& iterator, TreeNode*& iteratorParent, TreeNode*& nodeToDelete, TreeNode* nTDParent)
{
	if (iterator->HasLeft()) { //favor left node from NTD first
		iteratorParent = iterator;
		iterator = iterator->GetLeft(); //iterate left by one

		if (iterator->HasRight()) { //we are able to get the right most node from current
			TraverseRight(iterator, iteratorParent);
			nodeToDelete->SetData(iterator->GetData());

			if (iterator->HasLeft()) { //if the node we are replacing 
				iteratorParent->SetRight(iterator->GetLeft());
			}
			else {
				iteratorParent->SetRight(nullptr);
			}

			delete iterator;
		}
		else { //if the current node doesnt have right nodes
			nodeToDelete->SetData(iterator->GetData());

			if (iterator->HasLeft()) { //if it has a left node
				nodeToDelete->SetLeft(iterator->GetLeft());
			}
			else {
				nodeToDelete->SetLeft(nullptr);
			}
		}
	}


	else if (iterator->HasRight()) { //if left doesnt exist
		iteratorParent = iterator;
		iterator = iterator->GetRight(); //iterate right one

		if (iterator->HasLeft()) { //we are able to get the left most node from current
			TraverseLeft(iterator, iteratorParent);
			nodeToDelete->SetData(iterator->GetData());

			if (iterator->HasRight()) { //if the node we are replacing 
				iteratorParent->SetLeft(iterator->GetRight());
			}
			else {
				iteratorParent->SetLeft(nullptr);
			}
			delete iterator;
		}
		else { //if the current node doesnt have left nodes
			nodeToDelete->SetData(iterator->GetData());

			if (iterator->HasRight()) { //if it has a right node
				nodeToDelete->SetRight(iterator->GetRight());
			}
			else {
				nodeToDelete->SetRight(nullptr);
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

//removes root node and prefers to replace with closest right value, if not then closest left value
void BinaryTree::RootRemove(TreeNode*& iterator, TreeNode*& iteratorParent, TreeNode*& nodeToDelete, TreeNode* nTDParent)
{
	if (iterator->HasRight()) { //favor right node from root first
		iteratorParent = iterator;
		iterator = iterator->GetRight(); //iterate right one

		if (iterator->HasLeft()) { //we are able to get the left most node from current
			TraverseLeft(iterator, iteratorParent);
			m_pRoot->SetData(iterator->GetData());

			if (iterator->HasRight()) { //if the node we are replacing 
				iteratorParent->SetLeft(iterator->GetRight());
			}
			else {
				iteratorParent->SetLeft(nullptr);
			}

			delete iterator;
		}
		else { //if the current node doesnt have left nodes
			m_pRoot->SetData(iterator->GetData());

			if (iterator->HasRight()) { //if it has a right node
				m_pRoot->SetRight(iterator->GetRight());
			}
			else {
				m_pRoot->SetRight(nullptr);
			}
		}
	}
	else if (iterator->HasLeft()) { //if right doesnt exist
		iteratorParent = iterator;
		iterator = iterator->GetLeft(); //iterate left one

		if (iterator->HasRight()) { //we are able to get the right most node from current
			TraverseRight(iterator, iteratorParent);
			m_pRoot->SetData(iterator->GetData());

			if (iterator->HasLeft()) { //if the node we are replacing 
				iteratorParent->SetRight(iterator->GetLeft());
			}
			else {
				iteratorParent->SetRight(nullptr);
			}
			delete iterator;
		}
		else { //if the current node doesnt have right nodes
			m_pRoot->SetData(iterator->GetData());

			if (iterator->HasLeft()) { //if it has a left node
				m_pRoot->SetLeft(iterator->GetLeft());
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

	if (m_pRoot == nullptr) { //checks if root doesnt exist, if so, insert and return
		m_pRoot = insertNode;
		return;
	}
	else {
		current = m_pRoot;
		if (insertNode->GetData() == m_pRoot->GetData()) { //if its the root, return as the value is existant
			delete insertNode;
			std::cout << "ERROR: number exists in tree, returning..." << std::endl;
			return;
		}
		else if (insertNode->GetData() > m_pRoot->GetData()) { //if right of root
			RightInsert(current, insertNode); //finds spot in right to insert
		}
		else { //if to the left
			LeftInsert(current, insertNode); //finds spot in left to insert
		}

		//inserts value based on if the current is greater or less than the To-Be-Parent-Node(current).
		insertNode->GetData() > current->GetData() 
			? current->SetRight(insertNode) //if true
			: current->SetLeft(insertNode); //if false
	}

}

//finds specific node using FindNode function, yet only returns the current node
TreeNode* BinaryTree::Find(int a_nValue) 
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

//iterates throught right nodes until there is no more right nodes, returning the current and current's parent
void BinaryTree::TraverseRight(TreeNode* &outStarting, TreeNode* &outParent) { 
	TreeNode* parent = outParent;
	TreeNode* current = outStarting;
	while (current->HasRight()) {
		parent = current;
		current = current->GetRight();
	}

	outStarting = current;
	outParent = parent;
}

//iterates throught left nodes until there is no more left nodes, returning the current and current's parent
void BinaryTree::TraverseLeft(TreeNode* &outStarting, TreeNode* &outParent) { 
	TreeNode* parent = outParent;
	TreeNode* current = outStarting;
	while (current->HasLeft()) {
		parent = current;
		current = current->GetLeft();
	}

	outStarting = current;
	outParent = parent;
}

//finds node of value and returns as outnode and outparent
bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent) 
{

	TreeNode* parent = nullptr;
	TreeNode* current = m_pRoot; //iterator

	if (current == nullptr) { //if the root is null
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

//searches for value, and replaces it with what is the next closest value depending on conditions(decides if left or right node is replacer)
void BinaryTree::Remove(int a_nSearchValue) {


	TreeNode* nodeToDelete;
	TreeNode* nTDParent;

	if (!FindNode(a_nSearchValue, nodeToDelete, nTDParent)){ //if the node we want to delete doesnt exist, return, but if it does it sets the nodes
		return;
	}

	//saves right and left nodes if they exist
	if (nodeToDelete->HasRight()) {
		TreeNode* nTDRight = nodeToDelete->GetRight();
	}
	if (nodeToDelete->HasLeft()) {
		TreeNode* nTDLeft = nodeToDelete->GetLeft();
	}

	//iterators
	TreeNode* parent = nullptr;//parent of current
	TreeNode* current = nullptr;//value that gets moved eventually

	if (FindNode(a_nSearchValue, current, parent)) { //if the data exists (current set to position of nodeToDelete)

		if (current->GetData() > m_pRoot->GetData()) { //if right of root
			RightRemove(current, parent, nodeToDelete, nTDParent); 
		}
		else if (current->GetData() < m_pRoot->GetData()) { //if left of root
			LeftRemove(current, parent, nodeToDelete, nTDParent); 
		}
		else { //if it is root
			RootRemove(current, parent, nodeToDelete, nTDParent); 
		}
	}
	else {
		std::cout << "ERROR: value doesnt exist, returning...";
		return;
	}

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