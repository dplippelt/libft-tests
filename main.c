/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:35:03 by dlippelt          #+#    #+#             */
/*   Updated: 2024/12/04 13:13:37 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
// change path below according to location of project folder
#include "/home/dlippelt/codam/main/libft/libft.h"

static void	ft_printstr(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%c", ((char *)str)[i]);
		i++;
	}
	printf("\n");
}

static void	test_issomething()
{
	int		c;

	// c = -150;
	c = 'x';

	printf("ft_isalpha('%c') = %d\n", c, ft_isalpha(c));
	printf("isalpha('%c') = %d\n", c, isalpha(c));
	printf("\n");
	printf("ft_isdigit('%c') = %d\n", c, ft_isdigit(c));
	printf("isdigit('%c') = %d\n", c, isdigit(c));
	printf("\n");
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));
	printf("isalnum('%c') = %d\n", c, isalnum(c));
	printf("\n");
	printf("ft_isascii('%c') = %d\n", c, ft_isascii(c));
	printf("isascii('%c') = %d\n", c, isascii(c));
	printf("\n");
	printf("ft_isprint('%c') = %d\n", c, ft_isprint(c));
	printf("isprint('%c') = %d\n", c, isprint(c));
}

static void	test_strlen()
{
	char	*s;

	s = "Hello!";

	printf("ft_strlen(\"%s\") = %zu\n", s, ft_strlen(s));
	printf("strlen(\"%s\") = %zu\n", s, strlen(s));
}

static int	test_memset_bzero()
{
	void	*str_user;
	void	*str_builtin;
	int		c;
	size_t	n;

	c = 'A';
	n = 4;
	str_user = malloc(n);
	if (str_user == NULL)
		return (0);
	str_builtin = malloc(n);
	if (str_builtin == NULL)
		return (0);

	printf("ft_memset(str_user, '%c', %zu) = %p\n", c, n, (void *)ft_memset(str_user, c, n));
	printf("memset(str_builtin, '%c', %zu) = %p\n", c, n, (void *)memset(str_builtin, c, n));
	printf("Data at memory block #1 (set by ft_memset): ");
	ft_printstr(str_user, n + 6);
	printf("Data at memory block #2 (set by memset): ");
	ft_printstr(str_builtin, n + 6);
	printf("\n");

	printf("ft_bzero(str_user, %zu)\n", n);
	ft_bzero(str_user, n);
	printf("bzero(str_user, %zu)\n", n);
	bzero(str_builtin, n);
	printf("Data at memory block #1 (cleared by ft_bzero): ");
	ft_printstr(str_user, n + 6);
	printf("Data at memory block #2 (cleared by bzero): ");
	ft_printstr(str_builtin, n + 6);

	free(str_user);
	free(str_builtin);
	return (1);
}

static int	test_memcpy()
{
	void		*dest_user;
	void		*dest_builtin;
	const void	*src;
	size_t		n;

	n = 10;

	src = "Hello!";
	/* src = NULL; */

	dest_user = malloc(n);
	if (dest_user == NULL)
		return (0);
	dest_builtin = malloc(n);
	if (dest_builtin == NULL)
		return (0);

	/* dest_user = NULL; */
	/* dest_builtin = NULL; */

	/* printf("dest_start = %p\n", (void *)dest);
	printf("dest_end = %p\n", (void *)(dest + n - 1));
	printf("src_start = %p\n", (void *)src);
	printf("src_end = %p\n", (void *)(src + n - 1)); */

	printf("ft_memcpy(dest_user, \"%s\", %zu) = %p\n", (char *)src, n, (void *)ft_memcpy(dest_user, src, n));
	printf("memcpy(dest_builtin, \"%s\", %zu) = %p\n", (char *)src, n, (void *)memcpy(dest_builtin, src, n));
	printf("Data at memory block #1 (copied by ft_memcpy): ");
	ft_printstr(dest_user, n);
	printf("Data at memory block #2 (copied by memcpy): ");
	ft_printstr(dest_builtin, n);

	printf("\nbzero(dest_user, %zu);\n", n);
	printf("bzero(dest_builtin, %zu);\n", n);
	bzero(dest_user, n);
	bzero(dest_builtin, n);
	free(dest_user);
	free(dest_builtin);
	printf("\n");
	return (1);
}

static int	test_memmove()
{
	void		*dest_user;
	void		*dest_builtin;
	const void	*src;
	size_t		n;

	n = 10;
	src = "Hello!";
	dest_user = malloc(n);
	if (dest_user == NULL)
		return (0);
	dest_builtin = malloc(n);
	if (dest_builtin == NULL)
		return (0);

	/* printf("dest_start = %p\n", (void *)dest);
	printf("dest_end = %p\n", (void *)(dest + n - 1));
	printf("src_start = %p\n", (void *)src);
	printf("src_end = %p\n", (void *)(src + n - 1)); */
	printf("ft_memmove(dest_user, \"%s\", %zu) = %p\n", (char *)src, n, (void *)ft_memmove(dest_user, src, n));
	printf("memmove(dest_builtin, \"%s\", %zu) = %p\n", (char *)src, n, (void *)memmove(dest_builtin, src, n));
	printf("Data at memory block #1 (moved by ft_memmove): ");
	ft_printstr(dest_user, n);
	printf("Data at memory block #2 (moved by memmove): ");
	ft_printstr(dest_builtin, n);

	bzero(dest_user, n);
	bzero(dest_builtin, n);
	free(dest_user);
	free(dest_builtin);
	return (1);
}

static void	test_strlcpy()
{
	char	dst_user[10];
	char	dst_builtin[10];
	char	*src;
	size_t	size;

	src = "Hello!";
	size = 4;

	printf("src = %s\n", src);
	printf("ft_strlcpy(dst_user, \"%s\", %zu) = %zu (src length)\n", src, size, ft_strlcpy(dst_user, src, size));
	printf("strlcpy(dst_builtin, \"%s\", %zu) = %zu (src length)\n", src, size, strlcpy(dst_builtin, src, size));
	printf("dst_user = %s\n", dst_user);
	printf("dst_builtin = %s\n", dst_builtin);
	printf("\n\n");
}

static void	test_strlcat()
{
	char	dst_user[13] = "Hello, ";
	char	dst_builtin[13] = "Hello, ";
	char	*src = "world!";
	size_t	size;

	size = 13;

	printf("ft_strlcat(\"%s\", \"%s\", %zu) = ", dst_user, src, size);
	printf("%zu (total length)\n", ft_strlcat(dst_user, src, size));

	printf("strlcat(\"%s\", \"%s\", %zu) = ", dst_builtin, src, size);
	printf("%zu (total length)\n", strlcat(dst_builtin, src, size));

	printf("dst_user (post) = %s\n", dst_user);
	printf("dst_builtin (post) = %s\n", dst_builtin);
}

static void	test_toupper()
{
	int	c[] =
	{
		'a',
		'z',
		'A',
		'Z',
		'*',
		'\t',
		77,
		120,
		-12,
		-130,
		-134,
		-166,
		EOF,
	};

	int	ncases = sizeof(c) / sizeof(c[0]);

	int	i = 0;
	while (i < ncases)
	{
		if (c[i] == EOF)
		{
			printf("ft_toupper(EOF) = %d\n", ft_toupper(c[i]));
			printf("toupper(EOF) = %d\n", toupper(c[i]));
			printf("\n");
		}
		else
		{
			printf("ft_toupper(\'%c\') = %c\n", c[i], ft_toupper(c[i]));
			printf("toupper(\'%c\') = %c\n", c[i], toupper(c[i]));
			printf("\n");
		}
		i++;
	}
}

static void	test_tolower()
{
	int	c[] =
	{
		'a',
		'z',
		'A',
		'Z',
		'*',
		'\t',
		77,
		120,
		-12,
		-130,
		-134,
		-166,
		EOF,
	};

	int	ncases = sizeof(c) / sizeof(c[0]);

	int	i = 0;
	while (i < ncases)
	{
		if (c[i] == EOF)
		{
			printf("ft_tolower(EOF) = %d\n", ft_tolower(c[i]));
			printf("tolower(EOF) = %d\n", tolower(c[i]));
			printf("\n");
		}
		else
		{
			printf("ft_tolower(\'%c\') = %c\n", c[i], ft_tolower(c[i]));
			printf("tolower(\'%c\') = %c\n", c[i], tolower(c[i]));
			printf("\n");
		}
		i++;
	}
}

static void	test_strchr()
{
	char	*s;
	int		c;

	s = "Hello, world!";
	c = 'o';

	printf("ft_strchr(\"%s\", \'%c\') = %s\n", s, c, ft_strchr(s, c));
	printf("strchr(\"%s\", \'%c\') = %s\n\n", s, c, strchr(s, c));
}

static void	test_strrchr()
{
	char	*s;
	int		c;

	s = "Hello, world!";
	c = 'o';

	printf("ft_strrchr(\"%s\", \'%c\') = %s\n", s, c, ft_strrchr(s, c));
	printf("strrchr(\"%s\", \'%c\') = %s\n\n\n\n", s, c, strrchr(s, c));
}

static void	test_memchr()
{
	char	*temp;
	void	*s;
	int		c;
	size_t	n;

	temp = "Hello, world!";
	s = (void *)temp;
	c = 'o';
	n = 10;

	printf("char *temp = \"%s\";\n", temp);
	printf("void *s = (void *)temp;\n\n");

	printf("ft_memchr(s, \"%c\", %zu) = %s\n",  c, n, (char *)ft_memchr(s, c, n));
	printf("memchr(s, \"%c\", %zu) = %s\n",  c, n, (char *)memchr(s, c, n));
}

static void	test_strncmp()
{
	char	*s1;
	char	*s2;
	size_t	n;

	s1 = "ABC";
	s2 = "AB";
	n = 3;

	printf("ft_strncmp(\"%s\", \"%s\", %zu) = %d\n", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("strncmp(\"%s\", \"%s\", %zu) = %d\n\n\n\n", s1, s2, n, strncmp(s1, s2, n));
}

static void	test_memcmp()
{
	char	*temp1;
	char	*temp2;
	void	*s1;
	void	*s2;
	size_t	n;

	temp1 = "ABC";
	temp2 = "AB";
	s1 = (void *)temp1;
	s2 = (void *)temp2;
	n = 3;

	printf("char *temp1 = \"%s\";\n", temp1);
	printf("char *temp2 = \"%s\";\n", temp2);
	printf("void *s1 = (void *)temp1;\n");
	printf("void *s2 = (void *)temp2;\n\n");
	printf("ft_memcmp(s1, s2, %zu) = %d\n", n, ft_memcmp(s1, s2, n));
	printf("memcmp(s1, s2, %zu) = %d\n", n, memcmp(s1, s2, n));
}

static void	test_strnstr()
{
	char	*big;
	char	*little;
	size_t	len;

	big = "Hello, world!";
	// big = (void *)0;
	// big = NULL;

	little = "llo";
	// little = "\0";
	// little = NULL;

	len = 5;
	// len = NULL;

	printf("strnstr(\"%s\", \"%s\", %zu) = %s\n", big, little, len, strnstr(big, little, len));
	printf("ft_strnstr(\"%s\", \"%s\", %zu) = %s\n", big, little, len, ft_strnstr(big, little, len));
}

static void	test_atoi()
{
	char	*nptr[] =
	{
		"0",
		"10",
		"0000021",
		"2147483647",
		"-2147483648",
		"    -2147483649000000abc2",
	};

	int		ncases = sizeof(nptr) / sizeof(nptr[0]);

	int		i = 0;
	while (i < ncases)
	{
		printf("ft_atoi(\"%s\") = %d\n", nptr[i], ft_atoi(nptr[i]));
		printf("atoi(\"%s\") = %d\n\n", nptr[i], atoi(nptr[i]));
		i++;
	}
}

static int	test_calloc()
{
	size_t	nmemb;
	size_t	size;
	void	*user_ptr;
	void	*builtin_ptr;

	nmemb = 0;
	size = 4;
	user_ptr = ft_calloc(nmemb, size);
	if (user_ptr == NULL)
		return (0);
	builtin_ptr = calloc(nmemb, size);
	if (builtin_ptr == NULL)
		return (0);

	printf("ft_calloc(%zu, %zu) = %p\n", nmemb, size, (void *)user_ptr);
	printf("calloc(%zu, %zu) = %p\n\n", nmemb, size, (void *)builtin_ptr);
	printf("Number of bytes attempted to allocate = %zu\n", nmemb * size);
	printf("[USER] Number of bytes actually allocated = %zu\n", malloc_usable_size(user_ptr));
	printf("[BUILTIN] Number of bytes actually allocated = %zu\n", malloc_usable_size(builtin_ptr));

	free(user_ptr);
	free(builtin_ptr);

	return (1);
}

static int	test_strdup()
{
	char	*s;
	char	*user_dup;
	char	*builtin_dup;

	s = "Hello, world!";
	user_dup = ft_strdup(s);
	if (user_dup == NULL)
		return (0);
	builtin_dup = strdup(s);
	if (builtin_dup == NULL)
		return (0);

	printf("ft_strdup(\"%s\") = %s\n", s, user_dup);
	printf("strdup(\"%s\") = %s\n", s, builtin_dup);

	free(user_dup);
	free(builtin_dup);

	return (1);
}

static int	test_substr()
{
	char			*s;
	unsigned int	start;
	size_t			len;
	char			*sub;

	s = "";
	start = 0;
	len = 1;
	sub = ft_substr(s, start, len);
	if (sub == NULL)
		return (0);

	printf("ft_substr(\"%s\", %u, %zu) = %s\n", s, start, len, sub);

	free(sub);

	return (1);
}

static int test_strjoin()
{
	char	*s1;
	char	*s2;
	char	*sj;

	s1 = "Hello, ";
	s2 = "world!";
	sj = ft_strjoin(s1, s2);
	if (sj == NULL)
		return (0);

	printf("ft_strjoin(\"%s\", \"%s\") = %s\n", s1, s2, sj);

	free(sj);

	return (1);
}

static int	test_strtrim()
{
	char	*s1;
	char	*set;
	char	*st;

	s1 = "   ,,#$Hello, world!  $$,,##";
	/* s1 = ""; */
	/* s1 = "  ,$"; */
	set = " ,#$";
	st = ft_strtrim(s1, set);
	if (st == NULL)
		return (0);

	printf("ft_strtrim(\"%s\", \"%s\") = %s\n", s1, set, st);

	free(st);
	return (1);
}

static int	test_split()
{
	char	c;
	char	**sa;
	size_t	ai;

	char	*s[] =
	{
		 "oneword",
		  "     lorem ipsum dolor sit amet, consectetur    adipiscing elit. Sed non risus. Suspendisse    ",
		  "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.",
		  "",
		  "     ",
		  " ",
		  "a",
		  "\t",
	};

	c = ' ';
	int	ncases = sizeof(s) / sizeof(s[0]);
	int	i = 0;

	while (i < ncases)
	{
		sa = ft_split(s[i], c);
		if (sa == NULL)
			return (0);

		printf("char **sa = ft_split(\"%s\", \'%c\')\n\n", s[i], c);
		ai = 0;
		if (sa[ai])
		{
			while (sa[ai])
			{
				printf("sa[%zu] = %s\n", ai, sa[ai]);
				ai++;
			}
		}
		else
		{
			printf("sa[%zu] == NULL\n", ai);
			printf("string array is empty!\n");
		}
		/* if (ai != 0 && sa[ai] == NULL)
			printf("sa[%zu] = NULL\n", ai); */
		while (ai--)
			free(sa[ai]);
		free(sa);
		printf("\n      -------\n\n");
		i++;
	}
	return (1);
}

static int	test_itoa()
{
	char	*s;

	int		n[] =
	{
		4231,
		-4231,
		+4231,
		INT_MAX,
		INT_MIN,
		0,
		-1,
		1,
		100,
		INT_MAX - 1,
		INT_MIN + 1,
		-99999,
	};
	int		ntests = sizeof(n) / sizeof(n[0]);

	int	i = 0;
	while (i < ntests)
	{
		s = ft_itoa(n[i]);
		if (s == NULL)
			return (0);
		printf("ft_itoa(%d) = %s\n", n[i], s);
		i++;
	}

	free(s);
	return (1);
}

#define STRINGIFY(x) #x
#define FUNCTION_NAME(func) STRINGIFY(func)

static char	test_strmapi_altcase(unsigned int i, char c)
{
	if (i % 2)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

static int	test_strmapi()
{
	char	*s;
	char	*ts;

	s = "Hello, World!";
	ts = ft_strmapi(s, test_strmapi_altcase);
	if (ts == NULL)
		return (0);

	printf("s = %s;\n\n", s);
	printf("ts = ft_strmapi(s, %s);\n\n", FUNCTION_NAME(test_strmapi_altcase));
	printf("ts = %s;\n", ts);

	free(ts);
	return (1);
}

static void	test_striteri_altcase(unsigned int i, char *s)
{
	if (i % 2)
		*s = ft_toupper(*s);
	else
		*s = ft_tolower(*s);
}

static void	test_striteri()
{
	char	s[] = "Hello, World!";

	printf("s = %s;\n\n", s);
	printf("ft_striteri(s, %s);\n\n", FUNCTION_NAME(test_striteri_altcase));
	ft_striteri(s, test_striteri_altcase);
	printf("s = %s;\n", s);
}

static void	test_putchar_fd()
{
	char	c;
	int		fd;

	c = 'X';
	fd = 1;

	printf("c = %c;\n", c);
	printf("fd = %d;\n\n", fd);
	printf("ft_putchar_fd(c, fd);\n\n\n");
	ft_putchar_fd(c, fd);
	ft_putchar_fd('\n', fd);
}

static void	test_putstr_fd()
{
	char	*s;
	int		fd;

	s = "Hello, world!";
	fd = 1;

	printf("s = %s;\n", s);
	printf("fd = %d;\n\n", fd);
	printf("ft_putstr_fd(s, fd);\n\n\n");
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

static void test_putendl_fd()
{
	char	*s;
	int		fd;

	s = "Hello, world!";
	fd = 1;

	printf("s = %s;\n", s);
	printf("fd = %d;\n\n", fd);
	printf("ft_putendl_fd(s, fd);\n\n\n");
	ft_putendl_fd(s, fd);
}

static void test_putnbr_fd()
{
	int	fd;

	int	n[] =
	{
		4231,
		-4231,
		+4231,
		INT_MAX,
		INT_MIN,
		0,
		-1,
		1,
		100,
		INT_MAX - 1,
		INT_MIN + 1,
		-99999,
	};
	fd = 1;
	int	ntest = sizeof(n) / sizeof(n[0]);

	printf("fd = %d;\n\n\n", fd);
	int	i = 0;
	while (i < ntest)
	{
		printf("n = %d;\n", n[i]);
		printf("ft_putnbr_fd(n, fd);\n");
		ft_putnbr_fd(n[i], fd);
		ft_putstr_fd("\n\n", fd);
		i++;
	}
}

int	main(void)
{
	printf("\n\n------------------------------------------------\n\n\n");
	test_issomething();
	printf("\n\n------------------------------------------------\n\n\n");
	test_strlen();
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_memset_bzero())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_memcpy())
		return (1);
	if (!test_memmove())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	test_strlcpy();
	test_strlcat();
	printf("\n\n------------------------------------------------\n\n\n");
	test_toupper();
	printf("\n\n------------------------------------------------\n\n\n");
	test_tolower();
	printf("\n\n------------------------------------------------\n\n\n");
	test_strchr();
	test_strrchr();
	test_memchr();
	printf("\n\n------------------------------------------------\n\n\n");
	test_strncmp();
	test_memcmp();
	printf("\n\n------------------------------------------------\n\n\n");
	test_strnstr();
	printf("\n\n------------------------------------------------\n\n\n");
	test_atoi();
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_calloc())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_strdup())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_substr())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_strjoin())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_strtrim())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_split())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_itoa())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	if (!test_strmapi())
		return (1);
	printf("\n\n------------------------------------------------\n\n\n");
	test_striteri();
	printf("\n\n------------------------------------------------\n\n\n");
	test_putchar_fd();
	printf("\n\n------------------------------------------------\n\n\n");
	test_putstr_fd();
	printf("\n\n------------------------------------------------\n\n\n");
	test_putendl_fd();
	printf("\n\n------------------------------------------------\n\n\n");
	test_putnbr_fd();
	printf("\n\n------------------------------------------------\n\n\n");
	return (0);
}
