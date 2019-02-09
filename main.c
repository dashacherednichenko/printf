/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:06:34 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:06:58 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

# define FMT "{%-15Z}\n", 123
//# define FMT "[test %90.10s TEST %00d]\n", "hello 12345", -42

int	main(void)
{
	int res;
	int res1;
	ft_putnbr(res = printf(FMT));
	ft_putchar('\n');
	ft_putnbr(res1 = ft_printf(FMT));
	ft_putchar('\n');
//	printf("hello\n");
//	ft_printf("hello\n");
//	char *s = "hello";
//	printf("--test 1 %.2s\n", "MY_!");
//	ft_printf("mytest 1 %.2s\n", "MY_!");
//	printf("--test 1 %.3s\n", 0);
//	ft_printf("mytest 1 %.3s\n", 0);
//	printf("--test 1.1 %s\n", "MY_!");
//	ft_printf("mytest 1.1 %s\n", "MY_!");
//	printf("--test 2 %c\n", 'N');
//	ft_printf("mytest 2 %c\n", 'N');
//	printf("--test 3 %.10d\n", -423);
//	ft_printf("mytest 3 %.10d\n", -423);
//	printf("--test 4 %d\n", -423);
//	ft_printf("mytest 4 %d\n", -423);
//	printf("--test 4 %p\n", s);
//	printf("--test 4 %p\n", s);
//	ft_printf("mytest 4 %p\n", s);
//	printf("--test 5 %s %d\n %s\n", s, 42, s);
//	ft_printf("mytest 5 %s %d\n %s\n", s, 42, s);
//	printf("--test 6 %i\n", 42);
//	ft_printf("mytest 6 %i\n", 42);
//	printf("--test 7 %c\n", 0);
//	ft_printf("mytest 7 %c\n", 0);
//	printf("--test 8 %d\n%%\n", 5);


//	printf ("1. Вывод простой строки\n");
//	ft_printf ("1. Вывод простой строки\n");
//
//	printf ("\n2. Вывод целых чисел\n");
//
//	printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
//	{ int d1=123;
//		printf ("%d\n",d1);
//		printf ("% d\n",d1);
//		ft_printf ("%d\n",d1);
		//ft_printf ("% d\n",d1);
//	}
//	printf ("\n2.2 Вывод чисел c выравниванием по правому краю:\n");
//	{ int d1=123, d2=42, d3=1543;
//		printf ("%6d\n%6d\n%6d\n",d1,d2,d3);
//		ft_printf ("%6d\n%6d\n%6d\n",d1,d2,d3);
//	}
//	printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
//	{ int d1=123, d2=42, d3=1543;
//		printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);
	//	ft_printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);
//	}
//	printf ("\n2.4 Вывод числа с выводом 0 в недостающих символах:\n");
//	{ int d1=-123;
//		printf ("%06d\n",d1);
//	}
//	printf ("\n2.5 Вывод числа -123 с заданной шириной 6 и точностю 4 символов:\n");
//	{ int d1=-123;
//		printf ("%6.4d\n",d1);
//		printf ("%-6.4d\n",d1);
//		ft_printf ("%6.4d\n",d1);
//	}
//	printf ("\n2.6 Вывод числа -123 с заданной точностью 6 символов:\n");
//	{ int d1=-123;
//		printf ("%.6d\n",d1);
//		ft_printf ("%.6d\n",d1);
//	}
//	printf ("\n2.7 Вывод числа типа char:\n");
//	{ char d1=123;
//		printf ("%hhd\n",d1);
//		ft_printf ("%hhd\n",d1);
//	}
//	printf ("\n2.8 Вывод числа типа short int:\n");
//	{ short int d1=123;
//		printf ("%hd\n",d1);
//		ft_printf ("%hd\n",d1);
//	}
//	printf ("\n2.9 Вывод числа типа long int:\n");
//	{ long int d1=-2147483648;
//		printf ("%ld\n",d1);
//		ft_printf ("%ld\n",d1);
//	}
//	printf ("\n2.10 Вывод числа типа long long int:\n");
//	{ long long int d1=922337203685;
//		printf ("%lld\n",d1);
//		ft_printf ("%lld\n",d1);
//	}
//	printf ("\n2.11 Вывод целого без знакового числа:\n");
//	{ unsigned int d1=123;
//		printf ("%u\n",d1);
//		ft_printf ("%u\n",d1);
//	}
//	printf ("\n2.12 Вывод целого числа в восьмеричном формате:\n");
//	{ unsigned int d1=123;
//		printf ("%o\n",d1);
//		ft_printf ("%o\n",d1);
//	}
//	printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
//	{ unsigned int d1=-42;
//		printf ("%x\n",d1);
//		ft_printf ("%x\n",d1);
//	}
//	printf ("\n2.13.1 Вывод целого числа в шестнадцатеричном формате:\n");
//	{ unsigned int d1=255;
//		printf ("%X\n",d1);
//		ft_printf ("%X\n",d1);
//	}
//	printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
//	{ unsigned int d1=123;
//		printf ("%#x\n",d1);
//	}
//	printf ("\n3. Вывод чисел c плавающей точкой\n");
//	printf ("3.1 Вывод числа 123.456 с форматом по умолчанию:\n");
//	{ double d1=123.456;
//		printf ("%f\n",d1);
//		ft_printf ("%f\n",d1);
//	}
//	printf ("\n3.2 Вывод числа 123.456 с точностью 2:\n");
//	{ double d1=123.456;
//		printf ("%.2f\n",d1);
//		ft_printf ("%.2f\n",d1);
//	}
//	printf ("\n3.2.1 Вывод числа 123.456 с точностью 8:\n");
//	{ double d1=123.456123456;
//		printf ("%.8f\n",d1);
//		ft_printf ("%.8f\n",d1);
//	}
//	printf ("\n3.2.2 Вывод числа 922337203685.7777777777777777777777777777L с точностью 12:\n");
//	{
//		long double d1;
//		d1 = 922337203684.7777777777777777777777777777L;
//		printf ("%.12Lf\n",d1);
//		ft_printf ("%.12Lf\n",d1);
//	}
//	printf ("\n3.2.3 Вывод числа типа long int:\n");
//	{ double d1=2147483639.5;
//		printf ("%lf\n",d1);
//		ft_printf ("%lf\n",d1);
//	}
//	printf ("\n3.3 Вывод числа 123.456 в экспоненциальной форме:\n");
//	{ double d1=123.456;
//		printf ("%e\n",d1);
//	}
//	printf ("\n3.4 Использование преобразователя g:\n");
//	{ double d1=123.4567, d2=1234567.34567;
//		printf ("%g\n%g\n",d1,d2);
//	}
//	printf ("\n3.5 Вывод числа 123.456 в шестнадцатеричной форме:\n");
//	{ double d1=123.456;
//		printf ("%a\n",d1);
//	}
//	printf ("\n4. Вывод символа 'k':\n");
//	{ char d1='k';
//		printf ("%c\n",d1);
//		ft_printf ("%c\n",d1);
//	}
//	printf ("\n5. Вывод строки 'abc':\n");
//	{ char d1[4]="abc";
//		printf ("%s\n",d1);
//		printf ("%s\n",d1);
//	}
//	printf ("\n6. Вывод указателя:\n");
//	{ char d1[4]="abc";
//		printf ("%p\n",d1);
//		ft_printf("%p\n",d1);
//	}
//	printf ("\n7. Подсчет выведенных символов:\n");
//	{ int d1=0;
//		fflush (stdout);
//		printf ("Derived characters:%n",&d1);
//		printf (" %d\n",d1);
//	}

//	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", filename, str);

	system("leaks ft_printf");
	return (0);
}
