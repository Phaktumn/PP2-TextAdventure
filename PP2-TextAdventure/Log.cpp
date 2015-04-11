#include "Log.h"


Log::Log() : head(nullptr)
{
}


Log::~Log()
{
}

void Log::addLog(const std::string &text)
{
	LogData* ptr = head;

	while (ptr != nullptr) {
		ptr = ptr->next;
	}

	ptr = new LogData();
	ptr->data = text;
}