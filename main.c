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