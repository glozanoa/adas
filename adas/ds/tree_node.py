#!/usr/bin/env python3

from typing import List, Any

class TNode:
    """
    Tree node
    """
    def __init__(self, key:Any, parent = None, children = []):
        """
        Parameters
        ----------
        key: Any
            Node key
        parent: TNode
            Parent of node (default None)
        children: List[TNode]
            Children of node (default [])
        """
        self.depth  = 0
        self.height = 0

        if parent:
            if not isinstance(parent, TNode):
                raise Exception(f"Invalid paremeter type: parent type {type(parent)}")
            parent.add_child(self)

        else:
            self.parent = parent
            self.key = key
            self.children = children

    def set_depth(self, depth:int):
        """
        Set depth of a node recursively

        Parameters
        ----------
        depth: int
            Depth of node
        """
        if depth < 0:
            raise Exception(f"Invalid depth: depth={depth}")

        self.depth = depth
        for child in children:
            child.set_depth(depth+1)

    def __eq__(self, node):
        """
        Compare if 2 nodes are equals (key, depth and children)

        Parameters
        ----------
        node: TNode
            Node to compare

        Returns
        -------
        bool
            True if the nodes are equals and False otherwise
        """

        if self.key != node.key \
           or self.depth != node.depth:
            return False

        for child in node.children:
            if not self.has_child(child):
                return False

        return True

    def has_child(self, node):
        """
        Check if a node is its child

        Parameters
        ----------
        node: TNode
            Node to search

        Returns
        -------
        bool
            True if node is a child and False otherwise
        """

        for child in self.children:
            if node == child:
                return True
        return False
