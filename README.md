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


<table>
    <tr>
        <th> TYPE </th>
        <th> NAME </th>
        <th> EFFICIENCY </th>
    </tr>
    <tr>
        <td> Sort </td>
        <td>
            <table>
                <tr>
                    <th> Bubble </th>
                </tr>
                <tr>
                    <th> Bibubble </th>
                </tr>
                <tr>
                    <th> Insertion </th>
                </tr>
                <tr>
                    <th> Selection </th>
                </tr>
                <tr>
                    <th> Merge </th>
                </tr>
                <tr>
                    <th> HeapSort </th>
                </tr>
            </table>
        </td>
        <td>
            <table>
                <tr>
                    <th> BUBBLE_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> BIBUBBLE_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> INSERTION_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> SELECTION_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> MERGE_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> HEAPSORT_COMPLEXITY </th>
                </tr>
            </table>
        </td>
    </tr>
    <tr>
        <td> Search </td>
        <td>
            <table>
                <tr>
                    <th> A1 </th>
                </tr>
                <tr>
                    <th> A2 </th>
                </tr>
                <tr>
                    <th> A3 </th>
                </tr>
                <tr>
                    <th> A4 </th>
                </tr>
                <tr>
                    <th> A5 </th>
                </tr>
                <tr>
                    <th> A6 </th>
                </tr>
            </table>
        </td>
        <td>
            <table>
                <tr>
                    <th> A1_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> A2_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> A3_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> A4_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> A5_COMPLEXITY </th>
                </tr>
                <tr>
                    <th> A6_COMPLEXITY </th>
                </tr>
            </table>
        </td>
    </tr>
</table>

<!-- | Algorithm | Efficiency | -->
<!-- |-----------|------------| -->
<!-- | bubble    |            | -->
<!-- | bibubble  |            | -->
<!-- | insertion |            | -->
<!-- | selection |            | -->
<!-- | merge     |            | -->
<!-- | heap sort | O(n log n) | -->


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

