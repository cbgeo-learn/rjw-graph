//
// Created by Renjie Wu on 2019-03-07.
//

#ifndef PIPELINE_GRAPH_MESH_H
#define PIPELINE_GRAPH_MESH_H

#include "edge.h"
#include "node.h"
#include <iostream>
#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace pipe_graph {
//! Mesh class
//! \brief  class that stores the information about a grid
//! \details  class that store edges and nodes
class Mesh {

 public:
  //! constructor
  //! \param[in] id Global/local index for the mesh
  explicit Mesh(int id) : mesh_id_{id} {};

  int mesh_id() { return mesh_id_; }
  //! get function for number of nodes/edges
  auto num_nodes() { return nodes_.size(); };
  auto num_edges() { return edges_.size(); };

  //! set nodes for the mesh
  //! \param[in] coordinates Vector of pair of double that specify nodes
  //! coordinates (node id will be the corresponding location in input vector)
  bool set_nodes(const std::vector<std::pair<double, double>>& coordinates);

  //! set nodes for the mesh
  //! \param[in] coordinates Vector of pair of int that specify the the ids of
  //! two connecting nodes, which form a edge (edge id will be the corresponding
  //! location in input vector)
  bool set_edges(const std::vector<std::pair<int, int>>& nodes);

 private:
  int mesh_id_;
  //! map for shared pointers that point to node
  std::map<int, std::shared_ptr<Node>> nodes_;
  //! map for edges
  std::map<int, Edge> edges_;
};
}  // namespace pipe_graph

#endif  // PIPELINE_GRAPH_MESH_H
