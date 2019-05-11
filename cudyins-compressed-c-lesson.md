guaranteeguarantee# Tl;dr C

## Main

```C
int main(void) {  
}
```

or

```C
int main(int argc, char** argv) {
}
```

## Primitive types

      Java                       C                 Notes
==================   ======================   ==================
char                      char                no exact equiv as char can be anything
String                    char* aka char []   just a bunch of chars
short                     short               not really.
int                       int                 not really.
long                      long                not really.
boolean                   bool                (since C99)
==================   ======================   ==================

### why the "not really?"

Because in Java, short, int, long are guaranteed to be 2, 4, and 8 bytes respectively.

In C, however, they're only guaranteed to be **at least** 1, 2, and 4 bytes respectively.
In reality it is even worse as the datatype sizes depend on the OS and 32- vs 64-bit architectures.

For example, long on win32 and linux 32 is 4 bytes. But on win64 it is 8, on linux 32 it is 8, too.
Int, on the other hand, stays 16 on some archs, yet becomes even as large as 64 bit = 8 byte on very rare ones.

### Rule

Do not use any of `short`, `int`, `long` for anything but loop counters/indices.

Instead, use ` ` and `<inttypes.h>`, together with `<stddef.h>` Headers.

These give you `int8_t`, `int16_t`, `int32_t`, `int64_t` (and some others),
as well as the unsigned equivalents of `uint8_t`, `uint16_t`, ... and `uint64_t`.

These datatypes are **guaranteed** to be the exact size.
The `_least_` variants of those datatypes are guaranteed to be **at least** that size.
We won't go into detail about the latter ones just yet.

so far so good? yep! it makes sense now the int8_t v int

### Booleans or the lack thereof 'til recently.

Until the 1999 overhaul of the C standard, there was no boolean datatype in C,
yet you could have boolean expressions.

example

```C
#define int BOOL
#define 1 TRUE
#define 0 FALSE

if(2 == 3) { // never true
  return ohboy;
} else {
  return yay; //#duh, this one gets returned.
}

int foo(/*...*/) {
  //...
  return TRUE;
}

if(foo(...)) {
  do_something();
}
```

As one can see, `foo` returns an integer, which is then used as a boolean in the
following if statement.

There's an implicit conversion rule from anything to bool:
if the value is 0, then the bool is `false`.
else, the bool is `true`.

```C
if(0) {
  //never gets here
}
while(0) {
  //loop never gets executed.
}

if(1) {
  //always gets here
}
while(1) {
  //forever loop
}
```

With C99, and C11, one can now instead include the `<stdbool.h>` header, and use
```C
bool foo(/*...*/) {
  //...
  return true;
}
```

makes sense? yep 1 = true, 0 = false uppercase names are usually macros  aka `#define`

## Compilers are smarter than you. #duh

If you think that a compiler got something wrong, odds are that you indeed did something wrong.

As such, use all the damn warnings that a compiler can give you in order to fix your code.

With that in mind, regardless of gcc or clang, use the following

`-Wall -Wextra -g3`

with clang, use `-Weverything -g3` instead. `-Weverything` does indeed warn about **EVERYTHING**
that you're possibly doing the wrong way.

## Automate the shit aka Makefiles

Makefiles are a somewhat dark art, but rather simple

rulename: prerequisites
<TAB> command(s)

so to build a file `foo.c` into an executable `foo`, your `Makefile` would be something like this:

```Makefile
foo: foo.o
	$(CC) $(CFLAGS) -o $@ $^
```

With that in place in the same directory as `foo.c`, you can type `make foo` and be done with it.
Adding in the above recommended flags for clang, this turns into

```Makefile
CC := clang
CFLAGS := -Weverything -g3 -O1 -fPIC
foo: foo.o
	$(CC) $(CFLAGS) -fPIE -o $@ $^
```

why the `-O1`, '-fPIC' and `-fPIE`? Some warnings can only be generated with optimization optionss enabled,
yet higher than `-O1` can make debugging way harder as `-g3` includes debug symbols into the binary, yet higher optimizations make the code vastly different and don't allow one to inspect all the variable values.

`-fPIC` and `fPIE` adds ASLR (address space layout randomisation) to the compiled code so it'll properly crash in case of a buffer overflow.
The difference is that `-fPIC` must be specified for all intermediate compile stages and for
(shared) libraries, whereas `-fPIE` can only be specified for runnable binaries aka programs.

There are other flags that one might want to use, but for now, that's outside of the topic(s) at hand.

## Does this array make me look fat or sizes.

```
uint8_t foo[10] = {1,2,3,4,5,6,7,8,9,10}; // 10 octets.

void foo(uint8_t bar[]) {
  //how do we get the # of elements in bar?
  //unlike Java, there's no .length attribute or any attribute for that matter.
  size_t num_items = sizeof(bar); // subtle, but still WRONG.
  size_t actual_num_items = sizeof(bar) / sizeof(uint8_t);
  //BUT what happens if the type of bar changes? wrong value if you forgot to change the sizeof(uint8_t) along with it

  //Here's the robust way of getting the number of items.
  size_t robust_num_items = sizeof(bar) / sizeof(bar[0]); // in this context, return the storage size, not the value
}
```
that's why there's `sizeof()`. sizeof takes one argument and returns the size
of that argument in multiples of `char`. (Almost) any storage size in C is of type
`size_t`, which is defined in `<stddef.h>` together with `SIZE_MAX`.

As such, `sizeof()` does indeed return a `size_t`.

As being said, `sizeof` returns the size of its argument in multipes of char.
So if you have an array of say, `int64_t`, that doesn't give you the number of items, but rather
the number of items * 8 as int64_t is 8 bytes in size.

## Arrays vs Pointers

```
uint16_t values[10] = {1, }; // first item is ==1, all others are semi-random --
                             // compiler will warn about this, though.
uint16_t* valptr; // pointer that doesn't point to anything in particular so far.

uint16_t temp1 = *valptr; // get the item that valptr points too... BOOM!
//this will most likely crash with ASLR, as we try to access a piece of memory
//whose address is random at runtime.
```

So let's go back. What is `uint16_t* valptr`, actually? it is a pointer that will eventually
store a memory address. Given that we haven't assigned any memory address to it, it is
storing a random memory address.
so if we called free on valptr that would be really bad yeah? since we dont know what its pointing to?
free is as bad as the `temp1` line.

So how do we distinguish between a pointer with an assigned memory address and one that hasn't been assigned a memory address?

### Hallowed are the Ori

`NULL` is the answer. And the problem. well, how programmers misuse `NULL`, rather.

`NULL` is a predefined and **OS-dependent** value that implies a "Non-existant" memory address.

so in the above example,

```
uint16_t* valptr = NULL;
uint16_t temp1 = *valptr; // still big badda BOOM!
```

But didn't you say that `NULL` fixes that issue? Yes, it does. BUT YOU still have to CHECK that it is NOT NULL.
As people say, C hands you a rifle but doesn't prevent you from blowing your head off.

```
uint16_t* valptr = NULL;
uint16_t temp1;
if(NULL != valptr) {
  temp1 = *valptr;
}
//now we're safe.
```

#### Interlude (tool-intermission.mp3)

why `NULL != valptr` instead of the way more often encountered `valptr != NULL`?

 Because I'm the harbringer of quality and defensive coding.
 slip and omit the `!` and you just overwrote a valid pointer with `NULL`, which might even lead to a memory leak.
 whereas the `NULL = valptr` WILL create a compiler error.

### More pointer fun.

Just like Java, C got explicit memory allocation.
Whereas Java uses `new`, `new[]`, `delete`, `delete[]`, C offers 4 memory handling pieces (actually 5...).

int[] a = new int[15]; that's what I meant with new[]

void* malloc(size_t SIZE);
void* calloc(size_t COUNT, size_t ELEMENT_SIZE);
void* realloc(void* current_ptr, size_t NEW_SIZE);
void free(void* ptr);

#### Hit that repeat button aka interlude aka void vs void*

void: nothing. Useful when a function doesn't return anything or doesn't take arguments.
void*: pointer to data of any type. Can only be used to access the actual data
       after casting to that actual data's type.

makes sense? yeah, but one question. does the * mean its a pointer? mostly yes.

`int* foo` Pointer to int named foo
`*foo` dereference a pointer named foo aka access the value that the pointer points to.

shortest program to crash:

```
int main(void) {
  *(NULL); //null-pointer dereference <- aka the magic search phrase in CVEs.
}
```

does that answer your question? yep

now then, ...

### The beauty of Overflows.

```
int a = INT_MAX; // usually == +2 billion and change
int b = a + 1;
```

What is the value of b? overflow so minus 2 billion and change ?yep. INT_MIN namely. ofc.

speaking of INT_MAX...

#### Those pesky interludes

each of int8_t, ... int64_t, uint8_t, ... uint64_t has predefined min/max values.

Named... INT8_MAX, INT8_MIN, ... INT64_MAX, INT64_MIN, UINT8_MIN, UINT8_MAX, ... UINT64_MIN, UINT64_MAX.
As one can easily guess, the MIN value for the UINT variants is 0.

### Back to memory management

With overflows in mind, what happens if one passes -1 to `malloc`?
Recall that malloc takes a size_t (unsigned data type), and returns either NULL if the allocation failed, or a pointer to that many bytes of raw memory?
does malloc have a default value that -1 could work with? nope. Also, two's-complement.
-1 is all 11111...111 in binary. so by casting that value to size_t, we get malloc(SIZE_MAX). hrm yeah i dont fully understand 2's complement yet, ill need to look into that. no worries.

so technically, this malloc call **can** work, but the SIZE_MAX thing is tricky

SIZE_MAX is defined in the standard as an *implementation-defined* value that represents the maximum number of addressable elements in an array or in memory.

SIZE_MAX is only guaranteed to be **at least** 65535.

Want to allocate a million fields? Better check that `SIZE_MAX >= alloc_size`.
And this leads to one of the two reasons as to why one should avoid `malloc` in favor of `calloc`.

```
const size_t count = 10000;
uint64_t* array = malloc(count * sizeof(uin64_t)); // proper syntax, but some issue.
```

What happens if count = SIZE_MAX? your answer: is that the size of unit64_t * 8?
sizeof(x) returns the size of x in bytes. so sizeof(uint64_t) == 8. wow ok.
the answer, as so often with C, is "it depends"

On the OS and Architecture.

in the best case, it'll return NULL as the internal value of count * 8 will be 8 times as large as SIZE_MAX, which is only guaranteed to be 65535. so if size_t is a 32-bit type and SIZE_MAX is 65535, then that value will not overflow.

But if, say, size_t is 64-bit and SIZE_MAX in the terabytes, then this would try to allocate all the available memory
til, on Linux, it'll OOM (out of memory). OOM's default behavior is to terminate **random** processes. <- lol wowreall

and there are other issues with malloc.

Memory allocated with malloc has random values (unless the OS zeroes out the memory, but that pretty much never happens).

Now look what cool stuff `calloc` does instead.

calloc ensures that the product of its two arguments is <= SIZE_MAX.
and in case of successful memory allocation, it'll zero out the allocated memory.

Time for a direct comparison:

```C
void* make_array_malloc(const size_t num_items, const size_t per_item_size) {
  if(SIZE_MAX < num_items || SIZE_MAX / num_items < per_item_size) {
    return NULL;
  }
  void* ret = malloc(num_items * per_item_size);
  if(NULL != ret) {
    memset(ret, 0, num_items * per_item_size); //zero out allocated memory
  }

  return ret;
}

void* make_array_calloc(const size_t num_items, const size_t per_item_size) {
  return calloc(num_items, per_item_size);
}
```

your reaction: im surprised its not as verbose
they do the exact same thing. thats cool, so calloc is better then? yep
generally the way better option instead of malloc.

### The perils of realloc or programmers and tools are dumb.

`realloc` is a function that takes a pointer (to an array or other allocated memory structure), and a new size.
it'll then try to increase the size of the current structure to that new size or allocated a new memory area and copy the data over. finally, it returns a pointer to the new (re-)sized memory.

```C
//extremely shitty, don't use my implementation in production
void* realloc(void* current, size_t new_size) {
  if(!increase_current_memory_area(current, new_size)) {
    void* new_mem = malloc(new_size);
    if(NULL != new_mem) {
      memcpy(new_mem, current, current_size);
    } else {
      return current;
    }
  }
}
```

as you can see, the realloc behavior is complex, but the issues arising from the use of realloc are two-fold
and ultimately the programmer's fault.

A), in `void* res = realloc(current, new_size);`, `res` can be != `current`. And b)., all the isssues with the size_t and malloc do also apply to realloc.

Most programmers do this:

```
    current = realloc(current, new_size);
    ...
```

But what is wrong with that? your answer: they didnt check for null? yes. and another issue in case of non-NULL result. Your answer: is it size related? like how you were saying earlier about allocating too much memory.

Hint: check A) above. not sure tbh. A potential memory leak.

```
    current = realloc(current, new_size);
```

If the returned pointer is not the one provided to `realloc`, then the subsequent assignment overwrites the memory address that current is pointing to without freeing the previous memory area.

As instead, one must write

```C
    void* new_pointer = realloc(current, new_size);
    if(NULL != new_pointer && new_pointer != current) {
      free(current);
      current = new_pointer;
    }
```
# Boolean print function
```
static inline char*const boolstr(const bool b) {
    return (b) ? "true" : "false";
}
```
