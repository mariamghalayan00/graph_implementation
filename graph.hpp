// add vertices
// add edges
// add weights

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>

class graph
{
public:
    using vertex_descriptor = int;

    using edge = std::pair<int, int>;

    using vertices = std::vector<vertex_descriptor>;

    using edges = std::vector<edge>;

    void add_vertex(const vertex_descriptor& v);

    void add_vertices(const vertices& v);

    const vertices& get_adjacent_vertices(vertex_descriptor& );

    void add_edge(const edge& e);

    void add_edges(const edges& e);

    void print_adjacency_list();

private:
    bool check_vertex_uniqueness(int vertex);

    bool check_edge_uniqueness(const vertices& v,
                               vertex_descriptor destination);
private:
    using adjacency_list = std::map<vertex_descriptor, vertices>;
    adjacency_list m_adjacency_list;

public:
    graph()
        : m_adjacency_list{}
    {}

    graph(vertices vertices);

    graph(const vertices& vertices,
          const edges& edges);

    graph(const graph&);

    graph& operator=(const graph& r);

    explicit graph(graph&& e); // graph a = g1; and graph a(g1);

    graph& operator=(graph&& r); // g = std::move(g1);

    ~graph() {};
};

#endif

