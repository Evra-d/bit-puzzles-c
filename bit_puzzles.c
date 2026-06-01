/* * Solution for CS:APP Exercise 2.58
 * @brief Checks the endianness of the host machine
 * This function determines if the underlying hardware uses Little Endian
 * or Big Endian byte ordering by inspecting the first byte of an integer.
 * @return 1 if the machine is Little Endian, 0 if it is Big Endian.
 */
int is_little_endian() {
    //Let's take an arbitrary value, much easy to manipulate and represent in memory such as 1
    int x = 1;
    /*We only need to inspect the first byte of the integer. 
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
    */
    return *start;
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
    
    //We could've alse use x + y
    return x | y;
}

/* Solution for CS:APP Exercice 2.61-A
 * @brief Examine bits of x
 * @return 1 if any bit of x equals to 1 and 0 if not. Using restrictions
 */
int bit_of_x_1(int x){
    //I will the NOT operator ! which convert any value to its logical inverse. if x = 0 then x is false, !x = 1 then it is true, and !(!x) = !(1) = 0.
    //if x != 0 then x is true and !x is false so !x = 0, !(!x) = !(0) = 1 
    return !(!x);
}

/* Solution for CS:APP Exercice 2.61-B
 * @brief Examine bits of x
 * @return 1 if any bit of x equals to 0 and 0 if not. Using restrictions
 */
int any_bit_of_x_0(int x){
    /* if x = ~0 (no bit equal 0), !(!(~x))=!(!(0))=!(1)=0
     * if x != 0 or x = 0 (some bits of x equal 0), ~x also have some bits to 1, !(!(~x)) = !(!1) = !(0) = 1
     */

    return !(!(~x));
}

/* Solution for CS:APP Exercice 2.61-C
 * @brief Examine bits of LSB of x
 * @return 1 if any bit of the LSB bits of x equals to 1 and 0 if not. Using restrictions
 */
int LSB_bit_of_x_1(int x){
   //In order to isolate the LSB we will use bit mask operation to the value of x then apply the function bit_of_x_1(int)
   x = x & 0xFF;
   return !(!x);
}

/* Solution for CS:APP Exercice 2.61-D
 * @brief Examine bits MSB of x
 * @return 1 if any bit of MSB of x equals to 0 and 0 if not. Using restrictions
 */
int MSB_bit_of_x_0(int x){
    //Extracting the MSB by right shifting
    //And & 0xFF for avoiding the case where right shifting is donne arithmetically and the bit sign is 1
    x = ( x >> ((sizeof(int) << 3) - 8) ) & 0xFF;
    return !(!(~x));
}
