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
    if( strlen( str1 ) > strlen( str2 ) )
    {
        p1 = str2 ;
        str1 = str2 ; 
        str2 = p1 ; 
    }
    
    // find common factors of string lengths
    int len_s1 = strlen( str1 ) ;
    int len_s2 = strlen( str2 ) ; 
    
    int * fac_list1 = ( int * )malloc( sizeof( int ) ) ;
    int * fac_list2 = ( int * )malloc( sizeof( int ) ) ;

    int n_common_facs = 0 ; 
    int * common_facs_list = ( int * )malloc( sizeof( int ) ) ;
    
    int n_facs1 = get_factors( len_s1, fac_list1 ) ;
    int n_facs2 = get_factors( len_s2, fac_list2 ) ;
   
    print_factors( n_facs1, fac_list1 ) ;
    print_factors( n_facs2, fac_list2 ) ; 

    for( int i = 0 ; i < len_s1 ; i++ )
    {
        if( fac_list1[ i ] == fac_list2[ i ] )
        {
            n_common_facs++ ;
            common_facs_list = ( int * )realloc( common_facs_list, n_common_facs ) ;
            common_facs_list[ i ] = fac_list1[ i ] ;
        }
    }

    if( n_common_facs > 0 )
    {
        printf( "\ncommon factors : [" ) ;
        for ( int i = 0 ; i < n_common_facs - 1 ; i++ )
        {
            printf( "%d, ", common_facs_list[ i ] ) ;
        }
        printf( "%d]\n\n", common_facs_list[ n_common_facs - 1 ] ) ;
    }
    
    int longest_substr_index = -1;
    int ff = 0 ;
 
    for( int i = 0 ; i < n_common_facs ; i++ ) 
    {
        ff = 0 ;
        for( int j = 0 ; j < len_s2 ; j = j + common_facs_list[ i ])
        {
            for( int k = 0 ; k < common_facs_list[ i ] ; k++ )
            {
                if( str1[ k ] !=  str2[ j + k ])
                {
                    ff = 1 ;
                    printf( "setting fail flag and break\n" ) ;
                    break ;
                }
            }
        if( ff == 1 )
            { printf("break #2.\n" ) ; break ; }
        else { longest_substr_index = common_facs_list[ i ] ; }
        }        
    }

    printf( "longest_substr_index = %d\n", longest_substr_index ) ;
    return out ;
}

int main( void )
{
    char *gcd = gcdOfStrings( "A", "ABABABAB" ) ;
    
    if( *gcd != '\0' )
        { printf( "\ngcd = \"%s", gcd ) ; printf( "%s", "\"\n\n" ) ; return 0 ; }
    else return -1 ;
}
