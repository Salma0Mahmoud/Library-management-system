#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "takeaction.h"

user_t* head = NULL ;
user_t* tail = NULL ;

//Function to add a node
void appendNode( char* username , int password , short id ){
    user_t* node = ( user_t* ) malloc( sizeof(user_t) ) ;
    node->next = NULL ;

    strcpy( node->username , username ) ;
    node->password = password ;
    node->id = id ;

    if ( head == NULL ){
        head = node ;
        tail = node ;
    }
    else {
        tail->next = node ;
        tail = node ;
    }
}

//Function to print nodes (Users' data)
void printNodes( ){
    user_t* node = '\0' ;

    printf("\t\t\tUsername   \t  | Password   \t  | ID" ) ;
    printf("\n\t\t\t____________________________________________________________\n");


    for ( node=head ; node!=NULL ; node=node->next ){
        printf("\t\t\t %s     \t  | %d    \t  | %d\n", node->username, node->password, node->id ) ;
    }

}

//Function to input new user
user_t* inputNode( user_t* node ){

    printf("\n\t\t\tEnter username : ");
    scanf("%s", &(node->username) ) ;
    if ( check_username( &(node->username) ) == 1 ){
        printf("\n\t\t\tThis username is already taken, Please Choose another one.\n\n") ;
        add_user( ) ;
    }
    printf("\n\t\t\tEnter password : ");
    scanf("%d", &(node->password) ) ;
    printf("\n\t\t\tEnter ID : ");
    scanf("%d", &(node->id) ) ;

    return node ;
}

//Function to print the data of a particular user
void printNode( user_t* node ){
            printf("\n\t\t\tUsername : %s\n", node->username ) ;
            printf("\t\t\tPassword : %d\n", node->password ) ;
            printf("\t\t\tID : %d \n\n", node->id ) ;
}

//Function to check username and compare it with the other uasenames
int check_username( char username[50] ){
    user_t* node = '\0' ;

    for ( node=head ; node!=NULL ; node=node->next ){
        if ( strcmp( username , node->username ) == 0 ){
            UserN.id = node->id ;
            return 1 ;
        }
    }

    return 0 ;
}

//Function to check a particular password
int check_pass( int pss ){
    user_t* node = '\0' ;

    for ( node=head ; node!=NULL ; node=node->next ){
        if ( pss == node->password ){
            return 1 ;
        }
    }

    return 0 ;
}

//Function to check the user ID
int check_id( short id ){
    user_t* node = '\0' ;

    for ( node=head ; node!=NULL ; node=node->next ){
        if ( id == node->id ){
            return 1 ;
        }
    }

    return 0 ;
}

//Function to check the user id for make reservation
int check_userID( short bookid ){
    user_t* node = '\0' ;

    printf("\n\t\t\tEnter the student ID you want to reserve book to : ") ;
    scanf("%d", &STDid ) ;

    for ( node=head ; node!=NULL ; node=node->next ){
        if ( STDid == node->id ){
            node->bookID = bookid ;
            STDid = node->id ;
            return 1 ;
        }
    }

    return 0 ;

}
