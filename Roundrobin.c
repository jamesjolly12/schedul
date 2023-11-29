#include <stdio.h>
#define max 10

int main() {
    int n, TQ, count = 0, temp, sq = 0, PID[max], AT[max], BT[max], REM_BT[max], WT[max], TAT[max];
    int TotalWT = 0, TotalTAT = 0;

    printf("Enter the number of Process:-");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter PID :-");
        scanf("%d", &PID[i]);
        printf("Enter the A.T:-");
        scanf("%d", &AT[i]);
        printf("Enter the B.T:- ");
        scanf("%d", &BT[i]);
        REM_BT[i] = BT[i];
    }

    printf("Enter the TQ:-");
    scanf("%d", &TQ);

    while (1) {
        int allComplete = 1; 
        for (int i = 0; i < n; i++) {
            temp = TQ;
            if (REM_BT[i] == 0){
                count++;
              continue;
            }

            if (REM_BT[i] > TQ) {
                REM_BT[i] -= TQ;
            } else {
                temp = REM_BT[i];
                REM_BT[i] = 0;
            }
            sq += temp;
            TAT[i] = sq;
            allComplete = 0;
        }

        if (allComplete) {
            break;
        }
    }

    printf("\nPID\t AT\t BT\t TAT\t WT\n");
    for (int i = 0; i < n; i++) {
        TAT[i] = TAT[i] - AT[i]; 
        WT[i] = TAT[i] - BT[i];  
        TotalWT += WT[i];
        TotalTAT += TAT[i];
        printf("%d\t %d\t %d\t %d\t %d\n", PID[i], AT[i], BT[i], TAT[i], WT[i]);
    }

    printf("Average Waiting time is %.2f\n", (float)TotalWT / n);
    printf("Average Turn Around Time is %.2f\n", (float)TotalTAT / n);

    return 0; 
}
