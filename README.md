# Project_2048

## About

**If you are in China and do not want to waste your life, please visit https://hub.fastgit.org/CmsMartin/Project_2048**

This is a command line game written in C++. The compiler is Visual Studio, and C++11 is used as the language standard for compilation. 

And you can use 'w' to merge up, use 'a' to merge left, use 's' to merge down ,use 'd' to merge right.

You can type 'e' to exit the game.

This item will be updated from time to time.

## Principle

You can read it on bilibili ： https://www.bilibili.com/read/cv14189181

Again, only the up merge operation is explained.

Up is the operation on each column, for each column, we can put non-0 elements into a deque, record the number of elements, and set the column to 0

Add the first element to the end of the team, and then size - 1 this loop, at this time can ensure that the team head and the team tail is adjacent elements, if the team head and the team tail is different, pop the team head element, the element into the team tail, if the team head and the team tail is the same, you can merge, pop the team head, pop the team tail, add up, press into the team tail ~~(STL method is good)~~

After a merge, you get a new two-ended queue with the number of elements counted as Size'

If Size is size, then this merge fails, exits,

If Size! s Size', the merge succeeds and continues the process until it fails.

Finally, replace the columns with elements in the deque.

## Update

### 2021.11.27

The updates: First version!
