#!/usr/bin/env python3
#
# Strassen's algorithm for matrix multiplication

from adas.ds import NMatrix

def strassen(mtx:NMatrix, other:NMatrix):
    """
    Strassen's algorithm for matrix multiplication

    Parameters
    ----------
    mtx: NMatrix
        Left numerical matrix to multiply
    other: NMatrix
        Right numerical matrix to multiply

    Returns
    -------
    NMatrix:
        Result of matrix multiplication
    """

    if mtx.ncols != other.nrows:
        raise Exception("Invalid matrices dimensions")

    if not (NMatrix.is_equare(mtx) and NMatrix.is_square(other)):
        raise Exception("Some matrix is not square")

    if not (mtx.nrows %2 == 0 and other.nrows %2 == 0):
        raise Exception("Some matrix dimension is not divisable by 2")

    # At this point,matrices are squares and their dimensions are divible by 2
    # Needed properties to apply strassen algorithm
    


