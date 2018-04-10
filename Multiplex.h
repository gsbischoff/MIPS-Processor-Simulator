#ifndef __MULTIPLEX_H__
#define __MULTIPLEX_H__

class Multiplex
{

    public:

        int output;
        int in_a;
        int in_b;
        int selector_bit;

        Multiplex();
        ~Multiplex();

        void print_out();                  //print out the values in the multiplexor
        void set_output();                 //sets the output line
        void set_selector(int selector);   //sets selector bit based on the control line

            //multiplex1.set_selector(control.ALUSrc)

};
#endif

