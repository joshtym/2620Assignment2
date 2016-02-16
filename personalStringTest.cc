#include<iostream>
#include"myString.h"
using namespace std;

int main()
{
	myString test1;
	myString test2('a');
	myString test3("Tabcdefg");
	myString test4(test3);
	const myString test5("Constant String");
	
	cout << "Test 1 is: ";
	test1.print();
	cout << endl;
	cout << "Test 2 is: ";
	test2.print();
	cout << endl;
	cout << "Test 3 is: ";
	test3.print();
	cout << endl;
	cout << "Test 4 is: ";
	test4.print();
	cout << endl;
	cout << "Test 5 is: ";
	test5.print();
	cout << endl;
	
	cout << "Size of Test 1 is: " << test1.length() << endl;
	cout << "Size of Test 2 is: " << test2.length() << endl;
	cout << "Size of Test 3 is: " << test3.length() << endl;
	cout << "Size of Test 5 is: " << test5.length() << endl;
	
	cout << "Char at position 2 in test 3 is: " << test3.at(2) << endl;
	
	cout << "SubString of Test 4 test: ";
	test4.substr(1,3).print();
	cout << endl;
	
	cout << "Test3 with the middle erased is: ";
	test3.erase(1, 2);
	test3.print();
	cout << endl;
	
	cout << "Test4 with Tymbo added is: ";
	test4.insert(2, "Tymbo");
	test4.print();
	cout << endl;
	
	cout << "Pos of Tymbo in Test4 is: " << test4.find("Tymbo") << endl;
	cout << "Pos of is in Test2 is: " << test2.find("Test") << endl;
	cout << "Pos of fg in Test3 is: " << test3.find("fg") << endl;
	
	return 0;
}
