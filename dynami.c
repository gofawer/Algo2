#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <readline/readline.h>

typedef int (*fn_type)(int);

void *fn_void()
{
    int a = 9;
    int *aptr = &a;
    printf("%p\n", &a);
    printf("%p\n", aptr);

    return (void*)aptr;
}

int main()
{
    char *a_line = NULL;
    //readline(a_line);
    fn_type fd = fn_void();
    printf("%p\n", fd);

    return 0;
}
