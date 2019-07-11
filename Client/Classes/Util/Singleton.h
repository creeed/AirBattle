#ifndef __XLB_SINGLETON_H1__
#define __XLB_SINGLETON_H1__

#include <assert.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T> 
class  Singleton
{
public:
    Singleton()
    {
        assert( !singleton_ );
        singleton_ = static_cast<T*>(this);
    }

    ~Singleton( )
    { 
        assert( singleton_ );  
        singleton_ = 0;  
    }

    static T* singleton()
    { 
        return (singleton_);
    }

protected:
    static T* singleton_ ;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif