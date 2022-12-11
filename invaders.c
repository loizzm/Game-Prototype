#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>
#include <time.h>
#define TAM_LINK 20
#define count 0
#define PASSO 20
#define Bdist 55
#define avel 2



const float FPS = 60;

const int SCREEN_W = 960;
const int SCREEN_H = 540;
int NAVEG = 1;
int countp=0;
ALLEGRO_FONT *fonte;
ALLEGRO_FONT *fonte1;
ALLEGRO_FONT *vidah;
ALLEGRO_FONT *vidae;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *golpe=NULL;
ALLEGRO_BITMAP *scenario=NULL;
ALLEGRO_BITMAP *batalh1=NULL;
ALLEGRO_BITMAP *inimigo = NULL;
ALLEGRO_BITMAP *rick=NULL;
ALLEGRO_BITMAP *golpem=NULL;
ALLEGRO_BITMAP *p1=NULL, *p10=NULL,*p2=NULL,*p3=NULL,*p4=NULL,*p5=NULL,*p6=NULL,*p7=NULL,*p8=NULL,*p9=NULL;
ALLEGRO_BITMAP  *especial=NULL;
ALLEGRO_BITMAP *instru=NULL;




typedef struct ataque{
	int x;
	int y;
	int dano;
}a;

typedef struct ponto{
	float x;
	float y;
}ponto;

typedef struct enemy{
int nivel;
int vida; 
int x;
int y;
}e;
typedef struct warrior{
int nivel;
int carisma;
int vida; 
int Cx;
int Cy;
//batlha
int acao;
int executar;
int x_bck,y_bck;
int ataque;

}w;



int chegou(int x1)
{
	if (x1 ==40)
	{
		return 1;
	}
	
	return 0;
}
int chegoum(int x1)
{
	if (x1+60 >= SCREEN_W/2)
	{
		return 1;
	}
	
	return 0;
}


float dist(int x1, int y1, int x2, int y2)
{
return sqrt((pow(x1-x2,2)+(pow(y1-y2,2))));
}
void initataquem(a *ataquem)
{
	ataquem->x=65;
	ataquem->y=(SCREEN_H/2)-36;
	
}

void initataque(a *ataque)
{
	ataque->x=SCREEN_W/2-10;
	ataque->y=(SCREEN_H/2)-36;
		
}
	
	

void initmonstro(e *monstro)
{
	
monstro->vida=100;
do{
monstro->x= rand()%SCREEN_W;
monstro->y= rand()%SCREEN_H;
}while (monstro->x >= SCREEN_W-66  || monstro->y >= SCREEN_H-72 || monstro->x >= 780 || monstro->y <=100 );


}

void initglobais()
{
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
     fonte = al_load_font("arial.ttf", 20, 1);   
	if(fonte == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
		
	}
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    fonte1= al_load_font("arial.ttf", 20, 1);
	if(fonte1==NULL){
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
	}
//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
     vidae = al_load_font("arial.ttf", 20, 1);   
	if(vidae == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
		
		
		
     
    }
			
		 
    }
	




void initwarrior(w *link)
{
	srand(time(NULL));

int x,y;
x=rand()%25;

link->vida=100;
link->carisma=x;
link->Cx= 0 ;
link->Cy= SCREEN_H - TAM_LINK;
}
void draw_warrior(w link)
{
	al_draw_filled_rectangle(link.Cx, link.Cy, link.Cx + TAM_LINK,link.Cy + TAM_LINK,
  (al_map_rgb(0,255,0)));
}

void draw_warriorbatalha(w link)
{
	link.Cx= SCREEN_W/2;
	link.Cy= SCREEN_H/2;
	al_draw_filled_rectangle(link.Cx, link.Cy, link.Cx + TAM_LINK,link.Cy + TAM_LINK,
  (al_map_rgb(0,255,0)));
}
void draw_monstro()
{
	al_draw_filled_triangle(60, SCREEN_H/2, 0, (SCREEN_H/2)-30,
   0, (SCREEN_H/2)+30,(al_map_rgb(25, 67, 129)) );
}


void draw_dungeon()
{
al_draw_bitmap(rick,860, 60,0);

}
void draw_scenario(w link)
{
char pontos[20];
sprintf(pontos, "Pontos: %d", countp);

			  
		
		al_draw_bitmap(scenario,0,0,0);


draw_dungeon();
draw_warrior(link);
al_draw_text(vidae, al_map_rgb(0, 255, 0), 310, 40, 0, pontos);



}

int final(w link)
{
if (link.Cx+10==910 && link.Cy+10 ==110)
{
	return 1;
}
}

 void btecla(w *link, int tecla)
 {
link->Cx=link->x_bck;
	 link->Cy=link->y_bck;	
	switch (tecla)
 {
 case ALLEGRO_KEY_LEFT:
 link->acao=1;
 
 break;
  case ALLEGRO_KEY_RIGHT:
 link->acao=1;
 break; 
 
 case ALLEGRO_KEY_UP:
link->acao=1;
 break; 
  case ALLEGRO_KEY_DOWN:
 link->acao=1;
 break;
 
 case ALLEGRO_KEY_ENTER:
 link->executar=1;
 
 }
 }

 
 
 int processaacao(w *link)
{
	
	if (link->executar==1)
	{
		link->executar=0;
		if (link->acao=1)
		{
			link->Cx= link->x_bck;
			link->Cy=link->y_bck;
			
			return 1;
		}
		
	}
	else 
	{
	
return 0;	
	}
	
	
	
	
}
	 
 
 
 
 void navegtecla (w *link, int tecla)
 {
	 
 switch (tecla)
 {
 case ALLEGRO_KEY_LEFT:
 if ( link->Cx > 0 && count < 2)
	 link->Cx -= PASSO;
 
 break;
  case ALLEGRO_KEY_RIGHT:
 if ( link->Cx + TAM_LINK < SCREEN_W && count < 2)
	 link->Cx += PASSO;
 break; 
 
 case ALLEGRO_KEY_UP:
 if ( link->Cy > 0)
	 link->Cy -= PASSO;
 break; 
  case ALLEGRO_KEY_DOWN:
  if ( link->Cy + TAM_LINK < SCREEN_H)
	 link->Cy += PASSO;
 break;
 case 16:
 countp++;
 break;
 
 
 }
 }
 void batalha()
 {
	 
	  
	  al_clear_to_color(al_map_rgb(0, 0, 0));
	  
	   al_draw_bitmap(batalh1,0,0,0);
	   al_draw_filled_rectangle(3*SCREEN_W/4,SCREEN_H/2+100,960,540,
 (al_map_rgb(0,0,0)));
	  al_draw_filled_triangle(900, 420, 840, 450,
   840, 390,(al_map_rgb(255, 255, 255)) );
    al_draw_filled_rectangle(840, 430, 780,410,
 (al_map_rgb(255, 255, 255)) );
	
    draw_monstro();
	al_draw_text(fonte, al_map_rgb(255,255,255),800,500,0,"dar fuga?");

	
   
  
 }
 
 

 
 int Bmonstro(w link,e monstro1,e monstro2, e monstro3,e monstro4, e monstro5,e monstro6,e monstro7)
 {
 if (dist(link.Cx,link.Cy,monstro1.x+33,monstro1.y+36) <= Bdist || dist(link.Cx,link.Cy,monstro2.x+33,monstro2.y+36)<=Bdist || dist(link.Cx,link.Cy,monstro3.x+33,monstro3.y+36) <= Bdist || dist(link.Cx,link.Cy,monstro4.x+33,monstro4.y+36) <= Bdist || dist(link.Cx,link.Cy,monstro5.x+33,monstro5.y+36) <= Bdist || dist(link.Cx,link.Cy,monstro6.x+33,monstro6.y+36) <= Bdist || dist(link.Cx,link.Cy,monstro7.x+33,monstro7.y+36) <= Bdist)
 {
	 return 1;
 }
 
 return 0;
 }

int perdeu(int vida)
{
	if (vida<=0)
	{
	return 1;
	}
	else
	{
		return 0;
	}
}



int berserker()
{
	
	
	return 50+rand()%100;	
	
	
}

int ganhou(int vida)
{
	
	if (vida<=0)
	{
	return 1;
	}
	else
	{
		return 0;
	}
	
}









void draw_bitmaps(e monstro1,e monstro2,e monstro3,e monstro4,e monstro5,e monstro6,e monstro7,e monstro8,e monstro9,e monstro10)
{
	 al_draw_bitmap(p1,monstro1.x,monstro1.y,0);
	  al_draw_bitmap(p2,monstro2.x,monstro2.y,0);
	   al_draw_bitmap(p3,monstro3.x,monstro3.y,0);
	    al_draw_bitmap(p4,monstro4.x,monstro4.y,0);
		 al_draw_bitmap(p5,monstro5.x,monstro5.y,0);
al_draw_bitmap(p6,monstro6.x,monstro6.y,0);
		  al_draw_bitmap(p7,monstro7.x,monstro7.y,0);
		   // al_draw_bitmap(p1,monstro8.x,monstro8.y,0);
			// al_draw_bitmap(p1,monstro9.x,monstro9.y,0);
			 // al_draw_bitmap(p1,monstro10.x,monstro10.y,0);
			  
	  
	
   
}

void campobatalha2(a *ataquem,w *link,a *ataque,e *monstro)
{
	
	int dano1;
	int dano2;
	int dano3;
	dano2= rand()%50;
	if (monstro->vida>0 && link->vida>0)
	{
		//monstro->vida -= dano2;
	al_draw_bitmap(golpem,ataquem->x,ataquem->y,0);
	if (ataquem->x <= (SCREEN_W/2)-50)
	{
		 
			
		ataquem->x += avel;
		  
		al_draw_bitmap(golpem,ataquem->x,ataquem->y,0);
		
		
		
	}
	else
	{
		dano1=rand()%50;
		link->vida -= dano1;
		
		ataquem->x=-1;
		ataque->x= (SCREEN_W/2)-10;
		
	}
	}
}

void draw_ataque(a *ataque,w *link)
{
	
		if (link->vida<=50)
	{
		
		al_draw_bitmap(especial,ataque->x,ataque->y,0);
		
	}
	
		else{
		al_draw_bitmap(golpe,ataque->x,ataque->y,0);
	
	
		}
	
}




int campobatalha(e *monstro1,e *monstro2,e *monstro3,e *monstro4,a *ataque,w *link, a *ataquem)
{
	
	int counta=0;

	srand(time(NULL));
	int dano;
	char life_text[20];
	char life1_text[20];
	 dano= rand()%50;
	sprintf(life_text, "Vida: %d", monstro1->vida);
	al_draw_text(vidae, al_map_rgb(255, 0, 0), 10, 50, 0, life_text);
	sprintf(life1_text, "Vida link: %d", link->vida);
	al_draw_text(vidae, al_map_rgb(255, 0, 0), 310, 50, 0, life1_text);
	
	
	
	


	     
	if (link->vida>0 && monstro1->vida>0)
	{
		
		 
	if (ataque->x>60)
	      {
			  
			  draw_ataque(ataque,link);
	      
		  //printf(" dano= %d\n",dano);
	      ataque->x -=avel;
	      
	      }
	    else{
	    
		 
		 

	      ataque->x=-1;
		  campobatalha2(ataquem,link,ataque,monstro1);
		

		
		
				
		}
		
}


	

	return NAVEG=1;
		
		 
		 
}			

		 
		 



	
	
	
	
			  
			 
	      
		    
	




 

	     

	
	
	
	


	 
 

 
 
 
	
	

 
int main(int argc, char **argv){
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	
	//----------------------- rotinas de inicializacao ---------------------------------------
		
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
    //inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	
	
	//inicializa o modulo que permite carregar imagens no jogo
	if(!al_init_image_addon()){
		fprintf(stderr, "failed to initialize image module!\n");
		return -1;
	}
   
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 
	//cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}
	
	//instala o mouse
	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();

	//inicializa o modulo allegro que entende arquivos tff de fontes
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "failed to load tff font module!\n");
		return -1;
	}
	
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    ALLEGRO_FONT *size_32 = al_load_font("arial.ttf", 32, 1);   
	if(size_32 == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
	}

 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}
   


	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registra na fila os eventos de mouse (ex: clicar em um botao do mouse)
	al_register_event_source(event_queue, al_get_mouse_event_source());  	


	//inicia o temporizador
	al_start_timer(timer);
	e monstro10, monstro1,  monstro2, monstro3, monstro4, monstro5, monstro6, monstro7, monstro8, monstro9;
      int v,p;
	  w link;
	  int dano;
	  a ataque;
	  a ataquem;
	 srand(time(NULL));
	 initataquem(&ataquem);
	  initataque(&ataque);
	  initwarrior(&link);
	  initmonstro(&monstro1);
	  initmonstro(&monstro2);
	  initmonstro(&monstro3);
	  initmonstro(&monstro4);
	  initmonstro(&monstro5);
	  initmonstro(&monstro6);
	  initmonstro(&monstro7);
	   initmonstro(&monstro8);
	    initmonstro(&monstro9);
		 initmonstro(&monstro10);
	  initglobais();
	 
	  
	int playing = 1;
	int count1=0;
	int debug=0;
	
	image=al_load_bitmap("st3.jpg");
		if(!image) {
      fprintf(stderr, "failed to create bird bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
		}	

	inimigo=al_load_bitmap("inimigo.jpg");
	scenario=al_load_bitmap("st.jpg");
		golpe=al_load_bitmap("haduken2.png");
		golpem=al_load_bitmap("haduken1.png");
		batalh1=al_load_bitmap("st1.jpg");
		rick=al_load_bitmap("rick2.png");
		p1=al_load_bitmap("pac2.png");
		p2=al_load_bitmap("pac2.png");
		p3=al_load_bitmap("pac2.png");
		p4=al_load_bitmap("pac2.png");
		p5=al_load_bitmap("pac2.png");
		p6=al_load_bitmap("pac2.png");
		p7=al_load_bitmap("pac2.png");
		instru=al_load_bitmap("instru.png");
		especial=al_load_bitmap("haduken31.png");
		
	while(playing) {
		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		if(ev.type == ALLEGRO_EVENT_TIMER) {


	
		
		


		
			if (NAVEG==1)
			{
				if (count1==0)
				{
		
		
		al_draw_bitmap(image,0,0,0);

//atualiza a tela
al_flip_display();

//pausa a tela por 3.0 segundos
al_rest(4.0);
			al_clear_to_color(al_map_rgb(255, 255, 255));
al_draw_bitmap(instru, 300, 150,0);
			al_flip_display();
			
			al_rest(3.0);
				count1++;
				}
				


			draw_scenario(link);
			
				
	  
	
   
			
			draw_bitmaps(monstro1,monstro2,monstro3,monstro4,monstro5,monstro6,monstro7,monstro8,monstro9,monstro10);
			if (final(link) ==1)
			{
			
			
			v=1;
			playing=0;
			
			}
			
			if (Bmonstro(link,monstro1,monstro2,monstro3,monstro4,monstro5,monstro6,monstro7))
			{
			NAVEG=0;
			}
			}
			if (NAVEG==0)
			{
			
				batalha();
				draw_warriorbatalha(link);
				
			
				NAVEG=1;
			NAVEG=campobatalha( &monstro1,&monstro2,&monstro3,&monstro4,&ataque,&link, &ataquem);
				NAVEG=1;
				NAVEG=processaacao(&link);
				//campobatalha2(&ataquem,&link);

				
				
					
	
				
				 
			
	
				
				
				
				
			}
				
			
			}
			//atualiza a tela (quando houver algo para mostrar)
			al_flip_display();
	
			if(al_get_timer_count(timer)%(int)FPS == 0)
				printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
		
		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}
		//se o tipo de evento for um clique de mouse
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
		}
		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);
			
			if (NAVEG==1)
			{
			navegtecla(&link, ev.keyboard.keycode);
			}
			else
			{
				btecla(&link,ev.keyboard.keycode);
				
				
			}
			
		
		}

	} //fim do while
     char my_text[20];	
		
	//colore toda a tela de preto
	al_clear_to_color(al_map_rgb(0,0,0));
	//imprime o texto armazenado em my_text na posicao x=10,y=10 e com a cor rgb(128,200,30)
	if (v==1)
	{
	sprintf(my_text, "venceu");	
	al_draw_text(size_32, al_map_rgb(15, 200, 30), SCREEN_W/3, SCREEN_H/2, 0, my_text);
	}
	else
	{
		
		sprintf(my_text, "Perdeu");	
	al_draw_text(size_32, al_map_rgb(15, 200, 30), SCREEN_W/3, SCREEN_H/2, 0, my_text);
	}
	
	
	//reinicializa a tela
	al_flip_display();	
    al_rest(3);		   
	//procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
	
	
	al_destroy_bitmap(image);
	al_destroy_bitmap(inimigo);
	al_destroy_bitmap(batalh1);
   al_destroy_bitmap(rick);
   al_destroy_bitmap(p3);
 al_destroy_bitmap(p1);
  al_destroy_bitmap(p2);
 al_destroy_bitmap(p1);
 al_destroy_bitmap(scenario);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
   
 
	return 0;
}
