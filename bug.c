// a program with a bug
// this program was made to experiment with gnu debugger
#include <stdio.h>

int bugfunc( int value )
{
    int a[5] ;
    for( int i=0; i<=5; i++ ){
        a[i] = i * value ;
    }
    return a[5] ;
}

int main( void )
{
    int result = bugfunc(10) ;
    printf( "The result is: %d\n", result ) ;
    return 0 ;
}


