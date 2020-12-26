#include <stdio.h>
#include <string.h>
 #include <unistd.h>
#include <stdlib.h>
#include <string.h>
 ssize_t  ft_write(int fildes, const void *buf, size_t nbyte);
 ssize_t  ft_read(int fildes, void *buf, size_t nbyte); 
 char *ft_strcpy(char * dst, const char * src);
 int ft_strcmp(const char *s1, const char *s2);
 char *ft_strdup(const char *s1);
 size_t ft_strlen(const char *s);

#define PARAMS -1, "hakam", 1

int main()
{
	// char *s  = "qwert";
	// char *k = "qwert";
	// printf("%d\n",ft_strcmp(k,s));
	char *s = "hjjds hvdfjhvdfjhvdfj dfhvdfjvhdfv dfjvdfhvdfjhvdfjhdf dfdf jdffhdfjhvdfjvdfhv dfvhjdfhvdfjhvdfjhvdfjv dfvdfjhvdfjhvdfjhvdf df vdfjvhdfjvhdfjhvdfjhvfuheurhuvfhvdfjhvdfjvhdfvhdfuvhdfv fvhdfjvhdjfhvdjfhv";
	char *s1 = "hjjds hvdfjhvdfjhvdfj dfhvdfjvhdfv dfjvdfhvdfjhvdfjhdf dfdf jdffhdfjhvdfjvdfhv dfvhjdfhvdfjhvdfjhvdfjv dfvdfjhvdfjhvdfjhvdf df vdfjvhdfjvhdfjhvdfjhvfuheurhuvfhvdfjhvdfjvhdfvhdfuvhdfv fvhdfjvhdjfhvdjfhv";
	char *s2 = "";
	char *s3 = "";

	printf("|%s|\n", ft_strdup(s));

	return(0);
}

