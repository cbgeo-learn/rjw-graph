#ifndef PIPELINE_GRAPH_MESH_H
#define PIPELINE_GRAPH_MESH_H

#include <iostream>
#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "edge.h"
#include "node.h"

namespace pipe_graph {
//! Mesh class
//! \brief  class that stores the information about a grid
//! \details  class that store edges and nodes
class Mesh {
  friend void draw_graph(const Mesh&, std::string);

 public:
  //! constructor
  //! \param[in] id Global/local index for the mesh
  explicit Mesh(int id) : mesh_id_{id} {};

  int mesh_id() { return mesh_id_; }
  //! return number of nodes
  auto num_nodes() const { return nodes_.size(); };
  //! return number of edges
  auto num_edges() const { return edges_.size(); };

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
//! function that produce .dot graph of the mesh for visualization purpose
//! \param[in] m the mesh object
//! \param[in] file_name name for the output file
void draw_graph(const Mesh& m, std::string file_name = "graph.dot");

}  // namespace pipe_graph

#endif  // PIPELINE_GRAPH_MESH_H
