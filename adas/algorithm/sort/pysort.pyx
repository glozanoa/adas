# Python wrapper of Cxx sort algorithms

from typing import List, Any

from libcpp.vector cimport vector
from libcpp cimport bool

cdef extern from "serial.hpp" namespace "adas::algorithm::sort::serial":
    void bubble[RandomAccessIterator](RandomAccessIterator first, RandomAccessIterator last, bool verbose) except +


cpdef pybubble(elements: List[Any], verbose:bool = False):
    """
    Bubble sort algorithm

    Parameters
    ----------
    elements: List[Any]
        List of elements to sort
    verbose: bool
        Increase verbosity of algorithm
    """
    cdef vector[int] cxx_elements = elements
    bubble(cxx_elements.begin(), cxx_elements.end(), verbose)

cpdef hi(name:str):
    print(f"Hi {name}")
