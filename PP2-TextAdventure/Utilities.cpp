#include "Utilities.h"


Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

Item* Utilities::loadItem(const std::string &filePath)
{
	jsoncons::json file = jsoncons::json::parse_file(filePath);

	for (size_t i = 0; i < file.size(); i++) {
		
		try {
		jsoncons::json &field = file[i];
		std::string name = field["Name"].as<std::string>();
		std::string description = field["Description"].as<std::string>();
		int damage = field["Damage"].as<int>();

		std::cout << "Name: " << name << std::endl;
		std::cout << "Description: " << description << std::endl;
		std::cout << "Damage: " << damage << std::endl;

		}
		catch (const jsoncons::json_exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return nullptr;
}