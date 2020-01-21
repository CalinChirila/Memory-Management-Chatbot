#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
  std::cout << "GraphEdge constructor" << std::endl;
    _id = id;
}

GraphEdge::~GraphEdge()
{
  std::cout << "GraphEdge destructor" << std::endl;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
  std::cout << "GraphEdge::SetChildNode" << std::endl;
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
  std::cout << "GraphEdge::SetParentNode" << std::endl;
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
  std::cout << "GraphEdge::AddToken" << std::endl;
  
    _keywords.push_back(token);
}