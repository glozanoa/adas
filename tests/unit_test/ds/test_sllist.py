#!/usr/bin/env python3
#
# Unit Test for SLList class (Single Linked List)

import unittest

from adas.ds import SLList
from adas.ds import SLNode


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
        #import pdb; pdb.set_trace()
        slist = SLList(size)

        self.assertEqual(size, len(slist), 'Comparing size (len function)')

        real_size = 0
        node = slist.head
        while not node is None:
            real_size += 1
            node = node.next_node

        self.assertEqual(size, real_size,  'Comparing real size (Counting nodes)')

    def test_push_back2no_empty_list(self):
        # node to push back
        key = 1
        node = SLNode(key)

        # single linked list
        size = 10
        slist = SLList(size)

        slist.push_back(node)

        self.assertEqual(size+1, len(slist), 'Comparing size after push back')
        self.assertEqual(slist.tail, node, 'Testing if added node is the tail')
        self.assertIsNone(slist.tail.next_node, 'next node of tail is None')

    def test_push_back2empty_list(self):
        slist = SLList()

        key = 1
        extra_node = SLNode(key)
        node = SLNode(key, extra_node)

        slist.push_back(node)
        
        self.assertEqual(1, len(slist), 'Comparing size after push back')
        self.assertEqual(slist.tail, node, 'Testing if added node is the tail')
        self.assertIsNone(slist.tail.next_node, 'next node of tail is None')






