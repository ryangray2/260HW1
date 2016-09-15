/*
 * q4.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Ryan Gray
 */
#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

std::bitset<32> aBin;
std::bitset<16> bBin;
std::bitset<32> cBin;

int main () {

	int a, b, c;
	printf("Enter an integer:\n");
	scanf("%d", &a);
	printf("Enter an integer:\n");
	scanf("%d", &b);
	c = 0; // product initialized as 0.

	aBin = a; // putting integer a in binary form
	bBin = b; // putting integer b in binary form
	cBin = c; // putting integer c in binary form

	int bminus = 0; // initializes B0 as 0

	for (int i = 16; i > 0; i--) {
		int bzero = bBin[0]; // initializes B-1 as the first bit in B

		if (bzero == bminus) { // if 11 or 00
			int result = 0;    // lines 35-57 convert the binary aBin to the integer a
			if (aBin[31] == 0) {
				for (int i = 0; i < 32; i++) {
					if (aBin[i] == 1) {
						result += pow(2, i);
					} else {
						result += 0;
					}
				}
			} else {
				for (int i = 0; i < 32; i++) {
					if (i != 31) {
						if (aBin[i] == 1) {
							result += pow(2, i);
						} else {
							result += 0;
						}
					} else {
						result = result - pow(2, i);
					}
				}
			}
			a = result;
			bminus = bzero; // sets B-1 equal to B0 for next iteration
			aBin = (aBin<<1); // shifts A
			bBin = (bBin>>1); // shifts B
		}
		else if (bzero == 1 && bminus == 0) { // if 10
			int result = 0;   // lines 63-85 convert the binary aBin to the integer a
			if (aBin[31] == 0) {
				for (int i = 0; i < 32; i++) {
					if (aBin[i] == 1) {
						result += pow(2, i);
					} else {
						result += 0;
					}
				}
			} else {
				for (int i = 0; i < 32; i++) {
					if (i != 31) {
						if (aBin[i] == 1) {
							result += pow(2, i);
						} else {
							result += 0;
						}
					} else {
						result = result - pow(2, i);
					}
				}
			}
			a = result;
			bminus = bzero; // sets B-1 equal to B0 for next iteration
			c = c - a; // C subtracted by A
			cBin = c; // C put back into binary
			aBin = (aBin<<1); // shifts A
			bBin = (bBin>>1); // shifts B
		}
		else if (bzero == 0 && bminus == 1) { // if 01
			int result = 0;  // lines 93-115 convert the binary aBin to the integer a
			if (aBin[31] == 0) {
				for (int i = 0; i < 32; i++) {
					if (aBin[i] == 1) {
						result += pow(2, i);
					} else {
						result += 0;
					}
				}
			} else {
				for (int i = 0; i < 32; i++) {
					if (i != 31) {
						if (aBin[i] == 1) {
							result += pow(2, i);
						} else {
							result += 0;
						}
					} else {
						result = result - pow(2, i);
					}
				}
			}
			a = result;
			bminus = bzero; // sets B-1 equal to B0 for next iteration
			c = c + a; // C added to A
			cBin = c; // C put back in binary
			aBin = (aBin<<1); // shifts A
			bBin = (bBin>>1); // shifts B
		}
	}

	printf("the product = %d\n", c);
	cout << "the product in binary form = " << cBin;
}





