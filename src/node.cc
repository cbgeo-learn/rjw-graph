#include "node.h"

int pipe_graph::Node::node_id() const { return node_id_; }

Eigen::Array2d pipe_graph::Node::coordinate() const { return node_coord_; }
