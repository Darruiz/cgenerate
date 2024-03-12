#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000
#define MAX_NUMBERS 1000

int main() {
    char posto[100]; 
    printf("Digite o nome do posto: ");
    scanf("%s", posto);
    
   
    while (getchar() != '\n');

    char entrada[1000];
    int numeros[MAX_NUMBERS]; 
    char url[MAX_URL_LENGTH]; 
    int i = 0;

   
    printf("Digite os numeros separados por espacos: ");
    fgets(entrada, sizeof(entrada), stdin);

    char *token = strtok(entrada, " ");
    while (token != NULL && i < MAX_NUMBERS) {
        numeros[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    FILE *arquivo;
    arquivo = fopen("links.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

 
    for (int j = 0; j < i; j++) {
        snprintf(url, MAX_URL_LENGTH, "https://ttdash.com/views/limpeza-form.php?posto=%s&sala=%d", posto, numeros[j]);
        fprintf(arquivo, "%s\n", url);
    }

    fclose(arquivo);

    printf("Links gerados e armazenados no arquivo links.txt.\n");

    return 0;
}
