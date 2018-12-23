/*

Projeto ITP - SGBD
Aluno: Jo�o Paulo Carneiro e Silva

*/

#define MAX 100

typedef struct Tabela {

    char linha[MAX][MAX];         // Armazena strings referente as linhas da tabela.
    char coluna[MAX][MAX];        // Armazena strings referente as colunas da tabela.
    char tabelaNome[MAX];         // Armazena o nome da tabela.
    char aux[MAX][MAX];           // Usado somente na hora de copiar as informa��es da tabela, na hora de apagar a tabela.
    unsigned int chaveP;          // Vari�vel respons�vel por pegar o valor da chave prim�ria (para quest�es de compara��o em outra fun��o).

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
void pesquisaValor();   // Fun��o incompleta, ou seja, n�o especifiquei suas vari�veis.
void apagaValor();      // Fun��o incompleta, ou seja, n�o especifiquei suas vari�veis.
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

+ Func�es e vari�veis usadas:

    + Fun��o main: fun��o principal

        * escolha =  Vari�vel de escolha de op��o para o menu na fun��o principal.



    + Fun��o menu: fun��o respons�vel pela visualiza��o do menu com as op��es de visualizar outro menu ou colocar comandos das a��es.

        * escolhaMenu = Vari�vel que controla o menu de escolha caso a primeira escolha seja um menu com as a��es desejadas.



    +Fun��o confereTabela: fun��o respons�vel pela verifica��o de exist�ncia de tabela. retorna 1 caso a tabela n�o exista.

        * arq: vari�vel(ponteiro) respons�vel pela manipula��o do arquivo.
        * tabela_nome: vari�vel respons�vel por guardar o nome da tabela a ser comparada com o nome recebido por refer�ncia.
        * i: vari�vel respons�vel pelo controle do loop. Esse loop faz com que o fscanf passe por cada nome escrito no arquivo; logo em seguida, a compara��o � feita com a fun��o strcmp().



    + Fun��o criarTabela: respons�vel pela cria��o de uma nova tabela.

        * tabela: vari�vel(ponteiro) respons�vel pelas a��es de cria��o de arquivo .txt.
        * totalDeTabelas: vari�vel(ponteiro) respons�vel pela cria��o de um arquivo .txt que guarda todas as tabelas criadas.
        * nomeAntigo e nomeAntigo2: vari�veis com valores j� determinados, servindo para a troca de nomes do arquivo, com a ajuda das fun��es da biblioteca string.h.
        * i e j: vari�veis de controle do loop, caso seja digitado algum valor inv�lido.



    + Fun��o criarColuna: fun��o respons�vel por criar colunas em uma tabela. Ela recebe como par�metro o nome da tabela que desejamos adicionar a coluna.

        * col: vari�vel(ponteiro) respons�vel pelas a��es no arquivo criado.
        * tabela: vari�vel (struct) respons�vel pelo armazenamento dos valores da coluna e da linha da matriz.
        * nomeColuna: vari�vel que guarda o nome da coluna.
        * i, j e aux: vari�veis de controle do loop, na parte de verifica��o dos valores(se s�o v�lidos ou n�o).
        * k: respons�vel pela mudan�a do �ndice da coluna da matriz.
        * aux2 e i2: vari�veis para ajudar no loop referente ao pedido da chave prim�ria.



    + Fun��o listarTabelas: fun��o respons�vel listar todas as tabelas criadas at� o momento.

        * todasAsTabelas: vari�vel(ponteiro) respons�vel pelas a��es do arquivo.
        * EOF: EOF(End of File) foi usada na hora de imprimir todas as tabelas, ou seja, ler todo o conte�do do arquivo at� o final do arquivo e depois imprimir.



    + Fun��o criarLinha: fun��o respons�vel por criar uma nova linha de informa��o na tabela.

        * arq e arq2: respons�veis pela manipula��o do arquivo, um para leitura e outro para edi��o, respectivamente.
        * tabela: vari�vel struct.
        * i e j: vari�veis de controle.
        * linhas: contador para saber a quantidade de linhas que o arquivo possui.
        * dadosTabela: vari�vel que l� cada caractere do arquivo.
        * dados: vari�vel respons�vel por receber uma string com as informa��es a serem adicionadas na tabela.
        * separa: vari�vel (ponteiro) que separa a string recebida com a ajuda da fun��o strtok.



    + Fun��o mostrarDadosTabela: fun��o respons�vel pela visualiza��o de todos os dados cadastrados na tabela.

        * tabela: vari�vel (struct) para ajudar a armazenar os valores recebidos.
        * tab: vari�vel respons�vel pela manipula��o do arquivo.
        * dadosTabela: vari�vel respons�vel por pegar cada letra (char) para, depois de uma an�lise, com a ajuda da fun��o "fgetc", imprimir os dados.



    + Fun��o apagaTabela: fun��o respons�vel por apagar uma tabela criada.

        * nomeTabela: vari�vel respons�vel por guardar o nome da tabela a ser apagada, com a ajuda da fun��o remove().
        * tabela: vari�vel(ponteiro) respons�vel pela manupula��o do arquivo.
        * listaVelha e listaNova: vari�veis que guardam o nome dos arquivos.
        * tabelaVelha e tabelaNova: respons�veis por manipular o arquivo; leitura e escrita, respectivamente.
        * t: acesso as vari�veis do struct.
        * i: vari�vel de controle.



    + Fun��es com o nome "Comando" no final: essas fun��es s�o, basicamente, uma c�pia das outras fun��es, mudando s� alguns comandos.

*/
