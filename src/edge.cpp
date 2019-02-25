//
// Created by Renjie Wu on 2019-02-24.
//
#include "../include/edge.h"
namespace pipe_graph{
    double Edge::edge_id() const {
        return edge_id_;
    }

    std::pair<std::shared_ptr<pipe_graph::Node>, std::shared_ptr<pipe_graph::Node>> Edge::end_points() const {
        return end_points_;
    }

    void Edge::edge_id(const int id) {
        edge_id_ = id;

    }

    void Edge::end_points(std::shared_ptr<pipe_graph::Node> n_1, std::shared_ptr<pipe_graph::Node> n_2) {
        end_points_ = std::make_pair(n_1, n_2);
    }


}
