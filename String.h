//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __STRING_H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>



// ===========================================================================
//                              Class declarations
// ===========================================================================


class String
{
  public :
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    String(void);
    String(size_t a_size);
    String (const String& str);
    String(char* cstr);

    

    // =======================================================================
    //                                Destructor
    // =======================================================================

    virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    size_t getSize(void) const;
    size_t getCapacity(void) const;
    char* getData(void) const;


    // =======================================================================
    //                                Operators
    // =======================================================================
    
    String& operator+(char c);
    String& operator+(const String& str);
    String& operator+(const char* s);
    String& operator= (char c);
    String& operator= (const String& str);
    String& operator= (const char* s);
    char& operator[] (size_t pos);
    const char& operator[] (size_t pos) const;



    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
    void print(void);
    char* c_str(void);
    size_t size(void) const;
    size_t length(void) const;
    void clear(void);
    size_t max_size(void) const;
    void resize(size_t new_size);
    void resize(size_t new_size, char c);
    const char& at(size_t position) const;
    char& at(size_t position);
    size_t capacity(void) const;
    bool empty(void);
    void reserve(size_t n);



  protected :

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    static const size_t MAX_SIZE;
    char* data;
    size_t size_;
    size_t capacity_;
};


#endif // __STRING_H__

