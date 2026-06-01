/* * Solution for CS:APP Exercise 2.58
 * Function: is_little_endian
 */
int is_little_endian() {
    //Let's take an arbitrary value, much easy to manipulate and represent in memory such as 1
    int x = 1;
    /*Let's take 4 the size of an int, 
     * In Big Endian machine , x will be represent such as : 00 00 00 01
     * In little endian machine , x will be represent such as : 01 00 00 00
    */

    /* So let's convert start be a pointer to the first byte of x in memory
     * so that it will read one byte instead of 4 in a row like a pointer to an int at the moment of dereferencing
    */
    unsigned char *start = (unsigned char *)&x;
    
    /* Then, by the preceding demonstration of representations, if the first byte which is represent by start here 
     * equals to 1 , then we are in a little endian machine so it return 1. 
     * If not , we are in a Big endian one, then it return 0.
     *
     * And the & operator in order to promote the char to an int
    */
    return *start & ~0;
}
