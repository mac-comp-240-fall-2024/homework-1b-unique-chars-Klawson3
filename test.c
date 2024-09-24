/* Keaton Lawson
 * This file contains tests for the `hasUniqueChars` function, which checks if a string contains all unique characters except for spaces.
 * The test cases will ensure proper functionality of the function, including cases where the function should return `true`, `false`, 
 * and where it should fail due to invalid characters.
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>
#include "binary_convert.h"

// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // TODO: add your tests here
  // Test 3: test string with space being the only repeat, should return true
  strcpy(string3, "a b c d e f g h");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true

  // Test 4: another case with unique characters including numbers
  strcpy(string3, "1234567890");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true

  // Test 5: a string with repeated characters (should return false)
  strcpy(string3, "unique characters repeated");
  ok = hasUniqueChars(string3);
  assert(!(ok));  // Expecting false

  // Test 6: string with special characters (should return true)
  strcpy(string3, "!@#$%^&*()");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true

  // Test 7: test a string with repeated special characters (should return false)
  strcpy(string3, "!@#$%^&*()@");
  ok = hasUniqueChars(string3);
  assert(!(ok));  // Expecting false

  // Test 8: empty string (should return true)
  strcpy(string3, "");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true

  // Test 9: very short string with repeated characters (should return false)
  strcpy(string3, "aa");
  ok = hasUniqueChars(string3);
  assert(!(ok));  // Expecting false

  // Test 10: very short string with unique characters (should return true)
  strcpy(string3, "a!");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true

  // Test 11: test string with all printable characters (should return true)
  strcpy(string3, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+[]{}|;:',.<>?/`~ ");
  ok = hasUniqueChars(string3);
  assert(ok);  // Expecting true



  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}