#ifndef CPU_H
#define CPU_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef bool bit;
class CPU
{
    public:
        CPU();
        virtual ~CPU();

    protected:

    private:
        void run (u16);
        u8 fetch(u16);
        bit overflow(u8,u8);
        // Register declarations
        u16 pc;
        u8 A,X,Y,S;
        bit N,Z,C,I,D,V;
        // Memoria
        u8 mem[65536];
        u16 concatenate(u8,u8);




};

#endif // CPU_H
