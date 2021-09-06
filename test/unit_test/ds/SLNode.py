#!/usr/bin/env python3
#
# Unit Test for SLNode class (Single Linked Node)

import unittest

from adas.ds import SLNode


class Test(unittest.TestCase):
    def test_has_key(self):
        key = 10
        node = SLNode(key)

        self.assertTrue(node.has_key(key))

    def test_eq_operator(self):
        key = 1
        node = SLNode(key)
        other = SLNode(key)

        self.assertTrue(node == other, 'Both nodes has the same key and next_node=None')
    
        extra_key = 100
        extra_node = SLNode(extra_key)
        node.next_node = extra_node

        self.assertFalse(node == other, 'Both nodes hash the same key but diferent next_node')

    def test_lt_operator(self):
        k1 = 1
        k2 = 100

        n1 = SLNode(k1)
        n2 = SLNode(k2)

        self.assertTrue(n1 < n2, 'node n2 key(100) id greather than node n1 key(1)')

