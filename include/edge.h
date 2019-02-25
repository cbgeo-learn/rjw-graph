//
// Created by Renjie Wu on 2019-02-24.
//

#ifndef PIPELINE_GRAPH_EDGE_H
#define PIPELINE_GRAPH_EDGE_H

#include <utility>
#include <memory>
#include "node.h"
namespace pipe_graph {
    class Edge {
        typedef std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> pipe_type;
        int edge_id_;
        pipe_type end_points_;
    public:
        Edge(const int id, std::shared_ptr<Node> n_1, std::shared_ptr<Node> n_2):
        edge_id_(id), end_points_(n_1,n_2) {}

        //get/set functions
        double edge_id() const ;

        pipe_type end_points() const;

        void edge_id(int id);

        void end_points(std::shared_ptr<Node> n_1, std::shared_ptr<Node> n_2);


    };
}

#endif //PIPELINE_GRAPH_EDGE_H
