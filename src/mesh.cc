
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <iostream>
#include <cmath>
#include "mesh.h"
#include "edge.h"
#include "node.h"


bool pipe_graph::Mesh::set_nodes(
    const std::vector<std::pair<double, double>> &coordinates) {
  nodes_.clear();
  int node_id = 0;
  bool status = false;
  //! loop through the input node coordinate to construct node and add it into
  //! the node map
  try {
    for (auto &coord : coordinates) {
      nodes_.emplace(std::make_pair(
          node_id,
          std::make_shared<Node>(Node(node_id, coord.first, coord.second))));
      node_id++;
    }
    status = true;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << "node construction failed";
  }

  return status;
}

bool pipe_graph::Mesh::set_edges(
    const std::vector<std::pair<int, int>> &nodes) {
  edges_.clear();
  bool status = false;
  int edge_id = 0;
  //! loop through the input connecting nodes ids to construct edge and add it
  //! into the edge map
  try {
    for (auto node_pair : nodes) {
      Edge e(edge_id, nodes_.at(node_pair.first), nodes_.at(node_pair.second));
      edges_.emplace(std::make_pair(edge_id, e));
      edge_id++;
    }
    status = true;
  } catch (std::exception &e) {
    std::cout << "Pipe(id: " << edge_id
              << ") is not created, as input node does not exist, nodes id: "
              << nodes[edge_id].first << " or " << nodes[edge_id].second << '\n'
              << "Pipe creation is unfinished, please check the input" << '\n';
  }
  return status;
}

// std::vector<int> pipe_graph::Mesh::node_ids () {
//    std::vector<int> id_list;
//    for
//}
void pipe_graph::draw_graph(const pipe_graph::Mesh &m, std::string file_name) {
  struct VertexProps {
    std::string name;
  };
  struct EdgeProps {
    int weight;
  };
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
                                VertexProps, EdgeProps>
      Graph;

  //! start construct graph vertices from nodes info
  int n_node = m.num_nodes();
  int n_edge = m.num_edges();
  Graph g(n_node);
  //! initialize the graph vertices
  for (int i = 0; i < n_node; i++) {
    auto n_id = (m.nodes_).at(i)->node_id();
    g[n_id].name = "N" + std::to_string(n_id);
  }
  //! adding edges to the graph
  for (int i = 0; i < n_edge; i++) {
    auto node_ids = (m.edges_).at(i).end_points_id();
    auto nod_coords = (m.edges_).at(i).end_points_coord();
    int appro_dist =
        sqrt((nod_coords.first - nod_coords.second).square().sum());
    add_edge(node_ids.first, node_ids.second, {appro_dist}, g);
  }

  //! write the result to a file
  std::ofstream f(file_name);
  write_graphviz(f, g, make_label_writer(get(&VertexProps::name, g)),
                 make_label_writer(get(&EdgeProps::weight, g)));
  f.close();
}