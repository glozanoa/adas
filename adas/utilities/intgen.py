#!/usr/bin/env python3

# Generate random integer numbers to test algorithms
#
# Maintainer: glozanoa <glozanoa@uni.pe>

import random
import argparse

# debuged - date Apr 30 2021
def randint(a:int, b:int, n:int, unique:bool):
    """
    Generated n random intergers between a and b
    If unique=True generate unique random intergers
    """
    #import pdb; pdb.set_trace()
    if a <= b and n > 0:
        if not unique:
            while n > 0:
                yield random.randint(a, b)
                n-=1

        else: # return a list with unique random numbers
            unique_randint = []
            while n > 0:
                number = random.randint(a, b)
                if number not in unique_randint:
                    unique_randint.append(number)
                    n -= 1
                    yield number

    else:
            raise Exception(f"Invalid arguments: a={a}, b={a}, n={n}")


# debuged - date Apr 30 2021
def randint2file(a:int, b:int, n:int, file_name:str, unique: bool):
    """
    Write generated random interger between a and b to file
    """
    #import pdb; pdb.set_trace()
    with open(file_name, 'w') as random_file:
        numbers = randint(a, b, n, unique)
        for random_int in numbers:
            random_file.write(f"{random_int}\n")

def randint_parser():
    parser = argparse.ArgumentParser(description='Random integers generator')
    parser.add_argument("-u", '--unique', action='store_true',
                        help="Generate unique random integers")
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

    randint2file(args.minimum, args.maximum, args.nrand, args.path, args.unique)


if __name__=="__main__":
    main()
