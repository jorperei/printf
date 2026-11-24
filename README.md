*This project has been created as part of the 42 curriculum by jorperei.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`. The goal is to learn how variadic functions work in C (`<stdarg.h>`), how to structure a small program around a dispatcher, and how to handle low-level output with `write()` while respecting the 42 Norm.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, or `-1` if a write error occurs, just like the original.

### Supported conversions

| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a literal percent sign |

As required by the subject, the buffer management of the original `printf()` is **not** implemented: every piece of output is written directly with `write()`. Flags, width and precision are not part of the mandatory part and are not supported.

### Project structure

| File | Role |
|------|------|
| `ft_printf.c` | main function: walks through the format string and dispatches conversions |
| `ft_printf.h` | prototypes and includes |
| `ft_sc.c` | `%c` |
| `ft_pstring.c` | `%s` |
| `ft_pptr.c` | `%p` |
| `ft_putnb.c` | `%d` / `%i` |
| `ft_putunsignednb.c` | `%u` |
| `ft_hexl.c`, `ft_hexu.c` | recursive hexadecimal printing (lowercase / uppercase) |
| `ft_putnbhexlc.c`, `ft_putnbhexuc.c` | `%x` / `%X` entry points |

## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`. The Makefile produces the static library `libftprintf.a`:

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + make
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s, you are %d years old! %x\n", "42", 42, 255);
	ft_printf("printed %d characters\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Testing

To compare the output and the return value of `ft_printf` against the real `printf`, a simple approach is to call both with the same arguments:

```c
int a = printf("%d|%s|%p\n", -42, "abc", (void *)0);
int b = ft_printf("%d|%s|%p\n", -42, "abc", (void *)0);
// a and b must be equal, and both lines must be identical
```

Write errors can be checked by closing or redirecting standard output (for example `./test > /dev/full` or `./test >&-`): `ft_printf` must return `-1`.

## Algorithm and data structures

### Overview

`ft_printf` does a **single linear pass** over the format string (complexity `O(n)` in the length of the format plus the number of digits printed):

1. Read the character at the current position.
2. If it is a `%` followed by another character, call the dispatcher with that character; the dispatcher picks the right conversion function and consumes the matching argument from the `va_list`. The position advances by 2.
3. Otherwise, write the character as it is. The position advances by 1.
4. Add the number of characters written to a running counter, and stop immediately if any `write()` failed.

### Why this design

- **No extra data structure.** The only "structure" needed is the `va_list` provided by `<stdarg.h>`, which already gives sequential access to the arguments. Since buffer management is explicitly excluded from the project, there is no need for a buffer, a list or a table of states. Keeping the program stateless keeps it small, easy to read and easy to test.
- **Dispatcher with `if` conditions.** Each conversion lives in its own small function and a static dispatcher selects it from the conversion character. The dispatcher keeps `ft_printf` short and makes adding a new conversion trivial.
- **`va_list` passed by pointer.** Every conversion function receives a `va_list *`, so each `va_arg` call advances the same list. Passing the list by value would make the callee work on a copy and the next conversion would read the same argument again. `va_end` is called exactly once, before `ft_printf` returns, on every path.
- **Recursion for numbers.** To print a number in a given base the digits must come out from the most significant to the least significant, but the arithmetic (`n % base`, `n / base`) produces them in the opposite order. Recursion solves this without any buffer: print `n / base` first, then the last digit.
- **Correct types for each conversion.** `%d`/`%i` read an `int`, `%u`, `%x` and `%X` read an `unsigned int`, `%c` reads an `int` (default argument promotion), and `%p` converts the pointer to `unsigned long` to print all its bits. `INT_MIN` is handled as a special case so the negation never overflows.
- **Error propagation.** Like the real `printf`, the function returns `-1` when `write` fails. Every call to `write` and every recursive call is checked **individually** before its result is added to the total. Adding the results first would be wrong, since a `-1` could be hidden by a positive value (for example `-1 + 1 = 0`). The first failure is returned up through the whole chain, which stops any further output.
- **Edge cases that follow glibc.** `%s` with `NULL` prints `(null)`, `%p` with `NULL` prints `(nil)`, `%c` with `0` writes a NUL byte and counts as one character, and a lone `%` at the end of the string is not treated as a conversion.

## Resources

### Documentation and references

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html): behaviour and return value of the original function.
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html): `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy`.
- [Norminette](https://github.com/42School/norminette) and the 42 Norm: style rules followed by the code.
- [Francinette](https://github.com/xicodomingues/francinette): third-party tester used to validate the project.

### Use of AI

AI (Claude, by Anthropic) was used as a **learning and review tool**. The code of the project was written by me.

- **Understanding concepts:** step-by-step explanations of how variadic functions and `va_arg` work, why `va_list` has to be passed by pointer, and what the original `printf` does in edge cases (`NULL` strings and pointers, `%c` with `0`, `INT_MIN`).
- **Code review:** I sent my functions and received feedback on bugs, for example a wrong base in a recursive call, a pointer-increment mistake, the order of evaluation of the arguments, and calling `va_end` after a `return`.
- **Error handling:** discussion of how to propagate `write` failures and of the pattern of checking each result separately. A small helper for summing results with error detection (`ft_sum`) was suggested during this discussion.
- **Testing:** generation of a test harness that compares `ft_printf` against the real `printf` (output and return value) and tests write errors.