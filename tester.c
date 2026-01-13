#include "libft.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* ================= HELPERS ================= */

/* Libera el contenido de un nodo */
void	del_content(void *content)
{
	free(content);
}

/* Imprime una lista enlazada de strings de forma segura */
void	print_list(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
			printf("%s -> ", (char *)lst->content);
		else
			printf("(null) -> ");
		lst = lst->next;
	}
	printf("NULL\n");
}

/* Imprime una string o NULL de forma segura */
void	print_str(const char *s)
{
	if (s)
		printf("%s", s);
	else
		printf("(null)");
}

int	main(void)
{
	/* ================= ATOI ================= */
	// Convierte una string en un entero
	printf("\n--- ATOI TEST ---\n");
	printf("atoi: %d | ft_atoi: %d\n", atoi("42"), ft_atoi("42"));
	printf("atoi: %d | ft_atoi: %d\n", atoi("   -42"), ft_atoi("   -42"));
	printf("atoi: %d | ft_atoi: %d\n", atoi("4193abc"), ft_atoi("4193abc"));

	/* ================= BZERO ================= */
	// Pone a cero los primeros n bytes de memoria
	printf("\n--- BZERO TEST ---\n");
	char bz1[10] = "abcdef";
	char bz2[10] = "abcdef";
	bzero(bz1, 3);
	ft_bzero(bz2, 3);
	printf("bzero: %s | ft_bzero: %s\n", bz1, bz2);

	/* ================= CALLOC ================= */
	// Reserva memoria inicializada a cero
	printf("\n--- CALLOC TEST ---\n");
	int *c1 = calloc(5, sizeof(int));
	int *c2 = ft_calloc(5, sizeof(int));
	if (c1 && c2)
		printf("calloc[0]=%d | ft_calloc[0]=%d\n", c1[0], c2[0]);
	free(c1);
	free(c2);

	/* ================= IS* ================= */
	// Comprobaciones de caracteres ASCII
	printf("\n--- IS* TEST ---\n");
	printf("isalnum: %d | %d\n", isalnum('A'), ft_isalnum('A'));
	printf("isalpha: %d | %d\n", isalpha('1'), ft_isalpha('1'));
	printf("isascii: %d | %d\n", isascii(128), ft_isascii(128));
	printf("isdigit: %d | %d\n", isdigit('5'), ft_isdigit('5'));
	printf("isprint: %d | %d\n", isprint('\n'), ft_isprint('\n'));

	/* ================= ITOA ================= */
	// Convierte un entero en string recién reservada
	printf("\n--- ITOA TEST ---\n");
	char *itoa1 = ft_itoa(12345);
	char *itoa2 = ft_itoa(-42);
	print_str(itoa1);
	printf(" | ");
	print_str(itoa2);
	printf("\n");
	free(itoa1);
	free(itoa2);

	/* ================= MEM ================= */
	// Funciones de memoria sin semántica de string
	printf("\n--- MEM TEST ---\n");
	char mem1[20] = "hello world";
	char mem2[20] = "hello world";

	printf("memcmp: %d | %d\n",
		memcmp(mem1, mem2, 5),
		ft_memcmp(mem1, mem2, 5));

	ft_memset(mem1, 'X', 5);
	printf("memset: %s\n", mem1);

	printf("memchr: %p | %p\n",
		memchr("abcdef", 'd', 6),
		ft_memchr("abcdef", 'd', 6));

	char mv1[20] = "123456";
	char mv2[20] = "123456";
	memmove(mv1 + 2, mv1, 4);
	ft_memmove(mv2 + 2, mv2, 4);
	printf("memmove: %s | %s\n", mv1, mv2);

	/* ================= STR ================= */
	// Manipulación básica de strings
	printf("\n--- STR TEST ---\n");
	printf("strlen: %zu | %zu\n", strlen("hola"), ft_strlen("hola"));

	char dst1[20];
	char dst2[20];
	printf("strlcpy: %zu | %zu\n",
		strlcpy(dst1, "hola", 20),
		ft_strlcpy(dst2, "hola", 20));

	printf("strncmp: %d | %d\n",
		strncmp("abc", "abd", 2),
		ft_strncmp("abc", "abd", 2));

	printf("strchr: %p | %p\n",
		strchr("banana", 'n'),
		ft_strchr("banana", 'n'));

	printf("strrchr: %p | %p\n",
		strrchr("banana", 'a'),
		ft_strrchr("banana", 'a'));

	printf("strnstr: %p | %p\n",
		strnstr("hello world", "world", 11),
		ft_strnstr("hello world", "world", 11));

	char *dup = ft_strdup("libft");
	printf("strdup: ");
	print_str(dup);
	printf("\n");
	free(dup);

	/* ================= STR EXTRA ================= */
	// Creación y transformación de strings
	printf("\n--- STR EXTRA TEST ---\n");
	char *join = ft_strjoin("hola ", "mundo");
	printf("join: ");
	print_str(join);
	printf("\n");
	free(join);

	char *trim = ft_strtrim("  hola  ", " ");
	printf("trim: '");
	print_str(trim);
	printf("'\n");
	free(trim);

	char *sub = ft_substr("abcdef", 2, 3);
	printf("substr: ");
	print_str(sub);
	printf("\n");
	free(sub);

	/* ================= SPLIT ================= */
	// Divide una string en un array NULL-terminated
	printf("\n--- SPLIT TEST ---\n");
	char **split = ft_split("uno,dos,tres", ',');
	if (split)
	{
		for (int i = 0; split[i]; i++)
		{
			printf("[%d]: ", i);
			print_str(split[i]);
			printf("\n");
			free(split[i]);
		}
		free(split);
	}

	/* ================= TOUPPER / TOLOWER ================= */
	// Conversión de mayúsculas y minúsculas
	printf("\n--- TOUPPER / TOLOWER ---\n");
	printf("%c | %c\n", toupper('a'), ft_toupper('a'));
	printf("%c | %c\n", tolower('Z'), ft_tolower('Z'));

	/* ================= PUT* ================= */
	// Escritura en file descriptor
	printf("\n--- PUT* TEST ---\n");
	ft_putchar_fd('A', STDOUT_FILENO);
	write(1, "\n", 1);
	ft_putstr_fd("hola\n", STDOUT_FILENO);
	ft_putendl_fd("mundo", STDOUT_FILENO);
	ft_putnbr_fd(12345, STDOUT_FILENO);
	write(1, "\n", 1);

	/* ================= LIST ================= */
	// Manipulación de listas enlazadas
	printf("\n--- LIST TEST ---\n");
	t_list *lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_front(&lst, ft_lstnew(strdup("zero")));

	print_list(lst);

	printf("size: %d\n", ft_lstsize(lst));

	t_list *last = ft_lstlast(lst);
	if (last && last->content)
		printf("last: %s\n", (char *)last->content);
	else
		printf("last: (null)\n");

	ft_lstclear(&lst, del_content);
	printf("list cleared\n");

	return (0);
}