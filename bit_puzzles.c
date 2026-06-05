/* * Solution for CS:APP Exercise 2.58
 * @brief Checks the endianness of the host machine
 * This function determines if the underlying hardware uses Little Endian
 * or Big Endian byte ordering by inspecting the first byte of an integer.
 * @return 1 if the machine is Little Endian, 0 if it is Big Endian.
 */
int is_little_endian() {
    //Let's take an arbitrary value, much easy to manipulate and represent in memory such as 1
    /* In Big Endian machine , x will be represent such as : 00 00 00 01
     * In little endian machine , x will be represent such as : 01 00 00 00
    */

    int x = 1;
    // Let's point to the first byte of x
    unsigned char *start = (unsigned char *)&x;
    
    return *start;
}

/* *Solution for CS:APP Exercise 2.59
 * @brief Merge different part of variable x and y
 * Function : merge_x_y
 * @return the value a word consisting of the LSB of x and the other byte of y
 */

int merge_x_y(int x, int y){
    //Get the LSB of x
    x = x & 0xFF;
    //Set the LSB of y to 0
    y = y & ~0xFF;
    
    //We could've alse use x + y
    return x | y;
}

/* *Solution for CS:APP Exercise 2.60
 * @brief Replace byte of x by b. Starting to count the LSB to be the index 0
 * Function : replace_byte
 * @return the value of x replace by some byte of b
 */
unsigned replace_byte (unsigned x, int i, unsigned char b){
    int c;
    x = x & ~( 0xFF << ( 8 * i ) ); //initialise the i byte of x to 0
    c = b << (8 * i);//shifting the i byte of x to the i position
    return x | c; // combine all
}

/* Solution for CS:APP Exercice 2.61-A
 * @brief Examine bits of x
 * @return 1 if any bit of x equals to 1 and 0 if not. Using restrictions
 */
int bit_of_x_1(int x){
    int logical_inverse_value_of_x = !x;
    return !(logical_inverse_value_of_x);
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
   //Get the LSB of x
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

/* * Solution for CS:APP Exercise 2.62
 * @brief Determine if the machine use arithmetic right shifts for int’s.
 * @return 1 if the machine uses arithmetic right shifts, 0 if not.
 */
int int_shifts_are_arithmetic(){
    //Let's take x = -1 which is 111111111111...111 in binary using two complement
    int x = -1;
    
    //Then we shift x to get rid of all the actual bit. Then we test if the new value of x has any 0 using the precedding logic of functions any_bit_of_x_0(int)
    x = x >> ( (sizeof(int) << 3) - 1 );
    return !(~x);
}

/* *Solution for CS:APP Exercise 2.63
 * @brief Perform a logical shift using an arithmetical shift result
 * return the value of the logical shift performed
 */
unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    int y = -1 // y = 0b1111...11111
    int xshift = (sizeof(int) << 3) - 1 - k;
    y = y << xshift;

    return (unsigned) xsra & ~y;

}

int sra(int x, int k) {
    /* Perform shift logically */ 
    int xsrl = (unsigned) x >> k;
    int size = sizeof(int) << 3;
    int y = xsrl << k;

    int signBit = y & (1 << (size-1)); //Get the sign bit
    signBit = (~( !(!signBit) ) + 1) & (~0 << 1); //Extend the bit sign
    int mask = (~ !(!k) + 1) & ( signBit << (size-k) << 1 ); //Preparing the case where k = 0

    return xsrl | mask;
}

/* *Solution for CS:APP Exercice 2.64
 * @brief Check if any off bit of x is 1
 * return 1 if any odd bit of x is 1, and 0 if not
 */
int any_odd_one(unsigned x){
    //Assuming that sizeof(int)<<3 = 32
    //Without knowing the value of the type int , we could've mask with the value 2**0 + 2**2 + ... + 2**30 = (2**32 - 1)/3
    int mask = 0xAAAAAAAA;

    return !!(x & mask);
}
