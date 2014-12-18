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
  printf("s2.size = %d\n", s2.Size()); // size
  s1.clear(); // clear
  printf("\nClear s1:\ns1 = ");
  s1.print();
  printf("s1.size = %d\n", s1.Size());
  printf("\ns1 = s2;\n");
  s1 = s2; // operator=(string)
  printf("s1 = ");
  s1.print();

  printf("\ns1 = test + 'Y';\n");
  s1 = s1 + 'Y'; // operator+(char)
  printf("s1 = ");
  s1.print();
  printf("s1.size = %d\n", s1.Size());


  printf("\nMain executed without problem.\n");
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================


