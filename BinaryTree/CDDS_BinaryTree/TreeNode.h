#pragma once
#include <stdlib.h>
#include <stdio.h>

class TreeNode
{
public:
	TreeNode(int value);
	~TreeNode();

	bool HasLeft() { return m_left; }
	bool HasRight() { return m_right; }

	int GetData() { return m_value; }
	TreeNode* GetLeft() { return m_left ? m_left : nullptr; }
	TreeNode* GetRight() { return m_right ? m_right : nullptr; }

	
	void SetData(int value) { m_value = value; }//TODO: Finish SetData Function
	void SetLeft(TreeNode* node) { m_left = node; }
	void SetRight(TreeNode* node) { m_right = node; }

	void SetNode(TreeNode* node);

	void Draw(int x, int y, bool selected=false);

	// this could also be a pointer to another object if you like
	int m_value;

	// node's children
	TreeNode* m_left;
	TreeNode* m_right;
	
private:
	

	
};

