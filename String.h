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
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class String
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
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
    size_t getSize() const;
    size_t getCapacity() const;
    char* getData() const;


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    void setCapacity(size_t c);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    size_t size() const;
    size_t length() const;
    size_t max_size() const;
    size_t Capacity(void) const;
    const char& at(size_t position) const;
    char& at(size_t position);
    void resize(size_t new_size);
    void resize(size_t new_size, char c);
    char* c_str();
    void clear();
    void print();
    bool empty(void);
    void reserve(size_t n);
    String& operator+(char c);
    String& operator+(const char* s);
    String& operator= (char c);
    String& operator= (const String& str);

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*String(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };

    String(const String &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    static const size_t MAX_SIZE;
    char* data;
    size_t size_;
    size_t capacity;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

