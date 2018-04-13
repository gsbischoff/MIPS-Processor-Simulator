#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

#include "stdHeader.h"

class DataMemory
{

    public:

        std::vector<u32> data;

        int address;
        int write_data;
        int read_data;

        int control_read;
        int control_write;

        DataMemory();
        DataMemory(std::vector<u32> data_m);
        ~DataMemory();

        void print_out();
        void execute();
};
#endif
