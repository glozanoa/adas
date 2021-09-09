# Python wrapper of Cxx sort algorithms

from libcpp.vector import vector

cdef extern from "sort/serial.hpp" namespce "adas::algorithm::sort::serial":    
    void bubble(vector[T].iterator first, vector[T].iterator last, bool verbose)


cpdef bubble(vector, verbose:bool = False):
    return bubble(vector.begin(), vector.end(), verbose)
