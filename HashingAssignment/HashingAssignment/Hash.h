#pragma once

#include <functional>

class Hash
{

	typedef std::function<unsigned int(const char*, unsigned int)> HashFunc;

	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);

	//TODO: ADD FUNCTIONS HERE

	
	// a helper to access a default hash function
	static HashFunc default = badHash;
};

