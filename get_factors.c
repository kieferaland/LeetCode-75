#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_factors( int num, int * factors_list )
{
	int n_factors = 0 ;

	for(int i = 0 ; i < (int) ( sqrt( num ) ) ; i++ )
	{
		if( num % ( i + 1 ) == 0 )
		{
			n_factors = n_factors + 2 ;
			
			factors_list = ( int * )realloc( factors_list, n_factors * sizeof( int)) ;

			for( int j = 0 ; j < i ; j++ )
			{
				factors_list[ n_factors - ( i - j ) ] = factors_list[ ( ( n_factors / 2 ) - 1 ) + j ] ;
			}

			factors_list[ ( n_factors / 2 ) - 1 ] = i + 1 ;
			factors_list[ ( n_factors / 2 ) ] = num / ( i + 1 ) ;
		}
	}
	return n_factors ;
}

void print_factors( int n_factors, int * factors_list )
{
	printf( "\n%c", '[') ;
	for( int i = 0 ; i < n_factors - 1 ; i++ )
	{
		printf( "%d, ", factors_list[ i ] ) ;
	}
	printf( "%d%s", factors_list[ n_factors -1 ], "]\n\n" ) ;
}

int main( int argc, char ** argv ){
	
	if( argc < 2 ){

		printf( "error: no number to factor passed as argument.\n" ) ;
		return -1 ;

	} else if ( argc > 2 ) {

		printf( "error: more than one number passed as argument.\n" ) ;
		return -1;

	}
	
	int num2factor = ( int ) atoi( argv[1] ) ;

	int * factors_list = ( int * )malloc( sizeof( int ) ) ;

	int n_factors = get_factors( num2factor, factors_list ) ;

	print_factors( n_factors, factors_list ) ;

	return 0 ;
}
