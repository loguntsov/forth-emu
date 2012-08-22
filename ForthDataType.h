//---------------------------------------------------------------------------
#ifndef ForthDataTypeH
#define ForthDataTypeH
//---------------------------------------------------------------------------
// Поддерживаемые типы
enum DataType { None=0,INTF,ADRESSF };
// Цедый тип данных, аналогично int
typedef int FINT;

/*class FINT //: public DataType <int>
{
public:
int Data;
int Type;
FINT();
FINT(int);
~FINT();
};*/

#endif
