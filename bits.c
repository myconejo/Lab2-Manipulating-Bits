/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *
 */

/*
 * getBit - Get bit p from word x
 *   Example: getBit(14, 2) = 1, getBit(26, 0) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int getBit(int x, int p){
    // 0x1 << p = makes a number that only has 1 in the bit_p.
    // & x makes only bit_p of x to remain, others being 0. 
    // >> p to shift the bit.
    // & 0x1 in case of arithmetic shift, such as 0xFFFFFFFF;
   return (((0x1 << p) & x) >> p) & 0x1;
   
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
	int a = 0xAA; // 0xAA = 0b10101010, having 1 in only odd bits
	a = a | (a << 8); // 0xAAAA
	a = a | (a << 16); // 0xAAAAAAAA
	return !!(a & x);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // when x == 0, ~(!x)+1 = 0xFFFFFFFF and 0xFFFFFFFF & z = z
    // also, !x + ~0 = 0x0 and y & 0x0 = 0. Result is z.
    // when x != 0, ~(!x) + 1 = 0x0 and 0x0 & z = 0
    // also, !x + ~0 = 0xFFFFFFFF and y & 0xFFFFFFFF = y. Result is y
  return (((~(!x) + 1) & z )|( y & (!x + ~0)));
}
/* 
 * bitEvenCount - return 1 if the number of 1's in word is even
 *   Examples: bitEvenCount(7) = 0, bitEvenCount(5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitEvenCount(int x){
   // if xor with bytes of x is 0, then total bit '1' is even
	int A1 = 0xff & (x >> 24);
	int A2 = 0xff & (x >> 16);
	int A3 = 0xff & (x >> 8);
	int A4 = 0xff & x;
	int y = A1 ^ A2 ^ A3 ^ A4; // 8 - bit value
	int B1 = 3 & (y >> 6);
	int B2 = 3 & (y >> 4);
	int B3 = 3 & (y >> 2);
	int B4 = 3 & y;
	int z = B1 ^ B2 ^ B3 ^ B4; // 2 - bit value
	int C1 = 1 & (z >> 1);
	int C2 = 1 & z;
	// if total bits are even, then C1^C2 = 0.
	return !(C1 ^ C2); 
}
/* 
 * patternMatching - return the number of found 4-bit pattern p in the given 16-bit number x.
 *   Examples: patternMatching(11, 11) = 1, patternMatching(245, 13) = 1,
 *             patternMatching(170, 15) = 0, patternMatching(23397, 11) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 75
 *   Rating: 4
 */
int patternMatching(short x, int p){
   // check every [i:i+4] bits of X
	int A = !((x & 0xf) ^ p);
	A += !(((x >> 1) & 0xf) ^ p);
	A += !(((x >> 2) & 0xf) ^ p);
	A += !(((x >> 3) & 0xf) ^ p);
	A += !(((x >> 4) & 0xf) ^ p);
	A += !(((x >> 5) & 0xf) ^ p);
	A += !(((x >> 6) & 0xf) ^ p);
	A += !(((x >> 7) & 0xf) ^ p);
	A += !(((x >> 8) & 0xf) ^ p);
	A += !(((x >> 9) & 0xf) ^ p);
	A += !(((x >> 10) & 0xf) ^ p);
	A += !(((x >> 11) & 0xf) ^ p);
	A += !(((x >> 12) & 0xf) ^ p);
	return A;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int negate(int x) {
    // -x = ~x + 1
  return ~x + 1;
}
/* 
 * lsbPos - return a mask that marks the position of the
 *          least significant 1 bit. If x == 0, return 0
 *   Example: lsbPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int lsbPos(int x) {
  return x & (~x + 1);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    // shits x's MSB to bit 1
    // if MSB = 1, then x >> 31 = 0xFFFFFFFF = -1
    // if MSB = 0, and x = 0, then returns 0|0 = 0
    // if x > 0, then returns 0|1 = 1
    return (x >> 31) | !!x;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	// CASE 1: if signx == signy, compare by subtraction with no risk of overflow
	// CASE 2: if signx != signy,
	// if signx = 1, signy = 0 then return 0 = signy
	// if signx = 0, signy = 1 then return 1 = signy
	int sx = (x >> 31) & 0x1;
	int sy = (y >> 31) & 0x1;
	int sames = sx ^ sy;
	int case1 = (!sames) & (!((x + ~y) >> 31));
	int case2 = (sames) & sy;
	return case1 | case2;
}
/*
 * multSevenEighths - multiplies by 7/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*7/8),
 *   including overflow behavior.
 *   Examples: multSevenEighths(77) = 67
 *             multSevenEighths(-22) = -19
 *             multSevenEighths(1634616344) = -180323435 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 3
 */
int multSevenEighths(int x) {
	int y = (x << 2) + (x << 1) + x; // y = x*7
	y = y + ((x >> 31) & 7); // if x is negative, add 7. 
	return y >> 3;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
   int a = !(((~x + 1) & x) + (~x + 1)); // does x only has one bit of 1?
   int b = !!x; // is x non-zero?
   int c = !(x >> 31); // is x positive?
   return a & b & c;
}
/* 
 * float_negate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_negate(unsigned uf) {
	int a = 0x7FFFFFFF & uf; // removing the sign bit for abs
	if (a > 0x7F800000) { // is uf NaN?
		return uf;
	}
	return 0x80000000 ^ uf; // 31st bit is converted
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	int a =  0x7FFFFFFF & uf;  // removing the sign bit for abs.
	if (a > 0x7F800000) { // is uf NaN?
		return uf;
	}
	return a;
}
/* 
 * float_to_int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_to_int(unsigned uf) {
	int exp = ((uf >> 23) & 0xff); // [30:23]
	int fracNor = (uf & 0x7fffff) | 0x800000; // 1:[22:0]

	// NaN and Infinity
	if (exp == 0xff) return 0x80000000u;

	// Denormalized
	if (!exp) return 0;

	// Normalized
	if (exp < 127) return 0; // E < 0
    if (exp > 157) return 0x80000000u; // E > 30, when it exceed the integer TMAX
	if (exp >= 150) {
		fracNor = fracNor << (exp - 150);
	}
	else {
		fracNor = fracNor >> (150 - exp);
	}
	if (uf >> 31) {
		fracNor = ~fracNor + 1; // consider the sign, please. 
	}
	return fracNor;
}
/* 
 * float_divideby2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_divideby2(unsigned uf) {
	int exp = ((uf >> 23) & 0xff); // [30:23]
	int frac = (uf & 0x7fffff); //[22:0]

	// NaN and Infinity
	if ((0x7FFFFFFF & uf) >= 0x7f800000) {
      return uf;
   }

	if (exp > 1) { // Norm to Norm
		exp -= 1;
	}
	if (exp == 0) { // DeNorm to Denorm
		if (frac & 0x2) { // frac & 0b0010
			frac = (frac + 1) >> 1;
		}
		else {
			frac = frac >> 1;
		}
		//printf("%X\n", frac);
	}
	if (exp == 1) { // from Norm to DeNorm
		exp = 0;
		frac = 0x800000 | frac;
		// mind the rounding rules!
		if (frac & 0x2) { // frac & 0b0010
			frac = (frac + 1) >> 1;
		}
		else {
			frac = frac >> 1;
		}
		//printf("%X\n", frac);
	}
	//printf("%X\n", frac);
	return ((uf & 0x80000000) | (exp << 23) | frac);
}
