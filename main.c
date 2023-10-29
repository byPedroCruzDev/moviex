#include <stdio.h>
#include <string.h>

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
typedef struct usuario {
        int id;
        char nome[50];
        char email[50];
        char senha[20];
        int adm;
    } usuario;

int eh_admin(usuario u) {   //funcao que retorna se o usuário eh adm
        return u.adm == 1; 
    }

int main() {
    int resultado = eh_admin(u);
    printf("O usuário é administrador? %d\n", resultado);
    242628
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
    
    
    return 0;
}
    
