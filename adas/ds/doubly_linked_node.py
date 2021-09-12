#!/usr/bin/env  python3

from enum import Enum
from typing import Any

class DLNT(Enum):
    """
    Double Linked Node Type
    """
    NEXT_NODE = 0
    PREV_NODE = 1

class DLNode:
    """
    Double Linked Node
    """
    def __init__(self, key:Any, prev_node = None, next_node = None):
        """
        Contructor for DLNode class
        """
        self.key = key
        self.prev_node = prev_node
        self.next_node = next_node

    def set_node(self, node, ntype:DLNT):
        """
        Set a previous or next node

        Parameters
        ----------
        node: DLNode
            Node to set
        ntype: DLNT
            Type of node
        """
        if ntype is DLNT.NEXT_NODE:
            self.next_node = node
        else:
            self.prev_node = node
    
    def has_key(self, key:Any):
        """
        Check if a node has an specifc key
        
        Parameters
        ----------
        key: Any
            Key to check
        """
        return self.key == key

    def __lt__(self, node):
        """
        Lower than operator (between keys)
        
        Parameters
        ----------
        node: DLNode
            Node to compare
        """

        if not isinstance(node, DLNode):
            raise Exception(f"I can't compare DLNode with {type(node)}")
        return self.key < node.key

    def __str__(self):
        """
        String representation for DLNode class
        """
        return f"DLNode(key={self.key}, next={self.next_node}, prev={self.prev_node})"


    def __eq__(self, node):
        """
        Equal operator between 2 double linked nodes
    
        Parameters
        ----------
        node: DLNode
            Node to compare
        """
        if node and not isinstance(node, DLNode):
            raise Exception(f"I can't compare DLNode with {type(node)}")

        if self is None or node is None:
            if self is None and node is None:
                return True
            return False
        else:
            return self.key == node.key and\
                    self.next_node == node.next_node and\
                    self.prev_node == node.prev_node

    def __ne__(self, node):
        """
        No equal operator for DLNode class
        """
        return not self == node

