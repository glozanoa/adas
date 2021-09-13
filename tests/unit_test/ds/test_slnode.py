#!/usr/bin/env python3
#
# Unit Test for SLNode class (Single Linked Node)

import unittest

from adas.ds import SLNode


class Test(unittest.TestCase):
    def test_default_contructor(self):
        key = 1
        slnode = SLNode(key)

        self.assertEqual(slnode.key, key)
        self.assertIsNone(slnode.next_node, 'Default parameter for next_node is None')

    def test_has_key(self):
        key = 1
        node = SLNode(key)

        self.assertTrue(node.has_key(key))

    def test_eq_operator(self):
        key = 1
        node = SLNode(key)
        other = SLNode(key)

        self.assertEqual(node, other, 'Both nodes has the same key and next_node=None')
    
        extra_key = 100
        extra_node = SLNode(extra_key)
        node.next_node = extra_node

        self.assertNotEqual(node, other, 'Both nodes hash the same key but diferent next_node')

    def test_lt_operator(self):
        k1 = 1
        k2 = 100

        n1 = SLNode(k1)
        n2 = SLNode(k2)

        self.assertTrue(n1 < n2, 'node n2 key(100) id greather than node n1 key(1)')

