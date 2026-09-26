
#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        // prints out the prompts and messages
        printf("\nEnter the NFL score (Enter 1 to stop): ");

        if(scanf("%d", &score) != 1){ // ensures the user input is a numerical value
            printf("\nInvalid input\n");
            while (getchar() != '\n');
            continue;
        }
        else if(score == 1) { // user ends the session
            printf("Goodbye!\n");
            break;
        } 
        else if(score < 0){ // chesk for negative values
            printf("\nInvalid input\n");
            continue;
        }


        // finds the max possible values of any given scoring play
        int max_td  = score / 6;
        int max_fg  = score / 3;
        int max_safety = score / 2;
        int max_td2 = score / 8; /* TD + 2 point conversion */
        int max_td1 = score / 7; /* TD + 1 point field goal */

        // searches for all possible combinations
        for (int td = 0; td <= max_td; td++) {
            for (int fg = 0; fg <= max_fg; fg++) {
                for (int safety = 0; safety <= max_safety; safety++) {
                    for (int td2 = 0; td2 <= max_td2; td2++) {
                        for (int td1 = 0; td1 <= max_td1; td1++) {
                            int total = td * 6 + fg * 3 + safety * 2 + td2 * 8 + td1 * 7;

                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d pt FG, %d Safety\n", td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

    }

    return 0;
}