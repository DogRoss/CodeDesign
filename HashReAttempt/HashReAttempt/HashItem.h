#pragma once

#ifndef HASHITEM_H
#define	HASHITEM_H


#include <functional>
#include <string>

class HashItem
{
private:	
	std::string value; //value of item, uses value to make hash which will be used to find item location

public:

	HashItem(std::string inputValue);

	void SetValue(std::string inputValue);

	std::string GetValue();

	static HashItem* create_item(std::string value);

};

#endif // !1
