#include "StringTable.h"
TS::TS()
{
    Table=new str_lex[201];
    size=0;
    for(size_t i=0;i<201;i++)
    {
        Table[i].is_empty=0;
        Table[i].label=-1;
        Table[i].next=-1;
        Table[i].TL=-1;
    }
}

TS::~TS()
{
    delete [] Table;
    size=0;
}

int hash_func(int key)
{
    return (key%100)+1;
}

int TS::find(int key)
{
    int index=hash_func(key);
    if(Table[index].label!=key)
    {
        while(Table[index].next!=-1)
        {
            index=Table[index].next;
            if(Table[index].label==key)
            {
                return index;
            }

        }
    }
    else 
    {
        return index;
    }
}

int TS::find_empty(size_t i,size_t j)
{
    for(size_t k=i;k<j;k++)
    {
        if(Table[k].is_empty==0)
            return k;
    }
}

void TS::add(int key,int value)
{
    int index=hash_func(key);
    
    if(Table[index].is_empty!=0)
    {
        if(Table[index+100].is_empty!=0)
        {
            int index2=find_empty(101,201);
            Table[index2].label=key;
            Table[index2].TL=value;
            Table[index2].is_empty=1;
            size++;
            while(Table[index].next!=-1)
            {
                index=Table[index].next;
            }
            Table[index].next=index2;
            
        }
        else
        {
            Table[index+100].label=key;
            Table[index+100].TL=value;
            Table[index+100].is_empty=1;
            Table[index].next=index+100;
            size++;
        }
        
    }
    else
    {
        Table[index].label=key;
        Table[index].TL=value;
        Table[index].is_empty=1;
    }
}

void TS::print()
{
    
    for(size_t i=0;i<201;i++)
    {
        std::cout<<i<<"|"<<Table[i].label<<"    "<<Table[i].TL<<"   "<<Table[i].next<<std::endl;
        if(i==100)
        std::cout<<"Область переполнения--------------"<<std::endl;
    }
}
void TS::del(int key)
{
    int index=hash_func(key);
    int prev_index;
    if(Table[index].label!=key)
    {
        
        while (Table[index].label!=key)
        {
            prev_index=index;
            index=Table[index].next;
        }
        if(Table[index].next!=-1)
        {
            Table[index].label=-1;
            Table[index].TL=-1;
            Table[prev_index].next=Table[index].next;
            Table[index].next=-1;
            Table[index].is_empty=0;
        }
        else
        {
            Table[index].label=-1;
            Table[index].TL=-1;
            Table[index].is_empty=0;
        }
        
    }
    else
    {
        if(Table[index].next!=-1)
        {
            Table[index].label=-1;
            Table[index].TL=-1;
            Table[prev_index].next=Table[index].next;
            Table[index].next=-1;
            Table[index].is_empty=0;
        }
        else
        {
            Table[index].label=-1;
            Table[index].TL=-1;
            Table[index].is_empty=0;
        }
    }

}