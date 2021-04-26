# Algorithms
C++ Algortihms and Data Structures for `CC232`.

Almost all algorithms use iterators and the defined data structures use templates, so you can use each algorithm in a variety of containers.  
Also we try to codify some algorithms with `OpenMP` support, so you can use them to process efficiently large amounts of data.

# Dependences
* Boost (`Program Options` library)
* C++ Compiler with `OpenMP` support (almost all)

**NOTE:**  
If you are a windows user, you can use [Mingw](http://mingw-w64.org/doku.php/start) as C++ compiler.

# Usage
There are several examples (in [tests](https://github.com/glozanoa/algorithms/tree/master/tests) directory) that show you how you can use developed algorithms and  data structures.

```
EXAMPLES STRUCTURE
|- base   # This directory contains examples of how to use defined data structures
|- sort   # This directory contains examples of how to use sort algorithms
|- seach  # This directory contains examples of how to use search algorithms
|- data   # This directory contains data to test algorithms efficiency
```


# Compilation
To Compile examples, you've to have [CMake](https://cmake.org/).

### Windows Users
Open `PowerShell`
```bash
 New-Item -Path .\build -ItemType Directory
 cd .\build
 cmake -G "MinGW Makefiles" ..
 mingw32-make.exe all
```

### Linux Users
```bash
mkdir -p build && cd build
cmake ..
cmake --build .
```

# Utilities
In [dgen](https://github.com/glozanoa/algorithms/tree/master/dgen) (*data generator*) directory you can find useful **python** scripts to generate random data to test algorithms efficiency.

To learn more about what does a script do, run:

```bash
    python3 PATH2SCRIPT -h
```

