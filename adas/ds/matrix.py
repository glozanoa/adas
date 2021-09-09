#!/usr/bin/env python3
"""
Generic Matrix, Diagonal Matrix and Identity Matrix classes
"""
from typing import Any, List

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


    def set_value(self, i:int, j:int, value:Any):
        """
        Set the item (i, j) with a supplied value

        Parameters
        ----------
        i: int
            Row index
        j: int
            Column index
        value: Any
            Value to set
        """
        if i*j < 0 or\
           i >= self.nrows or\
           j >= self.ncols:
            raise Exception(f"Index out of range: i={i}, j={j}")

        self.data[i][j] = value

    def __len__(self):
        return (self.nrows, self.ncols)

    def __call__(self, i, j):
        """
        Return the element i, j of the matrix

        Parameters
        ----------
        i: int
            Row index
        j: int
            Column index

        Returns
        -------
        Any:
            Element i, j of the matrix
        """
        if i*j < 0 or\
            i >= self.nrows or \
            j >= self.ncols:
            raise Exception(f"Index out of range: i={i}, j={j}")

        return self.data[i][j]

    def __add__(self, mtx):
        """
        Matrix adition operation

        Parameters
        ----------
        mtx: Matrix
            Matrix to add

        Returns
        -------
        Matrix:
            Adition matrix
        """
        if not isinstance(mtx):
            raise Exception(f"Undefined + operation betwee Matrix and {type(mtx)}")

        if self.nrows != mtx.nrows or self.ncols != mtx.ncols:
            raise Exception(f"Unmatching dimensions: {self.size()} and {mtx.size()}")

        sum_mtx = Matrix(self.nrows, self.ncols)

        for i in range(self.nrows):
            for j in range(self.ncols):
                sum_mtx.data[i][j] = self.data[i][j] + mtx(i, j)

        return sum_mtx

    def __str__(self):
        out = ""
        for i in range(self.nrows):
            for j in range(self.ncols):
                out += str(self.data[i][j]) + ' '
            out += "\n"
        return out

class Diagonal(Matrix):
    """
    Diagonal Matrix
    """
    def __init__(self, size, diagonal: List[Any] = None):
        """
        Contructor for Diagonal matrix
        """
        super().__init__(size, size)

        if diagonal is None:
            diagonal = [0]*size
        else:
            if len(diagonal) != size:
                raise Exception(f"No matching dimentions: matrix order = {size}, diagonal size = {len(diagonal)}")

        for k in range(size):
            self.data[k][k] = diagonal[k]


class Identity(Matrix):
    """
    Identity Matrix
    """
    def __init__(self, size, neutral_element:Any = 1):
        """
        Contructor for Identity matrix
        """
        super().__init__(size, size)

        for k in range(size):
            self.data[k][k] = neutral_element


class NullMatrix(Matrix):
    """
    Null Matrix
    """
    def __init__(self, size):
        """
        Contructor for Null matrix (matrix of zeros)
        """
        super().__init__(size, size, 0)
