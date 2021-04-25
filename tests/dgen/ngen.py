#!/usr/bin/env python3

# Generate random numbers to test sort and search algorithms
#
# Maintainer: glozanoa <glozanoa@uni.pe>

import random


def randint(a:int, b:int, n:int):
    if a <= b:
        while n >= 0:
            yield random.randint(a, b)
            n-=1


def randint2file(a:int, b:int, n:int, file_name:str):
    with open(file_name, 'w') as random_file:
        for random_int in randint(a, b, n):
            random_file.write(f"{random_int}\n")


if __name__=="__main__":
    randint2file(0, 20, 30, "random.txt")
