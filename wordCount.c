/*************************************
* Tanner Wagner
* Professor Haugh
* CS 241
* Section 3RW

* This file is meant to hold all code 
* that is necessary for the wordCount
* project. To use this file, simply
* use the standard compiling commands 
* along with the < > operators to feed
* the program input and redirect it.
*
*************************************/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

/*************************************
* Each parameter’s type and name:
* - input:
*     - char myLine[MAX_LENGTH]
*     - int lineCount
*     - int wordCount
*     - int charCount
*     - int maxWordLine
*     - int maxWordCount
*     - int maxCharLine
*     - int maxCharCount
*     - int myLength
*     - int myWords
*     - int i
* - output: none
* - meaning:
*     - myLine: array to store each line of input
*     - lineCount: count of lines read
*     - wordCount: count of words read
*     - charCount: count of characters read
*     - maxWordLine: line number with maximum words
*     - maxWordCount: maximum number of words in a line
*     - maxCharLine: line number with maximum characters
*     - maxCharCount: maximum number of characters in a line
*     - myLength: length of the current line
*     - myWords: number of words in the current line
*     - i: loop variable
* - range of values:
*     - myLine: string input with maximum length MAX_LENGTH
*     - lineCount, wordCount, charCount, maxWordLine, maxCharLine: non-negative integers
*     - maxWordCount, maxCharCount, myLength, myWords, i: non-negative integers within valid range of int data type
* - Function’s return value: int (returns 0 to indicate successful execution)
* - Description of what the function does: 
*     Reads lines from input, counts words and characters in each line,
*     identifies the line with the maximum number of words and characters,
*     and prints statistics for each line.
* - Function’s algorithm:
*     1. Initialize variables for counting lines, words, and characters, and for storing maximum counts and corresponding line numbers.
*     2. Read lines from input using fgets() in a loop until end of input.
*     3. For each line:
*        a. Calculate the length of the line and initialize word count to zero.
*        b. Iterate through each character of the line:
*           i. If character is not a space, newline, or tab, increment word count and skip consecutive non-space characters.
*        c. Update total word count and character count.
*        d. If the last character of the line is a newline, remove it.
*        e. Print line information including line number, line content, word count, and character count.
*        f. Update maximum word count and line number if necessary.
*        g. Update maximum character count and line number if necessary.
*     4. Print overall statistics including total lines, total words, and total characters.
*     5. Print the line number with the most words and the line number with the most characters.
*     6. Return 0 to indicate successful execution.
*************************************/

int main()
{
  char myLine[MAX_LENGTH];
  int lineCount = 0;
  int wordCount = 0;
  int charCount = 0;
  int maxWordLine = 0;
  int maxWordCount = 0;
  int maxCharLine = 0;
  int maxCharCount = 0;
  int myLength;
  int myWords;
  int i;

  while (fgets(myLine, MAX_LENGTH, stdin) != NULL)
  {
    myLength = strlen(myLine);
    myWords = 0;
    lineCount++;

    for (i = 0; i < myLength; i++)
    {
      if (myLine[i] != ' ' && myLine[i] != '\n' && myLine[i] != '\t')
      {
	myWords++;

	while (myLine[i] != ' ' && myLine[i] != '\n' && myLine[i] != '\t' && i < myLength)
	{
	  i++;
	}
      }
    }

    wordCount += myWords;
    charCount += myLength - 1;

    if (myLine[myLength - 1] == '\n')
    {
      myLine[myLength - 1] = '\0';
      myLength--;
    }

    printf("(%2d) %s[%d, %d]\n", lineCount, myLine, myWords, myLength);

    if (myWords > maxWordCount)
    {
      maxWordCount = myWords;
      maxWordLine = lineCount;
    }

    if (myLength > maxCharCount)
    {
      maxCharCount = myLength;
      maxCharLine = lineCount;
    }
  }

  printf("\n");
  printf("%d lines, %d words, %d characters\n", lineCount, wordCount, charCount);
  printf("Line %d has the most words with %d\n", maxWordLine, maxWordCount);
  printf("Line %d has the most characters with %d\n", maxCharLine, maxCharCount);

  return 0;
}
