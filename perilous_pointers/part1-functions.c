https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * perilous_pointers
 * CS 241 - Spring 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Checks to see if the input parameter is a passing grade and prints out
 * if the grade is passing using the provided format specifiers. Note that
 * 'grade' is a char pointer pointing to the beginning of a C string. A grade
 * is considered passing iff the numeric interpretation (defined by strtof) is
 * above a 70. Suppose that 'grade' pointed to the string "73.58", then 'grade'
 * would be passing in this example. If 'grade' pointed to "it's over 9000!!!!",
 * then that is still
 * not a passing grade.
 *
 * @param grade
 *     The grade to check.
 */
void one(const char *grade) {
    //convert string to float
    float numeric_grade = strtof(grade, NULL); 
    if (numeric_grade > 70)
        printf("%f passed!\n", numeric_grade);
    else
        printf("%s not passed!\n", grade);
}

/**
 * Have the integer pointer p point to the integer x which is on the stack.
 * Then print the value that 'p' points to and format it as an integer
 */
void two() {
    int x = 4;
    //p stores the address of x
    int *p = &x;
    printf("The value of p is: %d\n", *p);
}

/**
 * Prints "x and y are equal." iff the values x and y point to are equal
 * where equality is defined by integer equality.
 * Else print "x and y are different".
 *
 * @param x
 *     First input parameter.
 *
 * @param y
 *     Second input parameter.
 */
void three(const int *x, const int *y) {
    //compare the int stored at the address
    if (*x == *y)
        printf("x and y are equal.\n");
    else
        printf("x and y are different.\n");
}

/**
 * Returns a pointer to a float that points to memory on the heap,
 * which contains a copy of the value that the integer pointer 'x' is pointing
 * to.
 *
 * @param x
 *     Input parameter, whose value will be returned as a (float *).
 *
 * @returns
 *     A new pointer, allocated on the heap and not freed, that
 *     contains the value of the input parameter.
 */
float *four(const int *x) {
    //store the copy of value of x on the heap
    float *p = malloc(sizeof(float));
    *p = *x;
    printf("%d == %f\n", *x, *p);
    return p;
}

/**
 * Takes a char pointer 'a' and checks to see if the first char
 * that it points to is alphabetic (upper or lower case).
 *
 * @param a
 *     Input parameter a, which is a char*
 *
 */
void five(const char *a) {
    if (isalpha(a[0]))
        //the first char is a letter
        printf("a is a letter.\n");
    else
        printf("a is not a letter.\n");
}

/**
 * Concatenates "Hello " and the parameter str, which is guaranteed to be a
 * valid c string, and prints the concatenated string.
 */
void six(const char *str) {
    char *s = "Hello ";
    //the pointer to the destination array 
    char *combine_str = malloc(sizeof(s) + sizeof(str) + 1);
    strcpy(combine_str, s);
    strcat(combine_str, str);
    printf("%s\n", combine_str);
    free(combine_str);
}

/**
 * Creates an array of values containing the values {0.0, 0.1, ..., 0.9}.
 */
void seven() {

    int i, n = 10;

    float *values = malloc(sizeof(float) * (n + 1));

    for (i = 0; i < n; i++)
        values[i] = (float)i / n;
    values[i] = '\0';

    for (i = 0; i < n; i++)
        printf("%f ", values[i]);
    printf("\n");
    free(values);
    values = NULL;
}

/**
 * Creates a 2D array of values and prints out the values on the diagonal.
 */
void eight(int a) {
    int **values;

    int i, j;
    values = malloc(11 * sizeof(int *));
    for (i = 0; i < 10; i++) {
        values[i] = malloc(11 * sizeof(int));
        for (j = 0; j < 10; j++)
            values[i][j] = i * j * a;
        values[i][j] = '\0';
    }
    values[i] = NULL;

    for (i = 0; i < 10; i++)
        printf("%d ", values[i][i]);
    printf("\n");

    for (i = 0; i < 10; i++) {
        free(values[i]);
        values[i] = NULL;
    }
    free(values);
    values = NULL;
}

/**
 * If s points to the string "blue", then print "Orange and BLUE!". If s points
 * to the string "orange", then print "ORANGE and blue!" else just print "orange
 * and blue!".
 * Use strcmp() and friends to test for string equality.
 *
 * @param s
 *     Input parameter, used to determine which string is printed.
 */
void nine(const char *s) {
    int flag = 0;
    if (strcmp(s, "blue") == 0) {
        flag = 1;
    } else if (strcmp(s, "orange") == 0) {
        flag = 2;
    }
    switch (flag) {
    case 1:
        printf("Orange and BLUE!\n");
        break;

    case 2:
        printf("ORANGE and blue!\n");
        break;

    default:
        printf("orange and blue!\n");
        break;
    }
}

/**
 * Prints out the radius of a circle, given its diameter.
 *
 * @param d
 *     The diameter of the circle.
 */
void ten(const int d) {
    printf("The radius of the circle is: %f.\n", (float)d / 2);
}

/**
 * @brief
 *     Clears the bits in "value" that are set in "flag" and prints the result.
 *
 * This function will apply the following rules to the number stored
 * in the input parameter "value":
 * (1): If a specific bit is set in BOTH "value" and "flag", that
 *      bit is NOT SET in the result.
 * (2): If a specific bit is set ONLY in "value", that bit IS SET
 *      in the result.
 * (3): All other bits are NOT SET in the result.
 *
 * Examples:
 *    clear_bits(value = 0xFF, flag = 0x55): 0xAA
 *    clear_bits(value = 0x00, flag = 0xF0): 0x00
 *    clear_bits(value = 0xAB, flag = 0x00): 0xAB
 *
 * @param value
 *     The numeric value to manipulate.
 *
 * @param flag
 *     The flag (or mask) used in order to clear bits from "value".
 */
void clear_bits(long int value, long int flag) {
    // TODO clear_bits
    long int cleared_value = (value ^ flag) & value;
    printf("cleared_value: %ld\n", cleared_value);
}

/**
 * @brief
 *     A little finite automaton in C.
 *
 * This function will use a provided transition function to simulate a DFA over
 * an input string. The function prints the final state.
 *
 * The DFA starts in state 0. For each character in input_string, call the
 * transition function with the current state and the current character. The
 * current state changes to the state the transition function returns.
 *
 * So, in pseudo code:
 *
 * state = 0
 * for character in input_string:
 *     state = transition_function(state, character)
 *
 * NOTE: the transition_function parameter is a "function pointer." For more
 * information about these fun creatures, see this:
 * http://www.cprogramming.com/tutorial/function-pointers.html
 *
 * @param transition - function pointer to a transition function to use
 * @param input_string - string to run the automaton over
 *
 */
void little_automaton(int (*transition)(int, char), const char *input_string) {
    int state = 0;
    size_t len = strlen(input_string);
    size_t i = 0;
    for (i = 0; i < len; i++) {
        state = transition(state, input_string[i]);
    }
    // put something here
    printf("final state: %d\n", state);
}
