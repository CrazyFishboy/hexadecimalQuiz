# hexadecimalQuiz

*** README Incomplete ***


Repo has two different programs. The initial purpose was to create a quiz that would present a number in hexadecimal and prompts the user to enter the value in decimal.
I attempted to use multiple classes to do this. During the development I discovered an easier way to provide the same functionality, so the classes
are purely to preserve them. In the process of making the quiz, I realized that I needed a way to convert these values for testing, so I created another program
to convert a number. 

I felt that the conversion program had more potential and would provide more utility, so that is where the majority of my effort went to.

With that out of the way, usage is quite simple. Steps:

  1. Download or clone the repo
  2. Navigate to convert folder
  3. Compile and link main.cpp and functions.cpp within this folder.
  ```
  g++ main.cpp functions.cpp -o <executable name>
  ```
  4. Usage `<executable> [options] number`
  Options:
  -b <number> --base <number> Sets the base for the program to interpret the number in
       ex:
         `<executable> -b 16 100` -> Interpreted as 100 hexadecimal, which is 256 decimal
         `<executable> -b 8 100` -> Interpreted as 100 octal, which is 64 decimal
       valid bases are :
         2 - binary
         8 - octal
         10 - decimal
         16 - hexadecimal
     If this flag is not present, default interpretation is base 10 (decimal)
     
  -o <number> --output <number>  Sets the base for the program to display the output in.
       same usage as -b flag. If not specified, program will display all four supported bases by default.
     
  -n <number> --number <number> Specifies the number you would like to be converted. This flag is only necessary if you
    would like to specify the number before your other options. If this flag is not present, the program will interpret
    the last number after all of the flags as the number you would like specified.
      ex:
        Typical call: `<executable> -b 16 100` -> the number being converted is 100, and is currently in base 10
        With -n flag `<executable> -n 100 -b 16` -> Does the exact same thing as above.


  Program supports base indicators, which allow it to infer the base of the number without using the -b flag. To use these,
    simply preceed the number to be converted with one of the base indicators:

      binary -> '0b'
      octal -> '0'
      decimal -> Decimal is the default base, so no specifier is needed
      hexadecimal -> '0x'

      Example:
        0b100 -> 100 in binary = 4 in decimal
        0100 -> 100 in octal = 64 in decimal
        100 -> 100 in decimal
        0x100 -> 100 in hexadecimal = 256 in decimal

      Note that the -b flag overrides the base indicator, so
        `<executable> -b 2 0x100` will still interpret the number as 100 in binary


Currently, only positive numbers are supported. 64 bit unsigned integers are used, which can hold 2^64 values. One of these values is 0, so the max number
supported is (2^64)-1 -> (0xFFFFFFFFFFFFFFFF), which is 18,446,744,073,709,551,615 in decimal.
