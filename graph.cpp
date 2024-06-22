#include "graph.hpp"
#include <iostream>
#include <algorithm>


void graph::print_adjacency_list() {
	for (size_t i = 0; i < m_adjacency_list.size(); ++i) {
		for (int num : m_adjacency_list[i]) {
			std::cout << num << "->";
		}
		std::cout << std::endl;
	}
}

void graph::add_vertex(const graph::vertex_descriptor& v) {
	if (m_adjacency_list.find(v) != m_adjacency_list.end()) {
        vertices adjacent_vertices;
		m_adjacency_list[v] = adjacent_vertices;
	}
}

void graph::add_vertices(const graph::vertices& v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		add_vertex(*it);
	}
}

void graph::add_edge(const graph::edge& e) {
	for (size_t j = 0; j < m_adjacency_list.size(); ++j) {
		if (m_adjacency_list[j].front() == e.first &&
		    check_edge_uniqueness(m_adjacency_list[j], e.second)) {
			m_adjacency_list[j].push_back(e.second);
		}
	}
}

void graph::add_edges(const graph::edges& edges) {
	for (size_t i = 0; i < edges.size(); ++i) {
		add_edge(edges[i]);
	}

}

bool graph::check_vertex_uniqueness(graph::vertex_descriptor v) {
	bool is_vertex_unique = true;
	for (size_t i = 0; i < m_adjacency_list.size(); ++i) {
		if (m_adjacency_list[i].front() == v) {
			is_vertex_unique = false;
			break;
		}
	}
	return is_vertex_unique;
}

bool graph::check_edge_uniqueness(const graph::vertices& adjacent_vertices,
				  graph::vertex_descriptor destination_vertex) {
	bool is_edge_unique = true;
	auto it = std::find(adjacent_vertices.begin(),
			    adjacent_vertices.end(), destination_vertex);
	if (it != adjacent_vertices.end()) {
		is_edge_unique = false;
	}
	return is_edge_unique;
}

graph::graph(const graph::vertices& vertices, const graph::edges& edges) {
	add_vertices(vertices);
	add_edges(edges);
}

graph::graph(graph::vertices vertices) {
	add_vertices(vertices);
}

