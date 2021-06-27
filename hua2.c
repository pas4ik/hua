#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, Ncom, Nout, debug = 1;
    char com_list[2000][20];
    char out_list[2000][16];

    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);

    scanf("%d", &Ncom);
    for (i = 1; i <= Ncom; i++)
    {
        scanf("%s", &com_list[i][0]);
    }

    // please finish the FUNCTION body here.

    if (debug)  printf("%s \n", "\nstart");

    for (i = 1; i <= Ncom; i++)
    {
        if (debug) printf("%s:%d", "n: ", i);
        if (!strncmp((const char*)com_list[i],"REQUEST",8))
        {
            if (debug) printf("%s \n", "req");
        } else
        {
            if (debug) printf("%s \n", "rel");
        }
    }
    Nout = 0;
    // please define the C output here. FOR EXAMPLE: printf("%d",a);

    printf("%s \n", "output:");
    for (i = 1; i <= Nout; i++)
        printf("%s \n", out_list[i]);

    return 0;
}