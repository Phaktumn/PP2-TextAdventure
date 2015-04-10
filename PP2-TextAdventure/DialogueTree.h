#pragma once
#include <string>
#include <vector>

typedef struct DialogueNode
{
	std::string text;
	std::vector<DialogueOption*> dialogueOptions;
} DialogueNode;

typedef struct DialogueOption
{
	std::string text;
	DialogueNode* nextNode;
} DialogueOption;

class DialogueTree
{
public:
	DialogueTree();
	~DialogueTree();

	void addOption(const std::string &text, DialogueNode* parentNode, DialogueNode* destinationNode);
	void addNode(const std::string &text);
	DialogueNode* getNode(int i);

private:
	DialogueNode* firstNode;
	std::vector<DialogueNode*> dialogueNodes;
};

