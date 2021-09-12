#!/usr/bin/env python3
"""
Vertex class
"""


from typing import Any


class Vertex:
    """
    Vertex class for undirected Graphs
    """
    def __init__(self, key: Any, degree: int = 0):
        """
        Constructor for Vertex class

        Parameters
        ----------
        key: Any
            Data of vertex
        degree: int
            Degree of vertex
        """
        if degree < 0:
            raise Exception(f"Invalid vertex degree: degree={degree}")

        self.key = key
        self.degree = degree

    def set_degree(self, degree: int):
        """
        Set vertex degree

        Parameters
        ----------
        degree: int
            Degree of vertex
        """
        if degree < 0:
            raise Exception(f"Invalid vertex degree: degree={degree}")
        self.degree = degree

    def __eq__(self, vertex):
        """
        Comparison between vertices

        Parameters
        ----------
        vertex: Vertex
            Vertex to compare

        Returns
        -------
        bool:
           True if both are equals and False otherwise
        """
        if self.key == vertex.key and self.degree == vertex.degree:
            return True
        return False

    def __str__(self):
        return f"Vertex(key={self.key}, degree={self.degree})"
