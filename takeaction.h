#ifndef TAKEACTION.H
#define TAKEACTION.H

typedef struct books
{
    char bookname[50] ;
    char authorname[50] ;
    int bookid ;
    int status ;
    short stdID ;

    struct books* nextB ;

} books_t ;

void start( ) ;

void adminPage( ) ;

void check_admin_pass( ) ;

void backadmin( ) ;

void show_users( ) ;

void add_user( ) ;

void make_available( ) ;

void show_books( ) ;

void reserve_Book( ) ;

void userpage( ) ;

void backuser( ) ;

void available_books( ) ;

void borrowed_books( ) ;

void user_data( ) ;

void user_login( ) ;

#endif // TAKEACTION
