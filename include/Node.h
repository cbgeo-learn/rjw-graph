//
// Created by Renjie Wu on 2019-02-24.
//

#ifndef PIPELINE_GRAPH_NODE_H
#define PIPELINE_GRAPH_NODE_H

#include <utility>
namespace PIPE_GRAPH{
    class Node {
        int node_id_;
        std::pair<double ,double > node_coord_;
    public:
        // constructor
        Node(const int node_id, const double coord_x, const double coord_y):
                node_id_(node_id), node_coord_(coord_x,coord_y){};
        // get functions
        long get_node_id() const {
            return  node_id_;
        }
        std::pair<double ,double > get_coordinate() const {
            return node_coord_;
        };
        // set functions
        void set_node_id(const int id){
            node_id_ = id;
        }
        void set_coordinate(const double coord_x,const double coord_y){
            node_coord_ = std::make_pair(coord_x,coord_y);
        }
    };
}



#endif //PIPELINE_GRAPH_NODE_H
