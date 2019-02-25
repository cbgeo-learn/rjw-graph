//
// Created by Renjie Wu on 2019-02-24.
//
#include "../include/node.h"


int pipe_graph::Node::node_id() const {
    return node_id_;
}

Eigen::Array2d pipe_graph::Node::coordinate() const {
    return node_coord_;
}

void pipe_graph::Node::node_id(const int id) {
    node_id_ = id;

}

void pipe_graph::Node::coordinate(double coord_x, double coord_y) {
    node_coord_<<coord_x,coord_y;
}
