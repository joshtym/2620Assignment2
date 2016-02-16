//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #2
// Class Interface
// Professor: Howard Cheng
// Program: myString.h
// Purpose: Header file defines the prototypes of everything used in
//          the myString class
// Programming Partner: Anthony Tymburski
//********************************************************************
#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

using namespace std;

class myString
{
	public:
		// Constructors
		myString();                   // Default Constructor
		
		myString(char);               // Sets string to size 1 with
		                              // the character in it
		                              
		myString(const char*);        // Creates a myString with the
		                              // characters given
		
		myString(const myString&);    // Copy Constructor
		
		~myString();                  // Destructor
		
		// Operator Overloads
		myString& operator=(const myString&); 
		                              // Assignment Operator
		                              
		char& operator[](int i);
									  // [] Operator
									 
	    const char& operator[](int i) const;
	                                  // Constant version of the same
	                                  // operator
	                                  
	    myString& operator+=(const myString&);
	                                  // Takes the original string and
	                                  // adds the user given string to
	                                  // the string
	                                  
	    myString operator+(const myString&);
									  // Takes the string of the object
									  // and constructs a new string
									  // that is a copy of the current
									  // string and concatenates it with
									  // the given string
								
		bool operator==(const myString&) const;
		
		bool operator<(const myString&) const;
		
		bool operator!=(const myString&) const;
		
		bool operator<=(const myString&) const;
		
		bool operator>(const myString&) const;
		
		bool operator>=(const myString&) const;
		
		// Get Methods
		int length() const;           // Returns the length of the
		                              // character array
		                              
		char& at(int);                // Returns the character at the
		                              // position given by the user
		                              
		const char& at(int) const;    // Enables use of Const Strings
		                              // with the same ability as above
		                              
		int find(const myString&) const;
		                              // Searches the current myString
		                              // for the myString given by the
		                              // user
		                              
		myString substr(int, int) const;
		                              // Takes the current myString and
		                              // returns a new myString that is
		                              // a substring of the current
		                              // myString
		                              
		// Set Methods                             
		myString& erase(int, int);    // Takes the current myString and
		                              // erases part of it defined by
		                              // the user
		                              
		myString& insert(int, const myString&);
		                              // Takes the current myString and
		                              // inserts a new string at the
		                              // location defined by the user
		
		// Friend Members
		friend istream& getline(istream& is, myString& s);
		                              // Enables the use of the getline
		                              // function as an input for the
		                              // myString class
		               
		friend istream& operator>>(istream&, myString& s);
		friend ostream& operator<<(ostream&, const myString& s);
	
	private:
		// Data Members
		char *str;
		int len;
		static const int npos = -1;
		
		// Function member
		void resize(int);
};
#endif
