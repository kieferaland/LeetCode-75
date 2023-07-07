#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int  main(void)
{
	int * faclist;
	faclist = ( int * )malloc( sizeof( int ) ) ;
	int numfacs = 0 ;

	// char * s1 = "ABABAB" ;
	char * s2 = "ABABABABABAB" ;

	// int len1 = strlen( s1 ) ;
	int len2 = strlen( s2 ) ;

	// printf( "%f\n", sqrt( len2 ) ) ;

	printf( "%d\n\n", len2 ) ;

	for(int i = 0 ; i < (int) ( sqrt( len2 ) ) ; i++ )
	{
		if( len2 % i == 0 )
		{
			numfacs = numfacs + 2 ;
			faclist = ( int * )realloc( faclist, numfacs * sizeof( int)) ;

			if( numfacs != 0 )
			{
				faclist[ numfacs - 1 ] = faclist[ numfacs / 2 ] ;
			}

		}
		
	}

	for( int i = 0 ; i < numfacs ; i++ )
	{
		printf( "%d\n", faclist[ i ] ) ;
	}

	return 0 ;
}