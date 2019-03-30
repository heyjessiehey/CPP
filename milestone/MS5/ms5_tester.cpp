// Final Project - Milestone 5
// ms5_tester.cpp
// Version 3.3
// Date	2018/03/11
// Authors:	Chris Szalwinski, Fardad Soleimanloo
//
// For your final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Chris              2017/12/16           name changes for Fall
// Chris              2018/01/25           Product name changes
// Chris              2018/02/07           I/O Alignments
// Chris              2018-03-03           Message -> State
// Chris              2018-03-11           align with specs
/////////////////////////////////////////////////////////////////
#include "iProduct.h"
#include "Product.h"
#include "Perishable.h"
void testPerishable();
void testProduct();
void promptUser(const char* sku, const char* name, const char* unit = "", char Tx = '\0',
  const char* price = "", const char* qty = "", const char* qtyNd = "",
  const char* date = "");
void dumpFile(const char* fname);
void pause_();
using namespace std;
using namespace AMA;

int main() {
  testProduct();
  cout << endl;
  testPerishable();
}

// testProduct tests the processing of Product objects
//
void testProduct() {
  fstream productFile("product.txt", ios::out);
  Product product;
  bool ok = true;
  cout << "--Product test:" << endl;
  cout << "----Taxed validation test:" << endl;
  promptUser("abc", "abc", "abc", 'a');
  cin >> product;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(2000, '\n');
    cout << "\nPassed!" << endl
      << " Message should be:  Only (Y)es or (N)o are acceptable" << endl
      << " Your Error message: " << product << endl;
  }
  else {
    ok = false;
    cout << " Taxed validation failed" << endl;
  }
  pause_();
  if (ok){
    cout << "----Price validation test:" << endl;
    promptUser("abc", "abc", "abc", 'y', "abc");
    cin >> product;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "\nPassed!" << endl
        << " Message should be:  Invalid Price Entry" << endl
        << " Your Error message: " << product << endl;
    }
    else {
      ok = false;
      cout << " Price validation failed" << endl;
    }
    pause_();
  }
  if (ok) {
    cout << "----Quantity validation test:" << endl;
    promptUser("abc", "abc", "abc", 'y', "10", "abc");
    cin >> product;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "\nPassed!" << endl
        << " Message should be:  Invalid Quantity Entry" << endl
        << " Your Error message: " << product << endl;
    }
    else {
      ok = false;
      cout << " Quantity validaton failed" << endl;
    }
  }
  pause_();
  if (ok) {
    cout << "----Quantity Needed validation test:" << endl;
    promptUser("abc", "abc", "abc", 'y', "10", "10", "abc");
    cin >> product;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "\nPassed!" << endl
        << " Message should be:  Invalid Quantity Needed Entry" << endl
        << " Your Error message: " << product << endl;
    }
    else {
      ok = false;
      cout << " Quantity Needed validaton failed" << endl;
    }
  }
  pause_();
  if (ok) {
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    promptUser("1234", "box", "kg", 'y', "123.45", "1", "5");
    cin >> product;
    //cin.ignore(1000, '\n');
	cout << "\n-Compare the output of the Program and your output:" << endl;
    cout << "--Linear------------" << endl;
    cout << " Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "   Yours: " << product << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << " Sku: 1234" << endl;
    cout << " Name (no spaces): box" << endl;
    cout << " Price : 123.45" << endl;
    cout << " Price after tax : 139.50" << endl;
    cout << " Quantity on hand : 1 kg" << endl;
    cout << " Quantity needed : 5" << endl;
    cout << "--Yours: " << endl;
    product.write(cout, false) << endl;
  }
  pause_();
  if (ok) {
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    Product tprd;
    product.store(productFile);
    product.store(productFile);
    productFile.close();
    cout << "--Store Product, program: " << endl
      << "N,1234,box,kg,1,123.45,1,5" << endl
      << "N,1234,box,kg,1,123.45,1,5" << endl;
    cout << "--Store Product, yours: " << endl;
    dumpFile("product.txt");
    cout << "--Load Product: " << endl;
    productFile.open("product.txt", ios::in);
    productFile.ignore(2);
    tprd.load(productFile);
    cout << " Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "   Yours: " << tprd << endl;
    productFile.clear();
    productFile.close();
  }
}

// testPerishable tests the processing of Perishable objects
//
void testPerishable() {
  fstream productShortFile("productShortFile.txt", ios::out);
  Perishable psh;
  bool ok = true;
  cout << "--Perishable Item test:" << endl;
  if (ok) {
    cout << "----Expiry date Validation test:" << endl;
    promptUser("abc", "abc", "abc", 'n', "10", "10", "10", "10/1/1");
    cin >> psh;
    if (cin.fail()){
      cin.clear();
      cout << "\nPassed!" << endl
        << " Message should be:  Invalid Year in Date Entry" << endl
        << " Your Error message: " << psh << endl;
    }
    else {
      ok = false;
      cout << " Expiry date validaton failed" << endl;
    }
    cin.ignore(2000, '\n');
  }
  pause_();
  if (ok) {
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    promptUser("1234", "water", "liter", 'n', "1.5", "1", "5", "2018/06/30");
    cin >> psh;
    cin.ignore(2000, '\n');
	cout << "\n-Compare the output of the Program and your output:" << endl;
	cout << "--Linear------------" << endl;
    cout << " Program: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30" << endl;
    cout << "   Yours: " << psh << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << " Sku: 1234" << endl;
    cout << " Name (no spaces): water" << endl;
    cout << " Price : 1.50" << endl;
    cout << " Price after tax : N/A" << endl;
    cout << " Quantity on hand : 1 liter" << endl;
    cout << " Quantity needed : 5" << endl;
    cout << " Expiry date : 2018/06/30" << endl;
    cout << "--Yours: " << endl;
    psh.write(cout, false) << endl;
	cout << endl;
  }
  pause_();
  if (ok) {
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    Perishable tpsh;
    psh.store(productShortFile);
    psh.store(productShortFile);
    productShortFile.close();
    cout << "--Store Perishable, program: " << endl
      << "P,1234,water,liter,0,1.5,1,5,2018/06/30" << endl
      << "P,1234,water,liter,0,1.5,1,5,2018/06/30" << endl;
    cout << "--Store Perishable, yours: " << endl;
    dumpFile("productShortFile.txt");
    cout << "--Load Perishable: " << endl;
    productShortFile.open("productShortFile.txt", ios::in);
    productShortFile.ignore(2);
    tpsh.load(productShortFile);
    cout << " Program: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30" << endl;
    cout << "   Yours: " << tpsh << endl;
    productShortFile.clear();
    productShortFile.close();
  }
}

// promptUser prompts user with data to be entered
//
void promptUser(const char* sku, const char* name, const char* unit, char Tx ,
  const char* price, const char* qty, const char* qtyNd ,
  const char* date){
  cout
    << "Enter the following: " << endl
    << " Sku: " << sku << endl
    << " Name (no spaces): " << name << endl
    << " Unit: " << unit << endl;
  if (Tx) cout << " Taxed? (y/n): " << Tx << endl;
  if (price[0]) cout << " Price: " << price << endl;
  if (qty[0]) cout << " Quantity on hand: " << qty << endl;
  if (qtyNd[0]) cout << " Quantity needed: " << qtyNd << endl;
  if (date[0]) cout << " Expiry date (YYYY/MM/DD): " << date << endl;
  cout << endl;
}

// dumpFile inserts the contents of fname into cout 
//
void dumpFile(const char* fname){
  ifstream f(fname);
  char ch;
  while (!f.get(ch).fail()) {
    cout.put(ch);
  }
  f.clear();
  f.close();
}

// pause_ pauses execution until user presses Enter
//
void pause_(){
  cout << "Press enter to continue ... ";
  cin.ignore(1000, '\n');
  cout << endl;
}

/*
--Product test:
----Taxed validation test:
Enter the following:
 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): a

 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): a

Passed!
 Message should be:  Only (Y)es or (N)o are acceptable
 Your Error message: Only (Y)es or (N)o are acceptable
Press enter to continue ...

----Price validation test:
Enter the following:
 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: abc

 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: abc

Passed!
 Message should be:  Invalid Price Entry
 Your Error message: Invalid Price Entry
Press enter to continue ...

----Quantity validation test:
Enter the following:
 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: 10
 Quantity on hand: abc

 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: 10
 Quantity on hand: abc

Passed!
 Message should be:  Invalid Quantity Entry
 Your Error message: Invalid Quantity Entry
Press enter to continue ...

----Quantity needed validation test:
Enter the following:
 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: 10
 Quantity on hand: 10
 Quantity needed: abc

 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): y
 Price: 10
 Quantity on hand: 10
 Quantity needed: abc

Passed!
 Message should be:  Invalid Quantity Needed Entry
 Your Error message: Invalid Quantity Needed Entry
Press enter to continue ...

----Display test, the output of the Program and yours must match:
Enter the following:
 Sku: 1234
 Name (no spaces): box
 Unit: kg
 Taxed? (y/n): y
 Price: 123.45
 Quantity on hand: 1
 Quantity needed: 5

 Sku: 1234
 Name (no spaces): box
 Unit: kg
 Taxed? (y/n): y
 Price: 123.45
 Quantity on hand: 1
 Quantity needed: 5

-Compare the output of the Program and your output:
--Linear------------
 Program: 1234   |box                 | 139.50|   1|kg        |   5|
   Yours: 1234   |box                 | 139.50|   1|kg        |   5|
--Form Display------
--Program:
 Sku: 1234
 Name (no spaces): box
 Price : 123.45
 Price after tax : 139.50
 Quantity on hand : 1 kg
 Quantity needed : 5
--Yours:
 Sku: 1234
 Name (no spaces): box
 Price: 123.45
 Price after tax: 139.50
 Quantity on Hand: 1 kg
 Quantity needed: 5
Press enter to continue ...

----Storage and loading test, the output of the Program and yours must match:
--Store Product, program:
N,1234,box,kg,1,123.45,1,5
N,1234,box,kg,1,123.45,1,5
--Store Product, yours:
N,1234,box,kg,1,123.45,1,5
N,1234,box,kg,1,123.45,1,5
--Load Product:
 Program: 1234   |box                 | 139.50|   1|kg        |   5|
   Yours: 1234   |box                 | 139.50|   1|kg        |   5|

--Perishable Item test:
----Expiry date Validation test:
Enter the following:
 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): n
 Price: 10
 Quantity on hand: 10
 Quantity needed: 10
 Expiry date (YYYY/MM/DD): 10/1/1

 Sku: abc
 Name (no spaces): abc
 Unit: abc
 Taxed? (y/n): n
 Price: 10
 Quantity on hand: 10
 Quantity needed: 10
 Expiry date (YYYY/MM/DD): 10/1/1

Passed!
 Message should be:  Invalid Year in Date Entry
 Your Error message: Invalid Year in Date Entry
Press enter to continue ...

----Display test, the output of the Program and yours must match:
Enter the following:
 Sku: 1234
 Name (no spaces): water
 Unit: liter
 Taxed? (y/n): n
 Price: 1.5
 Quantity on hand: 1
 Quantity needed: 5
 Expiry date (YYYY/MM/DD): 2018/06/30

 Sku: 1234
 Name (no spaces): water
 Unit: liter
 Taxed? (y/n): n
 Price: 1.5
 Quantity on hand: 1
 Quantity needed: 5
 Expiry date (YYYY/MM/DD): 2018/06/30

-Compare the output of the Program and your output:
--Linear------------
 Program: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30
   Yours: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30
--Form Display------
--Program:
 Sku: 1234
 Name (no spaces): water
 Price : 1.50
 Price after tax : N/A
 Quantity on hand : 1 liter
 Quantity needed : 5
 Expiry date : 2018/06/30
--Yours:
 Sku: 1234
 Name (no spaces): water
 Price: 1.50
 Price after tax:  N/A
 Quantity on Hand: 1 liter
 Quantity needed: 5
 Expiry date: 2018/06/30

Press enter to continue ...

----Storage and loading test, the output of the Program and yours must match:
--Store Perishable, program:
P,1234,water,liter,0,1.5,1,5,2018/06/30
P,1234,water,liter,0,1.5,1,5,2018/06/30
--Store Perishable, yours:
P,1234,water,liter,0,1.5,1,5,2018/06/30
P,1234,water,liter,0,1.5,1,5,2018/06/30
--Load Perishable:
 Program: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30
   Yours: 1234   |water               |   1.50|   1|liter     |   5|2018/06/30
Press any key to continue . . .

 */