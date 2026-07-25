# Intro to tutorial
- Type in the examples by hand
- Solve the given problems and compare it to the provided solution
- Don't neglect learning how to use a debugger. Debugging your own problems is the best way to become a good programmer.
# Intro to programs
- A **computer program** is a sequence of instructions that direct a computer to perform certain actions in a specified order.
- A **Software** is a collection of programs that tell a computer hardware what to do and how to perform a specific task. There are 4 types of software - System software, application software, Firmware and Middleware/Dev tools.
- The act of modifying a program so that it runs on other platform is called **porting**.
## Machine language
- CPUs are capable of only understanding Machine code.
- Machine code is raw binary or hex instructions encoded exactly as per the ISA.
- The set of all possible machine code that a system can understand is called an instruction set (IS).
- Each instruction is composed of 0s and 1s (a bit). The number of bits in a machine code instruction varies by the family of CPUs, called instruction set architecture (ISA). 
- ISA can be defined as a specification defining what the CPU can do.
## Assembly language
- An Assembly language is a programming language that is a human-readable machine code.
>[!note] Capabilities that make assembly more readable than Machine code
> 1. The operation is identified by short mnemonic (3-5 letter word).
> 2. Registers (fast memory part of CPU itself) is access by the name of that specific register.
> 3. Numbers can be represented in a more convenient format. Most assembly languages support both Decimal and Hexadecimal representations.
> For example, `mov al, 0x61` means copy the number 0x61 into register named al.
- CPUs do not understand Assembly code. They need to be converted to machine code. This is done by the assembler.
- Just like each CPU family has its own machine code, it also has its own assembly code. But, most of these assembly codes are conceptually similar.
- Assembly and Machine code are called 'low level' programming languages as they provide minimal abstraction.
- The down-sides to the low level languages are that it is not portable and very difficult to write, even to perform simple tasks.
- They provide primitive capabilities and all extra capabilities need to be manually implemented by the programmer.
## High level languages
- To address the above said downsides of low level languages, high level languages such as C, C++ and others were developed.
- Just like the assembly code, high level languages need to be converted to machine code. It is done in two ways - Compiling and interpreting.
- A **compiler** is a program that converts source code into machine code.
- Most C++ compilers can be configured to also generate the assembly code.
- Modern C++ compilers convert the source code directly to machine code. Most compilers internally use IR (Intermediate representation) for optimization & cross platform support but some simple compilers can be made to skip IR and produce machine code from AST (Abstract Syntax Tree).
- The machine code output by the compiler can then be packaged into an executable file, that can be distributed to others. To run an executable, we do not need the compiler.
- Interpreter is a program that directly executes the source code without having to compile them first. It is more flexible than compilers but are less efficient because they need to be interpreted every time the code is run. The interpreter must also be installed on the system first, before running the source code. Distribution becomes difficult due to sharing of source code (Intellectual property exposed). Compilers are generally slower to 'load up' than interpreters that is why web browsers use interpreter. 
>[!caution] One thing to note is that a *Language* is neither compiled nor interpreted. For example, C interpreters exist, especially to teach introductory classes or small implementations.
- Regarding these notes, callouts labelled as `rule` will be used for Rules that you *must* follow, `best-practice` for best practices in C++ and finally, `avoid` to signal things you should not do.
>[!rule] This is a rule

>[!best-practice] This is a best practice

>[!avoid] Avoid!!
# Intro to C++ development
- A good solution will have the following characteristics:
	1. They are straight-forward (not confusing or complex).
	2. They are well documented.
	3. They are built modularly.
	4. They can recover gracefully from an unexpected behaviour.
>[!best-practice] Name the primary source code as `main.cpp`
# Intro to compiler, linker, and libraries
- The compiler does 2 things - Give an error in case there is, and translate C++ source code into low-level language (sometimes directly to machine code instructions). These instructions are stored in an intermediate file called an **Object file**(.o). 
- The linker is a program that kicks in after the compiler is finished. Linker combines all the related object files into a machine executable code. This process is called linking and it can throw errors if there is some issue during linking.
>[!note] Compilation process
>Preprocessor -> expanded source code (Translation unit) -> compiler (parser + IR + optimizer + backend code) -> assembly(.s) -> assembler -> object files (.o) -> linker -> machine code.
- A **Library** is a pre-compiled code that has been packaged up for reuse in other programs.
- The C++ **Standard Library**, is an extensive library that comes with C++ that provides a set of useful capabilities for use in programs, such as printing text to screen or getting keyboard input.
### Standard version used by the compiler
- To check which C++ standard the compiler is using, run the command `g++ -dM -E -x c++ /dev/null | grep __cplusplus`.
- Or, write a quick test file that outputs `__cplusplus` (`std::cout<< __cplusplus;`)
>[!note] Some compilers for C++ are : Clang, GCC and MSVC