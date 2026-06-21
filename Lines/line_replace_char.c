#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main() {
    int c;
    struct termios old_terminal, raw_terminal;

    // 1. Get the current terminal settings and save a copy
    tcgetattr(STDIN_FILENO, &old_terminal);
    raw_terminal = old_terminal;

    // 2. Turn off Line-Buffering (ICANON) and Local Echo (ECHO) inside the flags
    raw_terminal.c_lflag &= ~(ICANON | ECHO);
    
    // 3. Apply these raw settings to the terminal instantly
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_terminal);

    // --- Your Original K&R Loop ---
    while ((c = getchar()) != EOF) {
        // In raw mode, Ctrl+C sends an ASCII value of 3. 
        // Let's create a manual exit condition!
        if (c == 3) { 
            break; 
        }

        switch (c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
            case 127: // Modern terminals often send 127 for backspace
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            default:
                putchar(c); // Print normal characters so we can see them (since echo is off)
                break;
        }
    }

    // 4. CRITICAL: Restore original terminal settings before closing!
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_terminal);
    printf("\nTerminal restored cleanly.\n");

    return 0;
}