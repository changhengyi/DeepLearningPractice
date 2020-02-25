#include "activator/activator.h"

#include <iostream>
#include <vector>

#ifndef DL_NODE_H
#define DL_NODE_H

namespace dl
{
class Connection;

class Node
{
private:

    int m_layer_index;
    int m_node_index;
    std::vector<Connection*> downstream_;
    std::vector<Connection*> upstream_;
    double m_output;
    double m_delta;

public:
    Node();
    ~Node();
    void SetOutput(double output);
    void AppendDownstreamConnection(Connection* conn);
    void AppendUpstreamConnection(Connection* conn);
    void CalculateOutput();
    void CalculateHiddenLayerDelta();
    void CalculateOutputLayerDelta(double label);
};

class Connection
{
public:
    Node* m_upstream_node;
    Node* m_downstream_node;
    double m_weight;
    double m_gradient;

public:
    Connection();
    ~Connection();
};
    
}

#endif
