/* Test Tuner's IO to Sev Segment Display */

#include <stdio.h>
#include <stdlib.h>
#include <machine/patmos.h>
#include <machine/spm.h>

#define DISP_SYM_MASK 0x80
#define YES 0x666662e5
#define NO  0x66666630
#define SURE 0x6666597e
#define ITISSO 0x14155066
#define INDEED 0x6613deed
#define NAY 0x666663a2
#define ITISTRUE 0x1415479e
#define SOBEIT 0x50be1466
#define NOSIR 0x66306517

#define GOOD 0xf0f0
#define BAD 0xf0f

#define LFSR_ADDR 0xf00b0000
#define TEXTDISP_ADDR 0xf0050000

void printSegmentInt(unsigned base_addr, int number, int displayCount)__attribute__((noinline));

void resetDisp(unsigned disp_addr, int from, int to){
	volatile _IODEV unsigned *disp_ptr = (volatile _IODEV unsigned *) disp_addr;
	unsigned pos = 0;
	for(pos=from; pos < to; pos++){
		*disp_ptr = DISP_SYM_MASK | 0x7F;
		disp_ptr++;
	}
}

void printSegmentInt(unsigned base_addr, int number, int displayCount) {
	volatile _IODEV unsigned *disp_ptr = (volatile _IODEV unsigned *) base_addr;
	unsigned pos = 0;
	unsigned byte_mask = 0x0000000F;
	unsigned range = (number > 0) ? displayCount : displayCount-1;	//reserve one digit for '-' symbol
	unsigned value = abs(number);
	for(pos=0; pos < range; pos++) {
		*disp_ptr = (unsigned)((value & byte_mask) >> (pos*4));
		byte_mask = byte_mask << 4;
		disp_ptr += 1;
	}
	if (number < 0) {
		*disp_ptr = DISP_SYM_MASK | 0x3F;
	}
}

void setLeds(int status) {
    #define LED (*(( volatile _IODEV unsigned * ) 0xf0090000 ))
    LED = status;
    return;
}

/* 
 * Fun magic 8 ball program that utilizes LFSR instead of using rand() in 
 * order to determine responses to questions
 * author: Lauren Kosub s186193
 */
int main(int argc, char **argv)
{
	volatile _IODEV int *uart_ptr = (volatile _IODEV int *)	PATMOS_IO_UART;
	volatile _IODEV int *led_ptr  = (volatile _IODEV int *) PATMOS_IO_LED;
	volatile _IODEV int *disp_ptr = (volatile _IODEV int *)	TEXTDISP_ADDR;
	volatile _IODEV int *lfsr_ptr = (volatile _IODEV int *)	LFSR_ADDR;

    int x, n, on;
    char resp = 'Y';

    x = 1718139409;  
	resetDisp(0xf0050000, 0, 8);
	printSegmentInt(0xf0050000, x, 8);

    // intro!
    printf("Welcome to Magic 8 Ball! Ask a yes or no Question: ");
    while (resp =='Y') {
        
        char line[1024];
        gets(line); // insecure hehe shouldn't use this but oh well
        
        printf("Thinking of response ...\n");

        // gen random number with lfsr
        n = *lfsr_ptr % 9;
        //printf("rand #: %d\n", n);

        switch(n) {
            case 0: x = YES; 
                    on = GOOD;
                    break;
            case 1: x = NO; 
                    on = BAD;
                    break;
            case 2: x = NOSIR; 
                    on = BAD;
                    break;
            case 3: x = ITISSO; 
                    on = GOOD;
                    break;
            case 4: x = INDEED; 
                    on = GOOD;
                    break;
            case 5: x = NAY; 
                    on = BAD;
                    break;
            case 6: x = ITISTRUE; 
                    on = GOOD;
                    break;
            case 7: x = SOBEIT; 
                    on = GOOD;
                    break;
            case 8: x = SURE;
                    on = GOOD;
                    break;
        }

        *led_ptr = on;

        resetDisp(0xf0050000, 0, 8);
        printSegmentInt(0xf0050000, x, 8);

        printf("Do you want to ask another question? Resond Y/N: ");
        resp = getchar();
    
         if (resp != EOF && (resp == 'Y' || resp == 'y')) {
            printf("What is your next question?: ");
            gets(line);
        }
    }

    printf("Thanks for playing! Goodbye!\n");
    return 0;
}   
