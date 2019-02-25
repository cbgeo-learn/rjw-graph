//
// Created by Renjie Wu on 2019-02-24.
//
#define CATCH_CONFIG_MAIN
#include "../external/catch.h"
#include "../include/edge.h"
#include "../include/node.h"
// Check mesh class
TEST_CASE("Checking Node/Edge", "Node/Edge") {
    // Tolerance
    const double tolerance = 1.e-12;
    SECTION("CHECK NODE/EDGE"){
        // construct two nodes
        int id1(111),id2(222);
        float coord_x_1(123.123),coord_y_1(234.234),coord_x_2(56.456),coord_y_2(789.789);

        pipe_graph::Node n_1(id1,coord_x_1,coord_y_1);
        pipe_graph::Node n_2(id2,coord_x_2,coord_y_2);

        REQUIRE(n_1.node_id() == id1);
        REQUIRE(n_1.coordinate()(0) == coord_x_1);
        REQUIRE(n_1.coordinate()(1) == coord_y_1);

        n_1.node_id(1231231231);
        n_1.coordinate(213123.213213,2141234.231);
        REQUIRE(n_1.node_id() == 1231231231);
        REQUIRE(n_1.coordinate()(0) == 213123.213213);
        REQUIRE(n_1.coordinate()(1) == 2141234.231);

        // Check Edge
        int e_id(3321);

        pipe_graph::Edge e1(e_id,std::make_shared<pipe_graph::Node> (n_1),
                std::make_shared<pipe_graph::Node> (n_2));
        REQUIRE(e1.edge_id() == e_id);
        REQUIRE(e1.end_points().second->node_id() == id2);
        e1.edge_id(123213);
        REQUIRE(e1.edge_id() == 123213);
        e1.end_points(std::make_shared<pipe_graph::Node> (n_2),
                      std::make_shared<pipe_graph::Node> (n_1));
        REQUIRE(e1.end_points().first->node_id() == id2);





    }

}