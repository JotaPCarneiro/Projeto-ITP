# Projeto-ITP
O projeto tem como objetivo simular um SGBD, utilizando arquivos .txt, na linguagem C.

--------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------

* O que foi feito?

   + Criação de tabelas, feita com duas opções de criação: ou pelo menu, ou por linha de comando. Ex.: create table,user
   + Listagem de todas as tabelas criadas;
   + Criação de uma nova linha na tabela;
   + Listagem de todos os dados de uma tabela;
   + Apagar valor de uma tabela (não 100%);
   + Apagar uma tabela.

* O que não foi feito?

   + Na parte de criação de linha na tabela, não foi verificada a chave primária;
   + Na parte de listargem de dados de uma tabela, não foi feito uma "centralização" das informações, ou seja, as informações da tabela sairão sem organização (mas funcional).
   + Pesquisar valor em uma tabela. Ainda criei uma função, comecei a pedi as informações, mas na hora da busca, não implementei o código para fazer tal função;
   + Na parte de apagar valor de uma tabela, criei uma tabela auxiliar para armazenar as informações da tabela que peço ao usuário... consigo apagar a linha escolhida, mas não há uma
      atualização dessas informações na tabela que armazena todas as tabelas criadas;
   + O que fiz a mais foi algumas linhas de comando um pouco parecidas com a do SQL.

* O que faria de forma diferente?

   + Bom... para começar, não ter feito esse projeto sozinho. Na próxima, vou tentar fazer novas amizades na turma. haha (Mas sem desculpas para isso);
   + O que eu teria feito de forma diferente era ter usado mais ponteiros. Não fiz o uso muito deles por que eu não consegui absorver bem o conteúdo
      (principalmente na parte de vetores), consegui entender o que são ponteiros, mas na hora de usar, eu ainda travo (acredito que na parte de centralizar as informações 
      da tabela com a ajuda de ponteiros e a função fseek teria resolvido meu problema...);
   + Pedir mais ajuda ao professor. Quando eu fico parado, sem sair do lugar em alguma parte do código, tento resolver até as minhas últimas forças... Isso pode ser um problema,
      pois pode levar muito tempo (também penso que o problema que eu estou com dúvidas pode ser "besta" e preferir pesquisar na internet ou pedir ajuda a amigos).
 
* Como complilar o projeto?

   + Sem segredos, é só compilar. :)
   + No Windows, consigo visualizar todos acentos e pontuações com a ajuda do setlocale(ALL_LC "Portuguese"), mas no Linux não consigo visualiza-lás.

