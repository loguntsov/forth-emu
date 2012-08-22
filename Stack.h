//---------------------------------------------------------------------------
#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

#include "ForthDataType.h"
class Stack
{
public:
    void **Stck;
public:
    int uk,num;
    Stack(int Num);
    ~Stack();
    bool push(void *Data);
    void *pop(void);
    void *ret(void);
    void Reset(void);
};
#endif
