#include <stdio.h>
#include "GUI/Graphics.h"
#include <pthread.h>
#include <conio.h>

void* render(void* context){
    Context *ctx = (Context*)context;
    if(context != NULL && ctx->isValid){
        while (ctx->isValid) {
            drawFrame(context);
            drawContext(*ctx);
        }
    }
}

int main() {
    hideCursor();
    Context context = initContext(80, 20);

    drawLine(&context, 1, 10 , 70, 2, 178);

    pthread_t renderThread;
    pthread_create(&renderThread, NULL, render, &context);

    getch();
    destroyContext(&context);
    pthread_join(renderThread, NULL);
    showCursor();
    return 0;
}
