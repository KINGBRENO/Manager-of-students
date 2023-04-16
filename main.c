#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define qntd_alunos 30
#define aulas 36
#define num_notas 4

// Estrutura

typedef struct {
  char nome[100];
  float notas[num_notas];
  float media;
  long int matricula;
  int turma;
  int faltas;
} aluno;

int qntd = 0;
aluno alunos_ordenados[qntd_alunos];
aluno alunos[qntd_alunos];
// Funções secudárias
void ler_alunos(int *qntd, aluno alunos[]);

// Função troca que auxilia na troca dos argumentos para o selection sort
void troca(aluno a[], int pos_max, int pos2) {
  aluno temp;

  strcpy(temp.nome, a[pos_max].nome);
  temp.notas[0] = a[pos_max].notas[0];
  temp.notas[1] = a[pos_max].notas[1];
  temp.notas[2] = a[pos_max].notas[2];
  temp.notas[3] = a[pos_max].notas[3];
  temp.media = a[pos_max].media;
  temp.matricula = a[pos_max].matricula;
  temp.turma = a[pos_max].turma;
  temp.faltas = a[pos_max].faltas;

  strcpy(a[pos_max].nome, a[pos2].nome);
  a[pos_max].notas[0] = a[pos2].notas[0];
  a[pos_max].notas[1] = a[pos2].notas[1];
  a[pos_max].notas[2] = a[pos2].notas[2];
  a[pos_max].notas[3] = a[pos2].notas[3];
  a[pos_max].media = a[pos2].media;
  a[pos_max].matricula = a[pos2].matricula;
  a[pos_max].turma = a[pos2].turma;
  a[pos_max].faltas = a[pos2].faltas;

  strcpy(a[pos2].nome, temp.nome);
  a[pos2].notas[0] = temp.notas[0];
  a[pos2].notas[1] = temp.notas[1];
  a[pos2].notas[2] = temp.notas[2];
  a[pos2].notas[3] = temp.notas[3];
  a[pos2].media = temp.media;
  a[pos2].matricula = temp.matricula;
  a[pos2].turma = temp.turma;
  a[pos2].faltas = temp.faltas;
}

// A Função A seguir selection_sort_matricula e suas variantes
// seletion_sort_notas, selection_sort_faltas ... Servem para Ordenar os dados.
// Falando um pouco sobre a lógica, a função pega os valores armazenados no
// vetor estrutura alunos que são inicializados pela função ler_alunos, e
// armazenam na estrutura alunos_ordenados que serve como cópia(Usei isso, pois
// como eu salvo o arquivo a cada ação, então o arquivo seria ordenado no
// arquivo txt, o que não é a finalidade), a partir disso é usada a lógica
// Selection Sort para ordenar os arquivos depedendo do argumento, sejá por
// nota, faltas ...
void selection_sort_matricula() {
  int i, j;
  int pos_max;
  ler_alunos(&qntd, alunos);

  for (i = 0; i < qntd; i++) {
    alunos_ordenados[i].matricula = alunos[i].matricula;
    alunos_ordenados[i].notas[0] = alunos[i].notas[0];
    alunos_ordenados[i].notas[1] = alunos[i].notas[1];
    alunos_ordenados[i].notas[2] = alunos[i].notas[2];
    alunos_ordenados[i].notas[3] = alunos[i].notas[3];
    alunos_ordenados[i].media = alunos[i].media;
    alunos_ordenados[i].faltas = alunos[i].faltas;
    alunos_ordenados[i].turma = alunos[i].turma;
    strcpy(alunos_ordenados[i].nome, alunos[i].nome);
  }

  int opcao_valida = 1;
  while (opcao_valida) {

    // Aqui utilizo um Switch case, para se caso o Usuário deseja exibir de
    // maneira crescente ou decrescente
    printf("\n1 - Crescente\n2 - Decrescente\n");
    int op;
    scanf("%d", &op);
    switch (op) {
    case 1: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].matricula >
              alunos_ordenados[pos_max].matricula) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    case 2: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].matricula <
              alunos_ordenados[pos_max].matricula) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    default: {
      printf("\nDigite Uma opção Válida!\n");
      opcao_valida = 1;
    } break;
    }
  }
  // Resultado do processamento da ordenação
  printf("\n                 Ordenados Por Matrícula");
  printf("\n______________________________________________________\n");
  for (i = 0; i < qntd; i++) {
    printf("Matricula: %ld Media: %.2f Faltas: %d Turma: %d Nome: %s\n",
           alunos_ordenados[i].matricula, alunos_ordenados[i].media,
           alunos_ordenados[i].faltas, alunos_ordenados[i].turma,
           alunos_ordenados[i].nome);
  }
}
// SEMELHANTE AO QUE FOI EXPLICADO ANTERIORMENTE
void selection_sort_faltas() {
  int i, j;
  int pos_max;
  ler_alunos(&qntd, alunos);

  for (i = 0; i < qntd; i++) {
    alunos_ordenados[i].matricula = alunos[i].matricula;
    alunos_ordenados[i].notas[0] = alunos[i].notas[0];
    alunos_ordenados[i].notas[1] = alunos[i].notas[1];
    alunos_ordenados[i].notas[2] = alunos[i].notas[2];
    alunos_ordenados[i].notas[3] = alunos[i].notas[3];
    alunos_ordenados[i].media = alunos[i].media;
    alunos_ordenados[i].faltas = alunos[i].faltas;
    alunos_ordenados[i].turma = alunos[i].turma;
    strcpy(alunos_ordenados[i].nome, alunos[i].nome);
  }

  int opcao_valida = 1;
  while (opcao_valida) {
    printf("\n1 - Crescente\n2 - Decrescente\n");
    int op;
    scanf("%d", &op);
    switch (op) {
    case 1: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].faltas > alunos_ordenados[pos_max].faltas) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    case 2: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].faltas < alunos_ordenados[pos_max].faltas) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    default: {
      printf("\nDigite Uma opção Válida!\n");
      opcao_valida = 1;
    } break;
    }
  }
  printf("\n                 Ordenados Por Faltas");
  printf("\n______________________________________________________\n");
  for (i = 0; i < qntd; i++) {
    printf("Matricula: %ld Media: %.2f Faltas: %d Turma: %d Nome: %s\n",
           alunos_ordenados[i].matricula, alunos_ordenados[i].media,
           alunos_ordenados[i].faltas, alunos_ordenados[i].turma,
           alunos_ordenados[i].nome);
  }
}
// SEMELHANTE AO QUE FOI EXPLICADO ANTERIORMENTE 2x
void selection_sort_media() {
  int i, j;
  int pos_max;
  ler_alunos(&qntd, alunos);

  for (i = 0; i < qntd; i++) {
    alunos_ordenados[i].matricula = alunos[i].matricula;
    alunos_ordenados[i].notas[0] = alunos[i].notas[0];
    alunos_ordenados[i].notas[1] = alunos[i].notas[1];
    alunos_ordenados[i].notas[2] = alunos[i].notas[2];
    alunos_ordenados[i].notas[3] = alunos[i].notas[3];
    alunos_ordenados[i].media = alunos[i].media;
    alunos_ordenados[i].faltas = alunos[i].faltas;
    alunos_ordenados[i].turma = alunos[i].turma;
    strcpy(alunos_ordenados[i].nome, alunos[i].nome);
  }
  int opcao_valida = 1;
  while (opcao_valida) {
    printf("\n1 - Crescente\n2 - Decrescente\n");
    int op;
    scanf("%d", &op);
    switch (op) {
    case 1: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].media > alunos_ordenados[pos_max].media) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    case 2: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (alunos_ordenados[j].media < alunos_ordenados[pos_max].media) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    default: {
      printf("\nDigite Uma opção Válida!\n");
      opcao_valida = 1;
    } break;
    }
  }
  printf("\n                 Ordenados Por Média");
  printf("\n______________________________________________________\n");

  for (i = 0; i < qntd; i++) {
    printf("Matricula: %ld Media: %.2f Faltas: %d Turma: %d Nome: %s\n",
           alunos_ordenados[i].matricula, alunos_ordenados[i].media,
           alunos_ordenados[i].faltas, alunos_ordenados[i].turma,
           alunos_ordenados[i].nome);
  }
}
// SEMELHANTE AO QUE FOI EXPLICADO ANTERIORMENTE, a Diferença é que como se
// trata da parte dos nomes, tornou-se necessario utilizar a função strcmp para
// comparar, já que as letras tem suas representações inteiras, isso se torna
// possível
void selection_sort_nome() {
  int i, j;
  int pos_max;
  ler_alunos(&qntd, alunos);

  for (i = 0; i < qntd; i++) {
    alunos_ordenados[i].matricula = alunos[i].matricula;
    alunos_ordenados[i].notas[0] = alunos[i].notas[0];
    alunos_ordenados[i].notas[1] = alunos[i].notas[1];
    alunos_ordenados[i].notas[2] = alunos[i].notas[2];
    alunos_ordenados[i].notas[3] = alunos[i].notas[3];
    alunos_ordenados[i].media = alunos[i].media;
    alunos_ordenados[i].faltas = alunos[i].faltas;
    alunos_ordenados[i].turma = alunos[i].turma;
    strcpy(alunos_ordenados[i].nome, alunos[i].nome);
  }

  int opcao_valida = 1;
  while (opcao_valida) {
    printf("\n1 - Crescente\n2 - Decrescente\n");
    int op;
    scanf("%d", &op);
    switch (op) {
    case 1: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (strcmp(alunos_ordenados[j].nome, alunos_ordenados[pos_max].nome) >
              0) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    case 2: {
      for (i = 0; i < qntd - 1; i++) {
        pos_max = 0;
        for (j = 1; j < qntd - i; j++)
          if (strcmp(alunos_ordenados[j].nome, alunos_ordenados[pos_max].nome) <
              0) {
            pos_max = j;
          }
        troca(alunos_ordenados, pos_max, qntd - 1 - i);
      }
      opcao_valida = 0;
    } break;
    default: {
      printf("\nDigite Uma opção Válida!\n");
      opcao_valida = 1;
    } break;
    }
  }
  for (i = 0; i < qntd; i++) {
    printf("Matricula: %ld Media: %.2f Faltas: %d Turma: %d Nome: %s\n",
           alunos_ordenados[i].matricula, alunos_ordenados[i].media,
           alunos_ordenados[i].faltas, alunos_ordenados[i].turma,
           alunos_ordenados[i].nome);
  }
}
// Função Utilizada para o Menu, o qual realiza a chama das funções
// selection_sort apresentadas anteriormente
void menu_selection_sort() {
  system("clear");
  printf("\nMenu De "
         "Ordenação\n__________________________________________________________"
         "___________");
  printf("\n1 - Ordenar Por Matricula \n2 - Ordenar Por Faltas \n3 - Ordenar "
         "Por Média \n4 - Ordenar Por Nome\n");
  int op;
  int opcao_valida = 1;
  while (opcao_valida) {
    scanf("%d", &op);
    switch (op) {
    case 1: {
      selection_sort_matricula();
      opcao_valida = 0;
    } break;
    case 2: {
      selection_sort_faltas();
      opcao_valida = 0;
    } break;
    case 3: {
      selection_sort_media();
      opcao_valida = 0;
    } break;
    case 4: {
      selection_sort_nome();
      opcao_valida = 0;
    } break;
    default: {
      printf("\nDigite Uma Opção Válida!");
    } break;
    }
  }
}
// A função Ler aluno, serve para leitura dos alunos no arquivo, ela utiliza a
// função fopen que, nesse caso, é utilizada para abrir o arquivo para leitura
// ("r"), e a função fscanf que armazena os dados na estrutura alunos,
// natualmente a fclose fecha o arquivo.
void ler_alunos(int *qntd, aluno alunos[]) {
  FILE *arq;
  int i = 0;

  arq = fopen("alunos.txt", "r");

  if (arq == NULL) {
    printf("Não foi possível abrir o arquivo\n");
  } else {
    while (fscanf(arq, "%ld %f %f %f %f %f %d %d %s", &alunos[i].matricula,
                  &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2],
                  &alunos[i].notas[3], &alunos[i].media, &alunos[i].turma,
                  &alunos[i].faltas, &alunos[i].nome[100]) != EOF)
      i++;

    fclose(arq);
  }
  *qntd = i;
}
// Função serve para escrever um novo aluno, recebe o registro de alunos com
// argumento, após isso é aberto o arquivo utilizando a função fopen já
// comentada anteriormente, e utiliza a função fprintf para armazenar os dados
// diretamente no arquivo
void escrever_novo_aluno(aluno cadastrando) {
  FILE *arq;
  arq = fopen("alunos.txt", "a");
  fprintf(arq, "%ld %.2f %.2f %.2f %.2f %.2f %d %d %s", cadastrando.matricula,
          cadastrando.notas[0], cadastrando.notas[1], cadastrando.notas[2],
          cadastrando.notas[3], cadastrando.media, cadastrando.turma,
          cadastrando.faltas, cadastrando.nome);
  fclose(arq);
}

// A função serve para listar os participantes armazenados no arquivo, ela faz a
// chamada da função ler_alunos(comentada anteriormente) e exibe no console
void listar_participantes() {

  int i;

  ler_alunos(&qntd, alunos);

  printf("\nAlunos "
         "cadastrados\n________________________________________________________"
         "_______________________\n");
  for (i = 0; i < qntd; i++) {

    printf("\nMatricula: %ld", alunos[i].matricula);
    printf(" - Nome: %s", alunos[i].nome);
    printf(" - Notas: %.2f %.2f %.2f %.2f", alunos[i].notas[0],
           alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3]);
    printf(" - Turma: %d", alunos[i].turma);
    printf(" - Faltas %d", alunos[i].faltas);
  }
}
// Aqui utiliza um variável cadastrando do tipo registro aluno, para armezenar
// os dados de falta, matricula ..., e para que essa mesma variável seja
// parâmentro da função escrever_novo_aluno, que escreve o aluno no arquivo txt
void cadastrar_aluno() {
  aluno cadastrando;
  char temporaria[100];
  long int matricula;

  ler_alunos(&qntd, alunos);
  int continuar = 1;
  if (qntd > qntd_alunos) {
    printf("Não há espaço!\n");
    continuar = 0;
  } else {
    int condicao = 1;
    while (condicao == 1) {
      printf("Informe a Matricula:");
      scanf("%ld", &matricula);
      getchar();
      // aqui verifica se a matricula está dentro da escala informada
      int opcao;
      if (matricula < 2021000 || matricula > 2021099) {
        system("clear");
        printf("ERRO, Matricula fora de Escala [20210XX,  2021099]\n");
        do {
          printf("Digite uma Opção Válida");
          printf("\nDeseja Continuar?\n1 - Sim\n2 - Não\n");
          scanf("%d", &opcao);
        } while (opcao != 1 && opcao != 2);
        if (opcao == 2) {
          system("clear");
          condicao = 0;
          continuar = 0;
        }
      } else {
        break;
      }
    }
    if (continuar) {
      int i;
      int verifica = 0;

      // Se caso o usuário digite uma matricula igual, aqui é feita a
      // verificação
      for (i = 0; i < qntd; i++) {
        if (matricula == alunos[i].matricula) {
          verifica++;
        }
      }
      if (verifica >= 1) {
        printf("\nJá Existe um Aluno Cadastrado com esta Matricula!");
      } else {
        // Armazena as informações no registro de alunos

        cadastrando.matricula = matricula;
        printf("Informe o nome do Aluno:");
        fgets(cadastrando.nome, 100, stdin);

        int i;

        printf("\nInforme a Turma:");
        scanf("%d", &cadastrando.turma);

        int condicao = 1;
        while (condicao) {
          printf("\nInforme a Nota 1:");
          scanf("%f", &cadastrando.notas[0]);
          if (cadastrando.notas[0] < 0 || cadastrando.notas[0] > 10) {
            printf("ERRO, Nota Fora da Escala [0,10]\n");
            condicao = 1;
          } else {
            break;
          }
        }
        while (condicao) {
          printf("\nInforme a Nota 2:");
          scanf("%f", &cadastrando.notas[1]);
          if (cadastrando.notas[1] < 0 || cadastrando.notas[1] > 10) {
            printf("ERRO, Nota Fora da Escala [0,10]\n");
            condicao = 1;
          } else {
            break;
          }
        }
        while (condicao) {
          printf("\nInforme a Nota 3:");
          scanf("%f", &cadastrando.notas[2]);
          if (cadastrando.notas[2] < 0 || cadastrando.notas[2] > 10) {
            printf("ERRO, Nota Fora da Escala [0,10]\n");
            condicao = 1;
          } else {
            break;
          }
        }
        while (condicao) {
          printf("\nInforme a Nota 4:");
          scanf("%f", &cadastrando.notas[3]);
          if (cadastrando.notas[3] < 0 || cadastrando.notas[3] > 10) {
            printf("ERRO, Nota Fora da Escala [0,10]\n");
            condicao = 1;
          } else {
            break;
          }
        }
        while (condicao) {
          printf("\nInforme as Faltas:");
          scanf("%d", &cadastrando.faltas);
          if (cadastrando.faltas < 0 || cadastrando.faltas > aulas) {
            printf("ERRO, Faltas Fora da Escala [0,36]\n");
            condicao = 1;
          } else {
            break;
          }
        }
        // Para evitar ficar calculando a média separadamente em alguns casos,
        // ela foi armazenada no arquivo txt
        cadastrando.media = (cadastrando.notas[0] + cadastrando.notas[1] +
                             cadastrando.notas[2] + cadastrando.notas[3]) /
                            4;
        // Chamada da função escrever aluno passando o registro como argumento
        escrever_novo_aluno(cadastrando);
        printf("\nNovo Aluno Cadastrado");
      }
    }
  }
}
// Função que tem como entrada uma matricula e busca o aluno correspondente no
// arquivo
void atualiza_valores() {
  aluno cadastrando;

  long int matricula;
  int condicao = 1;
  int opcao;
  int continuar = 1;
  while (condicao) {
    printf("Informe a Matricula:");
    scanf("%ld", &matricula);
    getchar();
    if (matricula < 2021000 || matricula > 2021099) {
      system("clear");
      printf("ERRO, Matricula fora de Escala [20210XX,  2021099]\n");
      do {
        printf("Digite uma Opção Válida");
        printf("\nDeseja Continuar?\n1 - Sim\n2 - Não\n");
        scanf("%d", &opcao);
      } while (opcao != 1 && opcao != 2);
      if (opcao == 2) {
        condicao = 0;
        continuar = 0;
      }
    } else {
      break;
    }
  }

  ler_alunos(&qntd, alunos);
  // Aqui utilizei a variável tam, ela é passada com o valor -1 para indicar que
  // ainda naquele momento o indice do aluno não foi encontrado, se caso ele for
  // encontrado o valor é atualizado e os valores referentes aquele aluno são
  // exibidos do vetor alunos
  if (continuar == 1) {
    int i;
    int indice = -1;
  
    for (i = 0; i < qntd; i++) {
      if (matricula == alunos[i].matricula) {
        indice = i;
      }
    }
    if (indice == -1) {
      system("clear");
      printf("\nAluno Não encontrado!\n");
    } else {
      while (condicao) {
        printf("Informe a Nota 1:");
        scanf("%f", &alunos[indice].notas[0]);
        if (alunos[indice].notas[0] < 0 || alunos[indice].notas[0] > 10) {
          printf("ERRO, Nota Fora da Escala [0,10]\n");
          condicao = 1;
        } else {
          break;
        }
      }
      while (condicao) {
        printf("Informe a Nota 2:");
        scanf("%f", &alunos[indice].notas[1]);
        if (alunos[indice].notas[1] < 0 || alunos[indice].notas[1] > 10) {
          printf("ERRO, Nota Fora da Escala [0,10]\n");
          condicao = 1;
        } else {
          break;
        }
      }
      while (condicao) {
        printf("Informe a Nota 3:");
        scanf("%f", &alunos[indice].notas[2]);
        if (alunos[indice].notas[2] < 0 || alunos[indice].notas[2] > 10) {
          printf("ERRO, Nota Fora da Escala [0,10]\n");
          condicao = 1;
        } else {
          break;
        }
      }
      while (condicao) {
        printf("Informe a Nota 4:");
        scanf("%f", &alunos[indice].notas[3]);
        if (alunos[indice].notas[3] < 0 || alunos[indice].notas[3] > 10) {
          printf("ERRO, Nota Fora da Escala [0,10]\n");
          condicao = 1;
        } else {
          break;
        }
      }
      while (condicao) {
        printf("Informe as Faltas:");
        scanf("%d", &alunos[indice].faltas);
        if (alunos[indice].faltas < 0 || alunos[indice].faltas > aulas) {
          printf("ERRO, Faltas Fora da Escala [0,36]\n");
          condicao = 1;
        } else {
          break;
        }
      }
      while (condicao) {
        printf("Informe a Turma: ");
        scanf("%d", &alunos[indice].turma);
        if (alunos[indice].turma <= 0) {
          printf("ERRO, Turma Nula ou Negativa!!\n");
        } else {
          break;
        }
      }
      alunos[indice].media = (alunos[indice].notas[0] + alunos[indice].notas[1] + alunos[indice].notas[2] + alunos[indice].notas[3]) / num_notas; 
  
      // Fopen aqui é utilizado para a escrita no arquivo, sobreescrevendo o já
      // existente
      system("clear");
      printf("ATUALIZADA COM SUCESSO");
      FILE *arq;
      arq = fopen("alunos.txt", "w");
      for (i = 0; i < qntd; i++) {
        fprintf(arq, "%ld %.2f %.2f %.2f %.2f %.2f %d %d %s \n",
                alunos[i].matricula, alunos[i].notas[0], alunos[i].notas[1],
                alunos[i].notas[2], alunos[i].notas[3], alunos[i].media,
                alunos[i].turma, alunos[i].faltas, alunos[i].nome);
      }
      fclose(arq);
    }
  }
  else {
    system("clear");
  }
}
// Função de remoção do aluno, parecida com a atualiza valores, possuindo apenas
// o diferencial de remover o aluno com a matricula informada da estrutura,
// depois a estrutura é sobreescrita no arquivo
void remove_aluno() {
  long int matricula;

  ler_alunos(&qntd, alunos);
  int condicao = 1;
  int opcao;
  int continuar = 1;
  while (condicao) {
    printf("Informe a Matricula:");
    scanf("%ld", &matricula);
    getchar();
    if (matricula < 2021000 || matricula > 2021099) {
      system("clear");
      printf("ERRO, Matricula fora de Escala [20210XX,  2021099]\n");
      do {
        printf("Digite uma Opção Válida");
        printf("\nDeseja Continuar?\n1 - Sim\n2 - Não\n");
        scanf("%d", &opcao);
      } while (opcao != 1 && opcao != 2);
      if (opcao == 2) {
        condicao = 0;
        continuar = 0;
      }
    } else {
      break;
    }
  }

  
  if (continuar == 1) {
    int i;
    int indice = -1;
    for (i = 0; i < qntd; i++) {
      if (alunos[i].matricula == matricula) {
        indice = i;
      }
    }
    if (indice == -1) {
      system("clear");
      printf("\nAluno não encontrado\n");
    } else {
  
      FILE *arq;
      arq = fopen("alunos.txt", "w");
      for (i = 0; i < qntd; i++) {
        if (i == indice) {
        } else {
          fprintf(arq, "%ld %.2f %.2f %.2f %.2f %.2f %d %d %s \n", alunos[i].matricula,
                  alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2],
                  alunos[i].notas[3], alunos[i].media, alunos[i].turma, alunos[i].faltas,
                  alunos[i].nome);
        }
      }
  
      fclose(arq);
      system("clear");
      printf("ALUNO REMOVIDO COM SUCESSO\n");
      }
    }
  else {
    system("clear");
  }
}
// Exibe os alunos Filtando pela Turma
void exibe_por_turma(int condicao_func) {
  
  int turma_testada;
  int condicao = -1;
  int condicao2 = 1;
  int cabecalho = 0;
  while (condicao2) {
    printf("\nDigite a Turma: ");
    scanf("%d", &turma_testada);
    if (turma_testada <= 0) {
      printf("ERRO, Turma Nula ou Negativa!!\n");
    } else {
      break;
    }
  }

  ler_alunos(&qntd, alunos);
  
  int i;
  for (i = 0; i < qntd; i++) {

    if (turma_testada == alunos[i].turma) {
      if (cabecalho == 0) {
        printf("\nAlunos da Turma "
               "%d\n___________________________________________________________"
               "_____________________\n\n",
               turma_testada);
      }
      cabecalho++;
      if (condicao_func == 1) {
      printf("\nMatricula: %ld - Média: %.2f", alunos[i].matricula,
             alunos[i].media);
      condicao++;
      }
      else {
        printf("\nMatricula: %ld - Notas: %.2f %.2f %.2f %.2f - Faltas: %d", alunos[i].matricula, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3], alunos[i].faltas);
        condicao++;
    }
      
      }
  }
  if (condicao == -1) {
    printf("\nNão há alunos cadastrados nessa turma");
  }
}
// A função lista_aprovados e suas variantes (reprovados_faltas,
// reprovados_frequencia) filtram os alunos em suas respectivas turmas, o que
// varia de uma para outra são os argumentos de comparação dos if
void lista_aprovados() {

  int condicao = 1;
  int turma_testada;
  while (condicao) {
    printf("\nDigite a Turma: ");
    scanf("%d", &turma_testada);
    if (turma_testada <= 0) {
      printf("ERRO, Turma Nula ou Negativa!!\n");
    } else {
      break;
    }
  }

  ler_alunos(&qntd, alunos);

  int i;
  condicao = 0;
  int cabecalho = 0;
  for (i = 0; i < qntd; i++) {
    if (alunos[i].turma == turma_testada) {
      float media;

      float frequencia;

      frequencia = aulas - alunos[i].faltas;
      frequencia = frequencia / aulas;

      if (alunos[i].media >= 7 && frequencia >= 0.60) {
        if (cabecalho == 0) {
          printf("\nAlunos "
                 "Aprovados\n__________________________________________________"
                 "______________________________\n\n");
        }
        cabecalho++;

        printf("\nMatricula: %ld Media: %.2f Frequência: %.2f %%",
               alunos[i].matricula, alunos[i].media, frequencia * 100);
        condicao++;
      }
    }
  }
  if (condicao == 0) {
    printf("\nNão há alunos Aprovados na Turma %d", turma_testada);
  }
}
// Semelhante a função anterior
void reprovados_media() {

  int condicao = 1;
  int turma_testada;
  while (condicao) {
    printf("\nDigite a Turma: ");
    scanf("%d", &turma_testada);
    if (turma_testada <= 0) {
      printf("ERRO, Turma Nula ou Negativa!!\n");
    } else {
      break;
    }
    printf("\n");
  }

  ler_alunos(&qntd, alunos);

  int i;
  condicao = 0;
  int cabecalho = 0;
  for (i = 0; i < qntd; i++) {
    if (alunos[i].turma == turma_testada) {

      if (alunos[i].media < 7) {
        if (cabecalho == 0) {
          printf("\nAlunos Reprovados por "
                 "Média\n______________________________________________________"
                 "__________________________\n\n");
        }
        cabecalho++;
        printf("\nMatricula: %ld Media: %.2f", alunos[i].matricula,
               alunos[i].media);
        condicao++;
      }
    }
  }
  if (condicao == 0) {
    printf("\nNão há alunos reprovados por Média na Turma %d\n", turma_testada);
  }
  printf("\n");
}
// Semelhante a função anterior 2x
void reprovados_falta() {

  int condicao = 1;
  int turma_testada;
  while (condicao) {
    printf("\nDigite a Turma: ");
    scanf("%d", &turma_testada);
    if (turma_testada <= 0) {
      printf("ERRO, Turma Nula ou Negativa!!\n");
    } else {
      break;
    }
  }

  ler_alunos(&qntd, alunos);
  condicao = 0;
  int i;
  int cabecalho = 0;
  for (i = 0; i < qntd; i++) {
    if (alunos[i].turma == turma_testada) {
      float frequencia;

      frequencia = aulas - alunos[i].faltas;
      frequencia = frequencia / aulas;

      if (frequencia < 0.60) {
        if (cabecalho == 0) {
          printf("\nAlunos Reprovados por "
                 "Falta\n______________________________________________________"
                 "__________________________\n\n");
        }
        cabecalho++;
        printf("\nMatricula: %ld Frequência: %.2f %%", alunos[i].matricula,
               frequencia * 100);
        condicao++;
      }
    }
  }
  if (condicao == 0) {
    printf("\nNão há alunos reprovados por falta na Turma %d\n", turma_testada);
  }
  printf("\n");
}

//------------------------------------------------------------------------------------

// função principal

int main(void) {

  int i, j;

  // Estrutura de Repetição

  int sim = 1, opcao_invalida = 1;

  while (sim == 1) {

    // switch case - Menu - Exibe um Menu de Escolhas

    opcao_invalida = 1;

    int opcao;

    long int matricula;
    // Utiliza-se o while para repetição caso o usuário digite uma opção
    // invalida
    while (opcao_invalida == 1) {

      printf("\nMenu de opções\n-----------------------------\nDigite a opção: "
             "\n1 - Cadastre o Aluno\n2 - Remover um Aluno\n3 - Listar alunos cadastrados \n4 - Atualizar Notas, Faltas, e Turma de um "
             "Aluno\n5 - Exibir "
             "Aprovados\n6 - Exibir Reprovados por Média\n7 - Exibir "
             "Reprovados por Falta\n8 - Exibir Alunos Cadastrados por Turma\n9 "
             "- Ordenação dos Dados\n10 - Exibir Todos "
             "Alunos"
             " Cadastrados (EXTRA)\n0 - Sair\n");

      printf("\n");

      scanf("%d", &opcao);

      switch (opcao) {
      case 1: {
        // Cadastrar aluno no vetor
        //  Matricula

        long int matricula;
        aluno alunos;

        cadastrar_aluno();
        opcao_invalida--;
        sim--;

      } break;
      case 2: {

        // Remove um Aluno do vetor
        system("clear");
        remove_aluno();

      } break;

      case 3: {
        // Exibe a lista de alunos cadastrados por Turma
        exibe_por_turma(1);
        opcao_invalida--;
        sim--;
      } break;

      case 4: {
        // Atualizar dados do aluno
        atualiza_valores();
      } break;
      // Exibe os aprovados
      case 5: {
        system("clear");
        lista_aprovados();
        opcao_invalida--;
        sim--;
      } break;
      case 6: {
        // Exibe os reprovados por média
        system("clear");
        reprovados_media();
      } break;
      case 7: {
        // Exibe os reprovados por falta

        system("clear");
        reprovados_falta();
        opcao_invalida--;
        sim--;
      } break;

      case 8: {
        // Exibir por Turma
        system("clear");
        exibe_por_turma(0);

        opcao_invalida--;
        sim--;
      } break;
      case 9: {
        //Menu de Ordenação
        menu_selection_sort();
        opcao_invalida--;
        sim--;
      } break;
        case 10: {
          //Lista Todos os participantes
          system("clear");
          listar_participantes();
          opcao_invalida--;
          sim--;
        } break;
      case 0: {
        // Sair do Programa
        opcao_invalida--;
        sim = sim - 2;
        system("clear");
      } break;

      default: {
        system("clear");
        printf("\nOpção inválida - Tente novamente \n");
        opcao_invalida = 1;
        break;
      }
      }
    }

    while (sim == 0) {
      printf("\n\nDeseja Continuar ?\n1-Sim \n2-Não \n\n");
      scanf("%d", &sim);
      if (sim != 1 && sim != 2) {
        printf("\nOpção inválida\n");
        sim = 0;
      }
    }
    system("clear");
  }
  printf("Encerrado com sucesso");
}