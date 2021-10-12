void *ft_memset(void *s, int c, int n)
{
    char *ptr;

    ptr = (char *) s;
    while (n-- > 0)
        *(ptr++) = (char) c;
    return (s);
}