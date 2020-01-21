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

void GraphNode::AddEdgeToParentNode(std::unique_ptr<GraphEdge>& edge)
{
  std::cout << "GraphNode::AddEdgeToParentNode" << std::endl;
    _parentEdges.emplace_back(std::move(edge));
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge>& edge)
{
  std::cout << "GraphNode::AddEdgeToChildNode. _childEdges size: " << _childEdges.size() << std::endl;
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(std::shared_ptr<ChatBot> chatBot)
{
  std::cout << "GraphNode::MoveChatbotHere" << std::endl;
    _chatBot = chatBot;
    chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  std::cout << "GraphNode::MoveChatbotToNewNode" << std::endl;
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
  std::cout << "GraphNode::GetChildEdgeAtIndex" << std::endl;
    //// STUDENT CODE
    ////
	auto childEdge = _childEdges[index].get();
    if(!childEdge){
      std::cout << "childEdge is null" << std::endl;
    }
    return childEdge;

    ////
    //// EOF STUDENT CODE
}