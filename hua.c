#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, N, DataType;
    char s[10], s2[10], s3[10];
    //char input[10][1000];
    struct {
        int dt;
        int si;
        int ef;
        int cl;
        char cont[1000];
    } segm[10];
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    // scanf("%s",&s);
    scanf("%d", &N);
    printf("%d \n", N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &segm[i].dt);
        scanf("%d", &segm[i].si);
        scanf("%d", &segm[i].ef);
        scanf("%d", &segm[i].cl);
        scanf("%s", &segm[i].cont[0]);
    }
    scanf("%d", &DataType);
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    //printf("%s",s);
    for (i = 1; i <= N; i++)
    {
        printf("%d ", segm[i].dt);
        printf("%d ", segm[i].si);
        printf("%d ", segm[i].ef);
        printf("%d ", segm[i].cl);
        printf("%s \n", segm[i].cont);
    }
    printf("%d ", DataType);
    //s3 = strcat(&segm[1].cont[0],&segm[2].cont[0]);
    //printf("%s", s3);
    return 0;
}
