#include "mbed.h"
#include "math.h"
#define espera   10ms


BusOut columnas(D2,D3,D4,D5,D6,D7,D8,D9);
BusOut filas(D10,D11,D12,D13,D14,D15,A0,A1);
DigitalIn botton1(A2);
DigitalIn botton2(A3);

void led(int fila, int columna){
    columnas = 0b00000000 + pow(2,columna-1);
    filas =    0b11111111 - pow(2,fila-1);
    
}

int main()
{   int j=1;
    int i=1;

    int actual1=0;
    int actual2=0;
    int anterior1=0;
    int anterior2=0;
    while (true) {
        actual1 = botton1;
        if(!actual1 && anterior1){
            if(j == 8){
                if(i==8){
                    i = 1;
                }
                else{
                    i++;
                }
                j = 1;
            }
            else{
                j++;
            }
        }
        anterior1 = actual1;

        actual2 = botton2;
        if(!actual2 && anterior2){
            if(j == 1){
                if(i == 1){
                    i = 8;
                }
                else{
                    i--;
                }
                j = 8;
            }
            else{
                j--;
            }
        }
        anterior2 = actual2;

        led(i,j);

        ThisThread::sleep_for(espera);
        
      }
}

