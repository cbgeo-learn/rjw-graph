
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "mesh.h"
// Check mesh class
TEST_CASE("Checking Mesh", "Mesh") {
  // Tolerance
  const double tolerance = 1.e-12;
  SECTION("CHECK CONSTRUCTORS") {
    int mesh_id = 135;
    pipe_graph::Mesh m(mesh_id);
    REQUIRE(m.mesh_id() == mesh_id);

    std::vector<std::pair<double, double>> coordinates{
        std::make_pair<double, double>(0, 0),
        std::make_pair<double, double>(0, 1),
        std::make_pair<double, double>(1, 0),
        std::make_pair<double, double>(0, 2),
        std::make_pair<double, double>(2, 0)};
    REQUIRE(m.set_nodes(coordinates));
    REQUIRE(m.num_nodes() == 5);

    std::vector<std::pair<int, int>> nodes_pair{
        std::make_pair<int, int>(0, 1), std::make_pair<int, int>(0, 2),
        std::make_pair<int, int>(0, 3), std::make_pair<int, int>(0, 4)};
    REQUIRE(m.set_edges(nodes_pair));
    REQUIRE(m.num_edges() == 4);

    std::vector<std::pair<int, int>> nodes_pair_false{
        std::make_pair<int, int>(0, 1), std::make_pair<int, int>(0, 2),
        std::make_pair<int, int>(0, 3), std::make_pair<int, int>(0, 121)};

    REQUIRE(m.set_edges(nodes_pair_false));
    REQUIRE(m.num_edges() == 3);
  }
}
