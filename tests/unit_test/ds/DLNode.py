#!/usr/bin/env python3
#
# Unit Test for DLNode class (Double Linked Node)

import unittest

from adas.ds import DLNode, DLNT


class Test(unittest.TestCase):

    def test_default_contructor(self):
        key = 1
        node = DLNode(key)

        self.assertTrue(node.has_key(key))
        self.assertIsNone(node.next_node, 'Default value for next_node is None')

        self.assertIsNone(node.prev_node, 'Default value for prev_node is None')
    
    def test_set_node(self):
        key = 1
        node = DLNode(key)
        prev_node = DLNode(100)
        node.set_node(prev_node, DLNT.PREV_NODE)

        self.assertEqual(node.prev_node, prev_node)

    def test_has_key(self):
        key = 10
        node = DLNode(key)

        self.assertTrue(node.has_key(key))

    def test_eq_operator(self):
        key = 1
        node = DLNode(key)
        other = DLNode(key)

        self.assertEqual(node, other, 'Both nodes has the same key and next_node=None and prev_node=None')
    
        extra_key = 100
        extra_node = DLNode(extra_key)
        node.set_node(extra_node, DLNT.NEXT_NODE)

        self.assertNotEqual(node, other, 'Both nodes hash the same key but diferent next_node')

    def test_lt_operator(self):
        k1 = 1
        k2 = 100

        n1 = DLNode(k1)
        n2 = DLNode(k2)

        self.assertTrue(n1 < n2, 'node n2 key(100) id greather than node n1 key(1)')

