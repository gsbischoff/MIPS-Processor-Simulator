#ifndef __MULTIPLEX_H__
#define __MULTIPLEX_H__

class Multiplex
{

    public:

        int output;
        int in_a;
        int in_b;
        int selectorBit;

        Multiplex()
        ~Multiplex();

        void print_out();
        void setOutput();                  //sets the output line
        void setSelector(int selector);   //sets selector bit based on the control line

            //multiplex1.setSelector(control.ALUSrc)

};
#endif

