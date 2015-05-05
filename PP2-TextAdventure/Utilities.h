#pragma once
#include <string>
#include "Item.h"
#include <jsoncons\json.hpp>
#include <iostream>

class Utilities
{
public:
	Utilities();
	~Utilities();

	static Item* loadItem(const std::string &filePath);

private:

};

