#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "model.h"



user a;


#include "tool.h"
#include "orderService.h"
#include "productService.h"
#include "userService.h"

int main()
{
    int c=2;
    while(c!=-1){
        c=mainMenu();
        switch(c){
            case 0:registe();
            case 1:a=login();
                    enterSystem(a.role,a.userId);
                    break;
            case -1:exit(1);
        }
   }

    return 0;
}
