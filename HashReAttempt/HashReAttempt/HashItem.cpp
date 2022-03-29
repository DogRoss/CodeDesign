#include "HashItem.h"

HashItem::HashItem(std::string inputValue)
{
	value = inputValue;
}

void HashItem::SetValue(std::string inputValue)
{
	value = inputValue;
}

std::string HashItem::GetValue()
{
	return HashItem::value;
}

HashItem* HashItem::create_item(std::string value)
{
	HashItem* item = new HashItem(value);
	item->SetValue(value);
	return item;
}
