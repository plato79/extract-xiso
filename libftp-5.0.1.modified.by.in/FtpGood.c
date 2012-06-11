/*
		      Library for ftpd clients.(libftp)
			Copyright by Oleg Orel
			 All rights reserved.
			
This  library is desined  for  free,  non-commercial  software  creation. 
It is changeable and can be improved. The author would greatly appreciate 
any  advises, new  components  and  patches  of  the  existing  programs.
Commercial  usage is  also  possible  with  participation of it's author.



*/

#include "FtpLibrary.h"

STATUS FtpGood(int va_alist, ...)
{
  va_list args;
  int Number;
  int Answer[MAX_ANSWERS];
  int counter=0;
  
  va_start(args, va_alist);

  Number = va_alist;
  
  while ( 1 )
    {
      if (counter == MAX_ANSWERS)
	return 0;
      Answer[counter] = va_arg(args,int);
      if (Answer[counter] == EOF ) break;
      counter++;
    }

  va_end(args);
  
  return FtpGood1(Number,Answer);
}


STATUS FtpGood1(int Number , int *Answer)
{
  while (1)
    {
      if ( *Answer == Number) return 1;
      if ( *Answer == 0) return 1;
      if ( *Answer == EOF ) return 0;
      Answer++;
    }
}

