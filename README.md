# Algorithms
C++ Algortihms and Data Structures for `CC232`.

Almost all algorithms use iterators and the defined data structures use templates, so you can use each algorithm in a variety of containers.  
Also we try to codify some *multithread* algorithms, so you can use them to process efficiently large amounts of data.

## Developed Algorithms and data structures

#### Sort Algorithms
+ Sort with comparison
    
| Algorithm | Efficiency   | Serial | Multithread |
|-----------|:------------:|:------:|:-----------:|
| bubble    | `O(n^2)`     | `YES`  | `YES`       |
| bibubble  |              | `YES`  | `YES`        |
| insertion | `O(n^2)`     | `YES`  | `YES`       |
| selection | `O(n^2)`     | `YES`  | `YES`       |
| merge     |              | `YES`  |             |
| heap_sort | `O(n log n)` | `YES`  |             |
| quicksort | `O(n log n)` | `YES`  |             |
    
+ Sort without comparison
    
| Algorithm | Efficiency | Serial | Multithread |
|-----------|------------|:------:|-------------|
| counting  | `O(n)`     | `YES`  | `NO`        |

#### Search Algorithms

| Algorithm      | Efficiency | Serial | Multithread |
|----------------|:----------:|:------:|:-----------:|
| secuential     | `O(n)`     | `YES`  | `NO`        |
| binary_search  |            | `YES`  | `YES`       |
| min_element    | `O(n)`     | `YES`  | `NO`        |
| max_element    | `O(n)`     | `YES`  | `NO`        |
| minmax_element | `O(n)`     | `YES`  | `NO`        |



##### Data Structures: 
`Matrix<T>`, `Heap<T>`, `Tree<T>`, `BinaryTree<T>`, `Graph<T>`, `Partition<T>`, `Node<T>`, `BinaryNode<T>`, `BST<T>`

##### Namespaces: 
`sort` (`sort::serial`, `sort::parallel`), `search`, `print`, `write`, `read`


**NOTE:**  
* In `Developed Data Structures` section, we use `<T>` to express that the `Data Structure` supports `templates`.
* For more details about `Dependences` or `Usage` of *algorithms*, *data structures* and *utilities* check our [wiki](https://github.com/glozanoa/algorithms/wiki).
