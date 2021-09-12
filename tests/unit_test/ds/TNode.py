#!/usr/bin/env python3
#
# Unit Test for TNode class (tree node)

import unittest

from adas.ds import TNode


class TNodeTest(unittest.TestCase):
    def test_default_contructor(self):
        key = 1
        node = TNode(key)

        comparisons = [
            (key, node.key, 'key'),
            (0, node.depth, 'depth'),
            (0, node.height, 'heigth'),
            (None, node.parent, 'parent'),
            ([], node.children, 'children')
        ]

        for expected_value, value, name in comparisons:
            self.assertEqual(expected_value, value, msg=f"Comparing {name} to default value")
