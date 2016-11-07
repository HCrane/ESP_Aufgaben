//------------------------------------------------------------------------------
// hw5.c
//
// Bitoperations
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//------------------------------------------------------------------------------
#include <stdio.h>
#include "input.c"

int main()
{
 ip_address_1 <<= suffix;   //000000D
 ip_address_1 >>= suffix;

 ip_address_2 >>= 32 - suffix;       //ABC00000
 ip_address_2 <<= 32 - suffix;

 int new_ip = (ip_address_1 | ip_address_2);

 int A = 0xFF000000;
 int B = 0x00FF0000;
 int C = 0x0000FF00;
 int D = 0x000000FF;

 A = (A & new_ip) >> 24;
 B = (B & new_ip) >> 16;
 C = (C & new_ip) >> 8;
 D = (D & new_ip);

 printf("New IP address: %d.%d.%d.%d/%d\n",A,B,C,D,suffix);
 return 0;
}
