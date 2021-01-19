#pragma once
#ifndef _STRING_H
#define _SREING_H

// default constructor 
string();

// copy constructor
string(const string &str);

// constructor with arguments
string(const char *s);
string(int n,char c);
// access charater 
const char &operator[](int n)const;
const char &at(int n) const;
char &operator[](int n);
char &at(int n);

// string length 
int length() const;
bool empty() const;

// string  assignment 
string &operator=(const string &s);
string &assign(const char *s);
string &assign(const char *s, int n);
string &assign(const string &s);
string &assign(int n,char c);
string &assign(const string &s,int start,int n);

// string append
string &operator+=(const string &s);
string &operator+=(const char *s);
string &append(const char *s);
string &append(const char *s,int n);
string &append(const string &s);
string &append(const string &s,int position,int n);
string &append(int n , char c);

// comparision
// more than return 1 ; equal return 0 ; less than return -1
int compare(const string &s)const;
int compare(const char *s)const;

// substring 
string substr(int position = 0 ; int n = npos )const;

// find  if not find return -1 
// from front to back
int find(char c , int pos = 0)const;
int find(const char *s,int pos=0)const;
int find(const string &s,int pos=0)const;
// from back to front
int rfind(char c,int pos=npos)const;
int rfind(const char *s,int pos=npos)const;

// replace
string &replace(int pos , int n,const char *s);
string &replace(int pos,int n, const string &s)
void swap(string &str);

// insert
string &insert(int pos,const char *s);
string &insert(int pos,const string &s);
string &insert(int pos,int n , char c);

// erase elements
string &erase(int pos =0,int n=npos);

#endif 

