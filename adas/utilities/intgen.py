#!/usr/bin/env python3
#
# Generate random integer numbers to test algorithms

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
