//
// Created by Michele Digiacomo on 10/12/2022.
//

#ifndef GRAPHICSLIBRAY_GAMELOOP_H
#define GRAPHICSLIBRAY_GAMELOOP_H

#include "../GUI/Graphics.h"
#include <pthread.h>
#include <conio.h>

/**
 * Rappresenta la struttura di passaggio per i parametri del gameLoop
 */
typedef struct {
    void (*updateFunction)(Context* contesto);
    void (*onPressFunction)(char character, Context* contesto);
    Context* context;
} GameLoopArgs;

/**
 * Avvia l'esecuzione del gameloop. Questo rimarrà in esecuzione fino a quando il contesto è valido
 * @param updateFunction Funzione invocata ad ogni aggiornamento
 * @param onPressChange Funzione invocata quando avviene la pressione di un tasto
 * @param context Contesto di disegno
 */
void startGameLoop(void (*updateFunction)(Context*), void (*onPressFunction)(char character, Context* contesto), Context *context);

#endif //GRAPHICSLIBRAY_GAMELOOP_H
