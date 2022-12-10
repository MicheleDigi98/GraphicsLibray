#include "GUI/Graphics.h"
#include "GameLoop/GameLoop.h"

//Variabili globali
int posX = 10;              //Indica la posizione X dell'elemento di esempio
int posY = 10;              //Indica la posizione Y dell'elemento di esempio

/**
 * Tutto quello inserito all'interno di questo blocco viene eseguito ogni volta che lo schermo ha terminato di aggiornarsi
 * @param context Contesto grafico di disegno
 */
void update(Context *context){
    //Il 178 è un carattere ASCII
    drawRect(context, posX - 2, posY - 2, 4, 4, 178);
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
     * 1) initContex -> Inizializza e restituisce una struttura Context con le dimensioni di larghezza e altezza passate come parametro
     * 2) destroyContex -> Termina e libera la memoria del contesto. Se ad esso è associato un gameLoop questo termina
     * 3) void drawPoint(Context *context, int posX, int posY, char character) -> Disegna un punto sul contesto
     * 4) void drawRect(Context *context, int posX, int posY, int width, int height, char character) -> Disegna un rettangolo sul contesto
     * 5) void drawLine(Context *context, int x1, int y1, int x2, int y2, char character)-> Disegna una linea sul contesto
     * 6) setColor(red, green, blue, intensity) Con valori ammessi solo 0 e 1 cambia il colore del cursore
     * 7) setBGColor Come sopra ma cambia il colore del background
     */
}
