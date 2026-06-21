#include <stdio.h>

int main() { 

struct Player {
    long double score;    // 4 bytes
    short health; // 2 bytes
    char rank;    // 1 byte
};  

  struct Player player1 = {'A', 100, 50};
  printf("\nsize of Player structure: %lu bytes\n", sizeof(struct Player));
  printf("size of player1: %lu bytes\n", sizeof(player1));  
  printf("Size of rank: %lu bytes\n", sizeof(player1.rank));
  printf("Size of score: %lu bytes\n", sizeof(player1.score));
  printf("Size of health: %lu bytes\n", sizeof(player1.health));

  printf("\n\nAddress of player1: %p\n", &player1);
  printf("Address of player1.rank: %p\n", &player1.rank);
  printf("Address of player1.score: %p\n", &player1.score);
  printf("Address of player1.health: %p\n", &player1.health);

  return 0;
}