#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath> // for floor()

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor((values.size()-1) / 2);
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) 
{
  // TO BE IMPLEMENTED
  // set the index to next node
  values.push_back(value);
  int c_index = values.size() - 1;
  // initalise paretnt index 
  int p_index = 0;

  while(c_index > 0)
  {
    // for child at index c, their parent is at floor((c-1)/2)
    p_index = floor((c_index - 1) / 2);

    if (values[c_index] < values[p_index])
    {
      // swap/ heapify
      std::swap(values[c_index], values[p_index]);
      c_index = p_index;
    }
    else
    {
      // break out of loop if no need to heapify 
      break;
    }
  
   /*
   // use heapify, dont swap
   for (int i = p_index; i >= 0; i--)
   {
    heapify(i);
   }
   */
  }
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) 
{
  // TO BE IMPLEMENTED
  // set to -1 so we can check later if we could find the thing to remove
  int i = -1;
  for (int index = 0; index < values.size(); i++)
  {
    if (values[index] == value)
    {
      i = index;
      break;
    }
  }
  // if target not found 
  if (i == -1)
  {
    return;
  }
  // swap with the last node and then heapify to restore heap property
  std::swap(values[i], values[values.size() - 1]);
  values.pop_back();
  heapify(i);
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() 
{
  // TO BE IMPLEMENTED
  // if empty then return 
  if (values.empty())
  {
    return T();
  }
  // min heap, first value is smallest
  return values[0];
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;

    // heapify the swapped index - it may need to move
    // further down the 'tree'
    heapify(index_of_smallest);
  }
}

#endif