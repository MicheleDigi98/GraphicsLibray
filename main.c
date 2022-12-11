#include "GUI/Graphics.h"
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

    drawString(context, "v 1.0 ", 1, 1);
    drawString(context, "posX: ", 1, 2);
    drawString(context, numberToString(posX), 8, 2);
    drawString(context, "posY: ", 1, 3);
    drawString(context, numberToString(posY), 8, 3);

    //Il 178 è un carattere ASCII
    drawPoint(context, posX, posY, (char)178);
}

/**
 * Tutto quello inserito all'interno di questo blocco viene eseguito ogni volta che l'utente preme un tasto da tastiera
 * @param character Tasto premuto da tastiera
 * @param context Contesto grafico di disegno
 */
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

    setColor(1, 1, 0, 1);                                        //Imposta il colore del testo

    startGameLoop(update, keyBoard, &context);         //Avvia l'esecuzione del gameloop

    //Attende fino a quando l'utente non preme p per terminare l'esecuzioen
    while (context.isValid);
    showCursor();
    return 0;

    /*
     * Alcune funzioni utili:
     * Context initContex(int width, int height) -> Inizializza e restituisce una struttura Context con le dimensioni di larghezza e altezza passate come parametro
     * void destroyContex(Context *context) -> Termina e libera la memoria del contesto. Se ad esso è associato un gameLoop questo termina
     * void drawPoint(Context *context, int posX, int posY, char character) -> Disegna un punto sul contesto
     * void drawRect(Context *context, int posX, int posY, int width, int height, char character) -> Disegna un rettangolo sul contesto
     * void drawLine(Context *context, int x1, int y1, int x2, int y2, char character)-> Disegna una linea sul contesto
     * void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char intensity) -> Cambia il colore del cursore per l'intero contesto, valori ammessi per parametro 0 e 1
     * void setBGColor Come sopra ma cambia il colore del background
     * void clearScreen(Context *context) -> Effettua la pulizia dello schermo
     * void drawString(Context *context, char string[STRING_MAX_LENGTH], int x, int y) -> Disegna una stringa sul contesto
     * char* numberToString(float number) -> Converte un numero float in una stringa
     */
}
