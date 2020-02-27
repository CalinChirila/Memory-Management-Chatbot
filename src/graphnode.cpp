#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
  std::cout << "GraphNode constructor" << std::endl;
    _id = id;
}

GraphNode::~GraphNode()
{
  std::cout << "GraphNode destructor" << std::endl;
    //// STUDENT CODE
    ////
  
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
  std::cout << "GraphNode::AddToken" << std::endl;
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::weak_ptr<GraphEdge> edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot && chatBot)
{
  std::cout << "GraphNode::MoveChatbotHere" << std::endl;
    _chatBot = ChatBot(std::move(chatBot));
  	_chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  std::cout << "GraphNode::MoveChatbotToNewNode" << std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
  std::cout << "GraphNode::GetChildEdgeAtIndex: " << index << std::endl;
  std::cout << "Child edges at node " << this->GetID() << " => " << _childEdges.size() << std::endl;
    //// STUDENT CODE
    ////
  
	auto childEdge = _childEdges[index].get();
    return childEdge;

    ////
    //// EOF STUDENT CODE
}