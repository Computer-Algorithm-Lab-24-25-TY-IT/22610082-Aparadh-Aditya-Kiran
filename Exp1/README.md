# Experiment-1 : Profiling with gprof

This code contains three implementations of calculating the nth Fibonacci Number (0-indexed). The compiled program is executed and profiled using the *gprof* tool.

The three algorithms are :

#### Iterative  Fibonacci
Uses a simple `for` loop and two variables to keep track of current fibonacci number. 

#### Simple Recursive Fibonacci
Uses the recurrence relation between fibonacci numbers :
> ```
>fibo(n) = fibo(n-1) + fibo(n-2)
>```


#### Memoized Recursive Fibonacci
Uses the same recurrence relation as above, but memoizes the results of function calls in a *n+1* sized array to prevent repetitive execution of identical function calls.


## Result of execution



Compiling the code with profiling enabled:
```bash
g++ -pg -o fibonacci fibonacci.cpp
```
Executing the code:
```
./fibonacci
```
#### Output:
```
n: 40

Iterative Fibonacci: 102334155
Simple Recursive Fibonacci: 102334155
Memoized Recursive Fibonacci: 102334155
```

## Result of Profiling

Reading the profiled information using:
```
gprof fibonacci gmon.out 
```

Here is the `gprof` output
```
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 40.27      0.23     0.23        1   225.51   225.51  RecursiveFibonacci(int)
 39.38      0.45     0.22                             _init
 14.32      0.53     0.08        1    80.18    80.18  iterativeFibonacci(int)
  6.26      0.56     0.04        1    35.08    35.08  MemoizedRecursiveFibonacci(int, int*)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
           else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
           function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
           the function in the gprof listing. If the index is
           in parenthesis it shows where it would appear in
           the gprof listing if it were to be printed.


Copyright (C) 2012-2024 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.


                     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 1.78% of 0.56 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     60.7    0.00    0.34                 main [1]
                0.23    0.00       1/1           RecursiveFibonacci(int) [2]
                0.08    0.00       1/1           iterativeFibonacci(int) [4]
                0.04    0.00       1/1           MemoizedRecursiveFibonacci(int, int*) [5]
-----------------------------------------------
                             331160280             RecursiveFibonacci(int) [2]
                0.23    0.00       1/1           main [1]
[2]     40.2    0.23    0.00       1+331160280 RecursiveFibonacci(int) [2]
                             331160280             RecursiveFibonacci(int) [2]
-----------------------------------------------
                                                 <spontaneous>
[3]     39.3    0.22    0.00                 _init [3]
-----------------------------------------------
                0.08    0.00       1/1           main [1]
[4]     14.3    0.08    0.00       1         iterativeFibonacci(int) [4]
-----------------------------------------------
                                  78             MemoizedRecursiveFibonacci(int, int*) [5]
                0.04    0.00       1/1           main [1]
[5]      6.2    0.04    0.00       1+78      MemoizedRecursiveFibonacci(int, int*) [5]
                                  78             MemoizedRecursiveFibonacci(int, int*) [5]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index      A unique number given to each element of the table.
                Index numbers are sorted numerically.
                The index number is printed next to every function name so
                it is easier to look up where the function is in the table.

     % time     This is the percentage of the `total' time that was spent
                in this function and its children.  Note that due to
                different viewpoints, functions excluded by options, etc,
                these numbers will NOT add up to 100%.

     self       This is the total amount of time spent in this function.

     children   This is the total amount of time propagated into this
                function by its children.

     called     This is the number of times the function was called.
                If the function called itself recursively, the number
                only includes non-recursive calls, and is followed by
                a `+' and the number of recursive calls.

     name       The name of the current function.  The index number is
                printed after it.  If the function is a member of a
                cycle, the cycle number is printed between the
                function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self       This is the amount of time that was propagated directly
                from the function into this parent.

     children   This is the amount of time that was propagated from
                the function's children into this parent.

     called     This is the number of times this parent called the
                function `/' the total number of times the function
                was called.  Recursive calls to the function are not
                included in the number after the `/'.

     name       This is the name of the parent.  The parent's index
                number is printed after it.  If the parent is a
                member of a cycle, the cycle number is printed between
                the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self       This is the amount of time that was propagated directly
                from the child into the function.

     children   This is the amount of time that was propagated from the
                child's children to the function.

     called     This is the number of times the function called
                this child `/' the total number of times the child
                was called.  Recursive calls by the child are not
                listed in the number after the `/'.

     name       This is the name of the child.  The child's index
                number is printed after it.  If the child is a
                member of a cycle, the cycle number is printed
                between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.


Copyright (C) 2012-2024 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.


Index by function name

   [2] RecursiveFibonacci(int) [5] MemoizedRecursiveFibonacci(int, int*)
   [4] iterativeFibonacci(int) [3] _init
```