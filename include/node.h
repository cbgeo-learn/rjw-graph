#ifndef PIPELINE_GRAPH_NODE_H
#define PIPELINE_GRAPH_NODE_H

#include <Eigen/Dense>
#include <utility>

namespace pipe_graph {
//! Node class
//! \brief  Class that stores the information about node
//! \details Node class that store node id and coordinates
class Node {

 public:
  //! Constructor
  //! \param[in] Node_id Global/local index for the node
  //! \param[in] Coord_x X coordinate for the node
  //! \param[in] Coord_y Y coordinate for the node
  Node(int node_id, double coord_x, double coord_y)
      : node_id_{node_id}, node_coord_{coord_x, coord_y} {};

  //! Get functions
  int node_id() const;
  Eigen::Array2d coordinate() const;

 private:
  //! Node id
  int node_id_;
  //! Eigen 2d array that stores node coordinate
  Eigen::Array2d node_coord_;
};

}  // namespace pipe_graph
#endif  // PIPELINE_GRAPH_NODE_H
