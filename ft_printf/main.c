#include "libftprintf.h"
# define S  "%*c", 5, 0
int main ()
{
	char *p = NULL;
  int a = ft_printf(S);
   ft_printf("\n");
     int b = printf(S);
     printf("\n\n%d -- %d\n",a,b);
return 0;
}