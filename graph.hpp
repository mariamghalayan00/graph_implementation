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
    using vertex_descriptor = unsigned int;

    using edge = std::pair<vertex_descriptor, vertex_descriptor>;

    using vertices = std::vector<vertex_descriptor>;

    using edges = std::vector<edge>;

    /**
     * @brief Add new vertex to the graph
     * @param v - vertex
     */
    void add_vertex(const vertex_descriptor& v);

    /**
     *  @brief Add vertices to the graph
     *  @param v: vertices
     */
    void add_vertices(const vertices& v);

    /**
     * @brief Get all adjacent vertices of
     * @param The vertex for which its adjacent vertices must be returned
     */
    const vertices& get_adjacent_vertices(vertex_descriptor& v);
   
    /**
     * @brief Check whether vertex is is adjacent vertices
     * @param vertex_to_search - vertex to search for
     * @param vertices - vertices among which to search for the specific vertex
     */
    bool is_vertex_in_values(vertex_descriptor vertex_to_search, const vertices& vs);

    /**
     * @brief Add edge to the adjacency list
     * @param e - the edge to add
     */
    void add_edge(const edge& e);

    /**
     * @brief Add edges to the adjacency list
     * @param e - the edges to add to the adjacency list
     */
    void add_edges(const edges& e);

    /**
     * @brief Get all edges
     */
    edges get_edges();

    /**
     * @brief Get all vertices
     */
    vertices get_vertices();

    /**
     * @brief Print adjacency list
     */
    void print_adjacency_list();

private:
    /**
     * @brief Check vertex uniqueness
     * @param vertex - the vertex to search for in the adjacency list
     */
    bool check_vertex_uniqueness(vertex_descriptor vertex);

    /**
     * @brief Check edge uniqueness
     * @param e - the edge to search for in the adjacency list
     */
    bool check_edge_uniqueness(const graph::edge& e);

private:
    using adjacency_list = std::map<vertex_descriptor, vertices>;

    adjacency_list m_adjacency_list;


public:
    graph()
        : m_adjacency_list{}
    {}

    graph(vertices vertices);

    graph(const vertices& vertices, const edges& edges);

    /// This class is copy-constructible
    graph(const graph&);

    explicit graph(graph&& e); // graph a = g1; and graph a(g1);

    graph& operator=(const graph& r);

    graph& operator=(graph&& r); // g = std::move(g1);

    ~graph() {};

};

#endif

