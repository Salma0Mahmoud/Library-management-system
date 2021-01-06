#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "takeaction.h"

void welcome( ) ;

int main()
{
    //To add users
    appendNode("ali"     , 1382 , 1) ; //First user
    appendNode("ahmed"   , 9430 , 2) ; //Second user
    appendNode("mohamed" , 5389 , 3) ; //Third user
    appendNode("youssef" , 4398 , 4) ; //Fourth user
    appendNode("mahmoud" , 8943 , 5) ; //Fifth user

    welcome( ) ;

}

//The start window for welcome
void welcome( ){
    printf("\n\n\n\n\t\t\t\t\t\tWelcome To\n") ;
    printf("\n\t\t\t\t\tLibrary management system\n") ;

    printf("\n\n\t\t\t\t\t>>Press any key to enter ^_^\n") ;
    getch( ) ;
    system("cls") ;
    start( ) ; //To go to start page
}
