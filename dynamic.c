#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <dlfcn.h>

void get_function()
{
    FILE *f = fopen("fn.c", "w");
    fprintf(f, "#include <math.h>\n"
            "double fn(double in) {\n");

    char *a_line = NULL;
    char *prompt = ">>double fn(double in) {>>\n";

    do {
        free(a_line);
        a_line = readline(prompt);
        fprintf(f, "%s\n", a_line);
        prompt = ">> ";
    } while (strcmp(a_line, "}"));
    fclose(f);
}

void compile_and_run()
{
    if (system("c99 -fPIC -shared fn.c -o fn.so -lm")) {
        printf("Compile error\n");
        return;
    }

    void *handle = dlopen("./fn.so", RTLD_LAZY);
    if (!handle) printf("Failed to load fn.so: %s \n", dlerror());

    typedef double (*fn_type)(double);
    fn_type f = dlsym(handle, "fn");
    printf("f(1) = %g\n", f(1));
    printf("f(64) = %g\n", f(64));


}

int main()
{
    compile_and_run();
    get_function();
    return 0;
}
