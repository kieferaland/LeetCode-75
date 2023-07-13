#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_factors( int num, int ** factors_list )
{
	int n_factors = 0 ;
	if( num == 1 )
	{
		n_factors = 1 ;
		*factors_list = ( int * )realloc( *factors_list, n_factors * sizeof( int)) ;
		( *factors_list )[ 0 ] = 1 ;
		return n_factors ;
	} else 
	{
		for(int i = 0 ; i < (int) ( sqrt( num ) ) ; i++ )
		{
			if( num % ( i + 1 ) == 0 )
			{
				n_factors = n_factors + 2 ;
				*factors_list = ( int * )realloc( *factors_list, n_factors * sizeof( int)) ;
				for( int j = 0 ; j < ( n_factors / 2 ) - 1 ; j++ )
				{
					( *factors_list )[ n_factors - ( j + 1 ) ] = ( *factors_list )[ ( n_factors - 2 ) - ( j + 1 ) ] ;
				}
				( *factors_list )[ ( n_factors / 2 ) - 1 ] = i + 1 ;
				( *factors_list )[ ( n_factors / 2 ) ] = num / ( i + 1 ) ;
			}
		}
	}
	return n_factors ;
}

void print_factors( int n_factors, int ** factors_list )
{
	printf( "%c", '[') ;
	for( int i = 0 ; i < n_factors - 1 ; i++ )
	{
		printf( "%d, ", ( *factors_list )[ i ] ) ;
	}
	printf( "%d%s", ( *factors_list )[ n_factors -1 ], "]\n" ) ;
}

void print_common_factors( int n_common_facs, int ** common_facs_list )
{
	printf( "n_common_facs : %d\n", n_common_facs ) ;

    if( n_common_facs > 0 )
    {
        printf( "common factors : [" ) ;
        for ( int i = 0 ; i < n_common_facs - 1 ; i++ )
        {
            printf( "%d, ", ( *common_facs_list )[ i ] ) ;
        }
        printf( "%d]\n", ( *common_facs_list )[ n_common_facs - 1 ] ) ;
    }
}

// DEF: A function to find the common factors to a list which is allocated in the calling function
// INPUT: two numbers and a pointer to the beginnng of allocated memory for the list
// OUTPUT: the number of common factors found, since these lists of ints have no terminating char.
int get_common_factors( int num1, int num2, int ** common_facs_list, int verbose_flag )
{
	// init list pointers for factors
    int * fac_list1 = ( int * )malloc( sizeof( int ) ) ;
    int * fac_list2 = ( int * )malloc( sizeof( int ) ) ;
    // get factor lists for each strlen and the num factors for each 
    int n_facs1 = get_factors( num1, &fac_list1 ) ;
    int n_facs2 = get_factors( num2, &fac_list2 ) ;
	if( verbose_flag == 1 ){
		print_factors( n_facs1, &fac_list1 ) ;
		print_factors( n_facs2, &fac_list2 ) ;
	}
	// run loop to check if factors match between factor lists for each number
	int n_common_facs = 0 ;
	// for each factor in the first factor list
    for( int i = 0 ; i < n_facs1 ; i++ )
    {
		int ff = 0 ;
		// for each factor in the second factor list
        for( int j = 0 ; j < n_facs2 ; j++ )
        {
			// if match is found add this to the common factor list
			// i.e. increase memory alloc by one sizeof( int ) and append factor to existing list
            if( fac_list1[ i ] == fac_list2[ j ] )
            {
				for( int k = 0 ; k < n_common_facs ; k++ )
				{
					if( fac_list1[ i ] == ( *common_facs_list )[ k ] ){
						ff = 1 ;
						break ;
					}
				}
				if( ff == 0 )
				{
					n_common_facs++ ;
					*common_facs_list = ( int * )realloc( *common_facs_list, sizeof( int ) * n_common_facs) ;
					( *common_facs_list )[ n_common_facs - 1 ] = fac_list1[ i ] ;
					break ; 
				}
				continue ;
            }
        }
    }
	
	if( verbose_flag == 1 ){
		print_common_factors( n_common_facs, common_facs_list ) ;
	}
	return n_common_facs ;
}


// example useage: 
// put the code below in main.c file
// can compile with: gcc -o out main.c get_factors.c
// can run with: ./out 12
// where 12 in the line above is a parameter which could be any other number
// returns: a list of factors for the given number

/* 
#include <stdio.h>
#include <stdlib.h>
#include "./get_factors.h"

int main( int argc, char ** argv )
{
	if( argc < 2 )
		{ printf( "error: no number to factor passed as argument.\n" ) ; return -1 ; }
	
	else if ( argc > 2 ) 
		{ printf( "error: more than one number passed as argument.\n" ) ; return -1; }
	
	int num2factor = ( int ) atoi( argv[1] ) ;
	int * factors_list = ( int * ) malloc( sizeof( int ) ) ;
	int n_factors = get_factors( num2factor, factors_list ) ;
	
	print_factors( n_factors, factors_list ) ;
	return 0;
}
*/

// dont forget the header file
// put the code below in get_factors.h file

/*
#ifndef GET_FACTORS_H
#define GET_FACTORS_H

int get_factors( int number, int * factors_list) ;
int print_factors( int n_factors, int * factors_list ) ;

#endif
*/
