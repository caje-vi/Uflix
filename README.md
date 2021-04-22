# Uflix 
**Feito por [Jean Calos Vieira Machado](https://github.com/caje-vi) e [Vinicius Moraes de Jesus](https://github.com/ViniciusMdJ)**

![ERRO](https://github.com/caje-vi/Uflix/blob/main/diagramaUflix.png)
Diagrama de fluxo do trabalho feito

No nosso trabalho nós decidimos carregar e manter todos os dados dos filmes, usuarios e historico em memoria enquanto o programa esta rodando e só ser salvo quando o programa for fechado corretamente, com isso nos decidimos dividir nas seguintes bibliotecas:

### Filmes.h
Ela é quem cuida da parte dos metadados passados do arquivo .csv dos filmes.

### Usuarios.h
Ela é quem cuida dos dados dos usuarios, toda a parte de cadastro, exclusão de contas, manipulação de dados do usuario e contem um ponteiro com o TAD de historico que é feito na proxima biblioteca descrita.

### Historico.h
Ela cuida do historico de filmes assistidos pelo usuario, a ordenaçao dele, adicão de um novo filme e salvamento.

### Utilidades.h
Nós decidimos criar essa biblioteca para colocar funções que nao se encaixavam nas outras bibliotecas ou seriam usada por mais de uma delas e para criar os menus.
