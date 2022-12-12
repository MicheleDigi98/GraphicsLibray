#include "Graphics/Graphics.h"
#include "GameLoop/GameLoop.h"

//Variabili globali
int posX = 14;              //Indica la posizione X dell'elemento di esempio
int posY = 10;              //Indica la posizione Y dell'elemento di esempio


/**
 * Tutto quello inserito all'interno di questo blocco viene eseguito ogni volta che lo schermo ha terminato di aggiornarsi
 * @param context Contesto grafico di disegno
 */
void update(Context *context){
    //Puliamo lo schermo
    clearScreen(context);

    unsigned short stringColor = color(1, 1, 0, 1);

    drawString(context, "v 1.0 ", 1, 1, stringColor);
    drawString(context, "posX: ", 1, 2, stringColor);
    drawString(context, numberToString(posX), 8, 2, stringColor);
    drawString(context, "posY: ", 1, 3, stringColor);
    drawString(context, numberToString(posY), 8, 3, stringColor);

    int mouseX, mouseY;
    if(mouseXY(&mouseX, &mouseY)){
        drawString(context, "MouseX: ", 1, 4, stringColor);
        drawString(context, numberToString(mouseX), 9, 4, stringColor);

        drawString(context, "MouseY: ", 1, 5, stringColor);
        drawString(context, numberToString(mouseY), 9, 5, stringColor);
    }

    //Il 178 è un carattere ASCII
    unsigned short c = color(1, 0, 0, 1);
    drawPoint(context, mouseX, mouseY, (char)178, c);
}

/**
 * Tutto quello inserito all'interno di questo blocco viene eseguito ogni volta che l'utente preme un tasto da tastiera
 * @param character Tasto premuto da tastiera
 * @param context Contesto grafico di disegno
 */
void keyBoard(char character, Context* context){
    switch (character) {
        case 'w':
            if(posY - 1 > 0)
                posY--;
            break;
        case 's':
            if(posY + 1 < context->height - 1)
                posY++;
            break;
        case 'a':
            if(posX - 1 > 0)
                posX--;
            break;
        case 'd':
            if(posX + 1 < context->width - 1)
                posX++;
            break;
        case 'p':
            //Se viene premuto il tasto p l'esecuzione termina
            destroyContext(context);
            break;
    }
}

/**
 * Entry point di esecuzione, solitamente non viene modificato
 * @return
 */
int main() {
    hideCursor();                                                                       //Nasconde il cursore
    Context context = initContext(80, 20);                                  //Inizializza un contesto di disegno 80*20

    startGameLoop(update, keyBoard, &context);         //Avvia l'esecuzione del gameloop

    //Attende fino a quando l'utente non preme p per terminare l'esecuzioen
    while (context.isValid);
    showCursor();
    return 0;

    /*
     * Alcune funzioni utili:
     * Context initContex(int width, int height) -> Inizializza e restituisce una struttura Context con le dimensioni di larghezza e altezza passate come parametro
     * void destroyContex(Context *context) -> Termina e libera la memoria del contesto. Se ad esso è associato un gameLoop questo termina
     * unsigned short color(unsigned char red, unsigned char green, unsigned char blue, unsigned char intensity) -> Restituisce il valore di un colore
     * void drawPoint(Context *context, int posX, int posY, char character, unsigned short color) -> Disegna un punto sul contesto
     * void drawRect(Context *context, int posX, int posY, int width, int height, char character, unsigned short color) -> Disegna un rettangolo sul contesto
     * void drawLine(Context *context, int x1, int y1, int x2, int y2, char character, unsigned short color)-> Disegna una linea sul contesto
     * void clearScreen(Context *context) -> Effettua la pulizia dello schermo
     * void drawString(Context *context, char string[STRING_MAX_LENGTH], int x, int y, unsigned short color) -> Disegna una stringa sul contesto
     * char* numberToString(float number) -> Converte un numero float in una stringa
     */
}
