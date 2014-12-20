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
  printf("s2.size = %lu\n", s2.size()); // size
  s1.clear(); // clear
  printf("\nClear s1:\ns1 = ");
  s1.print();
  printf("s1.size = %lu\n", s1.size());
  printf("\ns1 = s2;\n");
  s1 = s2; // operator=(string)
  printf("s1 = ");
  s1.print();

  printf("\ns1 = test + 'Y';\n");
  s1 = s1 + 'Y'; // operator+(char)
  printf("s1 = ");
  s1.print();
  printf("s1.size = %lu\n\n\n", s1.size());
  







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





//Test of methodes written by student 3
   printf("\n\n-------------\n");
   printf("Student 3 :D\n");

  char* str2 = new char[6];
  str2[0] = 'Y';
  str2[1] = 'u';
  str2[2] = 'p';
  str2[3] = 'p';
  str2[4] = 'y';
  str2[5] = '!';
  String s(str2);

  char* str3 = new char[6];
  String empty_string(str3);

  char* str4 = new char[2];
  str4[0] = 'H';
  str4[1] = 'i';
  String st(str4);

  char* str5 = new char[3];
    str5[0] = '!';
    str5[1] = '!';
    str5[2] = '!';
  String another_s(str5);

  printf("s = Yuppy!\n");


   // Test of method Capacity()
  printf("\nTest of Capacity():\ns.Capacity() = %lu \n", s.capacity());


  // Test of method empty()
  printf("\nTest of empty():\ns.empty() = %s \n", s.empty()?"true":"false");
  printf("empty_string.empty() = %s \n", empty_string.empty()?"true":"false");


  // Test of method reserve(size_t n)
  size_t n = 10;
  printf("\nTest of reserve:\nOld capacity = %lu \n", s.capacity());
  s.reserve(n);
  printf("New capacity for n=10 : %lu \n", s.capacity());
  n = 2;
  s.reserve(n);
  printf("New capacity for n=2 : %lu \n", s.capacity());


  // Test of operator= (const String* s)
  s = "Short";
  printf("\nTest of operator= for shorter new_string\nString s = ");
  s.print();
  s = "Supersuperlong";
  printf("Test of operator= for longer new_string\nString s = ");
  s.print();


  // Test of operator+ (const String& str)
  String ss1 = st + another_s;
  printf("\nTest of operator+\nHi + !!! = ");
  ss1.print();


  // Test of operator[] (size_t pos)
  printf("\nTest of operator[]\nFor the string 'Hi!!!', the second character is '%c'\n", ss1[1]);
  printf("This should give nothng = %c\n", ss1[5]);
  printf("This should give an error = ");
  ss1[10];

  // Test of operator[] (size_t pos) const
  const String const_string(str2);
  printf("\nThis should give me p = %c\n", const_string[2]);



  printf("\n\nMain executed without problem.\n");
  return 0;
}

