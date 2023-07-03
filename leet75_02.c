#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * gcdOfStrings( char * str1, char * str2 )
{
    // intit pointer for output
    static char *out ;
    char ** substrings ;
    // allocate a single char for null char
    out = malloc( sizeof( char ) ) ; 
    substrings = malloc( sizeof( uintptr_t )) ;
    *substrings = malloc( sizeof( uintptr_t )) ;
    // init pointer to pointer
    char *p1 ; 
    char *p2 ;

    p1 = str1 ;
    p2 = str2 ;

    int i = 0 ;
    int n_substrings = 0 ;

    while ((( p1 != &str1[ strlen( str1 ) ]) && (p2 != &str2[ strlen( str2 ) ]))) 
    {
        if ( *p1 == *p2 )
        {
            if ( i > 0 ){
                if ( *p1 == substrings[ i - 1 ][ 0 ] )
                {
                    return "yes" ;
                }
                else 
                {
                    for ( int n = 0 ; n < n_substrings ; n++ )
                    {
                        substrings[ n ] = substrings[ n + 1 ] ;
                    }
                    // substrings = realloc( substrings,  i-- ) ;
                    i--;
                }
            }
            substrings = realloc( substrings, i+1 ) ;
            substrings[ i ] = realloc( substrings[ i ], n_substrings+1 ) ;
            n_substrings++;
            for ( int j = 0; j < n_substrings ; j++ )
            {
                substrings[ i ][ j ] = str1[ j ] ;
            }
            substrings[ i ][ n_substrings ] = '\0' ;
            i++ ;
            p1++ ;
            p2++ ;
            
        }
        else { return "" ; }
    }
    out = substrings[ n_substrings - 1 ] ;
    return out ;
}

int main( void )
{
    char *gcd = gcdOfStrings( "ABCB", "ABABC" ) ;
    printf( "%s", gcd );
    return 0 ;
}
