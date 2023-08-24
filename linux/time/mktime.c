#include <time.h> 
#include <stdio.h>

int main () {
   int ret;
   struct tm info;
   char buffer[80];
    struct tm localTm;
   info.tm_year = 2001 - 1900;
   info.tm_mon = 7 - 1;
   info.tm_mday = 4;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 1;
   info.tm_isdst = -1;

    localTm.tm_sec  = 0;
    localTm.tm_hour = 0;
    localTm.tm_min  = 0;
    localTm.tm_mday = 1 ;
    localTm.tm_mon  = 0;
    localTm.tm_year = 70 ;


   ret = mktime(&localTm);
   if( ret == -1 ) {
      printf("Error: unable to make time using mktime\n");
   } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      printf("%s",buffer);
   }

   return(0);
}
