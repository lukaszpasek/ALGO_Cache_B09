# Cache

You are ... a digital machine. You can not remember how it happened. You only remember what the software allows you to do. Your memory is divided into cache memory (relatively small) and ordinary memory. Whenever a program that performs in you refers to an ordinary memory cell, it must first copy it to the cache, unless the contents of that cell are already there - then of course you do not need to copy it again.

For a given sequence of subsequent references to ordinary memory, what is the minimum number of cached copying needed?

Available memory: 128MB

Entrance
The first line of entry contains the natural number 𝑍 - the number of data sets. Then sets are given in the following order:

The first line of the set contains three integers 𝑘, 𝑛, 𝑚 (1≤𝑘≤1000, 1≤𝑛, 𝑚≤106). Normal memory is flocked to 𝑛 cells (numbered from 1 to 𝑛), cache memory of 𝑘 cells. The next 𝑚 of the set line contains 𝑚 cell numbers in ordinary memory, followed by subsequent references.

Exit
For each set, write the minimum number of cell copyings from the ordinary memory to the cache.

Example  
For input data:  
2  
2 4 5  
1  
2  
1  
4  
1  
3 3 3  
1  
3  
2  
The correct answer is:  
3  
3  
