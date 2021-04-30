#!/usr/bin/env python3

# Generate random floating point numbers (from an uniform distribution) to test sort and search algorithms
#
# Maintainer: glozanoa <glozanoa@uni.pe>

import random
import argparse
from math import isclose

def is_element(a: float, b: list[float]):
    for bk in b:
        if isclose(a, bk):
            return True
    return False

def uniform(a: float, b: float, n:int):
    """
    Generated n random numbers from a uniform distribution between a and b
    If unique=True generate unique random intergers
    """
    #import pdb; pdb.set_trace()
    if a <= b and n > 0:
        if not unique:
            while n > 0:
                yield random.uniform(a, b)
                n-=1

        else: # return a list with unique random numbers
            unique_numbers = []
            while n > 0:
                number = random.uniform(a, b)
                if is_element(number, unique_numbers):
                    unique_numbers.append(number)
                    n -= 1
                    yield number

    else:
            raise Exception(f"Invalid arguments: a={a}, b={a}, n={n}")

def randfp2file(a:float, b:float, n:int, file_name:str):
    with open(file_name, 'w') as random_file:
        for random_fp in uniform(a, b, n):
            random_file.write(f"{random_fp}\n")

def randfp_parser():
    parser = argparse.ArgumentParser(description='Random floating point numbers generator')
    parser.add_argument("-u", '--unique', action='store_true',
                        help="Generate unique random numbers")
    parser.add_argument("minimum", type=float,
                        help="Minimum random number")
    parser.add_argument("maximum", type=int,
                        help="Maximum random number")
    parser.add_argument("nrand", type=int,
                        help="Number of random numbers")
    parser.add_argument("path", type=str,
                        help="File to save generated random numbers")

    return parser

def main():
    parser = randfp_parser()
    args = parser.parse_args()
    randint2file(args.minimum, args.maximum, args.nrand, args.path, args.unique)

if __name__=="__main__":
    main()
