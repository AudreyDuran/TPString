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
    String(char* cstr);
    String(size_t a_size);
    String(const char* s, size_t s_size);
    String (const String& str);

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
    //                            Accessors: setters
    // =======================================================================

    void setCapacity(size_t c);

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
    
    size_t size(void) const;
    size_t length(void) const;
    size_t max_size(void) const;
    size_t capacity(void) const;
    const char& at(size_t position) const;
    char& at(size_t position);
    void resize(size_t new_size);
    void resize(size_t new_size, char c);
    char* c_str(void);
    void clear(void);
    void print(void);
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

