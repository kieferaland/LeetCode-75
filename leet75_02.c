#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * gcdOfStrings( char * str1, char * str2 )
{   

    // put strings in order of length i.e. strlen( str1 ) <= strlen( str2 )

    // intit pointers
    char *out, *p1 ;

    out = ( char* )malloc( sizeof( char ) ) ;
   
    p1 = str2 ;

    if( strlen( str1 ) > strlen( str2 ) )
        { str1 = str2 ; str2 = p1 ; }

    if( strlen( str1 ) == strlen( str2 ) ){
        for( int i = 0 ; i < strlen( str2 ) ; i++ )
        {
            if( str1[ i ] != str2[ i ] )
                { printf( "\n%s\n\n", "Error: strings have equal length but are equal strings.\n") ; return "" ; }
        }
    }

    if( strlen( str2 ) % strlen( str1 ) != 0 )
    { 
        printf( "\n%s\n\n", "Error: unfactorable.") ; 
        
        if( strlen( str2 ) % ( strlen( str1 ) / 2 ) == 0 )
            printf( "%s\n\n", "Possible factorization by half length string." ) ;
            
        return "" ; 
    }
    
    
    while( *p1 != '\0' )
    {
        if( *p1 !=  *str1 )
            { printf( "\n%s\n\n", "Error: start of one or more shortest subintervals not equal to the first letter.\n") ; return "" ; }
        
        p1 = p1 + strlen( str1 ) ;

        // check for over-run
        if( p1 > str2 + strlen( str2 ) )
            { printf( "\n%s\n\n", "CRITICAL ERROR: we have run p1 passed the last memory loc of str2.") ; return "\0"; }
    }

    for( int i = 0 ; i < strlen( str2 ) / strlen( str1 ) ; i = i + strlen( str1 ) )
    {
        for( int j = 0 ; j < strlen( str1 ) ; j++ )
        {
            if( str2[ i + j ] != str1[ j ] )
                { printf( "\n%s\n\n", "Error: substrings do not repeat.") ; return "" ; }
        }
    }

    // if we are here then str1 divides str2 or else there are unconsidered  cases
    out = str1;
    return out ;
}

int main( void )
{
    char *gcd = gcdOfStrings( "ABAB", "ABABAB" ) ;
    
    if( *gcd != '\0' )
        { printf( "\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ; return 0 ; }
    else return -1 ;
}
