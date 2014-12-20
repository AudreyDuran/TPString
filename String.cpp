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


// Default constructor
String::String(void)
{
  size_ = 0;
  data = NULL;
  capacity_ = 0;
}


// Constructor with the size as only parameter
String::String(size_t a_size)
{
  size_ = a_size;
  capacity_ = a_size;     
  data = new char[capacity_];
}


// Copy constructor
String::String (const String& str)
{
  size_ = str.getSize();
  capacity_ = str.getCapacity();
  data = new char[capacity_];
  for (size_t i=0; i<size_; i++)
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
  size_ = i;
  capacity_ = size_;
  data = new char[capacity_];
  memcpy(data, cstr, size_);
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
char* String::c_str(void)
{
  char* c_data = new char[capacity_+1];
  for(size_t i=0; i<size_; i++)
    {
      c_data[i] = data[i];
    }
  c_data[size_] = '\0';
  return c_data;
}


// Erases the contents of the string, which becomes an empty string with a length of 0 characters)
void String::clear(void)
{
  delete[] data;
  size_ = 0;
  capacity_ = 0;
  data = NULL;
}


// Return the size of the String
size_t String::size(void) const
{
  return (size_*sizeof(char));
}


// Return the size of the String
size_t String::getSize(void) const
{
  return size_;
}


// Return the size of the Strin
size_t String::length(void) const
{
  return size_*sizeof(char);     
}


// Return the capacity_ of the String
size_t String::getCapacity(void) const
{
  return capacity_;
}


// Return the Data of the String
char* String::getData(void) const
{
  return data;
}


//Set the Capacity of the String (for tests)
void String::setCapacity(size_t c)
{
  capacity_ = c;
}


//Returns the maximum length the string can reach.
//This is the maximum potential length the string can reach due to known system or 
//library implementation limitation
size_t String::max_size(void) const
{
  return MAX_SIZE*sizeof(char);
}


// Return size of allocated storage
size_t String::capacity(void) const
{
  return capacity_;
}


//Returns a reference to the character at position pos in the string.
//The function automatically checks whether pos is the valid position of a character
//in the string (i.e., whether pos is less than the string length), throwing an
//out_of_range exception if it is not.
const char& String::at(size_t position) const
{
  if(position<size_)
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
  if(position<size_)
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
  if(new_size < capacity_)
    {
      for(size_t i = new_size; i<size_; i++)
        {
      	  data[i]='\0';
        }
    }
  else if(new_size > capacity_)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_size];
      for(size_t i=0; i<size_; i++)
        {
          data2[i]=data[i];
        }
      delete [] data;
      data= NULL;
      for(size_t i=size_; i<new_size; i++)
        {
      	  data2[i]='\0';
        }
      data = data2; 
      capacity_ = new_size;
    }
  size_ = new_size;
}


//Resizes the string to a length of n characters.
//If n is smaller than the current string length, the current value is shortened to its first n character, 
//removing the characters beyond the nth.
//If n is greater than the current string length, the current content is extended by inserting at the end 
//as many characters as needed to reach a size of n. The new elements are initialized as copies of c.
void String::resize(size_t new_size, char c)
{
  if(new_size < capacity_ && new_size>size_)
    {
      for(size_t i = size_; i<new_size; i++)
        {
          data[i] = c;
        }
    }
  else if(new_size < size_)
    {
      for (size_t i = new_size; i < size_; i++)
        {
          data[i] = '\0';
        }
    }
  else if(new_size > capacity_)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_size];
      for(size_t i=0; i<size_; i++)
        {
          data2[i]=data[i];
        }
      delete [] data;
      data= NULL;
      for(size_t i=size_; i<new_size; i++)
        {
          data2[i]=c;
        }
      data = data2; 
      capacity_ = new_size;
    }
    size_ = new_size;
}



// Displays the String
void String::print(void)
{
  for(size_t i=0; i<size_; i++)
    {
      printf("%c", data[i]);
    }
  printf("\n");
}



// Returns whether the string is empty (i.e. whether its length is 0).
bool String::empty(void)
{
  if(size_ == 0)
    return true;
  else
    return false;
}


//Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
void String::reserve(size_t n)
{
  if (n > capacity_)
  {
    char* new_data = new char[n]; // Creating a new, bigger container of size n
    memcpy(new_data, data, size_); // Copying old string in new container
    delete [] data; // Erasing old, smaller container

    data = new_data; // Updating
    capacity_ = n;    // the attributes
  }

  // For the case n < capacity, I chose not to shrink the capacity, leaving it greater than n.

}


//---------------------------------------------------------------------------
//                                OPERATORS
//---------------------------------------------------------------------------


//Extends the string by appending an additional character at the end of its current value.
String& String::operator+(char c)
{
  if (capacity_ < size_+1) //Allocate a new storage space if the capacity is smaller than the new size
    {
      char* data2 = new char[capacity_]; // Creation of a pointer to temporally stock the values of data
      for(size_t i=0; i<size_; i++)
        {
          data2[i]=data[i];
        }
      delete [] data;
      capacity_ +=1;
      data = new char[capacity_];
      for(size_t i=0; i<size_; i++)
        {
          data[i]=data2[i];
        }
      delete [] data2;
    }
  data[size_] = c;
  size_ += 1;
  return *this;
}


// Takes the reference to a string as parameter and adds its associated string to the original string.
String& String::operator+(const String& str)
{
  size_t str_size = str.getSize(); 
  size_t new_size = size_ + str_size; // Finding new value of size
  size_t old_size = size_; // Storing value of old size
  size_ = new_size; // Changing the size into the new one / Making space for the extra characters
  reserve(new_size); // Changing the capacity so there is enough memory for the new string

  for (size_t i=old_size; i<new_size; i++)
      data[i] = str.at(i-old_size);
    
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
  //i corresponds to the size of s (the added thing)
  if(size_+i<=capacity_)
    {
      for(size_t j = size_; j<size_+i; j++)
        {
          data[j]=s[j-size_];
        }
    }
  else if(size_+i>capacity_)
    {
      char* s2= new char[size_+i];
      memcpy(s2,data,size_);
      delete[] data;
      data = NULL;
      for(size_t j = size_; j<size_+i; j++)
        {
          s2[j]=s[j-size_];
        }
      data = s2;
    }
  size_ = size_ + i;
  capacity_ = size_;
  return *this;
}



//Erase the data of the String and replace it by the character in parameter.
String& String::operator= (char c)
{
  delete [] data;
  size_ = 1;
  data = new char[size_];
  data [0] = c;
  return *this;
}


String& String::operator= (const String& str)
{
  size_ = str.getSize();
  if (capacity_ < size_) //Allocate a new storage space if the capacity is smaller than the new size
    {
      delete [] data;
      data = new char[size_];
      capacity_ = size_;
    }
  for (size_t i=0; i<size_; i++)
    {
      data[i] = str.at(i);
    }
  return *this;
}




// Takes a pointer to a null-terminated sequence of characters as parameter 
// and replaces the current contents of the string with the pointed sequence
String& String::operator= (const char* s)
{
  size_t new_size = 0;

  while (s[new_size]!='\0')
      new_size++; // Gets the size of the string pointed by s

  reserve(new_size); // Allocates space for new_string IF its size is > than the current capacity and moves old string in new container
  for(size_t i = 0; i<new_size; i++)
    data[i]=s[i]; // Copies new_string over old one

  size_ = new_size;
  capacity_ = size_;
 
  return *this;
}
  

// Returns a reference to the character at position pos in the string.
char& String::operator[] (size_t pos)
{
  if (pos > size_) 
    printf("Error: position greater than length\n");

  return data[pos];
}


// Returns a const reference to the character at position pos in the const string.
const char& String::operator[] (size_t pos) const
{
  if (pos > size_) 
    printf("Error: position greater than length\n");

  return data[pos];
}







// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
