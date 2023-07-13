#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "get_factors.h"



char * gcdOfStrings( char * str1, char * str2 )
{   
    // intit pointers
    char * out, * p1 ;
    int len_out ;
    out = ( char * )malloc( sizeof( char ) ) ;
    // put strings in order of length i.e. strlen( str1 ) <= strlen( str2 )
    if( strlen( str1 ) > strlen( str2 ) ){
        p1 = str1 ;
        str1 = str2 ; 
        str2 = p1 ; 
    }
    // init list pointer for common factors
    int * common_facs_list = ( int * )malloc( sizeof( int ) ) ;
    // get common factors list and num common factors
    int n_common_facs = get_common_factors( strlen( str1 ), strlen( str2 ), &common_facs_list, 1 ) ; 

    int substr_len = -1;
    int ff = 0 ;
    
    if( n_common_facs == 1 )
        if( strlen( str1 ) != 1 )
            return "" ;

    for( int i = 0 ; i < n_common_facs ; i++ ) 
    {
        substr_len = common_facs_list [ i ] ;

        if( common_facs_list[ i ] == 0 )
        {
            continue ;
        }
        for( int j = 0 ; j < strlen( str2 ) ; j = j + common_facs_list[ i ] )
        {

            // printf( "%c\n", str2[ j ] ) ;
            
            for( int k = 0 ; k < common_facs_list[ i ] ; k++ )
            {
                // printf("str1 = %c, str2 = %c\n", str1[ k ], str2[ j + k ] ) ;

                if( str1[ k ] != str2[ j + k ] )
                { 
                
                    ff = -1 ; 

                    break ; 
                
                } else if( ( j + k ) < strlen( str1 ) ){
                
            
                    if( str1[ k ] != str1[ j + k  ] ){
                
                        ff = -1;
                
                        break ;
                    }

                    ff = 1 ; 
                
                    continue ; 
                
                } else{ 

                    
                
                }
            } 
            if( ff == -1 ){ 
            
                substr_len = 0 ; 
                
                break ; 
            
            }
            else if( ff == 1 ){ 
            
                continue ; 
            
            }
        }
    }

    out = ( char * )realloc( out, ( sizeof(char) * substr_len ) + 1 ) ;
    
    for( int i = 0 ; i < substr_len ; i++ )
    {

        out[ i ] = str1[ i ] ;
    
    }
    
    return out ;
}

int main( void )
{
    
    char *
    
    gcd = gcdOfStrings( "A", "A" ) ;
    printf( "\"A\", \"A\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "A", "AA" ) ;
    printf( "\"A\", \"AA\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "A", "AAA" ) ;
    printf( "\"A\", \"AAA\" \ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "AB", "AA" ) ;
    printf( "\"AB\", \"AA\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "AB", "AAA" ) ;
    printf( "\"AB\", \"AAA\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "AB", "ABAB" ) ;
    printf( "\"AB\", \"ABAB\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "AB", "ABABAB" ) ;
    printf( "\"AB\", \"ABABAB\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "ABAB", "ABABABAB" ) ;
    printf( "\"ABAB\", \"ABABABAB\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;

    gcd = gcdOfStrings( "ABC", "ABCABC" ) ;
    printf( "\"ABC\", \"ABCABC\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ; 
    
    gcd = gcdOfStrings( "AAAAAAAAA", "AAACCC" ) ;
    printf( "\"AAAAAAAAA\", \"AAACCC\"\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ;
    
    return 0 ;

}
