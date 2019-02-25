//
// Created by Renjie Wu on 2019-02-24.
//

#ifndef PIPELINE_GRAPH_NODE_H
#define PIPELINE_GRAPH_NODE_H

#include <utility>
#include <Eigen/Dense>

namespace pipe_graph{
    class Node {
        int node_id_;
        Eigen::Array2d node_coord_;
    public:
        // constructor
        Node(int node_id, double coord_x, double coord_y):
                node_id_(node_id), node_coord_(coord_x,coord_y){};
        // get/set functions
        int node_id() const;
        void node_id(int id);

        Eigen::Array2d coordinate() const;
        void coordinate(double coord_x,double coord_y);


    };
}



#endif //PIPELINE_GRAPH_NODE_H
