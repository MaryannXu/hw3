#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m_;
  PComparator c_;


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  std::size_t index = data.size() - 1;

  while (index != 0){
    std::size_t parent_index = (index -1) / m_;
    T& current = data[index];
    T& parent = data[parent_index];
    if (c_(parent,current)){
      break;
    }
    std::swap(data[index],data[parent_index]);
    index = parent_index;
  }

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
    return data.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }

  std::swap(data[0], data[data.size()-1]);
  data.pop_back();

  std::size_t index = 0;
  while (index <= data.size()-1){
  std::size_t bestchild = index;
  for (int i = 1; i <= m_; i++){
    std::size_t currentchild = (index*m_) + i;
    if (currentchild < data.size() && c_(data[currentchild], data[bestchild])){
      bestchild = currentchild;
    }
  }

  if (bestchild != index){
    std::swap(data[index],data[bestchild]);
    index = bestchild;
  }
  else{
    break;
  }
  }

  /*
    std::size_t leftchild = (index*m_) + 1;
    std::size_t rightchild = (index*m_) + 2;
    std::size_t temp = index;
    if (leftchild < data.size() && data[leftchild] > data[index]){
      temp = leftchild;
    }
    if (rightchild < data.size() && data[rightchild] > data[index]){
      temp = rightchild;
    }

    if (temp != index){
      std::swap(data[index],data[temp]);
      index = temp;
    }
    else {
      break;
    }
  }
  */


}



#endif

