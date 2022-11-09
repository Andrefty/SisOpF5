#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *
strrev(char *str)
{
    int i;
    int j;
    char a;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
    return str;
}
int intrev(int nr)
{
    int nr_nou = 0;
    while (nr > 0)
    {
        nr_nou+=nr%10;
        nr_nou*=10;
        nr/=10;
    }
    return nr_nou/10;
}
int main(int argc, char *argv[])
{
    char *er;
    int nr;
    if (argc != 2)
    {
        fprintf(stderr, "Utilizare: %s numar\n", argv[0]);
        return 1;
    }
    char *cp = calloc(strlen(argv[1]) + 1, sizeof(char));
    if (cp == NULL)
    {
        perror(cp);
        return 2;
    }
    nr = strtol(argv[1], &er, 10);
    if (*er != '\0' || (strcmp(argv[1], "") == 0))
    {
        fprintf(stderr, " %s invalid\n", argv[1]);
        return 2;
    }
    printf("Imaginea in oglina a %s este: %d\n",argv[1],intrev(nr));
    //     strcpy(cp,argv[1]);
    //    printf("Imaginea in oglina a %s este: %s\n",argv[1],strrev(cp));
    return 0;
}