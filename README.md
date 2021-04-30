# Algorithms
C++ Algortihms and Data Structures for `CC232`.

Almost all algorithms use iterators and the defined data structures use templates, so you can use each algorithm in a variety of containers.  
Also we try to codify some algorithms with `OpenMP` support, so you can use them to process efficiently large amounts of data.

# Dependences
* Boost (`Program Options` library)
* C++ Compiler with `OpenMP` support (almost all)

# Usage
There are several examples (in [tests](https://github.com/glozanoa/algorithms/tree/master/tests) directory) that show you how you can use developed algorithms and  data structures.

```
EXAMPLES STRUCTURE
|- base   # This directory contains examples of how to use defined data structures
|- sort   # This directory contains examples of how to use sort algorithms
|- seach  # This directory contains examples of how to use search algorithms
|- data   # This directory contains data to test algorithms efficiency
```
## Developed Algorithms


| Algorithm | Efficiency |
|-----------|------------|
| bubble    |            |
| bibubble  |            |
| insertion |            |
| selection |            |
| merge     |            |
| heap sort | O(n log n) |


# Compilation
* To compile all examples:
```bash
make all
```

* To compile examples of `sort` algorithms:
```bash
make sort
```

* To compile examples of `search` algorithms:
```bash
make search
```
* To compile examples that test data structures:
```bash
make base
```

* To compile a particular example:

```bash
make EXAMPLE_NAME
```

# Utilities
In [dgen](https://github.com/glozanoa/algorithms/tree/master/dgen) (*data generator*) directory you can find useful **python** scripts to generate random data to test algorithms efficiency.

To learn more about what does a script do, run:

```bash
    python3 PATH2SCRIPT -h
```

