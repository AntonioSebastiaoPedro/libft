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

int     ftstrncmp(const char *str1, const char *str2, size_t num)
{
        size_t  i;

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

int main() {
    char str1[] = "acbcde";
    char str2[] = "abcdef";
    int resultado;

    // Comparando as duas strings inteiras
    printf("=============ORIGINAL==================\n");
    resultado = strncmp(str1, str2, 7); // O tamanho máximo é irrelevante aqui
    if (resultado == 0) {
        printf("As strings são iguais: %d.\n", resultado);
    } else {
        printf("As strings são diferentes: %d.\n", resultado);
    }

    // Comparando apenas os primeiros 5 caracteres
    resultado = strncmp(str1, str2, 5);
    if (resultado == 0) {
        printf("Os primeiros 5 caracteres são iguais: %d.\n", resultado);
    } else {
        printf("Os primeiros 5 caracteres são diferentes: %d.\n", resultado);
    }


    printf("=============CUSTOM==================\n");
    // Comparando as duas strings inteiras
    resultado = ftstrncmp(str1, str2, 7); // O tamanho máximo é irrelevante aqui
    if (resultado == 0) {
        printf("As strings são iguais: %d.\n", resultado);
    } else {
        printf("As strings são diferentes: %d.\n", resultado);
    }

    // Comparando apenas os primeiros 5 caracteres
    resultado = ftstrncmp(str1, str2, 5);
    if (resultado == 0) {
        printf("Os primeiros 5 caracteres são iguais: %d.\n", resultado);
    } else {
        printf("Os primeiros 5 caracteres são diferentes: %d.\n", resultado);
    }

    return 0;
}