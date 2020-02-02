#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // Move constructor
    ChatBot(ChatBot &&source);
    // Copy Constructor
    ChatBot(ChatBot &source);
    // Assignment operator
    ChatBot& operator=(ChatBot &source);
    // Move assignment operator
    ChatBot& operator=(ChatBot &&source);
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) {
    	std::cout << "Chatbot: Setting root node" << std::endl;
    	_rootNode = rootNode; 
        if(!_rootNode){
        	std::cout << "_rootNode is null" << std::endl;
        }
    }
    void SetChatLogicHandle(ChatLogic *chatLogic) {
    	std::cout << "Chatbot: Setting chat logic" << std::endl;
    	_chatLogic = chatLogic; 
        if(!_chatLogic){
        	std::cout << "_chatLogic is null" << std::endl;
        }
    }
    wxBitmap *GetImageHandle() {
    	return _image; 
    }
    
    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */