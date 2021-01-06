#ifndef LINKED_LIST.H
#define LINKED_LIST.H

typedef struct user
{
    char username[50] ;
    int password ;
    int bookID ;
    short id ;

    struct user *next ;

} user_t ;

//Global variable
short STDid ;
user_t UserN ;

void appendNode( char* username , int password , short id ) ;

void printNodes( ) ;

user_t* inputNode( user_t* node ) ;

void printNode( user_t* node ) ;

int check_username( char username[50] ) ;

int check_pass( int pss ) ;

int check_id( short id ) ;

int check_userID( short bookid ) ;

#endif // LINKED_LIST
