//
// Created by Renjie Wu on 2019-02-24.
//
#include "edge.h"

std::pair<int, int> pipe_graph::Edge::end_points_id() const {
  return std::make_pair(end_points_.first->node_id(),
                        end_points_.second->node_id());
}
int pipe_graph::Edge::edge_id() const { return edge_id_; };