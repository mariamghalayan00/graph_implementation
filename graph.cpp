#include "graph.hpp"
#include <iostream>
#include <algorithm>
#include <map>


void graph::print_adjacency_list()
{
    for (const auto& n : m_adjacency_list) {
        std::cout << n.first << " ";
        for (const auto &v : n.second) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

void graph::add_vertex(const graph::vertex_descriptor& v)
{
	if (m_adjacency_list.find(v) == m_adjacency_list.end()) {
        vertices adjacent_vertices;
		m_adjacency_list[v] = adjacent_vertices;
	} else {
        std::cout << "The vertex " << v << " is already in graph\n";
    }
}

void graph::add_vertices(const graph::vertices& v)
{
	for (auto it = v.begin(); it != v.end(); ++it) {
		add_vertex(*it);
	}
}

void graph::add_edge(const graph::edge& e)
{
    if (std::find(m_adjacency_list[e.first].begin(),
                  m_adjacency_list[e.first].end(),
                  e.first) == m_adjacency_list[e.first].end()) {
        m_adjacency_list[e.first].push_back(e.second);
        m_adjacency_list[e.second].push_back(e.first);
    } else {
        std::cout << "This edge already exists." << std::endl;
    }
}

bool graph::is_vertex_in_values(graph::vertex_descriptor vertex_to_search,
                                const vertices& vs)
{
    // why not return !(condition); ?????
    return !(std::find(vs.begin(), vs.end(), vertex_to_search) == vs.end());
}

bool graph::check_edge_uniqueness(const graph::edge &e)
{
    if (m_adjacency_list.contains(e.first)) {
        if (is_vertex_in_values(e.second, m_adjacency_list[e.first])) {
            return false;
        }
    }
    return true;
}

void graph::add_edges(const graph::edges& edges)
{
	for (const auto& edge : edges) {
        // check !!!
        if (check_edge_uniqueness(edge)) {
            add_edge(edge);
        }
	}

}
graph::edges graph::get_edges()
{
    edges all_edges{};
    for (const auto& [key, value] : m_adjacency_list) {
        for (const auto& it : value) {
            all_edges.push_back({key, it});
        }
    }
    return all_edges;
}

graph::vertices graph::get_vertices()
{
    vertices all_vertices{};
    for (const auto& [key, value] : m_adjacency_list) {
        all_vertices.push_back(key);
    }

    return all_vertices;
}

graph::graph(const graph::vertices& vertices, const graph::edges& edges)
{
	add_vertices(vertices);
	add_edges(edges);
}

graph::graph(graph::vertices vertices)
{
	add_vertices(vertices);
}

graph::graph(const graph& g)
{
    for (const auto& [key, value] : g.m_adjacency_list) {
        m_adjacency_list[key];
        for (const auto& it: value) {
            m_adjacency_list[key].push_back(it);
        }
    }
}

graph& graph::operator=(const graph& g) {
    m_adjacency_list.clear();
    for (const auto& [key, value] : g.m_adjacency_list) {
        m_adjacency_list[key];
        for (const auto& it: value) {
            m_adjacency_list[key].push_back(it);
        }
    }
    return *this;
}
