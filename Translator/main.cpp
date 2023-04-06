#include <iostream>
#include "StringTable.h"
int main()
{
    TS table;
    table.add(2,13);
        table.add(2,13);

    table.add(21,13);
    table.add(44,13);
    table.add(4,13);
    table.add(444,13);   
     table.add(444,13);
    table.add(444,13);

    table.print();
    table.del(444);
    table.print();
    
}