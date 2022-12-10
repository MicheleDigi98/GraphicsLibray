#include "GUI/Graphics.h"
#include "GameLoop/GameLoop.h"

int posX = 10;
int posY = 10;


void update(Context *context){
    drawPoint(context, posX, posY, 178);
}

void keyBoard(char character, Context* context){
    switch (character) {
        case 'w':
            posY--;
            break;
        case 's':
            posY++;
            break;
        case 'a':
            posX--;
            break;
        case 'd':
            posX++;
            break;
        case 'p':
            destroyContext(context);
            break;
    }
}

int main() {
    hideCursor();
    Context context = initContext(80, 20);

    startGameLoop(update, keyBoard, &context);

    while (context.isValid);
    showCursor();
    return 0;
}
