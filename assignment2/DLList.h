/*
* DLList.h
*
*  Created on: 2011-11-24
*      Author: morin
*/

#ifndef DLLIST_H_
#define DLLIST_H_

namespace ods {

  template<class T>
  class DLList {
  protected:
    struct Node {
      T x;
      Node *prev, *next;
    };
    Node dummy;
    int n;
    void remove(Node *w);
    Node* addBefore(Node *w, T x);
    Node* getNode(int i);
  public:
    DLList();
    virtual ~DLList();
    int size() { return n; }
    T get(int i);
    T set(int i, T x);
    virtual void add(int i, T x);
    virtual void add(T x) { add(size(), x); }
    virtual T remove(int i);
    virtual void clear();
    bool IsPalindrome();
    void Rotate(int r);
    void Absorb(DLList<T>* &l2);
    DLList<T> deal();
  };

  template<class T>
  DLList<T>::DLList() {
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
  }

  template<class T>
  typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
    Node *u = new Node;
    u->x = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    n++;
    return u;
  }

  template<class T>
  typename DLList<T>::Node* DLList<T>::getNode(int i) {
    Node* p;
    if (i < n / 2) {
      p = dummy.next;
      for (int j = 0; j < i; j++)
        p = p->next;
    }
    else {
      p = &dummy;
      for (int j = n; j > i; j--)
        p = p->prev;
    }
    return (p);
  }


  template<class T>
  DLList<T>::~DLList() {
    clear();
  }


  template<class T>
  void DLList<T>::clear() {
    Node *u = dummy.next;
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
    for (int i = size(); i != 0; i--) {
      Node *w = u->next;
      delete u;
      u = w;
    }
  }
  

  template<class T>
  void DLList<T>::remove(Node *w) {
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    n--;
  }


  template<class T>
  T DLList<T>::get(int i) {
    return getNode(i)->x;
  }

  template<class T>
  T DLList<T>::set(int i, T x) {
    Node* u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
  }

  template<class T>
  void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
  }

  template<class T>
  T DLList<T>::remove(int i) {
    Node *w = getNode(i);
    T x = w->x;
    remove(w);
    return x;
  }

  template<class T>
  bool DLList<T>::IsPalindrome() {
    Node* front_tmp = dummy.next;
    Node* back_tmp = dummy.prev;

    for (int i = 0; i < n / 2; i++) {
      if (front_tmp->x != back_tmp->x) {
        return false;
      }

      front_tmp = front_tmp->next;
      back_tmp = back_tmp->prev;
    }

    return true;
  }

  template<class T>
  void DLList<T>::Rotate(int r) {
    // simply move dummy to the int passed
    // update 2 pointers to remove dummy
    // update 4 pointers to instert dummy

    // Link head and tail to move dummy
    Node* current_tail = dummy.prev;
    Node* current_head = dummy.next;
    current_head->prev = current_tail;
    current_tail->next = current_head;

    Node* tmp_back = dummy.next; //pointer that iterates through loop

    for (int i = 0; i < r; i++) {
      tmp_back = tmp_back->next;
    }
    Node* tmp_front = tmp_back->prev;

    //insert dummy between tmp_front and tmp_back
    dummy.prev = tmp_front;
    dummy.next = tmp_back;
    tmp_front->next = &dummy;
    tmp_back->prev = &dummy;
  }

  template<class T>
  void DLList<T>::Absorb(DLList<T>* &l2) {
    dummy.prev->next = l2->dummy.next; //point tail of l1 to head of l2
    l2->dummy.next->prev = dummy.prev; //point head of l2 to tail of l1
    dummy.prev = l2->dummy.prev;       //point dummy.prev of l1 to tail of l2
    l2->dummy.prev->next = &dummy;     //point tail of l2 to dummy of l1

    l2->dummy.next = &(l2->dummy);  //point the dummy of l2 to itself
    l2->dummy.prev = &(l2->dummy);  //this clears the list l2
                                    //cannot call the clear method because then
                                    //then all of the nodes we just added to l1
                                    //will be deleted
    n = n + l2->size();
  }

  template<class T>
  DLList<T> DLList<T>::deal() {
    DLList<T> l2;

    if (size() > 1) { //Method does not need to run if n is less than 1
      Node* tmp = dummy.next;
      int index = 0;
      bool is_odd = false; //switch
      do {
        if (is_odd) {
          int e = tmp->x;
          l2.add(e);
          tmp = tmp->next;
          remove(index); // remove node from this list
          is_odd = false;
        }
        else {
          tmp = tmp->next;
          is_odd = true;
          index++;
        }
      } while (index != size());
    }

    return l2; // return list
  }

} /* namespace ods */
#endif /* DLLIST_H_ */


