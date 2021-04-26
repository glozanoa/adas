#!/usr/bin/env python3

# Generate random integer numbers to test algorithms
#
# Maintainer: glozanoa <glozanoa@uni.pe>

import random
import argparse

def randint(a:int, b:int, n:int):
    if a <= b and n > 0:
        while n > 0:
            yield random.randint(a, b)
            n-=1
    else:
        raise Exception(f"Invalid arguments: a={a}, b={a}, n={n}")

def randint2file(a:int, b:int, n:int, file_name:str):
    with open(file_name, 'w') as random_file:
        for random_int in randint(a, b, n):
            random_file.write(f"{random_int}\n")

def randint_parser():
    parser = argparse.ArgumentParser(description='Random integers generator')
    parser.add_argument("minimum", type=int,
                        help="Minimum random integer")
    parser.add_argument("maximum", type=int,
                        help="Maximum random integer")
    parser.add_argument("nrand", type=int,
                        help="Number of random integers")
    parser.add_argument("path", type=str,
                        help="File to save generated random integers")

    return parser

def main():
    parser = randint_parser()
    args = parser.parse_args()
    randint2file(args.minimum, args.maximum, args.nrand, args.path)

if __name__=="__main__":
    main()
