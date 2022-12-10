//
// Created by utente on 10/12/2022.
//

#include "Graphics.h"
#include <stdlib.h>
#include <stdio.h>

void refreshPrompt(){
    system("cls");
}

unsigned int calcArrayPosition(unsigned int width, unsigned int row, unsigned int column){
    unsigned int esito = -1;
    esito = width * row + column;
    return esito;
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
    if(context.isValid){
        refreshPrompt();

        for(int i = 0; i < context.height; i++){
            for(int j = 0; j < context.width; j++)
                printf("%c", context.screen[calcArrayPosition(context.width, i, j)]);
            //Manda a capo il prompt
            printf("\n");
        }
    }
}