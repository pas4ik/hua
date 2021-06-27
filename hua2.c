#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, Ncom, debug = 0;
    int com_done;
    char com_list[2000][21];

    struct {
        char mac_now[13];
        char mac_was[13];
    } ip_pool[256];

    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);

    scanf("%d", &Ncom);
    for (i = 1; i <= Ncom; i++)
    {
        //printf("%d?", i);
        scanf("%s", &com_list[i]);
    }

    for (i = 1; i < 255; i++) { strcpy(ip_pool[i].mac_now, ""); strcpy(ip_pool[i].mac_was, ""); }
    //for (i = 1; i <= Ncom; i++) printf("%d : %s\n", i, com_list[i]);
    // please finish the FUNCTION body here.

    //strcpy(ip_pool[1].mac_was, "aaaabbbbcccc");
    if (debug)  printf("%s \n", "\nstart");
    com_done = 0;

    for (i = 1; i <= Ncom; i++)
    {
        if (debug) printf("%s%d ", "i: ", i);
        com_done = 0;
        if (!strncmp((const char*)com_list[i],"REQUEST",7))
        {
            if (debug) printf("%s%s ", "req: ", com_list[i]);
            for (j = 0; j < 255; j++)       // search if it was before
            {
                if ((strcmp((ip_pool[j].mac_was), "") != 0) &&
                (strstr((const char*)com_list[i], (const char*)ip_pool[j].mac_was) != NULL))
                {
                    if (debug) printf("%s ", ip_pool[j].mac_was);
                    if (debug) printf("%s%d ", "was in ", j);
                    strcpy((char *)ip_pool[j].mac_now, (const char *)&com_list[i][8]);  // allocate again
                    if (debug) printf("%s", "allocated again");
                    printf("%s%d\n", "192.168.0.", j);
                    com_done = 1;
                    break;
                }
            }
            if (!com_done)  // if it not was before
            {
                for (j = 0; j < 255; j++)
                {
                    if (strcmp((ip_pool[j].mac_was), "") == 0)      // search first empty
                    {
                        strcpy((char *)ip_pool[j].mac_now, (const char *)&com_list[i][8]);
                        strcpy((char *)ip_pool[j].mac_was, (const char *)ip_pool[j].mac_now);
                        if (debug) printf("%s", "allocated new");
                        printf("%s%d\n", "192.168.0.", j);
                        com_done = 1;
                        break;
                    }
                }
            }
            if (!com_done) printf("%s\n", "NA");
        } else
        if (!strncmp((const char*)com_list[i],"RELEASE",7))
        {
            if (debug) printf("%s%s ", "req: ", com_list[i]);
            for (j = 0; j < 255; j++)       // search if allocated
            {
                if ((strcmp((ip_pool[j].mac_now), "") != 0) &&
                (strstr((const char*)com_list[i], (const char*)ip_pool[j].mac_now) != NULL))
                {
                    if (debug) printf("%s ", ip_pool[j].mac_now);
                    if (debug) printf("%s %d ", "allocated in", j);
                    if (debug) printf("%s%d\n", "released 192.168.0.", j);
                    com_done = 1;
                    break;
                }
            }
        }
    }
    
    // please define the C output here. FOR EXAMPLE: printf("%d",a);

    return 0;
}