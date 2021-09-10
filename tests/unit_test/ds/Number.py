import unittest

from adas.ds import Number


class TNodeTest(unittest.TestCase):
    def test_is_par(self):
        import pdb; pdb.set_trace()
        n = Number(4)
        self.assertTrue(n.is_par())
