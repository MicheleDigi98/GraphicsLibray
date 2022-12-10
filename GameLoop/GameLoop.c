//
// Created by Michele Digiacomo on 10/12/2022.
//

#include "GameLoop.h"

/**
 * Questa funzione è accessibile solo da questo documento
 * Questa è la funzione eseguita sul thread di aggiornamento del gameLoop, continua la sua esecuzione fino a quando il contesto risulta essere valido
 * @param gameLoopArgs Argomenti del gameloop
 */
void* gameLoopFunction(void* gameLoopArgs){
    printf("Game loop thread started\n");
    system("cls");
    GameLoopArgs *args = (GameLoopArgs*)gameLoopArgs;
    while (args->context->isValid){
        hideCursor();
        args->updateFunction(args->context);
        drawFrame(args->context);
        drawContext(*args->context);
    }
}

/**
 * Questa funzione è accessibile solo da questo documento
 * Questa è la funzione eseguita sul thread di acquisizione da tastiera del gameloop
 * @param gameLoopArgs Argomenti del gameloop
 */
void* keyboardInputFunction(void *gameLoopArgs){
    printf("Keyboard thread started\n");
    GameLoopArgs *args = (GameLoopArgs*)gameLoopArgs;
    while (args->context->isValid && args->onPressFunction!= NULL){
        char c = (char)getch();
        args->onPressFunction(c, args->context);
    }
}

void startGameLoop(void (*updateFunction)(Context*), void (*onPressFunction)(char character, Context* contesto), Context *context){
    if(updateFunction != NULL && context != NULL && context->isValid){
        updateFunction(context);

        GameLoopArgs* args = (GameLoopArgs*)malloc(sizeof(GameLoopArgs));
        args->updateFunction = updateFunction;
        args->onPressFunction = onPressFunction;
        args->context = context;

        pthread_t gameLoopThread;
        pthread_create(&gameLoopThread, NULL, gameLoopFunction, args);

        pthread_t keyboardThread;
        pthread_create(&keyboardThread, NULL, keyboardInputFunction, args);
    }
}