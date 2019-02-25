//
// Created by Renjie Wu on 2019-02-24.
//

#ifndef PIPELINE_GRAPH_EDGE_H
#define PIPELINE_GRAPH_EDGE_H

#include <utility>
#include "Node.h"
namespace PIPE_GRAPH {
    class Edge {
        typedef std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> pipe_type;
        int edge_id_;
        pipe_type end_points_;
    public:
        Edge(const int id, const Node &n_1, const Node &n_2) : edge_id_(id) {
            set_end_points(n_1, n_2);
        }

        //get/set functions
        double get_edge_id() const {
            return edge_id_;
        }

        pipe_type get_end_points() const {
            return end_points_;
        }

        void set_edge_id(const int id) {
            edge_id_ = id;
        }

        void set_end_points(const Node &n_1, const Node &n_2) {
            end_points_ = std::make_pair(std::make_shared<Node>(n_1), std::make_shared<Node>(n_2));
        }


    };
}

#endif //PIPELINE_GRAPH_EDGE_H
