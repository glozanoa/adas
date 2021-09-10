# Python wrapper of Cxx sort algorithms

from libcpp.vector import vector

cdef extern from "sort/serial.hpp" namespace "adas::algorithm::sort::serial":    
    void bubble(vector[T].iterator first, vector[T].iterator last, bool verbose)


cpdef pybubble(elements: vector, verbose:bool = False):
    bubble(elements.begin(), elements.end(), verbose)
