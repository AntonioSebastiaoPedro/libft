#include <stdio.h>
#include <string.h>
#include "../libft.h"

void    *memset(void *first, int value, size_t num)
{
        unsigned char *ptr;

        ptr = (unsigned char *)first;
        while (num--)
                *ptr++ = (unsigned char)value;
        return (first);
}

void    bzero(void *first2, size_t num2)
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

void    *ft_memmove(void *dest, const void *src, size_t num)
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
                while(num--)
                        d[num] = s[num];
        return (dest);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
        size_t  len;
        size_t  i;
        char    *s;

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

size_t  ftstrlcat(char *dest, const char *src, size_t size_dest)
{
        size_t  dest_len;
        size_t  remaining;
        size_t  i;

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

char    *ftstrchr(const char *str, int c)
{
        while (*str++)
                if (*str == c)
                        return ((char *)str);
        return (NULL);
}

char    *ftstrrchr(const char *str, int c)
{
        size_t  len;

        len = strlen(str);
        while (len--)
                if (str[len] == c)
                        return ((char *)&str[len]);
        return (NULL);
}

// int main() {
//     char str[] = "Olá, mundo!";
//     char *ptr;

//     // Procura a primeira ocorrência da letra 'm'
//     ptr = ftstrchr(str, '\0');

//     if (ptr != NULL) {
//         printf("O caractere foi encontrado em: %s = %p\n", ptr, ptr);
//         printf("Anterior: %s = %p\n", ptr-1, ptr-1);
//     } else {
//         printf("O caractere não foi encontrado.\n");
//     }

//     return 0;
// }

int main() {
    char str[] = "Olá, mundo, mundo!";
    char *ptr;

    // Procura a última ocorrência da letra 'm'
    ptr = ftstrrchr(str, 'd');

    if (ptr != NULL) {
        printf("O último caractere foi encontrado em: %s\n", ptr);
    } else {
        printf("O caractere não foi encontrado.\n");
    }

    return 0;
    
}