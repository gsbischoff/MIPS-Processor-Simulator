#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__

class DataMemory
{

    public:

        std::vector<int> data;

        int address;
        int write_data;
        int read_data;

        int control_read;
        int control_write;

        DataMemory(std::vector<int> data_m);
        ~DataMemory();

        void print_out();
        void execute();
};
#endif
