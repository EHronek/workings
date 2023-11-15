#include <stdarg.h>
#include "main.h"
/**
  * _printf - prints out formated characters to the console
  * @format - the string literal to print out to console
  * Return: printed chars to the console
  */
int _printf(const char *format, ...)
{
	int (*pr_func)(va_list, flags_f *);
	va_list arg;
	const char *pt;
	register int count = 0;

	flags_f flag = {0, 0, 0};
	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	pt = format;

	for (pt = format; *pt != '\0'; pt++)
	{
		if (*pt == '%')
		{
			pt++;
			if (*pt == '%')
			{
				count = count + _putchar('%');
				continue;
			}
			while (get_flag(*p, &flag))
			{
				pt++;
			}
			pr_func = get_print(*pt);
			count += (pr_func) ? pr_func(arguments, &flag) :
				_printf("%%%c", *pt);
		}
		else
			count = count + _putchar(*pt);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
