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
const int String::MAX_SIZE = 1000;

// ===========================================================================
//                                  Constructors
// ===========================================================================



String::String(void)
{
  size = 0;
  data = NULL;
  capacity = 0;
}


/*Constructor with the size only in parameter */
String::String(int a_size)
{
  size = a_size;
  capacity = a_size;     
  data = new char[capacity];
}



// Constructor by copy
String::String (const String& str)
{
  size = str.getSize();
  capacity = size;
  data = new char[capacity];
  for (int i=0; i<size; i++)
    {
      data[i] = str.at(i);
    }
}



String::String(char* cstr)
{

  int i = 0;

  while (cstr[i]!='\0')
  {
    i++;
  }

  //printf("i=%d\n",i );

  size = i;
  capacity = size;

  data = new char[capacity];

  memcpy(data, cstr, size);

  /*for (int i = 0; i < size; ++i)
  {
    printf("%c\n", data[i] );
  }*/

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
  for(int i=0; i<size; i++)
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






size_t String::Size() const
{
 return (size*sizeof(char));
}



int String::getSize() const
{
  return size;
}





int String::getCapacity() const
{
  return capacity;
}




char* String::getData() const
{
  return data;
}





size_t String::length() const
{
  return size*sizeof(char);     
}


void String::setCapacity(int c)
{
  capacity = c;

}

/*Returns the maximum length the string can reach.
This is the maximum potential length the string can reach due to known system or 
library implementation limitations*/
size_t String::max_size() const
{
  return MAX_SIZE*sizeof(char);
}





const char& String::at(int position) const
{
  return data[position];
}

char& String::at(int position)
{
  return data[position];
}





//resize the String. If the new size is lower, remove the characters beyond the nth. If bigger, add (new_size - size) null characters
void String::resize(size_t new_size)
{
  int new_s = new_size/(8*sizeof(char));

  if(new_s < capacity)
    {

      size = new_s;

      for(int i = new_size +1; i<size; i++)
      {
      	data[i]='\0';
      }

    }
  else if(new_s > capacity)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_s];

      
      for(int i=0; i<size; i++)
      {
        data2[i]=data[i];
        printf("%c %c\n", data2[i], data[i]);
      }

      

      delete [] data;
      
      data= NULL;

      for(int i=size; i<new_s; i++)
      {
      	data2[i]='\0';
      }

      data = data2; 
      size = new_s;

    }
	

}


void String::resize(size_t new_size, char c)
{
  int new_s = new_size/(sizeof(char));

  if(new_s < capacity)
    {

      size = new_s;

      for(int i = new_size +1; i<size; i++)
      {
        data[i]='\0';
      }

    }
  else if(new_s > capacity)
    {
      //create a pointer on a table of char to stock the value of data (because we are going to delete it)
      char* data2 = new char[new_s];

      
      for(int i=0; i<size; i++)
      {
        data2[i]=data[i];
        printf("%c %c\n", data2[i], data[i]);
      }

      

      delete [] data;
      
      data= NULL;

      for(int i=size; i<new_s; i++)
      {
        data2[i]=c;
      }

      data = data2; 
      size = new_s;
      capacity = new_s;

    }
  

}




String& String::operator+(char c)
{
  size += 1;
  if (capacity < size) //Allocate a new storage space if the capacity is smaller than the new size
    {
      delete [] data;
      data = new char[capacity];
    }
  data[size] = c;
  //printf("%c\n", data[size] );
  return *this;
}






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
    }
  for (int i=0; i<size; i++)
    {
      data[i] = str.at(i);
    }
  return *this;
}





// take a string in "" as parameter or a c_str and add it to the String
String& String::operator+(const char* s)
{
  int i = 0;

  while (s[i]!='\0')
  {
    i++;
  }

  //i corresponds to the size of s (the thing added)


  if(size+i<=capacity)
  {
    for(int j = size; j<size+i; j++)
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

    printf("s2[j]\n");

    for(int j = size; j<size+i; j++)
    {
      s2[j]=s[j-size];
      printf("%c\n",s2[j]);
    }

    data = s2;

  }

  size = size + i;
  capacity = size;

  return *this;

}







void String::print()
{
	for(int i=0; i<size; i++)
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
