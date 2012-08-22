//---------------------------------------------------------------------------
#ifndef MemoryH
#define MemoryH
//---------------------------------------------------------------------------
template <class Stype> class Memory
{
//private:
Stype *Mem;
public:
Stype& operator [](long Num);
Memory(long Num);
~Memory();
};
#endif
