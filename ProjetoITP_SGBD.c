#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "ProjetoITP_SGBD.h"

void criarTabela() {

    FILE *tab, *totalDeTabelas;
    Tabela tabela;
    char aux[MAX];
    int i = 0, j = 0;

    printf("Digite o nome da tabela que deseja criar: ");
    scanf("%s", tabela.tabelaNome);

    fflush(stdin);

    strcpy(aux, tabela.tabelaNome);

    strcat(tabela.tabelaNome, ".txt");

    if(confereTabela(tabela.tabelaNome) != 0) {

        tab = fopen(tabela.tabelaNome, "w");

        fclose(tab);

        // Armazenamento de todos os nomes criados como tabela:

        totalDeTabelas = fopen("Todas_as_Tabelas.txt", "a");

        if(totalDeTabelas == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            fprintf(totalDeTabelas, "%s\n", aux);

            fclose(totalDeTabelas);

        }

        printf("Tabela \"%s\" criada com sucesso.\n", tabela.tabelaNome);
        printf("Deseja adicionar uma coluna na tabela \"%s\"? (1 - Sim / 2 - N�o) ", tabela.tabelaNome);
        scanf("%i", &i);

        fflush(stdin);

        j = 0;

        while(j == 0) {

            if(i == 1) {

                criarColuna(tabela.tabelaNome);
                j = 1;

            }else if(i == 2) {

                j = 1;

            }else {

                printf("Valor inv�lido. Se deseja adicionar uma coluna na tabela, digite 1 (SIM), caso contr�rio, digite 2 (N�O): ");
                scanf("%i", &i);

                fflush(stdin);

            }

        }

    }else {

        printf("\nJ� existe uma tabela com esse nome.\n");

    }

}

void criarColuna(char nomeTabela[MAX]) {

    FILE *col; // coluna
    Tabela tabela;
    char nomeColuna[MAX];
    int i = 0, j = 0, k = 0, aux = 0, aux2 = 0, i2 = 0;

    tabela.chaveP = 0;

    while(i != 1) {

        printf("Digite o nome da nova coluna: ");
        scanf("%s", nomeColuna);

        fflush(stdin);

        col = fopen(nomeTabela, "a");

        if(col == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            sprintf(tabela.coluna[k], "%s", nomeColuna);

            fprintf(col, "%s                    ", tabela.coluna[k]);

            k++;

            fclose(col);

        }

        if(tabela.chaveP == 0) { // a vari�vel chaveP j� � inicializada com 0.

            printf("A coluna criada ser� a chave prim�ria? (1 - Sim / 2 - N�o) ");
            scanf("%i", &i2);

            fflush(stdin);

            aux2 = 0;

            while(aux2 == 0) {

                if(i2 == 1) {

                    tabela.chaveP = k; //Assim que a vari�vel recebe o valor de k, ele j� n�o faz mais a pergunta de escolha de chave prim�ria.
                    aux2 = 1;

                }else if(i2 == 2) {

                    aux2 = 1;

                }else {

                    printf("Valor inv�lido. Se deseja que essa coluna se torne a chave prim�ria, digite 1 (SIM), caso contr�rio, digite 2 (N�O): ");
                    scanf("%i", &i2);

                    fflush(stdin);

                }

            }

        }

        printf("Deseja adicionar mais uma coluna? (1 - Sim / 2 - N�o) ");
        scanf("%i", &j);

        fflush(stdin);

        aux = 0;

        while(aux == 0) {

            if(j == 1) {

                i = 0;
                aux = 1;

            }else if(j == 2){

                i = 1;
                aux = 1;

            }else {

                printf("Valor inv�lido. Se deseja adicionar mais uma coluna, digite 1 (SIM), caso contr�rio, digite 2 (N�O): ");
                scanf("%i", &j);

                fflush(stdin);

            }

        }

    }

}

void listarTabelas() {

    FILE *todasAsTabelas;
    Tabela tabela;

    printf("\n Todas as tabelas criadas at� o momento:\n\n");

    todasAsTabelas = fopen("Todas_as_Tabelas.txt", "r");

    if(todasAsTabelas == NULL) {

        printf("Erro na abertura do arquivo.\n");

    }else {

        while((fscanf(todasAsTabelas, "%s\n", tabela.tabelaNome)) != EOF){  // Ler e armazenar em tabela.tabelaNome at� n�o chegar no final do arquivo

            printf("%s\n", tabela.tabelaNome);

        }

        fclose(todasAsTabelas);

    }

}

int confereTabela(char nomeTabela[MAX]) {

    FILE *arq;
    char tabela_nome[MAX];
    int i = 0;

    arq = fopen("Todas_as_Tabelas.txt", "a+"); // "a+" - Leitura e escrita (no final), sem criar novo arquivo.

    if(arq == NULL) {

        printf("Erro na abertura do arquivo.\n");

    }else {

        while(i != -1) {

            i = fscanf(arq, "%s", tabela_nome); // Caso n�o encontre, retorna -1 (EOF).
            if(strcmp(strcat(tabela_nome, ".txt"), nomeTabela) == 0) { // Com o stricmp() n�o deu certo. (?)
                                                                      // Lembrando que com esse strcat, temos a jun��o do nome da tabela com a extens�o ".txt",
                return 0;                                            //  pois no arquivo o nome da tabela est� sem extens�o.

            }

        }

        fclose(arq);

    }

    return 1;    // caso retorne esse valor, o nome da tabela n�o � igual.

}

void criarLinha() {

    FILE *arq, *arq2;
    Tabela tabela;
    int i = 0, j = 0, linhas = 1;
    char dados[MAX], dadosTabela, *separa;

    printf("\n  Digite o nome da tabela que voc� deseja adicionar informa��es: ");
    scanf("%s", tabela.tabelaNome);

    fflush(stdin);

    strcat(tabela.tabelaNome, ".txt");

    if(confereTabela(tabela.tabelaNome) == 0) {

        arq = fopen(tabela.tabelaNome, "r");
        arq2 = fopen(tabela.tabelaNome, "a");

        if(arq == NULL || arq2 == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            // S� para informar ao usu�rio quais s�o as colunas que foram criadas.
            printf("\n\n  Colunas adicionadas nessa tabela: ");

            while((dadosTabela = fgetc(arq)) != EOF) {

                if(linhas == 1 && dadosTabela != '\n') { // Imprime s� a primeira linha

                    printf("%c", dadosTabela);

                }

                //Trecho que conta quantas linhas o arquivo possui.
                if(dadosTabela == '\n') {

                    linhas++;

                }

            }

            fprintf(arq2, "%s", "\n"); // Quebra de linha necess�ria, pois caso n�o tenha, o c�digo vai imprimir todo o conte�do em uma linha s� (a primeira).

            printf("\n\n  Digite seus dados(separados por v�rgula), respectivamente: ");
            fgets(dados, MAX, stdin);

            dados[strcspn(dados, "\n")] = 0;

            separa = strtok(dados, ",");

            while(separa != NULL) {

                strcpy(tabela.linha[i], separa);
                separa = strtok(NULL, ",");      // Quando n�o encontra mais o delimitador (,), a vari�vel recebe valor Nulo.

                i++;

            }

            for(j = 0; j < i; j++) {

                fprintf(arq2, "%s                    ", tabela.linha[j]);

            }

            fclose(arq);
            fclose(arq2);

            printf("\n  Dados Adicionados com sucesso!\n");

        }


    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void mostrarDadosTabela() {

    Tabela tabela;
    FILE *tab;
    char dadosTabela;

    printf("\n Digite o nome da tabela que voc� deseja ver os dados: ");
    scanf("%s", tabela.tabelaNome);

    printf("\n");

    fflush(stdin);

    strcat(tabela.tabelaNome, ".txt");

    if(confereTabela(tabela.tabelaNome) == 0) {

        tab = fopen(tabela.tabelaNome, "r");

        if(tab == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            while((dadosTabela = fgetc(tab)) != EOF) {

                if(dadosTabela != '\n') {

                    printf("%c", dadosTabela);

                }else {

                    printf("\n");

                }

            }

            fclose(tab);

        }

        printf("\n\n");

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void pesquisaValor() {    // Incompleto.

    Tabela tabela;
    FILE *tab;
    char dadosTabela, dadosTabelaAux[MAX][MAX], info[MAX];
    int i = 0, linhas = 1, aux = 1;

    printf("\n Digite o nome da tabela que deseja fazer a busca: ");
    scanf("%s", tabela.tabelaNome);

    fflush(stdin);

    if(confereTabela(tabela.tabelaNome) == 0) {

        tab = fopen(tabela.tabelaNome, "r");

        if(tab == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            printf("\n Digite a informa��o que deseja buscar: ");
            fgets(info, MAX, stdin);

            info[strcspn(info, "\n")] = 0;

            printf("\n ");

            while((dadosTabela = fgetc(tab)) != EOF) {

                if(dadosTabela != '\n') {

                    //strcpy(dadosTabelaAux[i], dadosTabela);   ---> O que eu planejava fazer aqui era pegar todos os caracteres de "dadosTabela" e
                    i++;                                        // copiar para o "dadosTabelaAux",  para depois imprimir toda a informa��o da linha
                                                                // caso tivesse alguma informa��o igual a digitada(info).

                    if(strcmp(dadosTabelaAux[i], info) == 0) {  // <--- A compara��o ia ser feita aqui.

                        printf("%c", dadosTabela);

                        aux = 0; // Retorna zero caso a informa��o fosse encontrada. Caso contr�rio, "aux" continua com o valor 1.

                    }

                }

                linhas++;
            }

            if(aux == 1) {

                printf("informa�ao digitada n�o foi encontrada na tabela.\n");

            }

        }

        fclose(tab);

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void apagaValor() {  // Incompleto

    Tabela tabela;
    FILE *tab, *tab2;
    int i = 0, linha = 1, del = 0;
    char dados;

    printf("\n Digite o nome da tabela que deseja apagar uma informa��o: ");
    scanf("%s", tabela.tabelaNome);

    fflush(stdin);

    strcat(tabela.tabelaNome, ".txt");

    if(confereTabela(tabela.tabelaNome) == 0) {

        tab = fopen(tabela.tabelaNome, "r");
        tab2 = fopen("tab_Aux.txt", "a");

        if(tab == NULL && tab2 == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            printf("\n Informa��es contidas na tabela:\n\n");

            while((dados = fgetc(tab)) != EOF) {

                if(dados != '\n') {

                    printf("%c", dados);
                    linha++;

                }else {

                    printf("\n");

                }

            }

            printf("\n\n Qual linha deseja apagar? ");
            scanf("%i", del);

            fflush(stdin);

            while((dados = fgetc(tab)) != EOF) {

                if(dados != '\n' && linha != (del + 1)) {    // "del + 1" porque conta a primeira linha, que seria o nome da coluna.

                    fprintf(tab2, "%c", dados);

                }

            }

            fclose(tab);
            fclose(tab2);

            remove(tabela.tabelaNome);

            rename("tab_Aux.txt", tabela.tabelaNome);

            printf("\n\n Linha apagada com sucesso.\n\n");

        }

    }else {

        printf(" A tabela n�o existe.\n\n");

    }

}

void apagaTabela() {

    char nomeTabela[MAX], nomeAux[MAX], listaVelha[] = "Todas_as_Tabelas.txt", listaNova[] = "NovaLista.txt";
    FILE *tabelaVelha, *tabelaNova;
    Tabela t;
    int i;

    printf("\n Digite o nome da tabela que deseja apagar: ");
    scanf("%s", nomeTabela);

    fflush(stdin);

    strcpy(nomeAux, nomeTabela);

    strcat(nomeTabela, ".txt");

    if(confereTabela(nomeTabela) == 0) {

        remove(nomeTabela);
        printf("\n Tabela removida com sucesso!\n\n");

        tabelaVelha = fopen(listaVelha, "r");
        tabelaNova = fopen(listaNova, "w"); // arquivo que vai armazena a lista de todas as tabelas criadas (atualizado).

        i = 0;

        while(fscanf(tabelaVelha, "%s", t.tabelaNome) != EOF) {

            strcpy(t.aux[i], t.tabelaNome);

            if(strcmp(nomeAux, t.aux[i]) != 0) {

                fprintf(tabelaNova, "%s\n", t.tabelaNome);

            }

        }

        fclose(tabelaVelha);
        fclose(tabelaNova);

        remove(listaVelha);

        rename(listaNova, listaVelha); // "ListaNova.txt" ser� renomeado (ou esperava ser renomeado) para "Todas_as_tabelas.txt".

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void menu() {

    int escolhaMenu;

    printf("\n O que voc� deseja fazer?\n\n  1 - Criar uma tabela.\n  2 - Listar todas as tabelas.\n  3 - Criar uma nova linha na tabela.\n");
    printf("  4 - Listar todos os dados de uma tabela.\n  5 - Pesquisar valor em uma tabela.\n  6 - Apagar valor de uma tabela. \n  7 - Apagar uma tabela.\n  0 - Sair.\n\n -> ");
    scanf("%i", &escolhaMenu);

    fflush(stdin);

    while(escolhaMenu != 0) {

        switch(escolhaMenu) {

            case 1:

                criarTabela();
                // Criar uma nova tabela

                break;

            case 2:

                listarTabelas();
                // Listar todas as tabelas criadas

                break;

            case 3:

                criarLinha();
                //Criar uma nova linha na tabela

                break;

            case 4:

                mostrarDadosTabela();
                //Listar todos os dados de uma tabela

                break;

            case 5:

                pesquisaValor();
                //Pesquisar valor em uma tabela

                break;

            case 6:

                apagaValor();
                //Apagar valor de uma tabela

                break;

            case 7:

                apagaTabela();
                //Apagar uma tabela

                break;

            case 0:

                break;

            default:

                printf("\n Valor inv�lido.\n");

        }

        printf("\n O que voc� deseja fazer?\n\n  1 - Criar uma tabela.\n  2 - Listar todas as tabelas.\n  3 - Criar uma nova linha na tabela.\n");
        printf("  4 - Listar todos os dados de uma tabela.\n  5 - Pesquisar valor em uma tabela.\n  6 - Apagar valor de uma tabela. \n  7 - Apagar uma tabela.\n  0 - Sair.\n\n -> ");
        scanf("%i", &escolhaMenu);

        fflush(stdin);

    }

}

void criarTabelaComando(char nomeTabela[MAX]) {

    FILE *tab, *totalDeTabelas;
    Tabela tabela;
    char aux[MAX];

    strcpy(aux, nomeTabela);

    strcat(nomeTabela, ".txt");

    if(confereTabela(nomeTabela) != 0) {

        tab = fopen(nomeTabela, "w");

        if(tab == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            printf("\n Tabela \"%s\" criada com sucesso! \n", nomeTabela);

            fclose(tab);

            totalDeTabelas = fopen("Todas_as_Tabelas.txt", "a");

            if(totalDeTabelas == NULL) {

                printf("Erro na abertura do arquivo.\n");

            }else {

                fprintf(totalDeTabelas, "%s\n", aux);

                fclose(totalDeTabelas);

            }

        }

    }else {

        printf("Tabela com esse nome j� existente.\n");

    }

}

void colunaComando(char nomeTabela[MAX], char comando[MAX], char nomeColuna[MAX]) {

    Tabela tabela;
    FILE *col;
    int k = 0;

    strcat(nomeTabela, ".txt");

    if(confereTabela(nomeTabela) == 0){

        if(strcmp(comando, "add column") == 0) {

            col = fopen(nomeTabela, "a");

            if(col == NULL) {

                printf("Erro na abertura do arquivo.\n");

            }else {

                sprintf(tabela.coluna[k], "%s", nomeColuna);

                fprintf(col, "%s                    ", tabela.coluna[k]);

                k++;

                fclose(col);

            }

        }else {

            printf("\n Comando de altera��o inv�lido.\n");

        }

    }else {

        printf("\n A tabela n�o exite.\n");

    }

}

void linhaComando(char tabelaNome[MAX]) {

    Tabela tabela;
    FILE *arq, *arq2;
    char dadosTabela, *separa, dados[MAX];
    int i = 0, j = 0, linhas = 1;

    strcat(tabelaNome, ".txt");

    if(confereTabela(tabelaNome) == 0) {

        arq = fopen(tabelaNome, "r");
        arq2 = fopen(tabelaNome, "a");

        if(arq == NULL || arq2 == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            printf("\n\n  Colunas adicionadas nessa tabela: ");

            while((dadosTabela = fgetc(arq)) != EOF) {

                if(linhas == 1 && dadosTabela != '\n') {

                    printf("%c", dadosTabela);

                }

                if(dadosTabela == '\n') {

                    linhas++;

                }

            }

            fprintf(arq2, "%s", "\n");

            printf("\n\n  -> ");            // Digitar os dados, separados por v�rgula.
            fgets(dados, MAX, stdin);

            dados[strcspn(dados, "\n")] = 0;

            separa = strtok(dados, ",");

            while(separa != NULL) {

                strcpy(tabela.linha[i], separa);
                separa = strtok(NULL, ",");

                i++;

            }

            for(j = 0; j < i; j++) {

                fprintf(arq2, "%s                    ", tabela.linha[j]);

            }

            fclose(arq);
            fclose(arq2);

            printf("\n  Dados Adicionados com sucesso!\n");

        }

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void mostrarDadosTabelaComando(char tabelaNome[MAX]) {

    FILE *tab;
    char dadosTabela;

    printf("\n");

    strcat(tabelaNome, ".txt");

    if(confereTabela(tabelaNome) == 0) {

        tab = fopen(tabelaNome, "r");

        if(tab == NULL) {

            printf("Erro na abertura do arquivo.\n");

        }else {

            while((dadosTabela = fgetc(tab)) != EOF) {

                if(dadosTabela != '\n') {

                    printf("%c", dadosTabela);

                }else {

                    printf("\n");

                }

            }

            fclose(tab);

        }

        printf("\n\n");

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void apagaTabelaComando(char nomeTabela[MAX]) {

    char nomeAux[MAX], listaVelha[] = "Todas_as_Tabelas.txt", listaNova[] = "NovaLista.txt";
    FILE *tabelaVelha, *tabelaNova;
    Tabela t;
    int i;

    strcpy(nomeAux, nomeTabela);

    strcat(nomeTabela, ".txt");

    if(confereTabela(nomeTabela) == 0) {

        remove(nomeTabela);
        printf("\n Tabela removida com sucesso!\n\n");

        tabelaVelha = fopen(listaVelha, "r");
        tabelaNova = fopen(listaNova, "w"); // arquivo que vai armazena a lista de todas as tabelas criadas (atualizado).

        i = 0;

        while(fscanf(tabelaVelha, "%s", t.tabelaNome) != EOF) {

            strcpy(t.aux[i], t.tabelaNome);

            if(strcmp(nomeAux, t.aux[i]) != 0) {

                fprintf(tabelaNova, "%s\n", t.tabelaNome);

            }

        }

        fclose(tabelaVelha);
        fclose(tabelaNova);

        remove(listaVelha);

        rename(listaNova, listaVelha); // "ListaNova.txt" ser� renomeado (ou esperava ser renomeado) para "Todas_as_tabelas.txt".

    }else {

        printf("A tabela n�o existe.\n\n");

    }

}

void linhaDeComando() {

    char comando[MAX], comandoAux[MAX], *separa;
    Comando cmd;
    int i = 0;

    printf("\n -> ");
    fgets(comando, MAX, stdin);

    comando[strcspn(comando, "\n")] = 0; // Retira a quebra de linha do fgets com a ajuda da fun��o strcspn.
                                        //  Como a express�o � igual a zero, a vari�vel "comando" vai receber a string at� achar o "\n".
    strcpy(comandoAux, comando);

    while(strcmp(comando, "exit") != 0) {

        separa = strtok(comando, ","); //Com a ajuda da fun��o strtok, separamos cada entrada de string, usando a v�rgula como delimitador.

        i = 0; // Recebe zero para voltar ao �ndice inicial. Caso contr�rio, o vetor acumularia comandos e quando chegasse nos "if's", n�o daria certo, ...
              //  ... smepre seria o mesmo comando.

        while(separa != NULL) {

            strcpy(cmd.comando[i], separa); // copiando cada string que foi separada para a matriz.
            separa = strtok(NULL, ",");
            i++;
        }

        //Como os comandos SQL sempre s�o citados primeiro (espera-se isso), eles sempre v�o ficar na primeira posi��o da matriz.

        if(strcmp(cmd.comando[0], "create table") == 0) { // Ex.: create table,[nome da tabela]

            criarTabelaComando(cmd.comando[1]);

        }else if(strcmp(cmd.comando[0], "show tables") == 0) {

            listarTabelas();

        }else if(strcmp(cmd.comando[0], "delete table") == 0) { // Ex.: drop table,[nome da tabela que deseja apagar].

            apagaTabelaComando(cmd.comando[1]);
                                                                 //               ou add line
        }else if(strcmp(cmd.comando[0], "alter table") == 0) {  //alter table,user,add column,Nome
                                                               //       0       1      2        3
            if(strcmp(cmd.comando[2], "add column") == 0) {

                colunaComando(cmd.comando[1], cmd.comando[2], cmd.comando[3]);

            }else if(strcmp(cmd.comando[2], "add line") == 0) {

                linhaComando(cmd.comando[1]);  // nome da tabela

            }else{

                printf("\n Comando de altera��o inv�lido.\n");

            }

        }else if(strcmp(cmd.comando[0], "select * from") == 0){

            mostrarDadosTabelaComando(cmd.comando[1]);

        }else {

            printf("\n\n Comando inv�lido.\n\n");

        }

        printf("\n -> ");
        fgets(comando, MAX, stdin);

        comando[strcspn(comando, "\n")] = 0;

    }

}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int escolha;

    printf("De qual modo voc� quer acessar o Banco de Dados?\n\n 1 - Atrav�s de linhas de comando SQL.\n 2 - Atrav�s de um menu, informando as a��es desejadas.\n 0 - Encerrar programa.\n");
    printf("\n -> ");
    scanf("%i", &escolha);

    fflush(stdin); // Limpando o fluxo de dados de entrada (do scanf).

    while(escolha != 0) {

        if(escolha == 1) {

            linhaDeComando();

        }else if(escolha == 2) {

            menu();

        }else {

            printf("\nN�mero de op��o inv�lido.\n\n");

        }

        printf("\nDe qual modo voc� quer acessar o Banco de Dados?\n\n 1 - Atrav�s de linhas de comando SQL.\n 2 - Atrav�s de um menu, informando as a��es desejadas.\n 0 - Encerrar programa.\n");
        printf("\n -> ");
        scanf("%i", &escolha);

        fflush(stdin);

    }

    return 0;

}


