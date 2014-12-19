//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================




// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"




//############################################################################
//                                                                           #
//                           Class String                                    #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const size_t String::MAX_SIZE = 1000;

// ===========================================================================
//                                  Constructors
// ===========================================================================



String::String(void)
{
  size = 0;
  data = NULL;
  capacity = 0;
}


// Constructor with the size as only parameter
String::String(size_t a_size)
{
  size = a_size;
  capacity = a_size;     
  data = new char[capacity];
}



// Copy constructor
String::String (const String& str)
{
  size = str.getSize();
  capacity = str.getCapacity();
  data = new char[capacity];
  for (size_t i=0; i<size; i++)
    {
      data[i] = str.at(i);
    }
}


// Constructor from a cstring
String::String(char* cstr)
{

  size_t i = 0;

  while (cstr[i]!='\0')
  {
    i++;
  }

  size = i;
  capacity = size;

  data = new char[capacity];

  memcpy(data, cstr, size);

}


// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete [] data;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// Returns a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object
char* String::c_str()
{
  char* c_data = new char[capacity+1];
  for(size_t i=0; i<size; i++)
  {
    c_data[i] = data[i];
  }
  c_data[size] = '\0';
  return c_data;
}




// Erases the contents of the string, which becomes an empty string with a length of 0 characters)
void String::clear()
{
  delete[] data;
  size = 0;
  capacity = 0;
  data = NULL;
}





// Return the size of the String
size_t String::Size() const
{
  return (size*sizeof(char));
}


// Return the size of the String
size_t String::getSize() const
{
  return size;
}


// Return the size of the Strin
size_t String::length() const
{
  return size*sizeof(char);     
}


// Return the Capacity of the String
size_t String::getCapacity() const
{
  return capacity;
}



// Return the Data of the String
char* String::getData(void) const
{
  return data;
}




//Set the Capacity of the String (for tests)
void String::setCapacity(size_t c)
{
  capacity = c;

}


//Returns the maximum length the string can reach.
//This is the maximum potential length the string can reach due to known system or 
//library implementation limitation
size_t String::max_size(void) const
{
  return MAX_SIZE*sizeof(char);
}


//Return size of allocated storage
size_t String::Capacity(void) const
{
  return capacity;
}





//Returns a reference to the character at position pos in the string.
//The function automatically checks whether pos is the valid position of a character
//in the string (i.e., whether pos is less than the string length), throwing an
//out_of_range exception if it is not.
const char& String::at(size_t position) const
{
  if(position<size)
  {
    return data[position];
  }
  else 
  {
      throw std::out_of_range ("Sorry, the position is bigger than the string length.");
  }
  
}

char& String::at(size_t position)
{
  if(position<size)
  {
    return data[position];
  }
  else
  {
   throw std::out_of_range ("Sorry, the position is bigger than the string length.");

  }
  
}





//Resizes the string to a length of n characters.
//If n is smaller than the current string length, the current value is shortened 
//to its first n character, removing the characters beyond the nth.
//If n is greater than the current string length, the current content is extended 
//by inserting at the end as many characters as needed to reach a size of n (null characters)
void String::resize(size_t new_size)
{

  if(new_size < capacity)
    {

      for(size_t i = new_size; i<size; i++)
      {
      	data[i]='\0';
      }

    }
  else if(new_size > capacity)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_size];

      
      for(size_t i=0; i<size; i++)
      {
        data2[i]=data[i];
      }

      

      delete [] data;
      
      data= NULL;

      for(size_t i=size; i<new_size; i++)
      {
      	data2[i]='\0';
      }

      data = data2; 
      capacity = new_size;

    }

	size = new_size;

}



//Resizes the string to a length of n characters.
//If n is smaller than the current string length, the current value is shortened to its first n character, 
//removing the characters beyond the nth.
//If n is greater than the current string length, the current content is extended by inserting at the end 
//as many characters as needed to reach a size of n. The new elements are initialized as copies of c.

void String::resize(size_t new_size, char c)
{

  if(new_size < capacity && new_size>size)
    {

      for(size_t i = size; i<new_size; i++)
      {
        data[i] = c;
      }

    }

  else if(new_size < size)
  {
    for (size_t i = new_size; i < size; i++)
    {
      data[i] = '\0';
   
    }
  }

  else if(new_size > capacity)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_size];

      
      for(size_t i=0; i<size; i++)
      {
        data2[i]=data[i];
      }

      

      delete [] data;
      
      data= NULL;

      for(size_t i=size; i<new_size; i++)
      {
        data2[i]=c;
      }

      data = data2; 
      capacity = new_size;

    }

    size = new_size;
  

}



//Extends the string by appending an additional character at the end of its current value.
String& String::operator+(char c)
{

  printf("\nExecution of OPERATOR + CHAR.\n");

  if (capacity < size+1) //Allocate a new storage space if the capacity is smaller than the new size
    {
      char* data2 = new char[capacity]; // Creation of a pointer to temporally stock the values of data
      for(size_t i=0; i<size; i++)
        {
          data2[i]=data[i];
        }
      delete [] data;
      capacity +=1;
      data = new char[capacity];
      for(size_t i=0; i<size; i++)
        {
          data[i]=data2[i];
        }
      delete [] data2;
    }

  data[size] = c;
  size += 1;
  
  return *this;
}


//Extends the string by appending a sequence, copied at the end of the string.
// Parameter : pointer to a null-terminated sequence of characters.
String& String::operator+(const char* s)
{
  size_t i = 0;

  while (s[i]!='\0')
  {
    i++;
  }

  //i corresponds to the size of s (the thing added)


  if(size+i<=capacity)
  {
    for(size_t j = size; j<size+i; j++)
    {
      data[j]=s[j-size];
    }

  }

  else if(size+i>capacity)
  {
    char* s2= new char[size+i];
    memcpy(s2,data,size);

    delete[] data;
    data = NULL;


    for(size_t j = size; j<size+i; j++)
    {
      s2[j]=s[j-size];
    }

    data = s2;

  }

  size = size + i;
  capacity = size;

  return *this;

}



//Erase the data of the String and replace it by the character in parameter.
String& String::operator= (char c)
{
  delete [] data;
  size = 1;
  data = new char[size];
  data [0] = c;
  return *this;
}






String& String::operator= (const String& str)
{
  size = str.getSize();
  if (capacity < size) //Allocate a new storage space if the capacity is smaller than the new size
    {
      delete [] data;
      data = new char[size];
      capacity = size;
    }
  for (size_t i=0; i<size; i++)
    {
      data[i] = str.at(i);
    }
  return *this;
}










//display the String
void String::print()
{
  for(size_t i=0; i<size; i++)
    {
      printf("%c", data[i]);
    }
  printf("\n");
}



// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
