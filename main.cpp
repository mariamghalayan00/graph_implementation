#include <vector>
#include "graph.hpp"

int main()
{
    std::vector<std::pair<int, int>> vector_of_edges = {{1, 2}, {1, 4}, {2, 3}, {4, 5}, {5, 3}, {5, 3}};

    graph eg;
    //assert(eg.get_vertices().empty());
    //assert(eg.get_edges().empty());

    graph::vertices v = {1, 2, 3, 4, 5};
    graph egv(v);
    //assert(eg.get_vertices().size() == 5);
    //assert(eg.get_edges().empty());
    //assert(eg.)
    


    //graph g(vector_of_nodes, vector_of_edges);

    //g.print_adjacency_list();
    //egv.print_adjacency_list();
}
