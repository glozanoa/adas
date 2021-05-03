# Algorithms
C++ Algortihms and Data Structures for `CC232`.

Almost all algorithms use iterators and the defined data structures use templates, so you can use each algorithm in a variety of containers.  
Also we try to codify some algorithms with `OpenMP` support, so you can use them to process efficiently large amounts of data.

## Developed Algorithms and data structures

#### Sort Algorithms
+ Sort with comparison
    
| Algorithm | Efficiency   | OpenMP |
|-----------|--------------|:------:|
| Bubble    |              | `NO`   |
| Bibubble  |              | `NO`   |
| Insertion |              |        |
| Selection |              |        |
| Merge     |              |        |
| HeapSort  | `O(n log n)` |        |
    
+ Sort without comparison
    
| Algorithm | Efficiency | OpenMP |
|-----------|------------|:------:|
| Counting  | O(n)       | `NO`   |

#### Search Algorithms

| Algorithm    | Efficiency | OpenMP |
|--------------|------------|:------:|
| Secuential   | `O(n)`     | `NO`   |
| BinarySearch |            | `YES`  |


#### Data Structures
`Matrix<T>`, `Heap<T>`, `Tree<T>`, `BinaryTree<T>`, `Graph<T>`, `Partition<T>`, `Node<T>`, `BinaryNode<T>`

#### Namespaces
`print`, `sort`, `search`


**NOTE:**  
* In `Developed Data Structures` section, we use `<T>` to express that the `Data Structure` supports `templates`.
* For more details about `Dependences` or `Usage` of *algorithms*, *data structures* and *utilities* check our [wiki](https://github.com/glozanoa/algorithms/wiki).
