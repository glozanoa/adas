#!/usr/bin/env python3

# Generate random floating point numbers (from an uniform distribution) to test sort and search algorithms
#
# Maintainer: glozanoa <glozanoa@uni.pe>

import random
import argparse

def uniform(a: float, b: float, n:int):
    if a <= b and n > 0:
        while n > 0:
            yield random.uniform(a, b)
            n-=1
    else:
        raise Exception(f"Invalid arguments: a={a}, b={a}, n={n}")

def randfp2file(a:float, b:float, n:int, file_name:str):
    with open(file_name, 'w') as random_file:
        for random_fp in uniform(a, b, n):
            random_file.write(f"{random_fp}\n")

def randfp_parser():
    parser = argparse.ArgumentParser(description='Random floating point numbers generator')
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
    randint2file(args.minimum, args.maximum, args.nrand, args.path)

if __name__=="__main__":
    main()
