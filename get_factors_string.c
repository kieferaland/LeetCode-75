#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_factors( char * s, int * faclist )
{

	int numfacs = 0 ;

	int s_len = strlen( s ) ;

	for(int i = 0 ; i < (int) ( sqrt( s_len ) ) ; i++ )
	{
		if( s_len % ( i + 1 ) == 0 )
		{
			numfacs = numfacs + 2 ;
			
			faclist = ( int * )realloc( faclist, numfacs * sizeof( int)) ;

			for( int j = 0 ; j < i ; j++ )
			{
				faclist[ numfacs - ( i - j ) ] = faclist[ ( ( numfacs / 2 ) - 1 ) + j ] ;
			}

			faclist[ ( numfacs / 2 ) - 1 ] = i + 1 ;
			faclist[ ( numfacs / 2 ) ] = s_len / ( i + 1 ) ;
		}
	}
	return numfacs ;
}

int main( void )
{
	int * faclist;
	faclist = ( int * )malloc( sizeof( int ) ) ;
	char * s = "ABABABABABAB" ;

	int numfacs = get_factors( s, faclist ) ;

	printf( "\n%c", '[') ;
	for( int i = 0 ; i < numfacs - 1 ; i++ )
	{
		printf( "%d, ", faclist[ i ] ) ;
	}
	printf( "%d%s", faclist[ numfacs -1 ], "]\n\n" ) ;


	return 0 ;
}