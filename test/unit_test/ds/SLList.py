#!/usr/bin/env python3
#
# Unit Test for SLList class (Single Linked List)

import unittest

from adas.ds import SLList


class Test(unittest.TestCase):
    def test_default_contructor(self):
        slist = SLList()

        default_size = 0

        comparisons = [
            (default_size, slist.size, 'size'),
            (None, slist.head, 'head node'),
            (None, slist.tail, 'tail node')
        ]

        for expected_value, value, name in comparisons:
            self.assertEqual(expected_value, value, msg=f"Comparing {name} to default value")
    def test_size_constructor(self):
        size = 3
        slist = SLList(size)

        self.assertEqual(size, len(slist), 'Comparing size (len function)')

        real_size = 0

        node = slist.head
        while not node is None:
            real_size += 1
            node = node.next_node

        self.assertEqual(size, real_size,  'Comparing real size (Counting nodes)')
