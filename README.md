# MIPS-Processor-Simulator

This program simulates a 5-stage, nonpipelined, MIPS processor.

## Usage

The processor is set up using a configuration file which is passed as a command line argument. A config file has a format of *parameter=value*. Possible parameters are:

* **program_input** is the name of a file containing MIPS assembly source. The following instructions are supported: ADD, SUB, ADDI, SLT, LW, SW, BEQ, and J. Labels are not supported -- instead, absolute addresses of instructions in memory are used. This abides by MIPS' convention where program execution begins at address *0x400000*.

* **memory_contents_input** is the name of a file containing the inital contents of memory. Formatted as *address:value*, for example *10000004:0ddc6522*. Values as assumed to be in hex always.

* **register_file_input**  is the name of a file containing the inital contents of the registers. Formatted as *registernumber:value*, for example *3:8*. Values as assumed to be in hex always.

* **output_mode** can be either *single_step* or *batch*, meaning execution of instructions are done one at a time or the entire program is run with no interrupts, respectively.

* **debug_mode** is either *true* or *false*.

* **print_memory_contents** is either *true* or *false*. If set, the progam will print to stdout the contents of memory and the registers at each step in *single_step* mode.

* **output_file** is the name of the file to which the contents of the data memory and registers will printed at the end of execution.

The inputs into all ALUs, Multiplexors, and all their control lines are simulated and displayed by this program.

## Building

Build on OSX using

```bash
make
```

Build on Windows using

```bash
build
```

Both create an executable with the name **main**.