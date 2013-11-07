#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main(){
	//Cargar ventana renderizada
	RenderWindow App(VideoMode(600,500,32),"Role&Music v1.0.0");
	//Objetos que contendran las imagenes (Graficos) de nuestra aplicacion
	Texture BG, Play1, Play2, Play3, Play4, Stop1, Stop2, Stop3, Stop4, Label1, Label2, Label3, Label4, Volume1, Volume2, Volume3, Volume4;
	//Objetos que contendran la musica
	Music M1,M2,M3,M4;
	//Carga de la fuente del texto
	Font fonts;
	fonts.loadFromFile("Fonts/font.ttf");
	//Carga de los textos
	//Texto titulo
	Text text1;
	text1.setPosition(320,450);
	text1.setFont(fonts);
	text1.setString("Role&Music v1.0.0");
	text1.setCharacterSize(40);
	text1.setColor(Color::Red);
	//Texto instrucciones
	Text text2;
	text2.setFont(fonts);
	text2.setString(" Cliquee encima del espacio para escritura, cuando se marque el recuadro,\n escriba el nombre de la cancion deseada acabado en .wav o .ogg,\n la cancion debe estar en formato .wav o .ogg para su correcta\n reproduccion. Por ultimo, pulse enter para cargar la cancion.");
	text2.setCharacterSize(20);
	text2.setColor(Color::Black);
	//Carga de imagenes en los objetos anteriores
	BG.loadFromFile("Images/Background.bmp");
	//Carga botones Play Stop
	Play1.loadFromFile("Images/Play.png");
	Stop1.loadFromFile("Images/Stop.png");
	Play2.loadFromFile("Images/Play.png");
	Stop2.loadFromFile("Images/Stop.png");
	Play3.loadFromFile("Images/Play.png");
	Stop3.loadFromFile("Images/Stop.png");
	Play4.loadFromFile("Images/Play.png");
	Stop4.loadFromFile("Images/Stop.png");
	//Carga de Texturas Labels
	Label1.loadFromFile("Images/Label.png");
	Label2.loadFromFile("Images/Label.png");
	Label3.loadFromFile("Images/Label.png");
	Label4.loadFromFile("Images/Label.png");
	//Creacion de Sprites
	Sprite Background(BG);
	//Sprites de botones Play y Stop
	Sprite Play1_;
	Play1_.setTexture(Play1);
	Sprite Stop1_;
	Stop1_.setTexture(Stop1);
	Sprite Play2_;
	Play2_.setTexture(Play2);
	Sprite Stop2_;
	Stop2_.setTexture(Stop2);
	Sprite Play3_;
	Play3_.setTexture(Play3);
	Sprite Stop3_;
	Stop3_.setTexture(Stop3);
	Sprite Play4_;
	Play4_.setTexture(Play4);
	Sprite Stop4_;
	Stop4_.setTexture(Stop4);
	//Sprites de los Labels
	Sprite Label1_;
	Label1_.setTexture(Label1);
	Sprite Label2_;
	Label2_.setTexture(Label2);
	Sprite Label3_;
	Label3_.setTexture(Label3);
	Sprite Label4_;
	Label4_.setTexture(Label4);
	//Carga de la musica
	M1.openFromFile("Samples/1.wav");
	M2.openFromFile("Samples/2.wav");
	M3.openFromFile("Samples/3.wav");
	M4.openFromFile("Samples/4.wav");
	//Lazo que mantendra la ventana abierta hasta que sea cerrada.
	while(App.isOpen()){
		Event Evento;
		while(App.pollEvent(Evento)){
			if(Evento.type==Event::Closed){
				App.close();
			}
			/*if(App.getInput().isKeyDown(Key::W)){
				M1.setLoop(true);
				M1.play();
			}*/
			//Botones Graficos
			if(Evento.type == Event::MouseButtonPressed){
				//Eventos con boton izquierdo de raton
				if(Evento.mouseButton.button == sf::Mouse::Left){
					if((Evento.mouseButton.x > Play1_.getPosition().x && Evento.mouseButton.x <= Play1_.getPosition().x+50)&&(Evento.mouseButton.y > Play1_.getPosition().y && Evento.mouseButton.y <= Play1_.getPosition().y+40)){
						M1.play();
					}
					if((Evento.mouseButton.x > Stop1_.getPosition().x && Evento.mouseButton.x <= Stop1_.getPosition().x+50)&&(Evento.mouseButton.y > Stop1_.getPosition().y && Evento.mouseButton.y <= Stop1_.getPosition().y+40)){
						M1.stop();
					}
					if((Evento.mouseButton.x > Play2_.getPosition().x && Evento.mouseButton.x <= Play2_.getPosition().x+50)&&(Evento.mouseButton.y > Play2_.getPosition().y && Evento.mouseButton.y <= Play2_.getPosition().y+40)){
						M2.play();
					}
					if((Evento.mouseButton.x > Stop2_.getPosition().x && Evento.mouseButton.x <= Stop2_.getPosition().x+50)&&(Evento.mouseButton.y > Stop2_.getPosition().y && Evento.mouseButton.y <= Stop2_.getPosition().y+40)){
						M2.stop();
					}
					if((Evento.mouseButton.x > Play3_.getPosition().x && Evento.mouseButton.x <= Play3_.getPosition().x+50)&&(Evento.mouseButton.y > Play3_.getPosition().y && Evento.mouseButton.y <= Play3_.getPosition().y+40)){
						M3.play();
					}
					if((Evento.mouseButton.x > Stop3_.getPosition().x && Evento.mouseButton.x <= Stop3_.getPosition().x+50)&&(Evento.mouseButton.y > Stop3_.getPosition().y && Evento.mouseButton.y <= Stop3_.getPosition().y+40)){
						M3.stop();
					}
					if((Evento.mouseButton.x > Play4_.getPosition().x && Evento.mouseButton.x <= Play4_.getPosition().x+50)&&(Evento.mouseButton.y > Play4_.getPosition().y && Evento.mouseButton.y <= Play4_.getPosition().y+40)){
						M4.play();
					}
					if((Evento.mouseButton.x > Stop4_.getPosition().x && Evento.mouseButton.x <= Stop4_.getPosition().x+50)&&(Evento.mouseButton.y > Stop4_.getPosition().y && Evento.mouseButton.y <= Stop4_.getPosition().y+40)){
						M4.stop();
					}
				}
				//Eventos con boton derecho del raton
				if(Evento.mouseButton.button == sf::Mouse::Right){
					if((Evento.mouseButton.x > Play1_.getPosition().x && Evento.mouseButton.x <= Play1_.getPosition().x+50)&&(Evento.mouseButton.y > Play1_.getPosition().y && Evento.mouseButton.y <= Play1_.getPosition().y+40)){
						M1.setLoop(true);
						M1.play();
					}
					if((Evento.mouseButton.x > Play2_.getPosition().x && Evento.mouseButton.x <= Play2_.getPosition().x+50)&&(Evento.mouseButton.y > Play2_.getPosition().y && Evento.mouseButton.y <= Play2_.getPosition().y+40)){
						M2.setLoop(true);
						M2.play();
					}
					if((Evento.mouseButton.x > Play3_.getPosition().x && Evento.mouseButton.x <= Play3_.getPosition().x+50)&&(Evento.mouseButton.y > Play3_.getPosition().y && Evento.mouseButton.y <= Play3_.getPosition().y+40)){
						M3.setLoop(true);
						M3.play();
					}
					if((Evento.mouseButton.x > Play4_.getPosition().x && Evento.mouseButton.x <= Play4_.getPosition().x+50)&&(Evento.mouseButton.y > Play4_.getPosition().y && Evento.mouseButton.y <= Play4_.getPosition().y+40)){
						M4.setLoop(true);
						M4.play();
					}
				}
			}
		}
		//Limpieza de pantalla
		App.clear();
		//Actualizacion:
		Play1_.setPosition(400,150);
		Stop1_.setPosition(455,150);
		Play2_.setPosition(400,195);
		Stop2_.setPosition(455,195);
		Play3_.setPosition(400,240);
		Stop3_.setPosition(455,240);
		Play4_.setPosition(400,285);
		Stop4_.setPosition(455,285);
		Label1_.setPosition(45,150);
		Label2_.setPosition(45,195);
		Label3_.setPosition(45,240);
		Label4_.setPosition(45,285);
		//Carga de graficos
		App.draw(Background);
		App.draw(Play1_);
		App.draw(Stop1_);
		App.draw(Play2_);
		App.draw(Stop2_);
		App.draw(Play3_);
		App.draw(Stop3_);
		App.draw(Play4_);
		App.draw(Stop4_);
		App.draw(text1);
		App.draw(text2);
		App.draw(Label1_);
		App.draw(Label2_);
		App.draw(Label3_);
		App.draw(Label4_);
		//Muestra la pantalla cargada
		App.display();
	}
	return EXIT_SUCCESS;
}
