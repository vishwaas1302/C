#include <stdio.h>
#include <stdlib.h>

int main() {
    
    struct Player { 
        double score; // 4 bytes
        short health; // 2 bytes
        char rank; // 1 byte
    };

    struct Player* server_players = malloc(3 * sizeof(struct Player));

    if (server_players == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    int i=0,total_size=0;
    while(i < 3) {
        total_size = total_size + sizeof(server_players[i]);
        server_players[i].score = 100.0 + i*50;
        server_players[i].health = 100 - i*10;
        server_players[i].rank = 'A' + i;   
        i++;
    }
    
    // printf("\nsize of Player structure: %lu bytes\n", sizeof(struct Player));
    printf("size of server_players: %d bytes\n", total_size);
    printf("The Score of first player is : %.2lf\n", server_players[0].score);
    
    
    (server_players + 2) -> score = 999;
    
    for(i=0;i<3;i++) {
        printf("\n\nPlayer - %d\n\n", i+1);
        printf("Address of Player %d: %p\n", i+1, (server_players + i));
        printf("Player %d: Score = %.2lf, Health = %d, Rank = %c\n", i+1, (server_players + i)->score, (server_players + i)->health, (server_players + i)->rank);
    }
    
    free(server_players);
    // new_player -> score = 500;
    // new_player->rank = 'S';
    // (*new_player).health = 100;
    // printf("\nsize of Player structure: %lu bytes\n", sizeof(struct Player));
    // printf("size of player1: %lu bytes\n", sizeof(new_player));
    // printf("The Score is : %.2lf\n", new_player->score);
    // printf("The Rank is : %c\n", new_player->rank);
    // printf("The Health is : %d\n", (*new_player).health);

    // printf("Size of rank: %lu bytes\n", sizeof(player1->rank));
    // printf("Size of score: %lu bytes\n", sizeof(player1->score));
    // printf("Size of health: %lu bytes\n", sizeof(player1->health));
    return 0;
}