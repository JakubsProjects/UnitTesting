/*myvector.h*/

//
// myvector class --- a replacement for std::vector based on linked
// nodes of varying-sized array "chunks".  The idea is to avoid the
// reallocation of the underlying dynamic array (and the copying of 
// elements) when the vector becomes full.
//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS341, Spring 2018
// Project #03
//

#pragma once

#include <iostream>
#include <iterator>
#include <string>

using namespace std;


//
// myvector<T>
//
template<typename T>
class myvector
{
private:
  //
  // One node of the vector, i.e. an array "chunk" of size nodeSize.
  //
  class Node
  {
  public:
    T          *Elements;
    int         NumElems;
    int         NodeSize;
    class Node *Next;

    // constructor:
    Node(int nodesize)
      : Elements(new T[nodesize]), NumElems(0), NodeSize(nodesize), Next(nullptr)
    {
      string s = "Node: constructor called (size" + to_string(NodeSize) + ")";
      Logger::WriteMessage( s.c_str() );  // debug output:
    }

    // destructor:
    ~Node()
    {
      // TODO: save this for the last step
    }

    void push_back(const T& e)
    {
      // NOTE: this function assumes there is room in the node to push in
      // another element --- check first before calling!

      Elements[NumElems] = e;
      NumElems++;
    }
  };

  //
  // myvector:
  //
private:
  Node  *Head;
  Node  *Tail;
  int    NumElems;
  int    NumNodes;

public:
  myvector()
    : Head(new Node(4)), Tail(Head), NumElems(0), NumNodes(1)
  { 
    Logger::WriteMessage("myvector: constructor called");  // debug output:
  }

  // copy constructor:
  myvector(const myvector& other)
  {
    // TODO: not yet implemented
  }
  
  // destructor:
  ~myvector()
  {
    // TODO: save this for the last step
  }

  int size() const
  {
    // TODO: not yet implemented, return # of elements currently in vector
    return -1;
  }

  int capacity() const
  {
    // TODO: not yet implemented, return how many elements we can store
    // given the current # of nodes in the linked-list
  }

  int nodes() const
  {
    // TODO: not yet implemented, return # of nodes in the linked-list
  }

  void push_back(const T& e)
  {
    // TODO: needs to be generalized to link on a new node when
    // the current node becomes filled:

    Tail->push_back(e);  // initial code to help you get started:
    NumElems++;
  }

  T& operator[](int i)
  {
    // TODO: not yet implemented, return ith element.  Assume i is valid.
  }

  T& front()
  {
    // Return first element (this is working code):
    return Head->Elements[0];
  }

  T& back()
  {
    // Return last element (this is working code):
    return Tail->Elements[Tail->NumElems - 1];
  }

  //iterator begin()
  //{
  //  return iterator(???);
  //}

  //iterator end()
  //{
  //  return iterator(???);
  //}

};
