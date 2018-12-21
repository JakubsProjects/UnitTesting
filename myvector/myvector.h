/*myvector.h*/

//
// myvector class --- a replacement for std::vector based on linked
// nodes of varying-sized array "chunks".  The idea is to avoid the
// reallocation of the underlying dynamic array (and the copying of 
// elements) when the vector becomes full.
//
// <<Jakub Glebocki>>
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
		delete[] Elements;
      // TODO: save this for the last step
    }

    void push_back(const T& e)
    {
      // NOTE: this function assumes there is room in the node to push in
      // another element --- check first before calling!
		//...done?

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
	  :Head(new Node(4)), Tail(Head), NumElems(0), NumNodes(1)
  {
    // TODO: not yet implemented
	  //done
	  Node *temporaryNode = other.Head;

	  while (temporaryNode != nullptr) {

		  for (int i = 0; i < temporaryNode->NumElems; i++) {
			  this->push_back(temporaryNode->Elements[i]);
		  }
		  temporaryNode = temporaryNode->Next;
	  }
  }
  
  // destructor:
  ~myvector()
  {
	  Node* temp = Head;
	  while (Head != nullptr) {

		  Head = Head->Next;
		  delete temp;
		  temp = Head;

	  }

	  delete[] Head;
    // TODO: save this for the last step
  }

  int size() const
  {
    // TODO: not yet implemented, return # of elements currently in vector
	  //done
    return NumElems;
  }

  int capacity() const
  {
    // TODO: not yet implemented, return how many elements we can store
    // given the current # of nodes in the linked-list
	  //done
	  return (Tail->NodeSize - Tail->NumElems) + NumElems;
  }

  int nodes() const
  {
    // TODO: not yet implemented, return # of nodes in the linked-list
	  //done
	  return NumNodes;
  }

  void push_back(const T& e)
  {
    // TODO: needs to be generalized to link on a new node when
    // the current node becomes filled:
	  //done
	  if (Tail->NumElems == Tail->NodeSize) {
		  auto *temporary = new Node(Tail->NodeSize *2);
		  Tail->Next = temporary;
		  Tail = temporary;
		  NumNodes++;
	  }

    Tail->push_back(e);  // initial code to help you get started:
    NumElems++;
  }

  T& operator[](int i)
  {
	  Node *temp = Head;
	  int OldNodeSize = 0;
	  int SizeOfNode = 0;
	  int ithPos = 0;

	  while (temp != temp->Next) 
	  {
		  OldNodeSize = SizeOfNode;
		  SizeOfNode = temp->NodeSize + SizeOfNode;

		  if (SizeOfNode > i) {
			  break;
		  }

		  temp = temp->Next;
	  }
	  ithPos = abs(OldNodeSize - i);
	  return temp->Elements[ithPos];

    // TODO: not yet implemented, return ith element.  Assume i is valid.
	  //done
  }

  T& front()
  {
    // Return first element (this is working code):
	  //done
    return Head->Elements[0];
  }

  T& back()
  {
    // Return last element (this is working code):
	  //done
    return Tail->Elements[Tail->NumElems - 1];
  }



	  class iterator
	  {
	  public:
		  Node * Pointer;
		  int IterPos;
		  iterator(Node* pointer, int pos)
			  :Pointer(pointer), IterPos(pos)
		  {}

		  iterator& operator++()
		  {

			  if (Pointer->NodeSize == (1 + IterPos)) {
				  Pointer = Pointer->Next;
				  IterPos = 0;
			  }
			  else {
				  IterPos++;
			  }

			  return *this;

		  }
		  T& operator*()
		  {
			  // ? ? ?
			  return Pointer->Elements[IterPos];
		  }
		  bool operator!=(const iterator& rhs)
		  {
			  if ((rhs.Pointer == Pointer) && (rhs.IterPos == IterPos)) {
				  return false;
			  }
			  else {
				  return true;
			  }

		  }
	  };

	  iterator begin()
	  {
		return iterator(Head, 0);
	  }

	  iterator end()
	  {
		  if (Tail->NumElems != Tail->NodeSize) {
			  return iterator(Tail, Tail->NumElems);
		  }
		  else {
			  return iterator(Tail->Next, 0);
		  }
	  }
};
