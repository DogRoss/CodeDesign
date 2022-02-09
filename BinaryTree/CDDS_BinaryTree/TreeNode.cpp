#include "TreeNode.h"
#include "raylib.h"
#include <string>

TreeNode::TreeNode(int value) : m_value(value), m_left(nullptr), m_right(nullptr)
{
	
}


TreeNode::~TreeNode()
{
}

void TreeNode::SetNode(TreeNode* node)
{
	m_value = node->GetData();

	if (node->HasLeft())
	{
		m_left = node->GetLeft();
	}
	else 
	{
		m_left = nullptr;
	}
	if (node->HasRight())
	{
		m_right = node->GetRight();
	}
	else
	{
		m_right = nullptr;
	}
	
}


void TreeNode::Draw(int x, int y, bool selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(x, y, 30, YELLOW);

	if (selected == true)
		DrawCircle(x, y, 28, GREEN);		
	else
		DrawCircle(x, y, 28, BLACK);
			

	DrawText(buffer, x - 12, y - 10, 12, WHITE);
}