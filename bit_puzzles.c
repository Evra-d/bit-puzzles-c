/* * Solution for CS:APP Exercise 2.58
 * @brief Checks the endianness of the host machine
 * This function determines if the underlying hardware uses Little Endian
 * or Big Endian byte ordering by inspecting the first byte of an integer.
 * @return 1 if the machine is Little Endian, 0 if it is Big Endian.
 */
int is_little_endian() {
    //Let's take an arbitrary value, much easy to manipulate and represent in memory such as 1
    int x = 1;
    /*Let's admit that the size of int is 4 here, 
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

/* *Solution for CS:APP Exercise 2.58
 * @brief Merge different part of variable x and y
 * Function : merge_x_y
 * @return the value a word consisting of the LSB of x and the other byte of y
 */

int merge_x_y(int x, int y){
    //Using bit mask operations in order to extract the LSB of x
    x = x & 0xFF;
    //Using ~0xFF for setting all bits to 1 except the last bytes put on 0. This help to put the LSB to 0 so that it will be easy to add the new value of x
    y = y & ~0xFF;

    return x + y;
}
