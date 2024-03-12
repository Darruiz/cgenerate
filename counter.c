#include <stdio.h>
#include <stdlib.h>

int main() {
    int inicio, maximo;


    printf("Digite o numero inicial: ");
    scanf("%d", &inicio);
    printf("Digite o numero maximo: ");
    scanf("%d", &maximo);

    FILE *arquivo;
    arquivo = fopen("numeros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = inicio; i <= maximo; i++) {
        fprintf(arquivo, "%d ", i);
    }

    fclose(arquivo);

    printf("Numeros gerados e armazenados no arquivo numeros.txt.\n");

    return 0;
}
