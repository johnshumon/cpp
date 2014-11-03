Homework 1 - Directory
Key words of your thesis are messed up by some weird virus. As a smart
student you will write an algorithm, which is as ecient as possible, to sort
words alphabetically. You remembered, that UDS lecture material said MSD-
Radix-sort to be good choice in this kind of situations. Your task is now to
implement the given interface. Changes in the interface are not allowed, so
all of your implementation have to be written in the private scope. Pay extra
attention to eciency of your implementation.
Commands
Command
R <t>
S
X min | max
P
E
Q
Description
Reads data from le <t> and adds words to the data structure
Sorts the data structure.
Prints shortest or longest word and length of the word
Prints contents of the data structure.
Empties the data structure.
Quits the program.
Input data le
Data le contains one word per one line. Words consists of lowercase letters
a-z. Structure of data le and example le is below.
<word>
beaus
adapter
bogeys
aardvark
anamorphic
astronomical
badgering
airframes
biochemist
approximate
Given parts
main.cc
Main program implements reading of word list and creating of data structure.
Main program also calls member functions. Student implements the given
interface and makes modications to the private part of the data structure.
Main program handles all needed printings except printing of the contents of
the data structure.
datastructure.hh
File datastructure.hh denes class Fatastructure and related interface. Stu-
dent implements all member functions and creates actual data structure and
other function if needed.
Functionality of program
Program stores each word to the data structure and sorts if when asked.
When printing word list, words are separated by using SEPARATOR cons-
tant variable, which is dened int the header le. So, the separator is printed
only between the words. It is possible to add words to the data structure
multiple times when running the program. On quit program have to release
all allocated memory. Use of vector as an array is allowed.
It is also possible to print shortest and longest word and length of it.
Command is either X min or X max depending on which one is asked. When
the word is printed, program prints SEPARATOR constant and after that
the length of the word. See sample run for example.
If the datastructure is empty when asking shortest or longest word, pro-
gram prints MSG_EMPTY_DS and returns.
Sample run of the program
Below $ means command prompt, so it is not a part of the le, input ot
output. Neither end of line after $-character is not part of the le, input nor
output.
$ ./prog < test_public.in
> R public_words
> S
> P
aardvark adapter airframes anamorphic approximate astronomical
2
badgering beaus biochemist bogeys
> X max
astronomical 12
> X min
beaus 5
> R does-not-exist
Error: file not found.
> Q
