#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, segN, DataType, t, debug = 1;
    int scount, si_temp, f_exit, si_temp_old;
    char ans[1000] = "";
        
    struct {
        int dt; // DataType
        int si; // SegIndex
        int ef; // EndFlag
        int cl; // ContentLen
        char cont[1000]; // Content
    } segm[10];
    
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    
    scanf("%d", &segN);
    for (i = 1; i <= segN; i++)
    {
        scanf("%d", &segm[i].dt);
        scanf("%d", &segm[i].si);
        scanf("%d", &segm[i].ef);
        scanf("%d", &segm[i].cl);
        scanf("%s", &segm[i].cont[0]);
    }
    scanf("%d", &DataType);
    
    // please finish the FUNCTION body here.
    
    scount = 0;
    for (i = 1; i <= segN; i++)
    {
        if (segm[i].dt == DataType)
        {
            scount++;
        }
    }
    
    if (scount == 0)
    {
        printf("%s \n", "output: NA");
        return 0;
    }

    si_temp = 0;
    f_exit = 0;
    
    if (debug)  printf("%s \n", "\nstart");
    while (!f_exit)
    {
        if (si_temp == si_temp_old)     // looping protect
        {
            printf("%s \n", "some error occured");
            return 0;
        } else si_temp_old = si_temp;

        for (i = 1; i <= segN; i++)
        {
            if (debug) printf("%s%d", "seg: ", i);
            if (segm[i].dt == DataType)
            {
                if (debug) printf("%s", " DT! ");
                if (debug) printf("%s%d%s%d \n", "si: ", segm[i].si, " si_temp: ", si_temp);
                
                if (segm[i].si == si_temp)
                {
                    strcat(&ans[0],(const char*)&segm[i].cont);
                    si_temp++;
                    if (debug) printf("%s \n", "IND!");
                } else
                {
                    // check error "is any segment index is lost?
                }
                if (debug) printf("%s%d%s%d \n", "si_temp: ", si_temp, " scount: ", scount);
                
                if ((si_temp == scount) && (segm[i].ef)) f_exit = 1;
            }
            if (f_exit) break;
        }
    }

    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    printf("%s \n", "input:");
    for (i = 1; i <= segN; i++)
    {
        printf("%d ", segm[i].dt);
        printf("%d ", segm[i].si);
        printf("%d ", segm[i].ef);
        printf("%d ", segm[i].cl);
        printf("%s \n", segm[i].cont);
    }
    printf("%d \n", DataType);
    printf("%s %s \n", "output:", ans);

    return 0;
}
