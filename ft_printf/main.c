#include "ft_printf.h"

void		assert_equal(int a, int b, char *test_name)
{
	if (a != b)
		printf("\033[33mERROR OCCURRED IN: %s\033[0m\n", test_name);
}

void		print_test(char *test_name)
{
	printf("\033[01;32m%s\033[0m\n", test_name);
}

void		test_strings(char *s1, int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("Start %%: %*.4s and %c \n", 20, s1, 'c');
	r2 = printf("Start %%: %*.4s and %c \n", 20, s1, 'c');
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("Start %%: %4.4s and %c \n", s1, 'c');
	r2 = printf("Start %%: %4.4s and %c \n", s1, 'c');
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("Start %%: %-5.4s and %c \n", s1, 'c');
	r2 = printf("Start %%: %-5.4s and %c \n", s1, 'c');
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("Start %%: %5.4s and %c \n", s1, 'c');
	r2 = printf("Start %%: %5.4s and %c \n", s1, 'c');
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("Start %%: %5.4s and %c \n", s1, 'c');
	r2 = printf("Start %%: %5.4s and %c \n", s1, 'c');
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("string padding %s.\n", s1);
	r2 = printf("string padding %s.\n", s1);
	assert_equal(r1, r2, test_name);
}

void		test_pointers(int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("ptr address %20p in hexadecimal.\n", &r1);
	r2 = printf("ptr address %20p in hexadecimal.\n", &r1);
	assert_equal(r1, r2, test_name);
}

void		test_numbers(int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("print out normal int %d\n", 1234);
	r2 = printf("print out normal int %d\n", 1234);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("- padding %-3d end.\n", 4);
	r2 = printf("- padding %-3d end.\n", 4);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("prefix plus %+3d\n", 4);
	r2 = printf("prefix plus %+3d\n", 4);
	assert_equal(r1, r2, test_name);

	ft_printf("%hhd, %lld, %li, %c, %f\n", 130, 12414, 9999, 10, 123.923923);
}

void		test_hex(int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("transform to long octal %lo\n", 3147483647);
	r2 = printf("transform to long octal %lo\n", 3147483647);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("hexadecimal in long long caps %lX\n", 8223372036854775807);
	r2 = printf("hexadecimal in long long caps %lX\n", 8223372036854775807);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("hash with o %#o & x %010x\n", 1234, 1234);
	r2 = printf("hash with o %#o & x %010x\n", 1234, 1234);
	assert_equal(r1, r2, test_name);
}

void		test_floats(int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("float tst padding %023.5f end.\n", -12.987);
	r2 = printf("float tst padding %023.5f end.\n", -12.987);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("double test with prec 15 %.15lf\n", -3.01234245245234859);
	r2 = printf("double test with prec 15 %.15lf\n", -3.01234245245234859);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("rounding final dec %.3f\n", 1.0029);
	r2 = printf("rounding final dec %.3f\n", 1.0029);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("float tst %f\n", -3.00001);
	r2 = printf("float tst %f\n", -3.00001);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("float tst prec %.3f\n", 10.0);
	r2 = printf("float tst prec %.3f\n", 10.0);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("\nft:52|%-+20.5f|\n", 10005.10005);
	r2 = printf("\nft:52|%-+20.5f|\n", 10005.10005);
	assert_equal(r1, r2, test_name);
}

void		test_extras(int r1, int r2, char *test_name)
{
	print_test(test_name);
	r1 = ft_printf("print %% percentage.\n");
	r2 = printf("print %% percentage.\n");
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("%% with padding %5%\n");
	r2 = printf("%% with padding %5%\n");
	assert_equal(r1, r2, test_name);
	ft_printf("print {red}RED {cyan}CYAN{normal}.\n");
	ft_printf("print {green}RED{normal}.\n");
	r1  = ft_printf("wildcard -* %-*d end.\n", 10, 8);
	r2 = printf("wildcard -* %-*d end.\n", 10, 8);
	assert_equal(r1, r2, test_name);
	r1 = ft_printf("wildcard * %*.10d end.\n", 30, 4);	
	r2 = printf("wildcard * %*.10d end.\n", 30, 4);
	assert_equal(r1, r2, test_name);
	ft_printf("Unicode %%: %-5.4ls and %1lc \n", L"yäman", L'ä');
	ft_printf("Test binary %08b\n", 16);
	r1 = ft_printf("ptr address %*p in hexadecimal.\n", 20, &r1);
	r2 = printf("ptr address %*p in hexadecimal.\n", 20, &r1);
	assert_equal(r1, r2, test_name);
	ft_printf("Binary %b\n", 10);

	ft_printf("Hex %.10X string %s char %c llo %llo\n", 123421, "stringi", 'F', 1293381293);
}

int			parse_options(char **options, char c)
{
	int		i;

	i = 1;
	while(options[i])
	{
		if (ft_strchr(options[i], c))
			return (1);
		i++;
	}
	return (0);
}

void		tests(char **av)
{
	int			r1;
	int			r2;
	
	r1 = 0;
	r2 = 0;

	if (parse_options(av, 's') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_strings("test string", r1, r2, "---- STRING TEST ----");
	if (parse_options(av, 'p') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_pointers(r1, r2, "---- POINTER TEST ----");
	if (parse_options(av, 'd') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_numbers(r1, r2, "---- INTEGER TEST ----");
	if (parse_options(av, 'x') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_hex(r1, r2, "---- HEX TEST ----");
	if (parse_options(av, 'f') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_floats(r1, r2, "---- FLOAT TEST ----");
	if (parse_options(av, 'e') || parse_options(av, 'a') || parse_options(av, 'l'))
		test_extras(r1, r2, "---- EXTRAS TEST ----");
	if (parse_options(av, 'l'))
		while(1);
}

int				main(int ac, char **av)
{
	if (ac > 1)
		tests(av);
	else
		printf("options:\n\ts - strings\n\tp - pointers\n\td - numbers\n\tx - hex and octal\n\tf - floats\n\te - extras\n\tm - mem leaks\n");
	return (0);
}
