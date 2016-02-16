//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #2
// Class Implementation
// Professor: Howard Cheng
// Program: myString.cc
// Purpose: Takes the header file and defines all the elements of it
// Programming Partner: Anthony Tymburski
//********************************************************************
#include<iostream>
#include<cassert>
#include<cctype>
#include"myString.h"
using namespace std;

//********************************************************************
// Default Constructor
// Post-Condition -- The character array will be set to size 0 as
//                   defined by the nullpointer whilst the length will
//                   be set to 0 as well
//********************************************************************
myString::myString()
{
	str = nullptr;
	len = 0;
}

//********************************************************************
// Constructor to set the character array at 1
// Post-Condition -- The character array will be set to size 1 and
//                   contain the given char entered by the user. The
//                   length will also be set to 1.
//********************************************************************
myString::myString(char c)
{
	str = new char[1];
	str[0] = c;
	len = 1;
}

//********************************************************************
// Constructor to set the character array greater than 1
// Post-Condition -- The character array will be set to the length
//                   of the given array. The length will also be set to
//                   this value.
//********************************************************************
myString::myString(const char *c)
{
	str = nullptr;
	len = 0;
	int charNum = 0;
	
	while (c[charNum] != '\0')
		charNum++;
	
	len = charNum;
	str = new char[charNum];
	
	for (int i = 0; i < charNum; i++)
		str[i] = c[i];
}

//********************************************************************
// Constructor that copies another object.
// Post-Condition -- The contents of object 1, in this case, s, are 
//                   copied entirely into a new object by performing 
//                   a deep copy.
//********************************************************************
myString::myString(const myString& s)
{
	len = s.len;
	str = new char[len];
	
	for (int i = 0; i < len; i++)
	{
		str[i] = s.str[i];
	}
}

//********************************************************************
// Assignment Operator Overload
// Post-Condition -- The assignment operater is overloaded to ensure
//                   that any assignment makes a deep copy.
//********************************************************************
myString& myString::operator=(const myString& s)
{
	if (this != &s)
	{
		delete[] str;
		len = s.len;
		
		str = new char[len];
		
		for (int i = 0; i < len; i++)
		{
			str[i] = s.str[i];
		}
	}
	
	return *this;
}

//********************************************************************
// Destructor 
// Post-Condition -- Deallocates all memory used in the constructor.
//                   Essentially resets the myString.
//********************************************************************
myString::~myString()
{
	delete[] str;
	len = 0;
	str = nullptr;
}

//********************************************************************
// Function returns the value of the length of the string as defined
// in the constructor
//********************************************************************
int myString::length() const
{
	return len;
}

//********************************************************************
// Function receives an index at which the user would like to view and
// returns the contents of that index
//********************************************************************

char& myString::at(int i)
{
	assert(0 <= i && i < len);
	return str[i];
}

//********************************************************************
// Function receives an index at which the user would like to view and
// returns the contents of that index. However, this version ensures
// that the character is kept constant
//********************************************************************
const char& myString::at(int i) const
{
	assert(0 <= i && i < len);
	return str[i];
}

//********************************************************************
// Function receives a position and length of a substring within the
// current object and constructs a new object with that new string and
// returns it.
//********************************************************************
myString myString::substr(int k, int n) const
{
	assert(k + n <= len && k >= 0);
	
	myString subString;

	for (int i = 0; i < n; i++)
	{
		subString.resize(i);
		
		subString.str[i] = str[i + k];
	}
	
	return subString;
}

//********************************************************************
// Function takes in the string and indexes to where the user would
// like the string to be removed. It takes the starting point and
// the length from that point to be removed and removes them
//********************************************************************
myString& myString::erase(int k, int n)
{
	assert(k + n <= len && k >= 0);
	
	myString tempString{*this};
	int stringSize = len;
	
	delete[] str;
	str = nullptr;
	len = 0;
	
	for (int i = 0; i < k; i++)
	{	
		resize(len);
		
		str[i] = tempString.str[i];
	}
	
	for (int i = (k + n); i < stringSize; i++)
	{	
		resize(len);
		
		str[len - 1] = tempString.str[i];
	}
	
	return* this;
}

//********************************************************************
// Function takes in an index and a myString. It then inserts the 
// given myString at the index inputted from the user
//********************************************************************
myString& myString::insert(int k, const myString& s)
{
	assert(k >= 0 && k <= len);
	myString temp{*this};
	int size = len;
	
	delete[] str;
	str = nullptr;
	len = 0;
	
	for (int i = 0; i < k; i++)
	{
		resize(len);
		
		str[i] = temp.str[i];
	}
	
	for (int i = 0; i < s.length(); i++)
	{
		resize(len);
		
		str[i + k] = s.str[i];
	}
	
	for (int i = k; i < size; i++)
	{
		resize(len);
		str[i + s.length()] = temp.str[i];
	}
	
	return *this;
}

//********************************************************************
// Function takes in a string from the user and attempts to locate that
// string. If found, it returns the position of the start of that
// string. If not found, it returns an invalid position, IE, -1.
//********************************************************************
int myString::find(const myString &s) const
{
  for (int i = 0; i <= len - s.len; i++)
  {
    int match = 0;     
    while (match < s.len && str[i+match] == s.str[match]) 
    {
      match++;
    }

    if (match == s.len) 
    {
      return i;
    }
  }

  return npos;
}

//********************************************************************
//********************************************************************
istream& getline(istream& is, myString& s)
{
	s.str = nullptr;
	s.len = 0;
	
	char c;
	
	cin.get(c);
	
	while (c != '\n')
	{
		s.resize(s.length());
		
		s.str[s.length()-1] = c;
		
		cin.get(c);
	}
	
	return is;
}

//********************************************************************
//********************************************************************
char& myString::operator[](int i)
{
	assert(0 <= i && i < len);
	return str[i];
}

//********************************************************************
//********************************************************************
const char& myString::operator[](int i) const
{
	assert(0 <= i && i < len);
	return str[i];
}

//********************************************************************
//********************************************************************
myString& myString::operator+=(const myString& s)
{
	for (int i = 0; i < s.len; ++i)
	{
		resize(len);
		str[len - 1] = s.str[i];
	}
	return *this;
}

//********************************************************************
//********************************************************************
myString myString::operator+(const myString& s)
{
	myString newString{*this};
	
	for (int i = 0; i < s.len; ++i)
	{
		newString.resize(len);
		newString.str[len - 1] = s.str[i];
	}
	
	return newString;
}

//********************************************************************
//********************************************************************
bool myString::operator==(const myString& s) const
{
	bool isEqual = false;
	
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == s.str[i])
			isEqual = true;
		else
			isEqual = false;
	}
	return isEqual;	
}

//********************************************************************
//********************************************************************
bool myString::operator<(const myString& s) const
{
	for (int i = 0; i < len; ++i)
	{
		if (str[i] < s.str[i])
			return true;
		else if (str[i] > s.str[i])
			return false;
	}
	return false;
}

//********************************************************************
//********************************************************************
bool myString::operator!=(const myString& s) const
{
	return !(*this == s);
}

//********************************************************************
//********************************************************************
bool myString::operator<=(const myString& s) const
{
	return	(*this == s && *this < s);
}

//********************************************************************
//********************************************************************
bool myString::operator>(const myString& s) const
{
	return !(*this <= s);
}

//********************************************************************
//********************************************************************
bool myString::operator>=(const myString& s) const
{
	return !(*this < s);
}
//********************************************************************
// Function takes a character array and resizes it to a size that is
// 1 greater than its former size
//********************************************************************
void myString::resize(int n)
{
	char *temp;
	
	temp = new char[n];
	
	for (int i = 0; i < n; i++)
	{
		temp[i] = str[i];
	}
	
	delete[] str;
	
	len = n+1;
	
	str = new char[len];
	
	for (int i = 0; i < n; i++)
	{
		str[i] = temp[i];
	}
	
	delete[] temp;
	temp = nullptr;
}

//********************************************************************
//********************************************************************
ostream& operator<<(ostream& os, const myString& s)
{
	for (int i = 0; i < s.length(); ++i)
		cout << s.str[i];
		
	return os;
}

//********************************************************************
//********************************************************************
istream& operator>>(istream& is, myString& s)
{
	s.str = nullptr;
	s.len = 0;
	char c;
	
	cin.get(c);
	
	while(c != '\n')
	{
		while(isspace(c))
			cin.get(c);
		
		s.resize(s.length());
		
		s.str[s.length() - 1] = c;
		
		cin.get(c);
	}
	return is;
}

	
	
	
	



