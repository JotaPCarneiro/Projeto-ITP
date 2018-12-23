/*

Projeto ITP - SGBD
Aluno: João Paulo Carneiro e Silva

*/

#define MAX 100

typedef struct Tabela {

    char linha[MAX][MAX];         // Armazena strings referente as linhas da tabela.
    char coluna[MAX][MAX];        // Armazena strings referente as colunas da tabela.
    char tabelaNome[MAX];         // Armazena o nome da tabela.
    char aux[MAX][MAX];           // Usado somente na hora de copiar as informações da tabela, na hora de apagar a tabela.
    unsigned int chaveP;          // Variável responsável por pegar o valor da chave primária (para questões de comparação em outra função).

} Tabela;

typedef struct Comando {

    char comando[MAX][MAX];       // Armazena strings referente aos comandos.

} Comando;

void criarTabela();
void criarColuna(char nomeTabela[MAX]);
void listarTabelas();
int confereTabela(char nomeTabela[MAX]);
void criarLinha();
void mostrarDadosTabela();
void pesquisaValor();   // Função incompleta, ou seja, não especifiquei suas variáveis.
void apagaValor();      // Função incompleta, ou seja, não especifiquei suas variáveis.
void apagaTabela();
void menu();
void criarTabelaComando(char nomeTabela[MAX]);
void listarTabelasComando();
void colunaComando(char nomeTabela[MAX], char comando[MAX], char nomeColuna[MAX]);
void linhaComando(char tabelaNome[MAX]);
void mostrarDadosTabelaComando(char tabelaNome[MAX]);
void apagaTabelaComando(char nomeTabela[MAX]);
void linhaDeComando();

/*

+ MAX: tamanho limite do vetor.

+ Funcões e variáveis usadas:

    + Função main: função principal

        * escolha =  Variável de escolha de opção para o menu na função principal.



    + Função menu: função responsável pela visualização do menu com as opções de visualizar outro menu ou colocar comandos das ações.

        * escolhaMenu = Variável que controla o menu de escolha caso a primeira escolha seja um menu com as ações desejadas.



    +Função confereTabela: função responsável pela verificação de existência de tabela. retorna 1 caso a tabela não exista.

        * arq: variável(ponteiro) responsável pela manipulação do arquivo.
        * tabela_nome: variável responsável por guardar o nome da tabela a ser comparada com o nome recebido por referência.
        * i: variável responsável pelo controle do loop. Esse loop faz com que o fscanf passe por cada nome escrito no arquivo; logo em seguida, a comparação é feita com a função strcmp().



    + Função criarTabela: responsável pela criação de uma nova tabela.

        * tabela: variável(ponteiro) responsável pelas ações de criação de arquivo .txt.
        * totalDeTabelas: variável(ponteiro) responsável pela criação de um arquivo .txt que guarda todas as tabelas criadas.
        * nomeAntigo e nomeAntigo2: variáveis com valores já determinados, servindo para a troca de nomes do arquivo, com a ajuda das funções da biblioteca string.h.
        * i e j: variáveis de controle do loop, caso seja digitado algum valor inválido.



    + Função criarColuna: função responsável por criar colunas em uma tabela. Ela recebe como parâmetro o nome da tabela que desejamos adicionar a coluna.

        * col: variável(ponteiro) responsável pelas ações no arquivo criado.
        * tabela: variável (struct) responsável pelo armazenamento dos valores da coluna e da linha da matriz.
        * nomeColuna: variável que guarda o nome da coluna.
        * i, j e aux: variáveis de controle do loop, na parte de verificação dos valores(se são válidos ou não).
        * k: responsável pela mudança do índice da coluna da matriz.
        * aux2 e i2: variáveis para ajudar no loop referente ao pedido da chave primária.



    + Função listarTabelas: função responsável listar todas as tabelas criadas até o momento.

        * todasAsTabelas: variável(ponteiro) responsável pelas ações do arquivo.
        * EOF: EOF(End of File) foi usada na hora de imprimir todas as tabelas, ou seja, ler todo o conteúdo do arquivo até o final do arquivo e depois imprimir.



    + Função criarLinha: função responsável por criar uma nova linha de informação na tabela.

        * arq e arq2: responsáveis pela manipulação do arquivo, um para leitura e outro para edição, respectivamente.
        * tabela: variável struct.
        * i e j: variáveis de controle.
        * linhas: contador para saber a quantidade de linhas que o arquivo possui.
        * dadosTabela: variável que lê cada caractere do arquivo.
        * dados: variável responsável por receber uma string com as informações a serem adicionadas na tabela.
        * separa: variável (ponteiro) que separa a string recebida com a ajuda da função strtok.



    + Função mostrarDadosTabela: função responsável pela visualização de todos os dados cadastrados na tabela.

        * tabela: variável (struct) para ajudar a armazenar os valores recebidos.
        * tab: variável responsável pela manipulação do arquivo.
        * dadosTabela: variável responsável por pegar cada letra (char) para, depois de uma análise, com a ajuda da função "fgetc", imprimir os dados.



    + Função apagaTabela: função responsável por apagar uma tabela criada.

        * nomeTabela: variável responsável por guardar o nome da tabela a ser apagada, com a ajuda da função remove().
        * tabela: variável(ponteiro) responsável pela manupulação do arquivo.
        * listaVelha e listaNova: variáveis que guardam o nome dos arquivos.
        * tabelaVelha e tabelaNova: responsáveis por manipular o arquivo; leitura e escrita, respectivamente.
        * t: acesso as variáveis do struct.
        * i: variável de controle.



    + Funções com o nome "Comando" no final: essas funções são, basicamente, uma cópia das outras funções, mudando só alguns comandos.

*/
