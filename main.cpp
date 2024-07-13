#include "graph.hpp"
#include <cassert>
#include <vector>
#include <iostream>

int main()
{
    graph::edges es = {{1, 2}, {1, 4}, {2, 3}, {4, 5}, {5, 3}, {3, 5}};
    graph::vertices vs = {1, 2, 3, 4, 5};

    graph default_graph;
    assert(default_graph.get_vertices().empty());
    assert(default_graph.get_edges().empty());

    graph vertices_graph(vs);
    vertices_graph.print_adjacency_list();
    assert(vertices_graph.get_vertices().size() == 5);
    assert(vertices_graph.get_edges().empty());

    graph g(vs, es);
    assert(g.get_vertices().size() == 5);
    assert(g.get_edges().size() == 10);


    g.print_adjacency_list();
    
    std::cout << "Copy graph object" << std::endl;
    graph copy_of_g(g);
    copy_of_g.print_adjacency_list();
}
