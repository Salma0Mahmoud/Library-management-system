#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "takeaction.h"
#include "linked_list.h"

#define admin_pass 1234 //static admin password

//Array of the books
//In status : 1>>Available & 0>>NotAvailable
struct books B[8]={ {"one"   , "a" , 1 , 1 } ,
                    {"two"   , "b" , 2 , 0 , 1} ,
                    {"three" , "c" , 3 , 1 } ,
                    {"four"  , "d" , 4 , 0 , 2} ,
                    {"five"  , "e" , 5 , 1 } ,
                    {"six"   , "f" , 6 , 0 , 1} ,
                    {"seven" , "g" , 7 , 0 , 5} ,
                    {"eight" , "h" , 8 , 1 } } ;


int pass ; //To take the admin password

//Function to choose if you are an admin or user and log in
void start( ){
    int ch ; //To take the choice from the user

    printf("\n\n\n");
    printf("\t\t\t\tSelect if U are an admin or an user\n");
    printf("\t\t\t\t\t1-admin \t 2-user\n");
    printf("\t\t\t_______________________________________________________\n");
    printf("\t\t\t>> ");
    scanf("%d", &ch );

    //To check admin or user
    if ( ch == 1 ){
        check_admin_pass( ) ;
    }
    else if ( ch == 2 ){
        user_login( ) ;
    }
    else {
        printf("\n\t\t\t\t\tWrong entery!!");
        printf("\n\t\t\t\t____________________________");
        start( );
    }
}

//***** Admin Functions *****

//Admin's page if you choose (1- amdin)
void adminPage( ){
    system("cls");

    int ch ; //To take the choice from the admin

    printf("\n\n\t\t\t\tWelcome to the admin page ^_^\n");
    printf("\t\t\t________________________________________\n\n");
    printf("\t\t\t1 - Show users data.\n");
    printf("\t\t\t2 - Add new user.\n");
    printf("\t\t\t3 - Reserve a book.\n");
    printf("\t\t\t4 - Make a book available.\n");
    printf("\t\t\t5 - Get back.\n");
    printf("\n\t\t\tPlease, Choose : \n");
    printf("\t\t\t>> ");
    scanf("%d", &ch );

    //To check the choice of the admin and display the choice page
    switch ( ch ){
        case 1 :
            show_users( ) ;
            break ;
        case 2 :
            system("cls") ;
            add_user( ) ;
            break ;
        case 3 :
            reserve_Book( ) ;
            break ;
        case 4 :
            make_available( ) ;
            break ;
        case 5 :
            system("cls");
            start( ) ;
            break ;
        default :
            printf("\n\t\t\t>>WRONG ENTERY!!\n") ;
            backadmin( ) ;
            break ;
    } //End switch case
}

//Function to check the admin password
void check_admin_pass( ){
    printf("\n\t\t\t>>Enter your password : ");
    scanf("%d", &pass );

    if ( pass == admin_pass ){
        adminPage( );
    }
    else{
        printf("\n\n\t\t\t\t>>Wrong Password!! Try again.");
        printf("\n\t\t\t\t_______________________________\n");
        start( );
    }
}

//Function to get back to the admin page
void backadmin( ){
    puts("\n\t\t\tEnter any key to get back : \n\t\t");
    getch( );
    adminPage( );
}

//Function to show the users' data
void show_users( ){
    system("cls");
    printf("\n\n" );
    printNodes( );
    backadmin( );
}

//Function to add a new user
void add_user( ){

    user_t node ;
    inputNode( &node  ) ;
    appendNode( node.username , node.password , node.id ) ;
    backadmin( ) ;
}

//Function to make a reserved book available again
void make_available( ){
    system("cls");

    short ID ; //To take the book id from admin
    int i ;

    show_books( 0 ) ; //Show not available books

    printf("\n\t\t\tEnter book id you want to make available : ");
    scanf("%d", &ID ) ;

    //To check the book id and status
    for( i=0 ; i<8 ; i++ ){
        if ( ID == B[i].bookid ){
            if ( !(B[i].status) ){
                B[i].status = 1 ;
                printf("\n\n\t\t\t>>The process is successful.\n") ;
                break ;
            }
            else {
                printf("\n\n\t\t\t>>The book id is not correct.\n") ;
                break ;
            }
        } //End if
    } //End for loop

    backadmin( ) ;
}

//Function to show the books details
void show_books( int status ){
    int i ;

    printf("\n\n\t\t\tName    \t  | Author's Name   \t  | BookID" ) ;
    printf("\n\t\t\t___________________________________________________\n");

    for ( i=0 ; i<8 ; i++ ){
        if ( status == B[i].status ){
        printf("\t\t\t %s     \t  |  %s      \t\t  |  %d\n", B[i].bookname, B[i].authorname, B[i].bookid) ;
        }
    }

}

//Function to reserve a book to an user
void reserve_Book( ){
    system("cls");
    show_books( 1 ) ; //Show available books to be reserved

    int i , ID ;
    int count = 0 ;

    printf("\n\t\t\tEnter the book ID you want to reserve : ") ;
    scanf("%d", &ID ) ;

    //To check the book id , status and the user id
    for ( i=0 ; i<8 ; i++ ){
        if ( ID == B[i].bookid ){
            switch ( B[i].status ){
                case 0 :
                    printf("\n\t\t\t>>The book id is not correct.\n") ;
                    break ;
                case 1 :
                    if ( check_userID( ID ) ){
                        B[i].status = 0 ;
                        B[i].stdID = STDid ;
                        printf("\n\n\t\t\t>>The process is successful.\n") ;
                    }
                    else{
                        printf("\n\n\t\t\t>>The student ID is not available.\n") ;
                    }
                    break ;
            } //End switch case
        } //End if
        count++ ;
    } //End for loop

    backadmin( ) ;
}



//***** User Functions *****

//user's page if you choose (2- user)
void userpage( ){
    system("cls");

    int ch ; //To take the choice from the user

    printf("\n\n");
    printf("\t\t\t\tWelcome to your page ^_^\n");
    printf("\t\t\t________________________________________\n\n");
    printf("\t\t\t1 - Show my data.\n");
    printf("\t\t\t2 - Show the available books.\n");
    printf("\t\t\t3 - Show already borrowed books.\n");
    printf("\t\t\t4 - Get back.\n");
    printf("\n\t\t\t>>Please, Choose : \n");
    printf("\t\t\t>> ");
    scanf("%d", &ch );

    //To check the choice of the user and display the choice page
    switch ( ch ){
        case 1 :
            user_data( ) ;
            break ;
        case 2 :
            available_books( ) ;
            break ;
        case 3 :
            borrowed_books( ) ;
            break ;
        case 4 :
            system("cls") ;
            start( ) ;
            break ;
        default :
            printf("\n\t\t\t>>WRONG ENTERY!!\n") ;
            backuser( ) ;
            break ;
    }
}

//Function to get back to user's page
void backuser( ){
    puts("\n\t\t\tEnter any key to get back : \n\t\t");
    getch( );
    userpage( );
}

//Function to show the available books to borrow
void available_books( ){
    int i = 0 ;

    system("cls");

    printf("\n\n\t\t\tThe available books : \n") ;
    printf("\t\t\t_________________________\n\n") ;

    printf("\t\t\tBook ID    | Book Name\n") ;
    printf("\t\t\t_________________________\n\n") ;

    while ( i < 8 ){
        if ( B[i].status == 1 ){
            printf("\t\t\t %d     \t   | %s\n", B[i].bookid, B[i].bookname );
        }

        i++ ;
    }

    backuser( ) ;
}

//Function to show the books the user already borrowed
void borrowed_books( ){
    int i = 0 ;

    system("cls");

    printf("\n\t\t\tThe borrowed books : \n") ;
    printf("\t\t\t_________________________\n\n") ;
    printf("\t\t\tBook ID    | Book Name\n") ;
    printf("\t\t\t_________________________\n\n") ;

    while ( i < 8 ){
        if ( !(B[i].status) && (UserN.id == B[i].stdID) ){
            printf("\t\t\t %d     \t   | %s\n", B[i].bookid, B[i].bookname );
        }

        i++ ;
    }

    backuser( ) ;
}

//Function to show user's data
void user_data( ){
    system("cls");

    printf("\n\n\t\t\tUser's data : ") ;
    printf("\n\t\t\t________________\n") ;
    printf("\n\t\t\tUsername : %s",  UserN.username ) ;
    printf("\n\t\t\tPassword : %d", UserN.password ) ;
    printf("\n\t\t\tID : %d\n", UserN.id ) ;

    backuser( ) ;
}

//Function to enter as an user
void user_login( ){

    printf("\n\t\t\tEnter username : ") ;
    scanf("%s", &UserN.username ) ;

    printf("\n\t\t\tEnter password : ") ;
    scanf("%d", &UserN.password ) ;

    //To check username and password of the user
    if ( check_pass( UserN.password ) && check_username( UserN.username ) ){
        userpage( ) ;
    }
    else {
        printf("\n\t\t\tWrong username or password!!\n\t\t\tPlease Try again.\n") ;
        start( ) ;
    }
}
