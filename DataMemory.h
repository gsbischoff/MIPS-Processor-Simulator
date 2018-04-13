#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include "stdHeader.h"

class DataMemory
{

    public:

        std::map<u32, u32> data;

        u32 address;
        u32 write_data;
        u32 read_data;

        int control_read;
        int control_write;

        DataMemory();
        DataMemory(std::map<u32, u32> data_m);
        ~DataMemory();

        void print_out();
        void execute();
};
#endif
