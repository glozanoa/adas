#!/usr/bin/env python3

class Number:
    def __init__(self, value):
        self.value = value

    def is_par(self):
        return self.value %2 == 0
