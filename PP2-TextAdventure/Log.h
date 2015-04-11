#pragma once

#include <string>

typedef struct LogData
{
	LogData* next;
	std::string data;

} LogData;

class Log
{
private:
	LogData* head;
	int count;

public:
	Log();
	~Log();

	void addLog(const std::string &text);
};

