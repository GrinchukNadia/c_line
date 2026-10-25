#include "strings.h"
#include "test.h"
#include "ft_printf.h"
#include "../src/libft/libft.h"
#include <stdio.h>
#include <limits.h>

int main(void)

{
    func_name("ft_printf");
    int a;
    int b;
    printf("\n-----------------c---------------------");
// --------------c------------------
    printf("\nExpected: ");
    b = printf("%c\n", 'a');

    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%c\n", 'a');

    check("digit", a, b);
// --------------c------------------

    printf("\n-----------------s---------------------");
// --------------s------------------
    printf("\nExpected: ");
    b = printf("%s\n", "Hello 42");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Hello 42");
    check("string", a, b);

    printf("\nExpected: ");
    b = printf("%s\n", "");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "");
    check("empty string", a, b);

    printf("\nExpected: ");
    b = printf("%s\n", "Hello\n42");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Hello\n42");
    check("string with \\n", a, b);

    printf("\nExpected: ");
    b = printf("%s\n", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets.");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets.");
    check("logn string", a, b);

    printf("\nExpected: ");
    b = printf("%s\n", "\0");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "\0");
    check("only \\0", a, b);

    printf("\nExpected: ");
    b = printf("%s\n", "%");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", "%");
    check("\% as a string", a, b);

    char *str = NULL;
    printf("\nExpected: ");
    b = printf("%s\n", str);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%s\n", str);
    check("\% as a string", a, b);
// --------------s------------------
    
    printf("\n-----------------p---------------------");
// --------------p------------------
    int c = 4;
    printf("\nExpected: ");
    b = printf("%p\n", &c);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%p\n", &c);
    check("pointer", a, b);

    printf("\nExpected: ");
    b = printf("%p\n", NULL);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%p\n", NULL);
    check("pointer address is NULL", a, b);
// --------------p------------------

    printf("\n-----------------d---------------------");
// --------------d------------------
    printf("\nExpected: ");
    b = printf("%d\n", 3);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 3);
    check("digit d", a, b);
        
    printf("\nExpected: ");
    b = printf("%d\n", 0);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", 0);
    check("digit d: 0", a , b);

    printf("\nExpected: ");
    b = printf("%d\n", INT_MAX);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", INT_MAX);
    check("digit i: INT_MAX", a, b);
        
    printf("\nExpected: ");
    b = printf("%d\n", -3);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", -3);
    check("negative digit d", a, b);

    printf("\nExpected: ");
    b = printf("%d\n", INT_MIN);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", INT_MIN);
    check("digit i: INT_MIN", a, b);
// --------------d------------------

    printf("\n-----------------i---------------------");
// --------------i------------------
    printf("\nExpected: ");
    b = printf("%i\n", 4);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%i\n", 4);
    check("digit i", a, b);

    printf("\nExpected: ");
    b = printf("%i\n", 0);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%i\n", 0);
    check("digit d: 0", a , b);

    printf("\nExpected: ");
    b = printf("%i\n", INT_MAX);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%i\n", INT_MAX);
    check("digit i: INT_MAX", a, b);
        
    printf("\nExpected: ");
    b = printf("%d\n", -3);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%d\n", -3);
    check("negative digit d", a, b);

    printf("\nExpected: ");
    b = printf("%i\n", INT_MIN);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%i\n", INT_MIN);
    check("digit i: INT_MIN", a, b);

// --------------i------------------

    printf("\n-----------------u---------------------");
// --------------u------------------
    printf("\nExpected: ");
    b = printf("%u\n", 4294967295U);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 4294967295U);
    check("unsigned decimal, max", a, b);

    printf("\nExpected: ");
    b = printf("%u\n", 42);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 42);
    check("unsigned decimal", a, b);

    printf("\nExpected: ");
    b = printf("%u\n", 0U);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%u\n", 0U);
    check("unsigned decimal, 0U", a, b);
// --------------u------------------

    printf("\n-----------------x---------------------");
// --------------x------------------
    printf("\nExpected: ");
    b = printf("%x\n", 0);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%x\n", 0);
    check("hexadeciaml lowercase: 0", a , b);

    printf("\nExpected: ");
    b = printf("%x\n", 420);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%x\n", 420);
    check("hexadeciaml lowercase", a, b);

    printf("\nExpected: ");
    b = printf("%x\n", UINT_MAX);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%x\n", UINT_MAX);
    check("hexadeciaml lowercase: UINT_MAX", a, b);
// --------------x------------------

    printf("\n-----------------X---------------------");
// --------------X------------------
    printf("\nExpected: ");
    b = printf("%X\n", 0);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%X\n", 0);
    check("hexadecimal uppercase: 0", a, b);
    
    printf("\nExpected: ");
    b = printf("%X\n", 300);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%X\n", 300);
    check("hexadecimal uppercase", a, b);
    
    printf("\nExpected: ");
    b = printf("%X\n", UINT_MAX);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%X\n", UINT_MAX);
    check("hexadecimal uppercase: UINT_MAX", a, b);
// --------------X------------------

    printf("\n-----------------%%---------------------");
// --------------%------------------
    printf("\nExpected: ");
    b = printf("%%\n");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%%\n");
    check("\% sign", a, b);
// --------------%------------------

    printf("\n---------without arguments-------------");
//--------without arguments---------
    printf("\nExpected: ");
    b = printf("Hello 42!\n");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("Hello 42!\n");
    check("\% sign", a, b);

    printf("\nExpected: ");
    b = printf("%%%%%%%%\n");
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%%%%%%%%\n");
    check("\% sign", a, b);
//--------without arguments----------

    printf("\n----------mixed arguments--------------");
//---------mixed arguments-----------
    printf("\nExpected: ");
    b = printf("%c %s %p %d %i %u %x %X %%\n", 'n', "hi", &c, 5, 125, 34U, 2983, 3734);
    printf("Actual:   ");
    fflush(stdout);
    a = ft_printf("%c %s %p %d %i %u %x %X %%\n", 'n', "hi", &c, 5, 125, 34U, 2983, 3734);
    check("all in one line", a, b);
//---------mixed arguments-----------
return (test_result());
}
