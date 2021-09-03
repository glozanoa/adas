#!/usr/bin/env python3

from .single_linked_node import SLNode

class SLList:
    """
    Single Linked List
    """

    def __init__(self, size:int = 0, default_key:Any = 0):
        if size < 0:
            raise Exception(f"Invalid size: size={size}")

        else if size == 0:
            self.head = None
            self.tail = None
            self.size = size
        else:
            self.head = SLNode(default_key)
            self.size = size

            node = self.head
            while size > 0:
                next_node = SLNode(default_key)
                node.next_node = next_node
                node = next_node
                size -= 1
            self.tail = node


    def push_back(self, node):
        """
        Push back a node to the list

        Parameters
        ----------
        node: SLNode
            Node to push back
        """
        if self.size == 0:
            self.head = self.tail = node
        else:
            node.next_node = None
            self.tail.next_node = node
            self.tail = node

        self.size += 1

    def push_front(self, node):
        """
        Push front a node to the list

        Parameters
        ----------
        node: SLNode
            Node to push front
        """
        if self.size == 0:
            self.head = self.tail = node
        else:
            node.next_node = self.head
            self.head = node

        self.size += 1


    def __iter__(self):
        self.node = self.head
        return self

    def __next__(self):
        if self.node is None:
            raise StopIteration
        else:
            self.node = self.node.next_node
            return self.node

    def __len__(self):
        return self.size
