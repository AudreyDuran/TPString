//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <cstdlib>
#include <cstdio>



// ===========================================================================
//                             Include Project Files
// ===========================================================================

#include "String.h"

// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  // Test of methods made by student 1
  printf("\n-------------\n");
  printf("Student 1 :)\n");
  
  char* str = new char [4];
  str[0] = 't';
  str[1] = 'e';
  str[2] = 's';
  str[3] = 't';
  String s1(str);

  printf("\ns1 = ");
  s1.print();
  printf("\nString s2(s1); (Use of the copy constructor)\n");
  String s2(s1); // Use of the copy constructor
  printf("s2 = ");
  s2.print();
  printf("s2.size = %lu\n", s2.Size()); // size
  s1.clear(); // clear
  printf("\nClear s1:\ns1 = ");
  s1.print();
  printf("s1.size = %lu\n", s1.Size());
  printf("\ns1 = s2;\n");
  s1 = s2; // operator=(string)
  printf("s1 = ");
  s1.print();

  printf("\ns1 = test + 'Y';\n");
  s1 = s1 + 'Y'; // operator+(char)
  printf("s1 = ");
  s1.print();
  printf("s1.size = %lu\n\n\n", s1.Size());
  







  // Test of the methods made by student 2
  printf("-------------\n");
  printf("Student 2 :)\n");

  //Test of the constructeur from a c-string, 
  printf("\nTest of the constuctor from a c-string\n");
  char* cstr = new char[4];
  cstr[0] = 'U';
  cstr[1] = 'e';
  cstr[2] = 's';
  cstr[3] = 'h';

  String s3(cstr);
  printf("s3 = ");
  s3.print();

  //Test of length
  printf("\nTest of length()\n");
  printf("s3.length() = %lu\n",s3.length());

  //Test of max_size
  printf("\nTest of max_size()\n");
  printf("s3.max_size = %lu\n", s3.max_size());

  //Test of resize
  printf("\nTest of resize()\n");
  s3.resize(2);
  printf("s3.resize(2) : ");
  s3.print();

  s3.resize(3,'f');
  printf("s3.resize(3,'f') : ");
  s3.print();

  s3.resize(6,'a');
  printf("s3.resize(6,'a') : ");
  s3.print();


  //Test of at
  printf("\nTest of at()\n");
  printf("s3.at(2) = %c\n", s3.at(2));
  //printf("s3.at(6) = %c\n", s3.at(6)); // I put this one in comment because it calls a throw


  //Test of the operator =(char) 
  printf("\nTest of the operator =(char)\n");
  s3 = 'I';
  printf("s3 = ");
  s3.print();

  //Test of the operator +(char*)
  printf("\nTest of the operator +(char*) \n");
  s3 + "t works !";
  printf("s3 = ");
  s3.print();





  printf("\nMain executed without problem.\n");
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

