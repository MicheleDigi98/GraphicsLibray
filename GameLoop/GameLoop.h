//
// Created by Michele Digiacomo on 10/12/2022.
//

#ifndef GRAPHICSLIBRAY_GAMELOOP_H
#define GRAPHICSLIBRAY_GAMELOOP_H

#include "../GUI/Graphics.h"

typedef struct {
    void (*updateFunction)(*Context);
    void (*onPressChange)(char character, char status);
    Context* context;
} GameLoopArgs;

#endif //GRAPHICSLIBRAY_GAMELOOP_H
