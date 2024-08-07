#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<stdlib.h>
#include "../libft.h"

void *memset(void *first, int value, size_t num)
{
        unsigned char *ptr;

        ptr = (unsigned char *)first;
        while (num--)
                *ptr++ = (unsigned char)value;
        return (first);
}

void bzero(void *first2, size_t num2)
{
        memset(first2, '\0', num2);
}

void *ft_memcpy(void *dest, const void *src, size_t num)
{
        unsigned char *d;
        unsigned char *s;

        d = (unsigned char *)dest;
        s = (unsigned char *)src;
        while (num--)
                *d++ = *s++;
        return (dest);
}

void *ft_memmove(void *dest, const void *src, size_t num)
{
        unsigned char *s;
        unsigned char *d;

        s = (unsigned char *)src;
        d = (unsigned char *)dest;
        if (num == 0 || s == d)
                return (dest);
        if (d < s)
                while (num--)
                        *d++ = *s++;
        else
                while (num--)
                        d[num] = s[num];
        return (dest);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
        size_t len;
        size_t i;
        char *s;

        s = (char *)src;
        i = 0;
        len = strlen(s);
        if (len > 0)
        {
                while (i < size - 1 && s[i] != '\0')
                {
                        dest[i] = s[i];
                        printf("Posicao: %zu = %c\n", i, dest[i]);
                        i++;
                }
                dest[i] = '\0';
        }
        return (len);
}

size_t ftstrlcat(char *dest, const char *src, size_t size_dest)
{
        size_t dest_len;
        size_t remaining;
        size_t i;

        dest_len = strlen(dest);
        remaining = size_dest - dest_len - 1;
        i = 0;
        while (i < remaining && src[i] != '\0')
        {
                dest[dest_len + i] = src[i];
                i++;
        }
        dest[dest_len + i] = '\0';
        return (dest_len + strlen(src));
}

char *ftstrchr(const char *str, int c)
{
        while (*str++)
                if (*str == c)
                        return ((char *)str);
        return (NULL);
}

char *ftstrrchr(const char *str, int c)
{
        size_t len;

        len = strlen(str);
        while (len--)
                if (str[len] == c)
                        return ((char *)&str[len]);
        return (NULL);
}

int ftstrncmp(const char *str1, const char *str2, size_t num)
{
        size_t i;

        i = 0;
        while (i < num)
        {
                if (str1[i] != str2[i] || !str1[i] || !str2[i])
                {
                        return (unsigned char)str1[i] - (unsigned char)str2[i];
                }
                i++;
        }
        return (0);
}

void    *ftmemchr(const void *str, int ch, size_t num)
{
        unsigned char   *ptr;

        ptr = (unsigned char *)str;
        while (num--)
                if (*ptr++ == (unsigned char)ch)
                        return ((void *)ptr - 1);
        return (NULL);
}

int     ftmemcmp(const void *ptr1, const void *ptr2, size_t num)
{
        size_t  i;
        unsigned char *str1;
        unsigned char *str2;

        str1 = (unsigned char *)ptr1;
        str2 = (unsigned char *)ptr2;
        i = 0;
        while (i < num)
        {
                if (str1[i] != str2[i])
                        return (str1[i] - str2[i]);
                i++;
        }
        return (0);
}

char    *ftstrnstr(const char *str1, const char *str2, size_t num)
{
        size_t  i;
        size_t  len_sub;

        len_sub = strlen(str2);
        i = 0;
        if (len_sub == 0)
                return ((unsigned char *)str1);
        while (i < num && str1[i])
        {
                if (str1[i] == str2[0])
                {
                        if ((num - i) >= len_sub)
                                if (ftstrncmp(str2, str1 + i, len_sub) == 0)
                                        return ((unsigned char *)&str1[i]);
                }
                i++;
        }
        return (NULL);
}

int     ftatoi(const char *str)
{
        int     i;
        int     num;
        int     signal;

        signal = 1;
        num = 0;
        i = 0;
        while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
                i++;
        if (str[i] == '-')
                signal = -1;
        if (str[i] == '-' || str[i] == '+')
                i++;
        while (ft_isdigit(str[i]))
        {
                num = num * 10 + str[i] - '0';
                i++;
        }
        return (num * signal);
}

int main() {
    char str1[] = " \n \t \f \v \r   -553 6363";
    char str2[] = "-b456abc";
    int num1;
    int num2;
    
    num1 = atoi(str1);
    num2 = atoi(str2);

    printf("str1 convertido para inteiro: %d\n", num1);
    printf("str2 convertido para inteiro: %d\n", num2);


    printf("\n========================CUSTOM======================\n");
    num1 = ftatoi(str1);
    num2 = ftatoi(str2);

    printf("str1 convertido para inteiro: %d\n", num1);
    printf("str2 convertido para inteiro: %d\n", num2);

    return 0;
}