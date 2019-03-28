Lecture 1 - Higher Computing
============================

> **Tip**
>
> Lecture @
> <https://www.youtube.com/watch?v=hE7l6Adoiiw&t=0s&index=2&list=PLEEAD1D187A7CCD6C>

-   ABC of people

    1.  A - Never programmed before and very stressed.

        -   50% of people are in this.

        -   At the end of course A and C people are no different skill
            wise or marks wise.

    2.  B - Little to no programming, but comfortabla and relaxed to
        learn.

    3.  C - Innate with computers, very competent and confident. Usually
        self taught.

-   No programming knowledge assumed.

    -   Things will always go wrong in computing.

    -   You need to know that you can solve it.

    -   Stay determined and keep at it.

    -   Lots of ups and down in computing.

        -   Ups are when you solve the problems.

        -   Downs are when you are in the process of solving the
            problems.

-   Textbook

    -   Programming, Problem Solving and Abstraction with C

    -   <https://www.goodreads.com/book/show/6308414-programming-problem-solving-and-abstraction-with-c>

-   Computing starts counting at 0.

Lecture 2 - Inside A Computer
=============================

> **Tip**
>
> Lecture @
> <https://www.youtube.com/watch?v=JA_G8XbVYug&list=PLEEAD1D187A7CCD6C&index=2>

-   Course will be teaching:

    1.  Computer literacy - history/

    2.  Computer science - analyitical ability and craftsmanship.

    3.  System stream - how computers works like, memory and assembly.

    4.  Programming stream - programming in C.

-   Course uses `gcc -Wall -o hello helloWorld.c`

-   `*.c` files have the source code

    -   Once the source code is compiled it is in a binary file.

-   Try stuff and see how it goes.

History
-------

-   Charles Babbage invented the difference engine machine to calculate
    polynomials.

    -   Was to be used for British navigation charts.

    -   It was never built during his life time. Because half way
        through he designed the analytical engine.

        -   This was programmable and general purpose.

        -   Ada Lovelace helped him build this and wrote the first
            programs for this.

        -   It was never built either. The concept was used 100 years
            later in ENIAC.

-   Jon Von Neuman built the ENIAC which is the worlds first computer.

-   Transistors make computing possible.

    -   For computing they are an electric switch

    -   They have 3 wires coming into it.

        1.  Input

        2.  Controller

        3.  Output

    -   Inside is a switch to route voltage between wires.

    -   Made of lots of different substances, but today made of silicon.

        -   Wafered silicon has losts of transistors.

    -   A single transistor can store 1 bit. Join lots together and you
        can store lots of bits / bytes.

    -   When they turn on and off a small amount of current flows that
        generates heat.

-   Logic gates are created from joining transistors together.

    -   Picture of logic gates @
        <https://en.wikipedia.org/wiki/Static_random-access_memory#Design>

    -   Signal is sent down the wire, 0 or 1. Its opposite (complement)
        is also sent down a corresponding wire.

        -   WL is write line, where the signal is sent. Only once the
            target voltage is reaches is the signal actually sent.

        -   BL is where the complement is sent.

        -   Vdd, Vcc, 1v, 5v, all mean voltage is on or true.

            -   High voltages at the top of the diagram, low at the
                bottom.

        -   The 3 lines means voltage of 0.

        -   The circle before a gate is NOT. So any positive voltage
            will turn this off.

    -   The feedback loop is what causes data to be stored in the
        transistor when the power is off. One side has a 1 and other has
        a 0.

        -   A single logic gate is a 1 bit memory chip.

-   Computer chips have lots of transistors and thus logic gates.

    -   This is Charles Babbage’s design.

    -   First microprocessors were 4 bits. Intel 4004. In the 1970’s.
        <https://en.wikipedia.org/wiki/List_of_Intel_microprocessors>

        -   Eventually improved into the Intel 8086. The x84
            architecture.

    -   Intel, AMD, ARM, or AVR.

-   4917 processor. 4 bit machine.

    -   16 memory locations (8x8 matrix)

        -   Holds 4 bit each cell.

        -   Each location has an address, 0 to 15.

        -   All memory locations are 0 except where data is stored.

        -   Can only store numbers 0-15. 0-7 is 1 byte and 8-15 is 2
            byte.

    -   4 regsiters

        -   IP = instruction pointer

        -   IS = instruction store

        -   R0 = general register 0

        -   R1 = general register 1

    -   16 instrusctions

        -   0-7 are 1 byte

        -   8-15 are 2 byte

    -   Fetch-Execute cycle. Explained @
        <https://youtu.be/JA_G8XbVYug?t=3360>

        -   The instruction at the address given by IP is loaded into IS

        -   IP is incremented by 1 for one byte instructions or 2 for
            two byte instructions

        -   Instruciton in IS is executed.

        -   Repeat until IS is HALT

> **Tip**
>
> Online emulator @
> <https://www.flagsoft.com/cmswp/en/apps/4917emu-microprocessor-emulator/>

Lecture 3 - Machine Code
========================

> **Tip**
>
> <https://www.youtube.com/watch?v=gTeDX4yAdyU&list=PLEEAD1D187A7CCD6C&index=3>

-   Binary

    -   Voltage on always means true / on.

    -   Voltage off always means false / off.

-   0 in C means false, every other number is true.

-   Transistors put together create logic gates

    -   These are how binary is passed around a system.

    -   Boolean algebra can be implemented this way

        -   AND, OR, NOT, XOR, NAND

-   Stuff stored in CPU registers can be accessed more quickly than
    stuff stored in memory locations

Lecture 4 - Simple C Program
============================

> **Tip**
>
> <https://www.youtube.com/watch?v=Y0QN2bk4OoA&index=4&list=PLEEAD1D187A7CCD6C>
> `Week01.c`

-   We are using gcc as the compiler for this course

    -   `gcc -Wall -Werror -o ouput-file input-file.c`

-   The Ariane 5 space rocket disaster was caused by implicit type
    casting done by C.

    -   <https://blog.bugsnag.com/bug-day-ariane-5-disaster/>

-   `printf` will print formatted text

-   `scanf` will read in data and format it

Lecture 5 - Clarity
===================

> **Tip**
>
> <https://www.youtube.com/watch?v=F5FPlq-MeWo&list=PLEEAD1D187A7CCD6C&index=5>
> `Week02.c`

-   Inside every complex problem is a simple solution.

-   In programs you should separate ideas like paragraph, one block of
    code per idea like 1 paragraph per idea.

-   Use whitespace to make it more readable.

-   `main` is the function that starts the program, it is called by the
    operating system.

    -   It will return an `int` to the O/S signaling if it was
        successful or not. 0 is successful.

-   The C compiler will use `a.out` if you don’t provide an output file.

-   In general dividing a negative integer will round down. The result
    given is division remainder, without the remainder.

Lecture 6 - Solving Problems
============================

> **Tip**
>
> <https://www.youtube.com/watch?v=dyiYQ8Z_nI0&list=PLEEAD1D187A7CCD6C&index=6>
> `Week02.c`

-   It is human to make mistakes, so you will always make mistakes when
    you program.

-   Viking 1 and Viking 2 were a NASA Mars robots. Viking 1 died and
    they thought it was the battery. So the Viking 2 battery program was
    changed and stored in the wrong spot. It overwrote the radio
    communication program. Communication was lost forever.

-   When you are writing formulas, you should really on brackets to
    explicitly state the order of operations.

-   It is easy to solve problems in your head but it takes time to tell
    a computer how to solve it.

    -   You need to think algorithmically. Which is the steps you need
        to take to solve a problem.

-   Problem solving techniques

    -   Top down - start with the big problem and forget the details
        (abstraction). Break down that problem into broad steps that
        would solve the problem. Keep breaking down the steps until they
        are small enough to solve.

        -   Can solve any sized problems this way.

    -   Bottom up - get all the small bits you need to solve a problem
        and keep assembling them until you solve the problem. This is
        the natural human way to solve problems. But isn’t great because
        you’ll build things that you don’t need.

> **Tip**
>
> Top down design really helps to overcome the mental wall of it being
> too hard. Keep breaking the problem down until its actually
> achievable.

-   Keep testing as you solve problem steps.

    -   Start small and expand out.

    -   Keep a track of all your tests.

    -   Always rerun all tests.

    -   You need both positive and negative tests.

> **Tip**
>
> Continuous testing makes software engineering easier. You should write
> the test first before the code.

-   Magic numbers are numbers that appear during the program but have no
    explanation.

    -   Replace magic numbers with CONSTANTS.

        -   `#define VARIABLE_NAME VARIABLE_VALUE` is used to create
            CONSTANTS

-   Problems with learning programming, or learning or doing anything!

-   The biggest obstacle to learning is you!

    -   You need to work hard and be determined.

    -   But doing anything needs to be fun so you don’t quit.

    -   Make sure you practice daily.

Lecture 7 - Side Effects
========================

> **Tip**
>
> <https://www.youtube.com/watch?v=7AZhjQjYX9w&list=PLEEAD1D187A7CCD6C&index=7>
> `Week02.c`

\*
