#include "libft.h"
void *ft_memcpy(void *dst, const void *src, size_t n)
{
    int i;
    char *ptrsrc;
    char *ptrdst;

    if (!dst && !src)
    {
        return (NULL);
    }
    
    ptrsrc = (char *) src;
    ptrdst = (char *) dst; 
    i = -1;
    while(++i < (int) n)
    {
        *(ptrdst + i) = *(ptrsrc + i);
    }
    return (dst);
}