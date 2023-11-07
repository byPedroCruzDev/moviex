#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100

typedef struct {
    int id;
    char titulo[100];
    char genero[50];
    char descricao[200];
    int duracao;
} Filme;

void inicializarBancoDeDados(Filme filmes[10]) {
    Filme filme1 = {1, "O Poderoso Chefão", "Crime", "Um clássico do cinema.", 175};
    Filme filme2 = {2, "Cidadão Kane", "Drama", "Um filme icônico de Orson Welles.", 119};
    Filme filme3 = {3, "Dançando na Chuva", "Musical", "Um musical inesquecível.", 103};
    Filme filme4 = {4, "Pulp Fiction", "Crime", "Dirigido por Quentin Tarantino.", 154};
    Filme filme5 = {5, "Brilho Eterno De Uma Mente sem Lembranças", "Romance", "Uma história única de amor.", 108};
    Filme filme6 = {6, "O Rei Leão", "Animação", "Um clássico da Disney.", 89};
    Filme filme7 = {7, "O Cavaleiro das Trevas", "Ação", "Com o Batman de Christopher Nolan.", 152};
    Filme filme8 = {8, "O Auto da Compadecida", "Comédia", "Baseado na obra de Ariano Suassuna.", 104};
    Filme filme9 = {9, "Tropa de Elite", "Ação", "Sobre o BOPE do Rio de Janeiro.", 115};
    Filme filme10 = {10, "Barbie", "Animação", "Um filme da Barbie.", 90};

    filmes[0] = filme1;
    filmes[1] = filme2;
    filmes[2] = filme3;
    filmes[3] = filme4;
    filmes[4] = filme5;
    filmes[5] = filme6;
    filmes[6] = filme7;
    filmes[7] = filme8;
    filmes[8] = filme9;
    filmes[9] = filme10;
}


Filme* encontrarFilmePorId(Filme filmes[10], int id) {
    for (int i = 0; i < 10; i++) {
        if (filmes[i].id == id) {
            return &filmes[i];
        }
    }
    return NULL;
}

void mostrarNomesDosFilmes(Filme filmes[10]) {
    printf("Escolha um filme pelo ID:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d - %s\n", filmes[i].id, filmes[i].titulo);
    }
}
typedef struct Usuario {
        int id;
        char nome[50];
        char email[50];
        char senha[20];
        bool isAdm;
} usuario;
struct Usuario dbUser[MAX_USERS];
int nUsuarios = 0;


void salvarUsuarios(){
    FILE *file = fopen("usuarios.txt", "w");
    
    if(file == NULL){
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    
    for (int i = 0; i < nUsuarios; i++) {
        fprintf(file, "%d,%s,%s,%s,%d\n", dbUser[i].id, dbUser[i].nome, 
        dbUser[i].email, dbUser[i].senha, dbUser[i].isAdm);
    }
    
    fclose(file);
}



void cadastroUsuarios(){
    printf("-----Insira sua informacoes-----\n");
    if(nUsuarios < MAX_USERS){
        struct Usuario novoUsuario;
        novoUsuario.id = nUsuarios + 1;
        
        printf("Seu nome: ");
        setbuf(stdin, 0);
        fgets(novoUsuario.nome, 50, stdin);
        printf("Seu email: ");
        setbuf(stdin, 0);
        fgets(novoUsuario.email, 50, stdin);
        printf("Sua senha: ");
        setbuf(stdin, 0);
        fgets(novoUsuario.senha, 50, stdin);
        novoUsuario.isAdm = false;
        
       
        
        dbUser[nUsuarios] = novoUsuario;
        

        nUsuarios++;
        salvarUsuarios();
        
        printf("Usuario cadastrado com sucesso!\n");
        
        
        
        
    }else {
        printf("Limite de usuários atingido. Não é possível cadastrar mais usuários.\n");
    }

    
}
void carregarUsuarios() {
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Arquivo de usuários não encontrado. Criando um novo...\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d\n", &dbUser[nUsuarios].id, 
    dbUser[nUsuarios].nome, dbUser[nUsuarios].email, 
    dbUser[nUsuarios].senha, &dbUser[nUsuarios].isAdm) == 5) {
        nUsuarios++;
    }

    fclose(file);
}
int login(struct Usuario usuarioLogado) {
    char email[50], senha[50];

    printf("\nDigite seu Email: ");
    setbuf(stdin, 0);
    fgets(email, 50, stdin);

    printf("\nDigite sua senha: ");
    setbuf(stdin, 0);
    fgets(senha, 50, stdin);

    for (int i = 0; i < nUsuarios; i++) {
        if (strcmp(dbUser[i].email, email) == 0 && strcmp(dbUser[i].senha, senha) == 0) {
            printf("Login bem sucedido!!");
            if (dbUser[i].isAdm == 0)
            {
                printf("mostrar filmes");
            }else{
                printf("mostrar opcoes de adm");
            }
            
            return dbUser[i].id;
        }else{
            printf("Login falhou, verifique email e senha!!");
        }
    }
    return -1;
}

int main() {
    
    int opcoes, nUsuario = 1; 
    struct Usuario usuarioLogado;
    
    printf("Bem-vindo ao sistema de filmes e usuarios!\n");
    
    carregarUsuarios();
    
    printf("Realize um login! Caso nao tenha uma conta voce pode se cadastrar!\n");
    printf("1.Login \n2.Cadastro\n3.Listar ususarios\n");
    scanf( "%d", &opcoes);
    if(opcoes == 1){
        login(usuarioLogado);
    }if(opcoes == 2){
        cadastroUsuarios();
    }if(opcoes = 3){
        carregarUsuarios();
    }else{
        printf("Comando invalido!");
    }
    struct Usuario u;
    
    if(opcoes == 15)
    {
  
    Filme filmes[10];
    inicializarBancoDeDados(filmes);
    
    mostrarNomesDosFilmes(filmes);

    int idDesejado;
    printf("Digite o ID do filme desejado: ");
    scanf("%d", &idDesejado);

    Filme* filmeEncontrado = encontrarFilmePorId(filmes, idDesejado);

    if (filmeEncontrado != NULL) {
        printf("Filme encontrado:\n");
        printf("ID: %d\n", filmeEncontrado->id);
        printf("Título: %s\n", filmeEncontrado->titulo);
        printf("Gênero: %s\n", filmeEncontrado->genero);
        printf("Descrição: %s\n", filmeEncontrado->descricao);
        printf("Duração: %d minutos\n", filmeEncontrado->duracao);
    } else {
        printf("Filme não encontrado.\n");
    }
    }
    
    
    return 0;
}
