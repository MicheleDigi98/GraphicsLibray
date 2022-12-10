#include <stdio.h>
#include "GUI/Graphics.h"

int main() {
    printf("Cosruiamo il contesto di grafica\n");

    Context context = initContext(40, 20);
    //drawFrame(&context);

    drawContext(context);

    destroyContext(&context);
    return 0;
}
