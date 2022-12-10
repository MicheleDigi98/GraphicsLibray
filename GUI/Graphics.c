//
// Created by utente on 10/12/2022.
//

#include "Graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void gotoXY(unsigned int x, unsigned int y){
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor(){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void showCursor(){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void refreshPrompt(){
    system("cls");
}

void clearScreen(Context *context){
    if(context != NULL && context->isValid){
        for(int i = 0; i < context->width * context->height; i++)
            context->screen[i] = (char)32;
    }
}

unsigned int calcArrayPosition(unsigned int width, unsigned int row, unsigned int column){
    return width * row + column;
}

Context initContext(unsigned int width, unsigned int height){
    Context esito;

    esito.width = width;
    esito.height = height;
    esito.isValid = 0;

    unsigned bufferSize = width * height * sizeof(char);
    esito.screen = (char*)malloc(bufferSize);

    //Calcolo della validità del contesto
    esito.isValid = esito.screen == NULL ? 0 : 1;

    if(esito.isValid){
        //Inizializziamo i valori dello schermo
        for(int i = 0; i < width * height; i++)
            esito.screen[i] = 32;
    }

    return esito;
}

void drawFrame(Context *context){
    if(context->isValid){
        //Disegnamo la cornice del contesto di grafica
        for(int i = 0; i < context->height; i++){
            for(int j = 0; j < context->width; j++){
                unsigned int arrayPosition = calcArrayPosition(context->width, i, j);

                //Costruzione delle righe verticali e orizzontali
                if(i == 0 || i == context->height - 1)
                    context->screen[arrayPosition] = (char)205;
                if(j == 0 || j == context->width - 1)
                    context->screen[arrayPosition] = (char)186;

                //Costruzione degli angoli
                if(i == 0 && j == 0)
                    context->screen[arrayPosition] = (char)201;
                if(i == 0 && j == context->width - 1)
                    context->screen[arrayPosition] = (char)187;
                if(i == context->height - 1 && j == 0)
                    context->screen[arrayPosition] = (char)200;
                if(i == context->height - 1 && j == context->width - 1)
                    context->screen[arrayPosition] = (char)188;
            }
        }
    }
}

void destroyContext(Context *context){
    if(context != NULL && context->isValid) {
        context->isValid = 0;
        free(context->screen);
    }
}

void drawContext(Context context){
    gotoXY(0, 0);
    if(context.isValid){
        for(int i = 0; i < context.height; i++){
            for(int j = 0; j < context.width; j++)
                printf("%c", context.screen[calcArrayPosition(context.width, i, j)]);
            //Manda a capo il prompt
            printf("\n");
        }
    }
}

void drawPoint(Context *context, int posX, int posY, char character){
    if(context != NULL && context->isValid){
        if(posX >= 0 && posX < context->width - 1 && posY >= 0 && posY < context->height - 1){
            //Controlla la validità delle coordinate di punto

            unsigned int arrayPosition = calcArrayPosition(context->width, posY, posX);
            context->screen[arrayPosition] = character;
        }
    }
}

void drawRect(Context *context, int posX, int posY, int width, int height, char character){
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            drawPoint(context, posX + j, posY + i, character);
}

void drawLine(Context *context, int x1, int y1, int x2, int y2, char character){
    //Implementiamo la linea usando il dda

    //Calcoliamo le distanze tra i due punti
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;

    int absDeltaX = abs(deltaX);
    int absDeltaY = abs(deltaY);

    int steps = absDeltaX > absDeltaY ? absDeltaX : absDeltaY;

    float incX = (float)deltaX / (float)steps;
    float incY = (float)deltaY / (float)steps;

    float startX = (float)x1;
    float startY = (float)y1;

    for(int i = 0; i < steps; i++){
        startX += incX;
        startY += incY;
        drawPoint(context, (int)startX, (int)startY, character);
    }
}