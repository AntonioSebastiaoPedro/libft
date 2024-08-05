#include <stdio.h>
#include <string.h>
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

int main()
{
        char str[] = "mOlá, mundo!";
        void *ptr;
        int numeros2[] = {1, 2, 3, 42, 5};
        void *ptr2;

        
        ptr2 = ftmemchr(numeros2, 42, sizeof(numeros2));
        ptr = ftmemchr(str, 'n', 10);

        if (ptr != NULL)
        {
                printf("O caractere 'm' foi encontrado em: %s\n", (char *)ptr);
        }
        else
        {
                printf("O caractere 'm' não foi encontrado nos primeiros 10 bytes.\n");
        }

        if (ptr2 != NULL) {
                printf("O valor 42 foi encontrado na posição: %ld\n", (char*)ptr2 - (char*)numeros2);
        } else {
                printf("O valor 42 não foi encontrado.\n");
        }

        return 0;
}
