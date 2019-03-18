
#include <edge.h>

#include "edge.h"

std::pair<int, int> pipe_graph::Edge::end_points_id() const {
  return std::make_pair(end_points_.first->node_id(),
                        end_points_.second->node_id());
}
int pipe_graph::Edge::edge_id() const { return edge_id_; }

std::pair<Eigen::Array2d, Eigen::Array2d>
pipe_graph::Edge::end_points_coord() const {
  return std::make_pair(end_points_.first->coordinate(),
                        end_points_.second->coordinate());
}
