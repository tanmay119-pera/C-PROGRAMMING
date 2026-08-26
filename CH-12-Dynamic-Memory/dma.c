//!  DYNAMIC MEMORY ALLOCATION (DMA) MODULE IN C PROGRAMMING      

//& ITS IS A WAY TO ALLOCATE MEMO TO A DATA STRUCTURE DURING THE RUNTIME.
//& WE NEED SOME FUNCTION TO ALLOCATE & FREE MEMORY DYNAMICALLY.                 

/*
Direct Memory Access (DMA) is the ultimate delegation tool in computer architecture. It prevents your CPU from being 
bogged down by tedious, low-level data transfer tasks, freeing it up to do actual computing

The Definition
Direct Memory Access (DMA) is a hardware feature that allows specific computer components (like disk drives, graphics cards, 
or network controllers) to read from or write to the main memory (RAM) directly, completely bypassing 
the Central Processing Unit (CPU).

Without DMA, the CPU would have to read every single byte of data from a peripheral and write it to the memory itself—a massive
waste of processing power. With DMA, the CPU simply tells a specialized chip called
the DMA Controller (DMAC): "Move this block of data from the hard drive to RAM, and let me know when you're done."

How It Works (The Core Lifecycle)

1. The Request: The CPU programs the DMA controller by giving it a source address, a destination address, and the amount of data to move.
2. The Handover: The CPU issues a command to start the transfer and goes back to executing other instructions.
3. The Transfer: The DMA controller takes over the system bus and moves the data directly between the hardware device and RAM.
4. The Interrupt: Once the transfer is complete, the DMA controller sends an interrupt signal to the CPU, letting it know the data is ready.

CRUCIAL POINTS TO REMEMBER:
1. It requires a dedicated controller: DMA isn't just a software trick; it requires physical hardware known as the DMA Controller (DMAC) to manage the system bus while the CPU is busy elsewhere.
2. Bus Contention: Since the CPU and the DMA controller share the same system bus to access memory, they can't usually use it at the exact same time. The DMA controller has to essentially "borrow" the bus from the CPU.
3. Three main transfer modes:
   - Burst Mode: The DMA takes complete control of the bus and transfers the entire block of data at once. The CPU is paused until it finishes. (Fastest transfer, but delays the CPU).
   - Cycle Stealing Mode: The DMA transfers one byte (or word) at a time, giving control back to the CPU between each transfer. (Slower, but keeps the CPU running smoothly).
   - Transparent Mode: The DMA only transfers data when the CPU is performing operations that don't require the system bus. (Most efficient, but hardest to implement).
4. Cache Coherency issues: Because DMA changes data in the RAM directly, the CPU's high-speed cache might contain outdated, "stale" data. Modern systems use snooping protocols to ensure the CPU's cache stays synchronized with the RAM after a DMA transfer.*/

//* FUNCTION FOR DMA IN C PROGRAMMING
/*
A.) malloc() Function
The malloc() function is used to allocate a block of memory on the heap. It takes a single argument: 
the size of the memory block to allocate (in bytes). It returns a pointer to the beginning of the block of memory allocated. 
If the allocation fails, it returns NULL.

Syntax:
void* malloc(size_t size);

Example:
int* ptr = (int*)malloc(sizeof(int) * 10); // Allocates memory for an array of 10 integers.

B.) calloc() Function
The calloc() function is similar to malloc(), but it also initializes the allocated memory to zero.

Syntax:
void* calloc(size_t num, size_t size);

Example:
int* ptr = (int*)calloc(10, sizeof(int)); // Allocates memory for an array of 10 integers and initializes them to zero.

C.) realloc() Function

The realloc() function is used to resize a previously allocated block of memory. It takes two arguments: 
a pointer to the previously allocated memory block and the new size (in bytes). It returns a pointer to the resized memory block.
If the reallocation fails, it returns NULL, and the original block of memory remains unchanged.

Syntax:
void* realloc(void* ptr, size_t new_size);

Example:
int* ptr = (int*)malloc(sizeof(int) * 10); // Allocates memory for an array of 10 integers.
ptr = (int*)realloc(ptr, sizeof(int) * 20); // Resizes the memory block to hold 20 integers. 

D.) free() Function
The free() function is used to deallocate a previously allocated block of memory. It takes a single argument: 
a pointer to the memory block to be freed. After calling free(), the pointer becomes invalid, and the memory can be 
reused by the system. It is important to avoid using the pointer after it has been freed, as this can lead to undefined behavior.

Syntax:
void free(void* ptr);

Example:
int* ptr = (int*)malloc(sizeof(int) * 10); // Allocates memory for an array of 10 integers.
free(ptr); // Deallocates the memory block. */

//* MALLOC() FUNCTION IN C PROGRAMMING

//^ TAKES NUMBER OF BYTES TO BE ALLOCATED AND RETURN A POINTER OF TYPE VOID.
//& ptr = (*int)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
#include <stdio.h>
#include <stdlib.h>
int main(){
   int *ptr;
   ptr = (int*)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
   ptr[0] = 10;
   ptr[1] = 20;
   ptr[2] = 30;
   ptr[3] = 40; 
   for(int i = 0; i < 5; i++){
      printf("%d\n", ptr[i]);
   }
   return 0;
}

//* CALLOC() FUNCTION IN C PROGRAMMING

//^ CONTINUOS ALLOCATION OF MEMORY BLOCKS AND INITIALIZES THEM TO ZERO.
//& ptr = (*int)calloc(5, sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND INITIALIZES THEM TO ZERO.
#include <stdio.h>
#include <stdlib.h>
int main(){
   int *ptr;
   ptr = (int*)calloc(5, sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND INITIALIZES THEM TO ZERO.
   for(int i = 0; i < 5; i++){
      printf("%d\n", ptr[i]);
   }
   return 0;
}

//* REALLOC() FUNCTION IN C PROGRAMMING

//^ REALLOCATE(INCREASE OR DECREASE) MEMORY USING THE SAME POINTER AND SIZE.
//& ptr = (*int)realloc(ptr, 10 * sizeof(int)); // RESIZES THE MEMORY BLOCK TO HOLD 10 INTEGERS.
#include <stdio.h>
#include <stdlib.h>
int main(){
   int *ptr;
   ptr = (int*)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
   ptr[0] = 10;
   ptr[1] = 20;
   ptr[2] = 30;
   ptr[3] = 40;
   ptr = (int*)realloc(ptr, 10 * sizeof(int)); // RESIZES THE MEMORY BLOCK TO HOLD 10 INTEGERS.
   for(int i = 0; i < 10; i++){
      printf("%d\n", ptr[i]);
   }
   return 0;
}  

//* FREE() FUNCTION IN C PROGRAMMING

//^ WE USE IT  TO FREE MEMO THAT IS ALLOCATED USING MALLOC() OR CALLOC().
//& free(ptr); // DEALLOCATES THE MEMORY BLOCK.
#include <stdio.h>
#include <stdlib.h>
int main(){
   int *ptr;
   ptr = (int*)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
   ptr[0] = 10;
   ptr[1] = 20;
   ptr[2] = 30;
   ptr[3] = 40;
   free(ptr); // DEALLOCATES THE MEMORY BLOCK.
   return 0;
}  