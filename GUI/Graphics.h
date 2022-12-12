//
// Created by Michele Digiacomo on 10/12/2022.
//

#ifndef GRAPHICSLIBRAY_GRAPHICS_H
#define GRAPHICSLIBRAY_GRAPHICS_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define STRING_MAX_LENGTH 101

/**
 * Definisce la struttura che rappresenta il contesto di grafica dell'applicazione
 */
typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char isValid;
    char *screen;
    unsigned short *colorBuffer;
} Context;



/**
 * Converte un numero in una stringa
 * @param number Numero da convertire in stringa
 * @return Restituisce un'array che rappresenta una stringa
 */
char* numberToString(float number);

/**
 * Va nella posizione X, Y del prompt dei comanid
 * @param x Posizione X del prompt
 * @param y Posizione Y del prompt
 */
void gotoXY(unsigned int x, unsigned int y);

/**
 * Genera un colore per il contesto grafico
 * @param red Presenza del colore rosso 0-1
 * @param green Presenza del colore verde 0-1
 * @param blue Presenza del colore blu 0-1
 * @param intensity Presenza di intensità nel colore 0-1
 * @return Restituisce il valore di rappresentazione del colore
 */
unsigned short color(unsigned char red, unsigned char green, unsigned char blue, unsigned char intensity);

/**
 * Nasconde il cursore
 */
void hideCursor();

/**
 * Mostra il cursore
 */
void showCursor();

/**
 * Effettua la pulizia dello schermo
 * @param context Contesto di grafica da pulire
 */
void clearScreen(Context *context);

/**
 * Effettua il calcolo della posizione indicata sulle dimensioni dell'array della matrice
 * @param width Larghezza della matrice
 * @param height Altezza della matrice
 * @param row Riga da identificare
 * @param column Colonna da identificare
 * @return Restituisce l'esito calcolato della posizione
 */
unsigned int calcArrayPosition(unsigned int width, unsigned int row, unsigned int column);

/**
 * Effettua l'inizializzazione del contesto di grafica dell'applicazione
 * @param width Larghezza del contesto
 * @param height Altezza del contesto
 * @return Restituisce l'esito del contesto di grafica
 */
Context initContext(unsigned int width, unsigned int height);

/**
 * Disegna la cornice del contesto
 * @param context Contesto su cui disegnare la cornice
 */
void drawFrame(Context *context);

/**
 * Disegna sullo schermo il contesto di grafica
 * @param context Contesto di grafica da disegnare sul prompt
 */
void drawContext(Context context);

/**
 * Effettua la distruzione del contesto di grafica dell'applicazione
 * @param context Contesto grafico da pulire
 */
void destroyContext(Context *context);

//Primitive di rendering


//Primitive di diesgno

/**
 * Effettua il disegno di un singolo punto sullo schermo
 * @param context Contesto su cui disegnare il punto
 * @param posX Posizione X del punto da disegnare
 * @param posY Posizione Y del punto da disegnare
 * @param character Carattere da disegnare nella posizione indicata
 * @param color Colore del punto da disegnare
 */
void drawPoint(Context *context, int posX, int posY, char character, unsigned short color);

/**
 * Effettua il disegno di un rettangolo sullo schermo
 * @param context Contesto su cui disegnare il rettangolo
 * @param posX Posizione X iniziale del disegtno
 * @param posY Posizione Y iniziale del disegno
 * @param width Larghezza del rettangolo
 * @param height Altezza del rettangolo
 * @param character Carattere di cui il rettangolo è costituito
 * @param color Colore del rettangolo da disegnare
 */
void drawRect(Context *context, int posX, int posY, int width, int height, char character, unsigned short color);

/**
 * Disenga una linea sullo schermo
 * @param context Contesto su cui disegnare il rettangolo
 * @param x1 Prima coordinata x
 * @param y1 Prima coordinata y
 * @param x2 Seconda coordinata x
 * @param y2 Seconda coordinata y
 * @param character Carattere di cui la linea è costituita
 * @param color Colore della linea da disegnare
 */
void drawLine(Context *context, int x1, int y1, int x2, int y2, char character, unsigned short color);

/**
 * Disenga una stringa sullo schermo
 * @param context Contesto su cui disegnare la stringa
 * @param string Stringa da disegnare, con un massimo di 100 caratteri
 * @param x Posizione X di disegno
 * @param y Posizione Y di disegno
 * @param color Colore della stringa da disegnare
 */
void drawString(Context *context, char string[STRING_MAX_LENGTH], int x, int y, unsigned short color);

#endif //GRAPHICSLIBRAY_GRAPHICS_H