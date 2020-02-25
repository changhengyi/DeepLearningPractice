#include "node.h"

namespace dl
{

void Node::SetOutput(double output){
    m_output = output;
}

void Node::AppendDownstreamConnection(Connection* conn){
    downstream_.push_back(conn);
}

void Node::AppendUpstreamConnection(Connection* conn){
    upstream_.push_back(conn);
}

void Node::CalculateOutput(){
    double ret = 0;
    for(int i=0;i<upstream_.size();i++){
        ret += upstream_[i]->m_weight * upstream_[i]->m_upstream_node->m_output;
    }
    m_output = ret;
}

}