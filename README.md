# Ft_printf

Ft_printf - time to recode the libc's printf function!

Concepts convered: 
- variadic functions with wchar_t
- wide character (wchar_t) management
- binary operations
- memory management
- in-depth understanding of printf

The first project of the algorithm branch at 42 is making your own printf. Printf writes to the standard output based on a format string and arguments provided. Argument conversions are preceeded by '%' in the format string and should have the following format:

%\[flags]\[field width][.precision]\[length modifier]type

Usage is almost identical to the original printf. The following options are available:

Flags: #, 0, -, +, ' and space.
Length modifiers: hh, h, l, ll, j and z.
Type conversions: c, C, s, S, d, D, i, I, u, U, o, O, x, X, p and n.
Precision and field width.
Use of * for precision and field width.

Additional options not provided by the libc's printf are the 'b' flag for binary conversions, and simple color management.

Should you have any questions or suggestions, feel free to send me an email at **jwalsh@student.42.fr**.
