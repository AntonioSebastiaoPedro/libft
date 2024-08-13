#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
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

void *ftmemcpy(void *dest, const void *src, size_t num)
{
        unsigned char *d;
        unsigned char *s;

        d = (unsigned char *)dest;
        s = (unsigned char *)src;
        while (num--)
                *d++ = *s++;
        return (dest);
}

void *ftmemmove(void *dest, const void *src, size_t num)
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

size_t ftstrlcpy(char *dest, const char *src, size_t size)
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

void *ftmemchr(const void *str, int ch, size_t num)
{
        unsigned char *ptr;

        ptr = (unsigned char *)str;
        while (num--)
                if (*ptr++ == (unsigned char)ch)
                        return ((void *)ptr - 1);
        return (NULL);
}

int ftmemcmp(const void *ptr1, const void *ptr2, size_t num)
{
        size_t i;
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

char *ftstrnstr(const char *str1, const char *str2, size_t num)
{
        size_t i;
        size_t len_sub;

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

void *ftcalloc(size_t num, size_t size)
{
        void *ptr;

        ptr = malloc(num * size);
        if (!ptr)
                return (NULL);
        ft_memset(ptr, 0, num * size);
        return (ptr);
}

char *ftstrdup(const char *str)
{
        unsigned char *str2;
        size_t size;

        size = ft_strlen(str) + 1;
        str2 = (char *)malloc(size);
        if (!str2)
                return (NULL);
        ft_memcpy(str2, str, size);
        return (str2);
}

char *ftsubstr(char const *s, unsigned int start, size_t len)
{
    size_t s_len;
    char   *ptr;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s + 1);
    if (start >= s_len)
        return (strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    ptr = (char *)calloc(len + 1, 1);
    if (!ptr)
        return (NULL);
    ftmemcpy(ptr, s + start, len);
    ptr[len] = '\0';
    return (ptr);
}

char    *ftstrjoin(char const *s1, char const *s2)
{
        char    *new_str;
        size_t  len1;
        size_t  len2;
        size_t total_len;

        if (!s1 || !s2)
                return (NULL);
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        total_len = len1 + len2 + 1;
        new_str = (char *)calloc(total_len, sizeof(char));
        if (!new_str)
                return (NULL);
        ft_strlcpy(new_str, s1, total_len);
        ft_strlcat(new_str, s2, total_len);
        return (new_str);
}

int	ft_isinset(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return 1;
	return 0;
}

char	*ftstrtrim(char const *s, char const *set)
{
	size_t	start, end, len;
	char	*trim;

	if (!s || !set)
		return NULL;
	start = 0;
	while (s[start] && ft_isinset(s[start], set))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && ft_isinset(s[end], set))
		end--;
	len = end - start + 1;
	trim = (char *)ft_calloc(len + 1, sizeof(char));
	if (!trim)
		return NULL;
	ft_strlcpy(trim, s + start, len + 1);
	return trim;
}

static int	ft_wdlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char const *s, int *i, char c)
{
	int	word_len;
	char	*word;

	word_len = 0;
	while (s[*i + word_len] && s[*i + word_len] != c)
		word_len++;
	word = ft_substr(s, *i, word_len);
	*i += word_len;
	return (word);
}

static void     freearray(char **array, int pos)
{
        while (pos > 0)
                free(array[--pos]);
        free(array);
}

char	**ftsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(tab = (char **)malloc((ft_wdlen(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_get_word(s, &i, c);
			if (!tab[j++])
			{
				freearray(tab, j);
				return (NULL);
			}
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

static int      ft_countnbr(int nbr)
{
        int     count;

        count = 0;
        while (nbr)
        {
                nbr /= 10;
                count++;
        }
        return (count);
}

static 

char    *ftitoa(int nbr)
{
        char    *number;
        int             count;

        count = ft_countnbr(nbr);
        number = (char *)ft_calloc(count + 1, sizeof(char));
        if (nbr == 0)
                return ("0");
        if (nbr < 0)
        {
                count++;
                nbr *= -1;
                number[0] = '-';
                number[count] = '\0';
        }
        while (nbr != 0)
        {
                number[--count] = nbr % 10 + '0';
                nbr /= 10;
        }
        return (number);
}

char    *ftstrmapi(char const *s, char (*f)(unsigned int, char))
{
        size_t	len;
        unsigned int     i;
        char			*str;

        if (!s || !f)
                return (NULL);
        len = ft_strlen(s);
        str = (char *)ft_calloc(len + 1, sizeof(char));
        if (!str)
                return (NULL);
	i = 0;
        while (s[i] != '\0')
        {
                str[i] = f(i, s[i]);
                i++;
        }
        str[i] = '\0';
        return (str);
}

void ftstriteri(char *s, void (*f)(unsigned int, char*))
{
        unsigned int    i;

        if (!s || !f)
                return;
        i = 0;
        while (s[i] != '\0')
        {
                f(i, &s[i]);
                i++;
        }
}


void print_index(unsigned int i, char *c) {
    printf("Index %u: %c\n", i, *c);
}

void    ftputchar_fd(char c, int fd)
{
        write(fd, &c, 1);
}

void    ftputstr_fd(char *s, int fd)
{
        if (!s || !fd)
                return;
        while (*s != '\0')
                write(fd, s++, 1);
        
}

void    ftputendl_fd(char *s, int fd)
{
        ft_putstr_fd(s, fd);
        write(fd, "\n", 1);
}

void    ftputnbr_fd(int n, int fd)
{
        int     sign;
        char     nbr;

        sign = 1;
        if (n == -2147483648)
        {
                write(fd, "-2147483648", 11);
                return;        
        }
        if (n < 0)
        {
                ft_putchar_fd('-', fd);
                n = -n;
        }
        if (n > 9)
                ftputnbr_fd(n / 10, fd);
        ft_putchar_fd((n % 10 + '0'), fd);
}

t_list  *ftlstnew(void *content)
{
        t_list  *node;
        node = ft_calloc(1, sizeof(t_list));
        if (!node)
                return (NULL);
        node->content = content;
        node->next = NULL;
        return (node);
}

void    ftlstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}


int main()
{
    t_list *list = NULL;
    t_list *new1 = ft_lstnew("Primeiro nó");
    t_list *new2 = ft_lstnew("Segundo nó");

    ftlstadd_front(&list, new2);
    ftlstadd_front(&list, new1);

    while (list) {
        printf("%s\n", (char *)list->content);
        list = list->next;
    }

    return 0;
}