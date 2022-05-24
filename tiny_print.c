#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	tiny_printf(const char *fmt, ...)
{
	int	put_count;
	size_t	i;
	va_list	ap;
	int		arg;

	put_count = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			putchar(fmt[i]);
			put_count++;
			i++;
		}
		else
		{
			i++;
			if (fmt[i] != 'd')
				exit(1);
			arg = va_arg(ap, int);
			putchar(arg + '0');
			put_count++;
			i++;
		}
	}
	return (put_count);
}

int	main(void)
{
	int	ret;

	ret = 0;
	ret = tiny_printf("hello: \n");
	tiny_printf("%d\n", ret);
	ret = tiny_printf("hello: %d\n", 1);
	tiny_printf("%d\n", ret);
	ret = tiny_printf("hello: %d %d\n", 1, 2);
	printf("%d\n", ret);
	return (0);
}
