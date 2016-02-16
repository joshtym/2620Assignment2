//
// CS 2620 Assignment 2 Solution
//
// Howard Cheng
// Sep 20, 2013
//
// This program tests various functionalities of the myString class.
//
// Note: this is not an exhaustive test!  You may wish to test your routines
// some more.  In particular, memory problems may not be detected with this
// program.
//

#include "myString.h"
#include <iostream>
#include <cassert>

using namespace std;

void printString(const myString& s, const char* prompt);

int main(void)
{
  myString s1;
  myString s2("abcdefg");
  myString s3('X');
  myString s4(s2);
  const myString s5 = "this is a constant string.";

  // test output and lengths
  printString(s1, "s1");
  cout << "Length = " << s1.length() << endl;
  printString(s2, "s2");
  cout << "Length = " << s2.length() << endl;
  printString(s3, "s3");
  cout << "Length = " << s3.length() << endl; 
  printString(s4, "s4");
  cout << "Length = " << s4.length() << endl;
  printString(s5, "s5");
  cout << "Length = " << s5.length() << endl;

  // test input
  cout << "get a line of text into s1:" << endl;
  getline(cin, s1);
  printString(s1, "s1");

  cout << (cin.good() ? "good" : "not good") << endl;
  cout << (cin.eof() ? "eof": "not eof") << endl;

  // test []
  cout << "printing every second letter of s1: " << endl;
  for (int i = 0; i < s1.length(); i += 2) {
    cout << s1.at(i);
  }
  cout << endl;

  cout << "printing every second letter of s5: " << endl;
  for (int i = 0; i < s5.length(); i += 2) {
    cout << s5.at(i);
  }
  cout << endl;

  // test substring
  cout << endl;
  cout << "Substring test:" << endl;
  printString(s2.substr(2, 4), "s2.substr(2, 4)"); 
  printString(s2.substr(0, s2.length()), "s2.substr(0, s2.length())"); 
  printString(s5.substr(2, 5), "s5.substr(2, 5)");
  
/*  // Test Find
  cout << endl;
  cout << "Find Test: " << endl;
  printString(s2.find("bcd"), "Location of bcd in s2 is: ");
  printString(s1.find("Test"), "Loc of Test in s1 is: ");
  printString(s3.find("ddd"), "Loc of ddd in s3 is: ");
  printString(s5.find("nstant"), "Loc of nstant in s5 is: ");*/
  

  // test erase
  cout << endl;
  cout << "Erase test:" << endl;
  s2.erase(2, 4);
  printString(s2, "s2.erase(2, 4)");
  s1.erase(0, s1.length());
  printString(s1, "s1.erase(0, s1.length())");

  // test insertion
  cout << endl;
  cout << "Insert test:" << endl;
  s1.insert(0, "hello world!");
  printString(s1, "s1.insert(0, \"hello world!\")");
  s1.insert(5, " cruel");
  printString(s1, "s1.insert(5, \" cruel\")");
  s1.erase(0, 5);
  s1.insert(0, "goodbye");
  printString(s1, "s1");

  // the following should not compile
  /*
  s5.erase(2,4);
  s5.insert(4, "hello");
  */
  return 0;
}

void printString(const myString& s, const char* prompt)
{
  cout << prompt << " = \"";
  for (int i = 0; i < s.length(); i++) {
    cout << s[i];
  }
  cout << "\"" << endl;
}
