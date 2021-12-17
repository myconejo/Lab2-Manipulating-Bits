/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
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
