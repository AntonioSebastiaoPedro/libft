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

int main() {
    char destino[20] = "Olá, ";
    char origem[] = "mundo! Eu sou-mau!";
    size_t tamanho = sizeof(destino);

    // Calcula o espaço restante: 20 - 6 = 14
    size_t novo_tamanho = ft_strlcat(destino, origem, tamanho);

    printf("String resultante: %s\n", destino); // Imprime "Olá, mundo!"
    printf("Tamanho total (incluindo nulo): %zu\n", novo_tamanho);

    return 0;
}