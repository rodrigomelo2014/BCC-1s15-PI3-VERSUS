#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "jogo.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_br = NULL;	

int main(void){
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL, *botao_sair = NULL, *botao_jogar = NULL, *botao_opcoes = NULL;
	ALLEGRO_BITMAP *botao_sair_press = NULL, *botao_jogar_press = NULL, *botao_opcoes_press = NULL;
	ALLEGRO_BITMAP *fundo_jogo = NULL;
	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
	int sair = 0, teste = 0, jogar = 0, opcoes = 0;

    // Inicializa a Allegro
    al_init();
 
	// Iniciando os Addons
    al_init_image_addon();
	al_install_mouse();
	al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
 
    // Configura a janela / Eventos
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
	fila_eventos = al_create_event_queue();
 
    // Carrega a imagem
    imagem = al_load_bitmap("imagens/fundo.png");
 	botao_sair = al_load_bitmap("imagens/botaosair.png");
	botao_jogar = al_load_bitmap("imagens/botaojogar.png");
	botao_opcoes = al_load_bitmap("imagens/botaoop.png");
	botao_sair_press = al_load_bitmap("imagens/botaosairpress.png");
	botao_jogar_press = al_load_bitmap("imagens/botaojogarpress.png");
	botao_opcoes_press = al_load_bitmap("imagens/botaooppress.png");
	fundo_jogo = al_load_bitmap("imagens/mapadefender.png");
	// Desenhar abertura do Jogo

	//Falar que os eventos vão vir do Mouse
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

	while(sair == 0){

		ALLEGRO_EVENT evento;

		al_draw_bitmap(imagem, 0, 0, 0);
		al_draw_bitmap(botao_sair, 30, 420, 0);
		al_draw_bitmap(botao_opcoes, 30, 220, 0);
		al_draw_bitmap(botao_jogar, 30, 20, 0);

		al_flip_display();
		al_wait_for_event(fila_eventos, &evento);

		if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

			if(evento.mouse.x >= 30 &&
				evento.mouse.x <= 330 && 
				evento.mouse.y <= ALTURA_TELA - 10 &&
				evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10){
				
				al_draw_bitmap(botao_sair_press, 30, 420, 0);
				al_flip_display();
				al_rest(0.15);
				sair = 1;
			}

			else if(evento.mouse.x >= 30 &&
					evento.mouse.x <= 330 &&
					evento.mouse.y <= ALTURA_TELA - 210 &&
					evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_opcoes) - 210){

				al_draw_bitmap(botao_opcoes_press, 30, 220, 0);
				al_flip_display();
				al_rest(0.15);
				testecam();
			}

			else if(evento.mouse.x >= 30 &&
					evento.mouse.x <= 330 &&
					evento.mouse.y <= ALTURA_TELA - 410 &&
					evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_jogar) - 410){

				al_draw_bitmap(botao_jogar_press, 30, 20, 0);
				al_flip_display();
				al_rest(0.15);
				jogar = 1;
				if(jogar == 1)
					detectacam(janela); 	
			}
		}
	}
    // Finaliza a janela
	al_destroy_bitmap(imagem);	
	al_destroy_bitmap(botao_jogar);	
	al_destroy_bitmap(botao_opcoes);	
	al_destroy_bitmap(botao_sair);	
    al_destroy_event_queue(fila_eventos);
    return 0;
}
