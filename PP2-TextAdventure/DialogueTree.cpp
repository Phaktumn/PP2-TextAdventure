#include "DialogueTree.h"


DialogueTree::DialogueTree()
{
	firstNode = nullptr;
}


DialogueTree::~DialogueTree()
{
}

DialogueNode* DialogueTree::getNode(int i)
{
	return dialogueNodes[i];
}

void DialogueTree::addOption(const std::string &text, DialogueNode* parentNode, DialogueNode* destinationNode)
{
	DialogueOption* dialogueOption = new DialogueOption();
	dialogueOption->nextNode = destinationNode;
	dialogueOption->text = text;

	parentNode->dialogueOptions.push_back(dialogueOption);
}

void DialogueTree::addNode(const std::string &text)
{
	DialogueNode* dialogueNode = new DialogueNode();
	dialogueNode->text = text;

	if (firstNode == nullptr) {
		firstNode = dialogueNode;
	}

	dialogueNodes.push_back(dialogueNode);
}