#include "CPU.h"

CPU::CPU()
{
    //ctor
}

CPU::~CPU()
{
    //dtor
}
u8 CPU::fetch(u16 address){
    return this->mem[address];
}
u16 CPU::concatenate(u8 first, u8 second){
   u16 result = (unsigned short)first << 8 + (unsigned short)second;
   return result;
}
void CPU::run(u16 address){
    u8 instruction = this->fetch(address);
    u8 b1,b2,a1;
    u16 indexed;
    switch (instruction){
    //ADD Instructions;
        case 0x69: // Immediate ADC #Arg
            b1 = this->fetch(address + 1);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A == 0;
            pc += 2;
        break;

        case 0x65:// Zero Page ADC Arg
            b1 = this->fetch(address + 1);
            b1 = this->fetch((unsigned short) b1);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A == 0;
            pc += 2;
        break;

        case 0x75:// Zero Page Arg, X
            b1 = this->fetch(address+1);
            indexed = (unsigned short)b1 + (unsigned short)X;
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A ==0;
            pc += 2;
        break;

        case 0x6D:
            b1 = this->fetch(address+1);
            b2 = this->fetch(address+2);
            indexed = concatenate(b1,b2);
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A ==0;
            pc += 3;

        break;

        case 0x7D:
            b1 = this->fetch(address+1);
            b2 = this->fetch(address+2);
            indexed = concatenate(b1,b2);
            indexed += X;
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A == 0;
            pc += 3;
        break;

        case 0x79:
            b1 = this->fetch(address+1);
            b2 = this->fetch(address+2);
            indexed = concatenate(b1,b2);
            indexed += Y;
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 =A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A == 0;
            pc += 3;
        break;


        case 0x61:
            b1 = this->fetch(address+1);
            indexed = (unsigned short) b1 + (unsigned short) X;
            b1 = this->fetch(indexed+1);
            b2 = this->fetch(indexed);
            indexed = concatenate(b1,b2);
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 =A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z = A == 0;
            pc += 2;
        break;

        case 0x71:
            b1 = this->fetch(address+2);
            b2 = this->fetch(address+1);
            indexed = concatenate(b1,b2);
            indexed += Y;
            b1 = this->fetch(indexed);
            b2 = b1;
            a1 = A;
            A = A+b1+C;
            C = this->carry(a1,b2);
            V = this->overflow(a1,b2);
            N = this->negative(A);
            Z= A==0;
            pc+=2;
        break;

        //ADC instructions.

    }
}
