/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>

using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	array<T> t1;
  array<T> t2;
	int n;   // number of values in T
	int q;   // number of non-null entries in T
	int d;   // t.length = 2^d
	T null, del;
	void resize();
	int hash(T x) { // new hash function
    int m = (1 << d);
    return (unsigned) ((x*3)/7) % m;
	}
  int doubleHash(T x, int i) { //simplified double hash equation to a method
    int m = (1 << d);
    return (hash(x) + (i * (1 + (hash(x) % (m - 1))))) % m;
  }

public:
	LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() { return n; }
	void clear();
	// FIXME: yuck
	void setNull(T null) { this->null = null; t.fill(null); }
	void setDel(T del) { this->del = del; }
};

/*
template<>
LinearHashTable<int>::LinearHashTable() : t(2, INT_MIN) {
	null = INT_MIN;
	del = INT_MIN + 1;
	n = 0;
	q = 0;
	d = 1;
}
*/

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() : t1(1, -1), t2(1, -1) {
	this->null = -1; // assuming the template type is int
	this->del = -2;

  n = 0;
	q = 0;
	d = 1;
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) : t1(1, null), t2(1, null)  {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
	d = 1;
	while ((1<<d) < 3*n) d++;
	array<T> tnew1((1<<d)/2, null);
  array<T> tnew2((1<<d)/2, null);
	q = n;
	// insert everything into tnew1 and tnew2

  for (int k = 0; k < t1.length; k++) { // interate through first backing array
    if (t1[k] != null && t1[k] != del) { // check to see if value exists at index
      int i = hash(t1[k]); // rehash
      bool number_added = false;
      int times_hashed = 1;
      
      while (number_added == false) { // iterate though until a valid index is double hashed
        if (i < tnew1.length) { // check to see if it should be added to first backing array
          if (tnew1[i] != null) {
            i = doubleHash(t1[k], times_hashed); // double hash
            times_hashed++;
          }
          else {
            number_added = true;
          }
        }
        else { // it must be added to second backing array based on current has number
          if (tnew2[i - tnew1.length] != null) {
            i = doubleHash(t1[k], times_hashed);
            times_hashed++;
          }
          else {
            number_added = true;
          }
        }
      }

      if (i < tnew1.length) {
        tnew1[i] = t1[k];
      }
      else {
        tnew2[i - tnew1.length] = t1[k];
      }
    }
  }

  for (int k = 0; k < t2.length; k++) { // interate through second backing array
    if (t2[k] != null && t2[k] != del) { // check to see if value exists at index
      int i = hash(t2[k]); // rehash
      bool number_added = false;
      int times_hashed = 1;

      while (number_added == false) { // iterate though until a valid index is double hashed
        if (i < tnew1.length) { // check to see if it should be added to first backing array
          if (tnew1[i] != null) { // check if i is a valid index to insert value
            i = doubleHash(t2[k], times_hashed); // i is not valid, double hash to get new i
            times_hashed++;
          }
          else { // i is valid
            number_added = true;
          }
        }
        else { // it must be added to second backing array based on current has number
          if (tnew2[i - tnew1.length] != null) {
            i = doubleHash(t2[k], times_hashed);
            times_hashed++;
          }
          else {
            number_added = true;
          }
        }
      }

      if (i < tnew1.length) {
        tnew1[i] = t2[k];
      }
      else {
        tnew2[i - tnew1.length] = t2[k];
      }
    }
  }

	t1 = tnew1; // replace backing arrays with larger arrays
  t2 = tnew2; // that have their values rehashed
}

template<class T>
void LinearHashTable<T>::clear() {
	n = 0;
	q = 0;
	d = 1;
	array<T> tnew(2, null);
	t = tnew;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
	if (find(x) != null) return false;
	if (2*(q+1) > (t1.length + t2.length)) resize();   // max 50% occupancy
	int i = hash(x);
  int times_hashed = 1;
  bool valid_index_hashed = false;

  while (valid_index_hashed == false) { // iterate through until a valid index is hashed
    if (i < t1.length) { // index falls in first backing array
      if (t1[i] != null && t1[i] != del) {
        i = doubleHash(x, times_hashed); // i is not a valid index
        times_hashed++;
      }
      else { // valid index is hashed
        valid_index_hashed = true;
      }
    }
    else { // index falls in second backing array
      if (t2[i - t1.length] != null && t2[i - t1.length] != del) {
        i = doubleHash(x, times_hashed);
        times_hashed++;
      }
      else {
        valid_index_hashed = true;
      }
    }
  }

  if (i < t1.length) { // check correct backing array to increment q
    if (t1[i] == null) q++;
  }
  else {
    if (t2[i - t1.length] == null) q++;
  }

	n++;

  if (i < t1.length) { // add value to correct backing array
    t1[i] = x;
  }
  else {
    t2[i - t1.length] = x;
  }
	return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
	int i = hash(x);
  int times_hashed = 1;
  bool value_found = false;

  while (value_found == false) { // iterate until value is found
    if (i < t1.length) { // check which backing array to access
      if (t1[i] != null) {
        if (t1[i] != del && t1[i] == x) { 
          return t1[i]; // return found value
        }
        else {
          i = doubleHash(x, times_hashed); // double hash
          times_hashed++; // increment times hashed
        }
      }
      else {
        value_found = true;
      }
    }
    else { // access decond backing arry
      if (t2[i - t1.length] != null) {
        if (t2[i - t1.length] != del && t2[i - t1.length] == x) {
          return t2[i - t1.length]; // return found value
        }
        else {
          i = doubleHash(x, times_hashed); // double hash
          times_hashed++; // increment times hashed
        }
      }
      else {
        value_found = true;
      }
    }
  }	
  
  return null; // return if no value is found
}

template<class T>
T LinearHashTable<T>::remove(T x) {
	int i = hash(x);
  int times_hashed = 1;
  bool value_removed = false;

  while (value_removed == false) { // iterate until value is found
    if (i < t1.length) { // access correct backing array
      T y = t1[i]; 
      if (y != del && x == y) { // check is value was hashed correctly
        t1[i] = del;
        n--;
        if (8 * n < (t1.length + t2.length)) resize(); // resize if less than 12.5%
        return y; // return removed value
      }
      else if (y == null) {
        value_removed = true;
      }
    }
    else { // index is in second backing array
      T y = t2[i - t1.length];
      if (y != del && x == y) {
        t2[i - t1.length] = del;
        n--;
        if (8 * n < (t1.length + t2.length)) resize();
        return y; // return removed value
      }
      else if (y == null) {
        value_removed = true;
      }
    }
    i = doubleHash(x, times_hashed); // double hash if value has not been found
    times_hashed++; // increment double hash
  }

	return null; // no value removed
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
	if (2*(q+1) > (t1.length + t2.length)) resize();   // max 50% occupancy
	int i = hash(x);
  int times_hashed = 1;
  bool hash_is_valid = false;

  while (hash_is_valid == false) { // iterate until value is found
    if (i < t1.length) { // check correct backing array
      if (t1[i] != null)
      {
        if (t1[i] != del && x.equals(t1[i])) {
          return false; // value exists
        }
        else {
          i = doubleHash(x, times_hashed);
          times_hashed++;
        }
      }
      else {
        hash_is_valid = true; // correct index hashed
      }
    }
    else { // index is in second backing array
      if (t2[i - t1.length] != null)
      {
        if (t2[i - t1.length] != del && x.equals(t2[i - t1.length])) {
          return false; // value exists
        }
        else {
          i = doubleHash(x, times_hashed);
          times_hashed++;
        }
      }
      else {
        hash_is_valid = true;
      }
    }
  }

  if (i < t1.length) { // add value to correct backing array
    t1[i] = x;
  }
  else {
    t2[i - t1.length] = x;
  }
	n++; q++;
	return true;
}


} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
