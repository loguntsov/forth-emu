// Описания слов, которые не возможно описать конструкциями Forth
static void woprimmediate(void *Link);
//
//
static void immediate(void *Link=NULL) // IMMEDIATE
{
    DictBegin->WordS->Immediate=true;
}
static void kom(void *Link) // \**
{
WOrd(Inpt,'\\');
}
static void execute(void* Link) // _EXECUTE
{
    Words *Wrd;
    EWord *a=(EWord *) Link;
    while(a!=NULL) {
    Wrd=(Words*)(a->Data);
    Stret->push(a->Link);
    (Run[Wrd->Execute])(Wrd->Link);
    a=(EWord *) Stret->pop();
    
    }
}
//------------------------------------------------------
static void forget(void *Link)
{
    try{
        Dictionary *x=DictBegin,*y=NULL;
        AnsiString a=WOrd(Inpt,' ');
        while ((x!=NULL) && (y==NULL))
        {
        if (x->WordS->Name==a) y=x;
        x=x->Link;
        }
        if (y==NULL) throw "Слово для удаления не найдено"; else
            {
            x=DictBegin;
            DictBegin=y->Link;
            y->Link=NULL;
            delete x;
            }
        }
        catch (char *S)
        {
        MessageDlg(AnsiString(S),mtError,TMsgDlgButtons() << mbOK,0);
        }
}
static void dot(void *Link) // .
{
    FINT *a;
    a=(FINT*) Stk->pop();
    ShowMessage(IntToStr(*a));
    delete a;
}
static void iplus(void *Link) // +
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=*a+*b;
    delete b;
    Stk->push(a);
}
static void iminus(void *Link) // -
{
    FINT *a,*b,*c;
    c=new FINT;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *c=(*b) - (*a);
    delete b,a;
    Stk->push(c);
}
static void imultip(void *Link) // *
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=(*a) * (*b);
    delete b;
    Stk->push(a);
}
static void idiv(void *Link) // /
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=(*b) / (*a);
    delete b;
    Stk->push(a);
}
static void imod(void *Link) // MOD
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=*b%*a;
    delete b;
    Stk->push(a);
}
static void woprimmediate(void *Link) // ?IMMEDIATE
{
    try
    {
        if (StateLFM==Compilat) throw "Нужен период выполнения";
    }
    catch (char *S)
    {
        MessageDlg(AnsiString(S),mtError,TMsgDlgButtons() << mbOK,0);
    }
}
static void woprcomp(void *Link) // ?COMP
{
    try
    {
        if (StateLFM==Immediat) throw "Нужен период компиляции";
    }
    catch (char *S)
    {
        MessageDlg(AnsiString(S),mtError,TMsgDlgButtons() << mbOK,0);
    }
}
static void dbldot(void *Link) // :
{
    Dictionary *a=new Dictionary(WOrd(Inpt,' '),FindExecution("_EXECUTE"));
    a->Add(DictBegin);
    DictBegin=a;
    PrevData=DictBegin->WordS;
    StateLFM=Compilat;
}
static void dotpunkt(void *Link) // ;
{
    woprcomp(Link);
    ((EWord *) PrevData)->Link=NULL;
    PrevData=NULL;
    StateLFM=Immediat;
}
static void swap(void *Link) // SWAP
{
    void *a,*b;
    a=Stk->pop();
    b=Stk->pop();
    Stk->push(a);
    Stk->push(b);
}
static void rot(void *Link) // ROT
{
    void *a,*b,*c;
    a=Stk->pop();
    b=Stk->pop();
    c=Stk->pop();
    Stk->push(b);
    Stk->push(a);
    Stk->push(c);
}
static void drop(void *Link) // DROP
{
    delete Stk->pop();
}
static void dropdrop(void *Link) // 2DROP
{
    drop(Link);drop(Link);
}
static void plus1(void *Link) // 1+
{
    FINT *a;
    a=(FINT *) Stk->pop();
    (*a)++;
    Stk->push(a);
}
static void minus1(void *Link) // 1-
{
    FINT *a;
    a=(FINT *) Stk->pop();
    (*a)--;
    Stk->push(a);
}
static void iliteral(void *Link) // _ILITERAL
{
    EWord *a;
    a=(EWord *) Stret->pop();
    Stret->push(a->Link);
    FINT *b=new FINT;
    *b=*((FINT *) a->Data);
    Stk->push(b);
}
static void dwumn(void *Link) // 2*
{
    FINT *a;
    a=(FINT *) Stk->pop();
    (*a)=(*a) << 1;
    Stk->push(a);
}
static void dwdiv(void *Link) // 2/
{
    FINT *a;
    a=(FINT *) Stk->pop();
    (*a)=(*a) >> 1;
    Stk->push(a);
}
static void beep(void *Link) // BEEP
{
Beep();
}
static void rb(void *Link) // R>
{
    void *a;
    a=Stret->pop();
    Stk->push(Stret->pop());
    Stret->push(a);
}
static void rm(void *Link) // R<
{
    void *a;
    a=Stret->pop();
    Stret->push(Stk->pop());
    Stret->push(a);
}
static void rdrop(void *Link) // RDROP
{
    void *a,*b;
    a=Stret->pop();
    b=Stk->pop();delete b;
    Stret->push(a);
}
static void aIFa(void *Link) // _IF
{
    EWord *b;
    FINT *a;
    b=(EWord *) Stret->pop();
    a=(FINT *) Stk->pop();
    if (*a!=0) {
                                Stret->push(b->Link);
                                } else { Stret->push(b->Data); }
    delete a;
}
static void IF(void *Link)// IF (immediate)
{
    woprcomp(Link);
    EWord *y=new EWord;
    y->Data=DictBegin->Find("_IF");
    CatDat(y);
    EWord *x=new EWord(false);
    CatDat(x);
    Stk->push(x);
    FINT *z=new FINT;
    *z=1;
    Stk->push(z);
}
static void nop(void *Link) // NOP
{
// Это слово ничего не делает
}
static void THEN(void *Link) // THEN (immediate)
{
    woprcomp(Link);
    FINT *z;
    z=(FINT *) Stk->pop();
    if (*z==1) {
                EWord *y=new EWord;
                y->Data=DictBegin->Find("NOP");
                CatDat(y);
                EWord *x;
                x=(EWord *) Stk->pop();
                x->Data=y;
                //delete Stret->popData(ADRESSF).Data;
                } else { throw "Ошибка в использовании конструкции IF..THEN"; }
    delete z;
}
static void aELSEa(void *Link) // _ELSE
{
    EWord *b;
    b=(EWord *) Stret->pop();
    Stret->push(b->Data);
}
static void ELSE(void *Link) // ELSE
{
    woprcomp(Link);
    FINT *z;
    z=(FINT *) Stk->pop();
    if (*z==1) {
                EWord *y=new EWord;
                y->Data=DictBegin->Find("_ELSE");
                CatDat(y);
                EWord *a=new EWord(false);
                CatDat(a);
                y=new EWord;
                y->Data=DictBegin->Find("NOP");
                CatDat(y);
                EWord *x;
                x=(EWord *) Stk->pop();
                x->Data=y;
                Stk->push(a);
                FINT *b=new FINT;
                *b=1;
                Stk->push(b);
                } else { throw "Неверное использование конструкции IF..ELSE..THEN"; }
    delete z;
}
static void arwa (void *Link) // 0=
{
    FINT *a;
    a=(FINT *) Stk->pop();
    if (*a==0) *a=-1; else *a=0;
    Stk->push(a);
}
static void abla (void *Link) // 0>
{
    FINT *a;
    a=(FINT *) Stk->pop();
    if (*a>0) *a=-1; else *a=0;
    Stk->push(a);
}
static void amna (void *Link) // 0<
{
    FINT *a;
    a=(FINT *) Stk->pop();
    if (*a<0) *a=-1; else *a=0;
    Stk->push(a);
}
static void NOT(void *Link) // NOT
{
    FINT *a;
    a=(FINT *) Stk->pop();
    *a=~(*a);
    Stk->push(a);
}
static void AND(void *Link) // AND
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=(*b)&(*a);
    Stk->push(a);
    delete b;
}
static void OR (void *Link) // OR
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=(*b)|(*a);
    Stk->push(a);
    delete b;
}
static void XOR (void *Link) // XOR
{
    FINT *a,*b;
    a=(FINT *) Stk->pop();
    b=(FINT *) Stk->pop();
    *a=(*b)^(*a);
    Stk->push(a);
    delete b;
}



