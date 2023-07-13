#ifndef GET_FACTORS_H
#define GET_FACTORS_H

int get_factors( int number, int ** factors_list) ;
int get_common_factors( int num1, int num2, int ** common_facs_list, int verbose_flag ) ;
int print_factors( int n_factors, int ** factors_list ) ;
int print_common_factors( int n_common_facs, int ** common_facs_list ) ;

#endif