# Algorithms
C++ Algortihms and Data Structures for `CC232`.

Almost all algorithms use iterators and the defined data structures use templates, so you can use each algorithm in a variety of containers.  
Also we try to codify some algorithms with `OpenMP` support, so you can use them to process efficiently large amounts of data.

## Developed Algorithms and data structures

#### Sort Algorithms
+ Sort with comparison
    
| Algorithm | Efficiency   | OpenMP |
|-----------|--------------|:------:|
| bubble    |              | `NO`   |
| bibubble  |              | `NO`   |
| insertion |              |        |
| selection |              |        |
| merge     |              |        |
| heap_sort | `O(n log n)` |        |
    
+ Sort without comparison
    
| Algorithm | Efficiency | OpenMP |
|-----------|------------|:------:|
| counting  | `O(n)`     | `NO`   |

#### Search Algorithms

| Algorithm      | Efficiency | OpenMP | Comparisons      |
|----------------|------------|:------:|:----------------:|
| secuential     | `O(n)`     | `NO`   |                  |
| binary_search  |            | `YES`  |                  |
| min_element    | `O(n)`     | `NO`   | `n-1`            |
| max_element    | `O(n)`     | `NO`   |                  |
| minmax_element | `O(n)`     | `NO`   | `3*MAX_INT(n/2)` |


#### Data Structures
`Matrix<T>`, `Heap<T>`, `Tree<T>`, `BinaryTree<T>`, `Graph<T>`, `Partition<T>`, `Node<T>`, `BinaryNode<T>`

#### Namespaces
`print`, `sort`, `search`, `write`, `read`


**NOTE:**  
* In `Developed Data Structures` section, we use `<T>` to express that the `Data Structure` supports `templates`.
* For more details about `Dependences` or `Usage` of *algorithms*, *data structures* and *utilities* check our [wiki](https://github.com/glozanoa/algorithms/wiki).
