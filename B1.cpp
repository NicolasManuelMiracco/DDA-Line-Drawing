#include <graphics.h>
#include <cmath>

// Function to draw a line using the DDA algorithm
void drawDDALine(int x1, int y1, int x2, int y2) {
    // Calculate Δx and Δy
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increment in x & y for each step
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    // Initialize starting point
    float x = x1;
    float y = y1;

    // Put pixel for each step
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Put pixel at (round(x), round(y))
        x += xIncrement;  // Increment x
        y += yIncrement;  // Increment y
    }
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Line coordinates
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;

    // Function call to draw line
    drawDDALine(x1, y1, x2, y2);

    // Hold the screen (for viewing)
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}