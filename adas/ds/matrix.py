#!/usr/bin/env python3

from numpy import np

class Matrix:
    """
    Class to represent a generic matrix
    """
    def __init__(self, nrows:int, ncols:int, default_data = 0):
        """
        Parameters
        ---------
        nrows: int
            Number of rows
        ncols: int
            Number of columns
        default_data: Any, optional
            Default data to poblate the matrix (defualt: 0)
        """

        if nrows*ncols < 0:
            raise Exception(f"Invalid matrix dimensions: nrows={nrows}, ncols={ncols}")

        self.nrows = nrows
        self.ncols = ncols
        self.data  = [[default_data]*ncols]*nrows


    def size(self):
        return (self.nrows, self.ncols)

    def __add__(self, mtx):
        if not isinstance(mtx):
            raise Exception(f"Undefined + operation betwee Matrix and {type(mtx)}")

        if self.nrows != mtx.nrows or self.ncols != mtx.ncols:
            raise Exception(f"Unmatching dimensions: {self.size()} and {mtx.size()}")

        sum_mtx = Matrix(self.nrows, self.ncols)

    def as_numpy_array(self):
        return np.array(self.data)
