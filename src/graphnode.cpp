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

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.emplace_back(edge);
  std::cout << "GraphNode::AddEdgeToParentNode. Node " << this->GetID() << " _parentEdges size: " << _parentEdges.size() << std::endl;
}

void GraphNode::AddEdgeToChildNode(std::shared_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(edge);
  std::cout << "GraphNode::AddEdgeToChildNode. Node " << this->GetID() << " _childEdges size: " << _childEdges.size() << std::endl;
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot* chatBot)
{
  std::cout << "GraphNode::MoveChatbotHere" << std::endl;
  	//(*_chatBot) = chatBot;	// this triggers the assignment operator
    //_chatBot = std::make_unique<ChatBot>((*chatBot.get()));
  
  	//auto tempChatbot = ChatBot(std::move(chatBot));
    _chatBot = std::move(chatBot);
  	_chatBot->SetCurrentNode(this);
  	//_chatBot = ChatBot(chatBot);
    //(*_chatBot) = std::move(chatBot);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  std::cout << "GraphNode::MoveChatbotToNewNode" << std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
  std::cout << "GraphNode::GetChildEdgeAtIndex" << std::endl;
    //// STUDENT CODE
    ////
	auto childEdge = _childEdges[index].get();
    
    return childEdge;

    ////
    //// EOF STUDENT CODE
}