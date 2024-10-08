/* Keaton lawson
 * hasUniqueChars.c
 * 
 * TODO: replace this line with lines containing a description
 * 
 * Author: 
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}


// TODO: Read this carefully to see how to loop over characters of a string
// TODO: (Remove TODOs once you have completed the task they describe)
/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;

  // Check for NULL pointer or empty string
    if (inputStr == NULL) {
        fprintf(stderr, "input string is NULL\n");
        exit(EXIT_FAILURE);
    }

        printf("Checking input string: '%s'\n", inputStr); // Debugging line
     
    if (inputStr[0] == '\0') {
        return; // An empty string is considered valid, no need to check further
    }
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      return;
    }
  }
}


/*
 * This function takes an input string and checks if every character (except spaces)
 * appears only once. Non-printing characters will trigger an error and cause the
 * program to exit. It uses two bit vectors to track whether characters have been seen:
 *   - checkBitsA_z for characters 'A' to 'z'
 *   - checkBitsexcl_amp for characters '!' to '@'
 * The function returns true if the string has unique characters, and false if duplicates are found.
 */
bool hasUniqueChars(char *inputStr) {

  
    // Check for invalid characters
    checkInvalid(inputStr);

     // Return true immediately if the string is empty
    if (inputStr[0] == '\0') {
        return true; // Empty string has no duplicate characters
    }

    int i;
    unsigned long checkBitsA_z = 0;     // for checking A through z and {|}~
    unsigned long checkBitsexcl_amp = 0; // for checking ! through @
    char nextChar;
    unsigned long mask;

    for (i = 0; i < strlen(inputStr); i++) {
        nextChar = inputStr[i];

        // Ignore spaces
        if (nextChar == ' ') {
            continue;
        }

        // Handle uppercase letters 'A' to 'Z'
        if (nextChar >= 'A' && nextChar <= 'Z') {
            int bitPosition = nextChar - 'A'; // Calculate bit position for uppercase letters
            mask = 1UL << bitPosition;

            // If the bit is already set, the character is a duplicate
            if (checkBitsA_z & mask) {
                return false;
            }
            // Otherwise, set the bit in the bit vector
            checkBitsA_z |= mask;
        } 
        
        // Handle lowercase letters 'a' to 'z'
        else if (nextChar >= 'a' && nextChar <= 'z') {
            int bitPosition = nextChar - 'a' + 26; // Offset for lowercase letters
            mask = 1UL << bitPosition;

            // If the bit is already set, the character is a duplicate
            if (checkBitsA_z & mask) {
                return false;
            }
            // Otherwise, set the bit in the bit vector
            checkBitsA_z |= mask;
        }

        // Handle characters between '!' (33) and '@' (64)
        else if (nextChar >= '!' && nextChar <= '@') {
            int bitPosition = nextChar - '!'; // Calculate bit position
            mask = 1UL << bitPosition;

            // If the bit is already set, the character is a duplicate
            if (checkBitsexcl_amp & mask) {
                return false;
            }
            // Otherwise, set the bit in the bit vector
            checkBitsexcl_amp |= mask;
        }
    }
}


  
