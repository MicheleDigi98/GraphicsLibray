//
// Created by utente on 10/12/2022.
//

#ifndef GRAPHICSLIBRAY_GRAPHICS_H
#define GRAPHICSLIBRAY_GRAPHICS_H

/**
 * Definisce la struttura che rappresenta il contesto di grafica dell'applicazione
 */
typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char isValid;
    char *screen;
} Context;

/**
 * Avvia la pulizia del prompt che sta eseguendo il programma
 */
void refreshPrompt();

/**
 * Effettua il calcolo della posizione indicata sulle dimensioni dell'array della matrice
 * @param width Larghezza della matrice
 * @param height Altezza della matrice
 * @param row Riga da identificare
 * @param column Colonna da identificare
 * @return Restituisce l'esito calcolato della posizione o -1 nel caso di problemi
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

//Primitive di diesgno

/**
 * Effettua il disegno di un singolo punto sullo schermo
 * @param context Contesto su cui disegnare il punto
 * @param posX Posizione X del punto da disegnare
 * @param posY Posizione Y del punto da disegnare
 * @param character Carattere da disegnare nella posizione indicata
 */
void drawPoint(Context *context, int posX, int posY, char character);

#endif //GRAPHICSLIBRAY_GRAPHICS_H