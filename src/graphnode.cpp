#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //std::cout << "graphnode desctr" << std::endl;
    //// STUDENT CODE
    ////

    //if (_chatBot != nullptr)
      //  delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

/*void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}*/
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //std::cout << "graph node add edge to child node MOVE SEMS" << std::endl;
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
//void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //*_chatBot = std::move(chatbot);
    _chatBot = std::move(chatbot);
    //chatBot->SetCurrentNode(this);
    //(*_chatBot).SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}