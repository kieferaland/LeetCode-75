#include <stdio.h>


char * gcdOfStrings(char * str1, char * str2){
    // put strings in order strlen(str1) <= strlen(str2)
    if( strlen( str1 ) > strlen( str2 ) ){
        char * temp = str1 ;
        str1 = str2 ;
        str2 = temp ; 
    }
    
}

int main( void ) {

	int a = 3 ;
	int b = 1 ;
	gcdOfStrings(char * str1, char * str2)
	printf( "%d\n", a % b ) ;
	
	return 0 ; 
}