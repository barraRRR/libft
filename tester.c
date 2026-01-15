#include "libft.h"
//#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* ========================================================= */
/* HELPERS                                                   */
/* ========================================================= */

/* Libera memoria usada como contenido genérico de listas */
void	del_content(void *content)
{
	free(content);
}

/* Imprime una string de forma segura (maneja NULL) */
void	print_str(const char *s)
{
	if (s)
		printf("%s", s);
	else
		printf("(null)");
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

int	main(void)
{
	/* ========================================================= */
	/* ft_atoi — Convierte una string en un int                  */
	/* Ignora espacios iniciales, gestiona signo y dígitos      */
	/* ========================================================= */
	printf("\n--- ATOI TEST ---\n");
	printf("libc: %d | ft: %d\n", atoi("42"), ft_atoi("42"));
	printf("libc: %d | ft: %d\n", atoi("   -42"), ft_atoi("   -42"));
	printf("libc: %d | ft: %d\n", atoi("4193abc"), ft_atoi("4193abc"));
	printf("libc: %d | ft: %d\n", atoi("abc"), ft_atoi("abc"));
	printf("libc: %d | ft: %d\n", atoi(""), ft_atoi(""));

	/* ========================================================= */
	/* ft_bzero — Pone a cero los primeros n bytes de memoria    */
	/* ========================================================= */
	printf("\n--- BZERO TEST ---\n");
	char bz1[10] = "abcdef";
	char bz2[10] = "abcdef";
	bzero(bz1, 3);
	ft_bzero(bz2, 3);
	printf("libc: %s | ft: %s\n", bz1, bz2);

	/* ========================================================= */
	/* ft_calloc — Reserva memoria y la inicializa a 0          */
	/* Protege contra overflow de count * size                  */
	/* ========================================================= */
	printf("\n--- CALLOC TEST ---\n");
	int *c1 = calloc(5, sizeof(int));
	int *c2 = ft_calloc(5, sizeof(int));
	printf("libc: %d %d | ft: %d %d\n",
		c1[0], c1[4], c2[0], c2[4]);
	free(c1);
	free(c2);

	/* ========================================================= */
	/* ft_is* — Clasificación de caracteres ASCII               */
	/* ========================================================= */
	printf("\n--- IS* TEST ---\n");
	printf("isalnum: %d | %d\n", isalnum('A'), ft_isalnum('A'));
	printf("isalpha: %d | %d\n", isalpha('1'), ft_isalpha('1'));
	printf("isascii: %d | %d\n", isascii(128), ft_isascii(128));
	printf("isdigit: %d | %d\n", isdigit('5'), ft_isdigit('5'));
	printf("isprint: %d | %d\n", isprint('\n'), ft_isprint('\n'));

	/* ========================================================= */
	/* ft_itoa — Convierte un int en una string recién reservada */
	/* ========================================================= */
	printf("\n--- ITOA TEST ---\n");
	char *i1 = ft_itoa(0);
	char *i2 = ft_itoa(-2147483648);
	char *i3 = ft_itoa(2147483647);
	print_str(i1); printf(" | ");
	print_str(i2); printf(" | ");
	print_str(i3); printf("\n");
	free(i1);
	free(i2);
	free(i3);

	/* ========================================================= */
	/* ft_memset — Rellena memoria con un byte                  */
	/* ft_memcmp — Compara bloques de memoria                   */
	/* ft_memchr — Busca un byte en memoria                     */
	/* ft_memmove — Copia memoria con solapamiento seguro       */
	/* ========================================================= */
	printf("\n--- MEM TEST ---\n");
	char m1[20] = "hello world";
	char m2[20] = "hello world";

	memset(m1, 'X', 5);
	ft_memset(m2, 'X', 5);
	printf("memset: %s | %s\n", m1, m2);

	printf("memcmp: %d | %d\n",
		memcmp("abc", "abd", 3),
		ft_memcmp("abc", "abd", 3));

	printf("memchr: %p | %p\n",
		memchr("abcdef", 'd', 6),
		ft_memchr("abcdef", 'd', 6));

	char mv1[20] = "123456";
	char mv2[20] = "123456";
	memmove(mv1 + 2, mv1, 4);
	ft_memmove(mv2 + 2, mv2, 4);
	printf("memmove: %s | %s\n", mv1, mv2);

	/* ========================================================= */
	/* ft_strlen — Devuelve la longitud de una string            */
	/* ft_strlcpy — Copia string de forma segura                */
	/* ft_strlcat — Concatena string con control de tamaño      */
	/* ========================================================= */
	printf("\n--- STR BASIC TEST ---\n");
	printf("strlen: %zu | %zu\n",
		strlen("hola"), ft_strlen("hola"));

	char d1[20] = "hola";
	char d2[20] = "hola";
	printf("strlcpy: %zu | %zu\n",
		strlcpy(d1, "mundo", 20),
		ft_strlcpy(d2, "mundo", 20));

	char c1b[20] = "hola";
	char c2b[20] = "hola";
	printf("strlcat: %zu | %zu\n",
		strlcat(c1b, "123", 20),
		ft_strlcat(c2b, "123", 20));

	/* ========================================================= */
	/* ft_strncmp — Compara strings hasta n caracteres          */
	/* ft_strchr — Busca carácter desde el inicio               */
	/* ft_strrchr — Busca carácter desde el final               */
	/* ft_strnstr — Busca substring con límite                  */
	/* ========================================================= */
	printf("\n--- STR SEARCH TEST ---\n");
	printf("strchr: %p | %p\n",
		strchr("banana", 'n'),
		ft_strchr("banana", 'n'));

	printf("strrchr: %p | %p\n",
		strrchr("banana", 'a'),
		ft_strrchr("banana", 'a'));

	printf("strnstr: %p | %p\n",
		strnstr("hello world", "world", 11),
		ft_strnstr("hello world", "world", 11));

	printf("strncmp: %d | %d\n",
		strncmp("abc", "abd", 2),
		ft_strncmp("abc", "abd", 2));

	/* ========================================================= */
	/* ft_strdup — Duplica una string en memoria dinámica       */
	/* ========================================================= */
	printf("\n--- STRDUP TEST ---\n");
	char *dup1 = strdup("libft");
	char *dup2 = ft_strdup("libft");
	printf("libc: "); print_str(dup1);
	printf(" | ft: "); print_str(dup2);
	printf("\n");
	free(dup1);
	free(dup2);

	/* ========================================================= */
	/* ft_strjoin — Concatena dos strings en una nueva           */
	/* ft_strtrim — Elimina caracteres del set en extremos      */
	/* ft_substr — Extrae substring segura                      */
	/* ========================================================= */
	printf("\n--- STR EXTRA TEST ---\n");
	char *join = ft_strjoin("hola ", "mundo");
	print_str(join); printf("\n");
	free(join);

	char *trim = ft_strtrim("  hola  ", " ");
	printf("'%s'\n", trim);
	free(trim);

	char *sub = ft_substr("abcdef", 2, 3);
	print_str(sub); printf("\n");
	free(sub);

	/* ========================================================= */
	/* ft_split — Divide string en array NULL-terminated        */
	/* ========================================================= */
	printf("\n--- SPLIT TEST ---\n");
	char **sp = ft_split("uno,,dos,", ',');
	for (int i = 0; sp && sp[i]; i++)
	{
		printf("[%d]: ", i);
		print_str(sp[i]);
		printf("\n");
		free(sp[i]);
	}
	free(sp);

	/* ========================================================= */
	/* ft_toupper / ft_tolower — Conversión de caracteres       */
	/* ========================================================= */
	printf("\n--- TOUPPER / TOLOWER ---\n");
	printf("%c | %c\n", toupper('a'), ft_toupper('a'));
	printf("%c | %c\n", tolower('Z'), ft_tolower('Z'));

	/* ========================================================= */
	/* ft_putchar_fd — Escribe un char en un fd                 */
	/* ft_putstr_fd — Escribe string en un fd                   */
	/* ft_putendl_fd — Escribe string + '\\n'                   */
	/* ft_putnbr_fd — Escribe número en texto                   */
	/* ========================================================= */
	printf("\n--- PUT TEST ---\n");
	ft_putchar_fd('A', 1);
	write(1, "\n", 1);
	ft_putstr_fd("hola\n", 1);
	ft_putendl_fd("mundo", 1);
	ft_putnbr_fd(-12345, 1);
	write(1, "\n", 1);

	/* ========================================================= */
	/* ft_lst* — Manipulación de listas enlazadas               */
	/* ========================================================= */
	printf("\n--- LIST TEST ---\n");
	t_list *lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_front(&lst, ft_lstnew(strdup("zero")));
	print_list(lst);
	printf("size: %d\n", ft_lstsize(lst));
	printf("last: %s\n", (char *)ft_lstlast(lst)->content);
	ft_lstclear(&lst, del_content);

	printf("\n--- END ---\n");
	return (0);
}