#pragma once
#ifndef _VECTOR_H
#define _VERCTOR_H

/*--vector is a containerthat manages elements in a dynamic array--*/
/*--It is simple adding or removing elements at the tail ----------*/
/*--BUt in the header or middle is time-consuming -----------------*/
/*--Vector implementes via template calss,such as vector<int>------*/

// default constructor 
vector<int> v1;
vector<float> v2;
// class Teacher{};
vector<Teacher> T1;
// consreuctor with arguments
vector(n,elemet);
vector(const vector &vec);

// assignment
vector &assign(T begin,T end); // left closed and right open interval
vector &assign(int num,T element);
vector &operator=(const vector &vec);
vector &swap(vec);

// size
int size()const;
bool emtpy()const;
vector &resize(int num);
vector &resize(int num,T element);

// adding and removing at the tail
vector &push_back(T element);
vector &pop_back(T element);

// accessing data
const 

// vector::erase()
vector &erase(iterator position);
vector &erase(iterator first,iterator last);

// vector::clear()
void clear();



#endif
