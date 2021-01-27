Projeto final ITP - Simulação epidemiológica(grupo 12)

#Descrição:
  Esse projeto tem como objetivo se utilizar de um Modelo Epidemiológico Computacional(MEC) do tipo SIR (Suscetível-Infectado-Removido) para prever o comportamento de uma certa população reagindo a uma certa doença em função do tempo, através da análise de dados.
  Para a análise dos dados, o código captura frames de certos intervalos de tempo, tendo valor fornecido pelo usuário, para três situações diferentes, contendo informações sobre a população no formato citado anteriormente(SIR), para os cenários 0, 1 e 2, que respectivamente são: um cenário onde não há combate a infecção; um cenário onde depois de um certo intervalo de tempo a população começa a utilizar máscara/distanciamento social(aumentando o tempo necessário para uma pessoa se infectar); um cenário onde os protocolos de atendimento são melhorados(diminuindo o tempo que um infectado demora a se recuperar);
  Os resultados esperados nessa tabela são: Que a população contida nos suscetíveis migre para os infectados e para os removidos ou permaneça em S; Que os infectados aumente até atingir um pico de infectados e depois comece a decair; 
Que os Removidos aumentem com o tempo, já que a tendência é que tanto os suscetíveis, quanto os infectados migrem para esse parâmetro. Ainda podemos dizer que se espera que nos cenários 1 e 2 as curvas de infecção sejam suavizadas.
Alem dos parametros SIR, outro parâmetro calculado será o de mortes.	  
  Para o cálculo dos parâmetro S,I e R, serão utilizados dois parâmetros de comparação com grupos de controle de tempos já decorridos. O grupo b, se refere a facilidade de contágio 
do individuo e o grupo k se refere a probabilidade do individuo se recuperar. Já a curva de morte é calculada sendo a taxa de mortalidade 2%.


#Requisitos para utilizar:
  - O programa foi escrito na linguagem C.
  -inserir na pasta que contém programa um arquivo '.txt' com os seguintes parâmetros, que devem ser escritos com '.' para os decimais e um espaço para separar os valores, respectivamente:
    -Tempo total da simulação em dias.
    -Número de pessoas suscetíveis a infecção no tempo zero.
    -Número total de pessoas já infectadas no tempo zero.
    -Número de pessoas que já estão recuperadas, imunes ou faleceram .
    -Número de pessoas suscetíveis que se infectaram no grupo b de controle em um certo tempo.
    -Tempo total para estimativa do grupo b de controle.
    -Número amostral de pessoas para obter o grupo b de controle.
    -Número de pessoas já infectadas no grupo b de controle.
    -Pessoas recuperadas do grupo k de controle.
    -Total de pessoas do grupo k de controle.
    -Tempo total do estudo k de controle.
    -Intervalo de tempo em que cada frame vai ser calculado.
    -Tempo total para estimativa de um novo grupo b de controle para o cenário do tipo 1.
    -Tempo total para estimativa de um novo grupo k de controle para o cenário do tipo 2.
    -Valor de tempo para adotar as novas medidas dos cenarios 1 e 2.
    -Para compilar o programa, deve-se ir pelo terminal até o diretório com os arquivos .c e .h juntos na mesma pasta e usar o comando : "gcc main.c Frame.c StructEntrada.c -o Projeto". 
    -Depois disso é criado um executável do programa dentro desta pasta e com o mesmo caminho de diretório acessar o executável.
    -Com isso serão gerados três tabelas do tipo CSV nesta pasta.
    observação: existe um arquivo exemplo junto para referência de como escrever tais dados.

#Como gerar os graficos:
  -Para gerar os gráficos, utilizamos um código em python, que vai anexado a pasta que contém os códigos .c e .h.
  -Os arquivos CSV gerados já estão com os nomes corretos para plotar os gráficos.
  -Para que o código reconheça as tabelas, elas precisam estar na mesma pasta do arquivo python.
  -Por ultimo, é necessário somente executar o arquivo python.

#Observações:
  -É válido lembrar que ambas as linguagens de programação usadas devem estar instaladas na máquina que vai ser usada para compilar e executar os códigos.

#Colaboradores:
-Pedro Henrique Dantas de Aragão Mendes , T02 , matricula: 20190003681;
-Lucas da Costa Fontes, T02, matricula: 20180122141;

