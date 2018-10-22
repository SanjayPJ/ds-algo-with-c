#include <stdio.h>

int main(void){
    enum month {
        Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };
    typedef enum month month;
    month birth_month = Apr;
    if (birth_month == Apr){
        printf("YOU BORN IN APRIL BOY!!!!\n");
    }
    return 0;
}