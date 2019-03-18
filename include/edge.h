#ifndef PIPELINE_GRAPH_EDGE_H
#define PIPELINE_GRAPH_EDGE_H

#include "node.h"
#include <memory>
#include <utility>

namespace pipe_graph {
//! Edge class
//! \brief  class that stores the information about edge
//! \details edge class that store edge id and connecting nodes
class Edge {
 public:
  //! constructor
  //! \param[in] id Global/local index for the edge
  //! \param[in] n_1 A shared pointer for a end node
  //! \param[in] n_2 A shared pointer for a end node
  Edge(int id, const std::shared_ptr<Node>& n_1,
       const std::shared_ptr<Node>& n_2)
      : edge_id_{id}, end_points_{n_1, n_2} {}

  int edge_id() const;
  //! return ids of two endpoints of the edge
  std::pair<int, int> end_points_id() const;
  //! return coordinate of two endpoints of the edge
  std::pair<Eigen::Array2d, Eigen::Array2d> end_points_coord() const;

 private:
  using pipe_type = std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>>;
  //! edge id
  int edge_id_;
  //! a pair of pointers point to connected nodes of the edge
  pipe_type end_points_;
};
}  // namespace pipe_graph

#endif  // PIPELINE_GRAPH_EDGE_H
