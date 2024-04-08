#include <stdio.h>
#include <locale.h> 
#include <math.h> 
#include <string.h> 

#define numAlunos 10

void limpar_Dados(char nomeAlunos[][50], float notas1[], float notas2[], float matriz[][2], int alunos) {
    
    for (int i = 0; i < alunos; i++) {
        nomeAlunos[i][0] = '\0';
    }

    for (int i = 0; i < alunos; i++) {
        notas1[i] = 0.0;
        notas2[i] = 0.0;
    }

    for (int i = 0; i < alunos; i++) {
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = 0.0;
        }
    }
}

void preencher_Nomes_Notas(char nomes[][50], int alunos, float limite[], float derivada[]){
    for (int n=0;n<alunos;n++){
        printf ("Digite o nome do %dº aluno:\n", n+1);
        setbuf(stdin, NULL);
        gets(nomes[n]);
        fflush(stdin);
    }
    
    printf ("\n**Digite as notas dos alunos, siga a mesma ordem\nna qual foi inserido os nomes**\n");
    printf ("\nExtremamente necessário para impressão correta das notas na tabela\n");
    for (int i=0; i < alunos; i++) {
        float nota1;
        do {
            printf ("Nota da prova de limites do %dº aluno (deve estar entre 0 e 10):\n", i+1);
            scanf("%f", &nota1);
            if (nota1 < 0 || nota1 > 10) {
                printf("Nota inválida! Por favor, insira uma nota entre 0 e 10.\n");
            }
        } while (nota1 < 0 || nota1 > 10); // Repete o loop se a nota for inválida
        limite[i] = nota1;
    }

    for (int j=0; j < alunos; j++) {
        float nota2;
        do {
            printf ("Nota da prova de derivada do %dº aluno (deve estar entre 0 e 10):\n", j+1);
            scanf("%f", &nota2);
            if (nota2 < 0 || nota2 > 10) {
                printf("Nota inválida! Por favor, insira uma nota entre 0 e 10.\n");
            }
        } while (nota2 < 0 || nota2 > 10); // Repete o loop se a nota for inválida
        derivada[j] = nota2;
    }
}

void imprimir_Nomes_Notas(char nome[][50], float alunos, float vetor1[], float vetor2[]){
    printf ("\n");
    for (int i=0;i<alunos;i++){
        printf ("%s\t\t%.2f\t%.2f\n", nome[i], vetor1[i], vetor2[i]);
    }
    printf ("\n");
}

void imprimir_Nomes_Notas_Ordem_Crescente(char nome[][50], float notas1[], float notas2[], int alunos) {

    float temp1[numAlunos];
    float temp2[numAlunos];
    char tempNome[numAlunos][50]; 

    for (int i1 = 0; i1 < alunos; i1++) {
        temp1[i1] = notas1[i1];
    }
    for (int i1 = 0; i1 < alunos - 1; i1++) {
        for (int j1 = 0; j1 < alunos - i1 - 1; j1++) {
            if (temp1[j1] > temp1[j1 + 1]) {
                // Trocar as notas da primeira prova
                float tempNota1 = temp1[j1];
                temp1[j1] = temp1[j1 + 1];
                temp1[j1 + 1] = tempNota1;

                char tempNome1[50];
                strcpy(tempNome1, nome[j1]);
                strcpy(nome[j1], nome[j1 + 1]);
                strcpy(nome[j1 + 1], tempNome1);
            }
        }
    }


    for (int i2 = 0; i2 < alunos; i2++) {
        temp2[i2] = notas2[i2];
        strcpy(tempNome[i2], nome[i2]); 
    }
    for (int i2 = 0; i2 < alunos - 1; i2++) {
        for (int j2 = 0; j2 < alunos - i2 - 1; j2++) {
            if (temp2[j2] > temp2[j2 + 1]) {
                // Trocar as notas da segunda prova
                float tempNota2 = temp2[j2];
                temp2[j2] = temp2[j2 + 1];
                temp2[j2 + 1] = tempNota2;

                char tempNome2[50];
                strcpy(tempNome2, tempNome[j2]);
                strcpy(tempNome[j2], tempNome[j2 + 1]);
                strcpy(tempNome[j2 + 1], tempNome2);
            }
        }
    }

    printf("\nNotas da primeira prova em ordem crescente:\n");
    for (int i1 = 0; i1 < alunos; i1++) {
        printf("%s\t%.2f\n", nome[i1], temp1[i1]);
    }

    printf("\nNotas da segunda prova em ordem crescente:\n");
    for (int i2 = 0; i2 < alunos; i2++) {
        printf("%s\t%.2f\n", tempNome[i2], temp2[i2]);
    }
}

float calcular_Mediana(float vetor[], int tamanho) {
    float mediana;
    int meio = tamanho / 2;

    if (tamanho % 2 == 0) {
        mediana = (vetor[meio - 1] + vetor[meio]) / 2.0;
    } else {
        mediana = vetor[meio];
    }

    return mediana;
}

float calcular_Moda(float vetor[], int tamanho) {
    float moda = -1; 
    float frequencia_max = 0; 

    for (int i = 0; i < tamanho; i++) {
        float frequencia = 1;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] == vetor[i]) {
                frequencia++;
            }
        }

        if (frequencia > frequencia_max) {
            moda = vetor[i]; 
            frequencia_max = frequencia; 
        }
    }

    if (frequencia_max == 1) {
        moda = -1;
    }

    return moda;
}

float calcular_Media(float vetor[], int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return soma / tamanho;
}
void Media_Aluno(char nomes[][50], float media[], float n1[], float n2[], int alunos){

    for (int i = 0; i < alunos; i++) {
        media[i]= (n1[i]+n2[i])/2;
    }
    printf ("A média de cada aluno foi:\n");
    for (int j=0;j<alunos;j++){
        printf ("%s \t\t %.2f\n", nomes[j], media[j]);
    }

}

float calcular_Variancia(float vetor[], int tamanho, float media) {
    float variancia = 0;

    for (int i = 0; i < tamanho; i++) {
        variancia += pow(vetor[i] - media, 2);
    }

    return variancia / tamanho;
}

float calcular_DesvioPadrao(float variancia) {
    return sqrt(variancia);
}

void calcular_Resultados(float notas1[], float notas2[], int num_elementos, float resultados[]) {
    resultados[0] = calcular_Moda(notas1, num_elementos);
    resultados[1] = calcular_Moda(notas2, num_elementos);
    resultados[2] = calcular_Media(notas1, num_elementos);
    resultados[3] = calcular_Media(notas2, num_elementos);
    resultados[4] = calcular_Mediana(notas1, num_elementos);
    resultados[5] = calcular_Mediana(notas2, num_elementos);
    resultados[6] = calcular_Variancia(notas1, num_elementos, resultados[2]);
    resultados[7] = calcular_Variancia(notas2, num_elementos, resultados[3]);
    resultados[8] = calcular_DesvioPadrao(resultados[6]);
    resultados[9] = calcular_DesvioPadrao(resultados[7]);
}

float calcular_Prob_Binomial_Passo1(float k, int n){

    float fat1 = 1;
    float fat2 = 1;
    float fat3 = 1;
    float multiplicado = n - k;
    float a;

    for (int i = 0; n > 1; i ++) {

        fat1 *= n;
        n--;
    }

        for (int j = 0; k > 1; j ++) {

            fat2 *= k;
            k--;
        }
            for (int j = 0; multiplicado > 1; j ++) {

                fat3 *= multiplicado;
                multiplicado--;
            }
            a = fat1/(fat2*fat3);
        return a;
}

float calcular_Prob_Binomial_Passo2(float k, float p){

    float base;
    base = p/100;
    float expoente = k;
    float b;

    b = pow(base, expoente);
    return b;

}

float calcular_Prob_Binomial_Passo3(float k, float p, int n){

    float Q;
    Q = 100 - p;
    float Qf = Q/100;
    float expoente = n - k;
    float c;

    c = pow(Qf, expoente);
    return c;
}

void calcular_Prob_Binomial(float sorteados, float P_reprovados, int alunos, float vetor[]) {
    vetor[0] = calcular_Prob_Binomial_Passo1(sorteados, alunos);
    vetor[1] = calcular_Prob_Binomial_Passo2(sorteados, P_reprovados);
    vetor[2] = calcular_Prob_Binomial_Passo3(sorteados, P_reprovados, alunos);
    //printf ("%f\n", vetor[0]);
    //printf ("%f\n", vetor[1]);
    //printf ("%f\n", vetor[2]);
    float probabilidade = vetor[0] * vetor[1] * vetor[2];
    float pFinal = probabilidade*100;
    printf("%.3f%% é a probabilidade de que isso ocorra\n", pFinal);
}

int Posicao_Buscar_Nome(char nomes[][50], int alunos, char nome[]){
    for (int i = 0; i < alunos; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i; // Retorna o índice onde o nome foi encontrado
        }
    }
    return -1; // Retorna -1 se o nome não for encontrado na matriz
}

void Imprimir_Media_Buscado_Aluno (char nomes[][50], float media[], float n1[], float n2[], int alunos, int indice) {
    for (int i = 0; i < alunos; i++) {
        media[i]= (n1[i]+n2[i])/2;
    }
    printf ("\nA média do aluno foi:\n");

    printf ("%s \t %.2f\n", nomes[indice], media[indice]);

}

void menuInterativo() {
    int menu;
    char nomeAlunos[numAlunos][50];
    float notas1[numAlunos], notas2[numAlunos];
    float matriz[10][2];  
    int executouCase1 = 0;
    int alunos = numAlunos;
    float resultados[10]; 
    float Binomial[3];
    float P_reprovados;
    int sorteados;
    float vetorMedia[numAlunos];
    char nomeProcurado[50];
    int posicao;

    do {
        printf("\n");
        printf("[1] - Cadastro das notas dos alunos e impressão da tabela com nomes e notas.\n");
        printf("[2] - Ordenação crescente das notas em uma nova matriz.\n");
        printf("[3] - Cálculo da moda, média, mediana, variância e desvio padrão de cada prova.\n");
        printf("[4] - Resolução de problemas de distribuição pré-definidos.\n");
        printf("[5] - Consulta da nota de um aluno pelo nome.\n");
        printf("[6] - Reiniciar tudo o que foi feito.\n");
        printf("[7] - Encerrar o programa.\n");

        if (scanf("%d", &menu) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            // Limpa o buffer do teclado
            while (getchar() != '\n');

        }

        switch (menu) {
            case 1:
                if (executouCase1 != 1) {
                    preencher_Nomes_Notas(nomeAlunos, numAlunos, notas1, notas2);
                    imprimir_Nomes_Notas(nomeAlunos, numAlunos, notas1, notas2);
                    executouCase1 = 1;
                } else {
                    printf("A funcionalidade já foi executada. Escolha outra opção.\n");
                }
                break;

            case 2:
                if (executouCase1 == 1) {
                    imprimir_Nomes_Notas_Ordem_Crescente(nomeAlunos, notas1, notas2, numAlunos);
                } else {
                    printf("Volte no cadastro das notas para realizar essa funcionalidade.\n");
                }
                break;

            case 3:
                if (executouCase1 == 1) {
                   
                    calcular_Resultados(notas1, notas2, numAlunos, resultados);
                    printf("Moda da prova de limites: %.2f\n", resultados[0]);
                    printf("Moda da prova de derivada: %.2f\n", resultados[1]);
                    printf("Média da prova de limites: %.2f\n", resultados[2]);
                    printf("Média da prova de derivada: %.2f\n", resultados[3]);
                    printf("Mediana da prova de limites: %.2f\n", resultados[4]);
                    printf("Mediana da prova de derivada: %.2f\n", resultados[5]);
                    printf("Variância da prova de limites: %.2f\n", resultados[6]);
                    printf("Variância da prova de derivada: %.2f\n", resultados[7]);
                    printf("Desvio padrão da prova de limites: %.2f\n", resultados[8]);
                    printf("Desvio padrão da prova de derivada: %.2f\n\n", resultados[9]);
                    Media_Aluno(nomeAlunos, vetorMedia, notas1, notas2, numAlunos);
                } 
                
                else {
                    printf("Volte no cadastro das notas para realizar essa funcionalidade.\n");
                }
                break;

            case 4:

                printf ("\nBem-vindo à área na qual o programa irá responder a duas perguntas probabilísticas.\n");

                printf ("\n1º - Um professor de cálculo tem uma turma de 10 alunos, onde normalmente P%% dos alunos \nreprovam. Qual é a probabilidade de que, ao sortear aleatoriamente K alunos, exatamente esses K alunos reprovem?\n");
                printf ("Digite a probabilidade dos alunos reprovarem (P):\n");
                printf ("OBS: por favor, utilize em porcentagem mas não insira o %%\n");
                scanf ("%f", &P_reprovados);
                printf ("Quantidade de alunos sorteados (K):\n");
                scanf ("%d", &sorteados);
                calcular_Prob_Binomial(sorteados, P_reprovados, numAlunos, Binomial);
                break;

            case 5:
                if (executouCase1 == 1) {
                printf ("Digite nome do aluno que você procura:");
                setbuf(stdin, NULL);
                gets(nomeProcurado);
                fflush(stdin);
                posicao = Posicao_Buscar_Nome(nomeAlunos, numAlunos, nomeProcurado);
                printf ("Posição: %d", posicao);
                Imprimir_Media_Buscado_Aluno(nomeAlunos, vetorMedia, notas1, notas2, numAlunos, posicao);

                }
                else {
                    printf("Volte no cadastro das notas para realizar essa funcionalidade.\n");
                }
                break;

            case 6:
                if (executouCase1 == 1) {
                limpar_Dados(nomeAlunos, notas1, notas2, matriz, alunos);
                executouCase1 = 0; // Define que a primeira funcionalidade ainda não foi executada
                printf("Dados reiniciados.\n");
                }

                else {
                    printf ("Não há dados para serem limpos\n");
                }
                break;

            default:
                if (menu != 7)
                    printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }

        while (getchar() != '\n');

    } while (menu!= 7);
}

int main (void) {
    setlocale(LC_ALL, "Portuguese");
    printf ("\n======= Software Estatístico e Probabilístico =======\n\n");
    printf ("\n==== Exemplificação rápida do que representa cada medida estatística presente: ====\n");
    printf ("Moda - É a nota da prova na qual teve mais repetições;\n");
    printf ("Média - É a soma das notas da prova feita pela divisão total dos alunos;\n");
    printf ("Mediana - Notas precisam estar ordenadas de forma crescente. É a nota central (se o total for ímpar) ou\na nota central somada a subsequente dividida por 2 (se o total for par);\n");
    printf ("Variância - É o quão distante cada nota desse conjunto está do valor central (média);\n");
    printf ("Desvio Padrão - É a medida que indica quão uniformes estão as notas do conjunto.\n\n");
    printf ("Você irá entrar no menu de opções\n");
    printf ("Digite 7 para encerrar o programa.\n");
    menuInterativo();

    return 0;
}
