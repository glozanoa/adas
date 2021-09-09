#!/usr/bin/env python3
#
# Undirected Graph (matrix and adjacency list representation)

from typing import List

from .matrix import NullMatrix
from .vertex import Vertex

class UDGraphMatrix:
    """
    Undirected Graph with adjacency matrix as representation
    """
    def __init__(self, vertices: List[Vertex] = None):
        if vertices is None:
            self.vertices = []
            size = 0
            self.mtx = NullMatrix(size)
        else:
            self.vertices = vertices
            size = len(vertices)
            self.mtx = NullMatrix(size)

    def add_edge(self, init_vertex:Vertex, end_vertex:Vertex, weight:float):
        if init_vertex in self.vertices and end_vertex in self.vertices:
            i = self.vertices.index(init_vertex)
            j = self.vertices.index(end_vertex)
            self.mtx.set_value(i, j, weight)
        else:
            raise Exception(f"Any vertex doen't belong to the graph")

    def __str__(self):
        out = f"Vertices:\n"
        out += f"{[str(vertex) for vertex in self.vertices]}"

        out += "\nMatrix:\n"
        out += f"{self.mtx}"

        return out
