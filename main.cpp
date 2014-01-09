#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

int main(){
	//Cargar ventana renderizada
	RenderWindow App(VideoMode(600,500,32),"Role&Music v1.0.0");
	//Variables
	bool Set_Rep=false;
	bool Sel_Lab[7];
    //Inicializacion de variables
    for(int i=0;i<7;i++)
        Sel_Lab[i]=false;
    //Creacion de objetos
    Texture TX[7];
    Sprite BG;
    Sprite Play[7];
    Sprite Stop[7];
    Sprite Label[7];
    Sprite Repr[2];
    Sprite SelLab[7];
    Text Textos[2];
    Font fuente;
	Music Pistas[7];
	String Cancion;
	Text Canciones[7];
	string str;
	//Inicializacion de objetos
        //Fuente
        fuente.loadFromFile("Fonts/font.ttf");
        //Textos
        Textos[0] = Text("Role&Music v1.0.0",fuente,40);
        Textos[0].setPosition(320,450);
        Textos[0].setColor(Color::Red);
        Textos[1] = Text(" Cliquee encima del espacio para escritura, cuando se marque el recuadro,\n escriba el nombre de la cancion deseada acabado en .wav o .ogg,\n la cancion debe estar en formato .wav o .ogg para su correcta\n reproduccion. Por ultimo, pulse enter para cargar la cancion.",fuente,20);
        Textos[1].setColor(Color::Red);
        //Fondo
        TX[0].loadFromFile("Images/Background.png");
        BG.setTexture(TX[0]);
        //Botones Play
        TX[1].loadFromFile("Images/Play.png");
        for(int i=0;i<7;i++){
            Play[i].setTexture(TX[1]);
            Play[i].setPosition(400,150+(45*i));
        }
        //Botones Stop
        TX[2].loadFromFile("Images/Stop.png");
        for(int i=0;i<7;i++){
            Stop[i].setTexture(TX[2]);
            Stop[i].setPosition(455,150+(45*i));
        }
        //Botones Label
        TX[3].loadFromFile("Images/Label.png");
        for(int i=0;i<7;i++){
            Label[i].setTexture(TX[3]);
            Label[i].setPosition(60,150+(45*i));
        }
        //Sprite Botones Reproductor
        TX[4].loadFromFile("Images/ReproductorG.png");
        Repr[0].setTexture(TX[4]);
        Repr[0].setPosition(400,90);
        TX[5].loadFromFile("Images/ReproductorB.png");
        Repr[1].setTexture(TX[5]);
        Repr[1].setPosition(400,90);
        //Sprite seleccion labels
        TX[6].loadFromFile("Images/Select.png");
        for(int i=0;i<7;i++){
            SelLab[i].setTexture(TX[6]);
            SelLab[i].setPosition(10,150+(45*i));
        }

    //Inicio lazo principal
    while(App.isOpen()){
        Event evento;
        if(App.pollEvent(evento)){
            if(evento.type == Event::Closed){
                App.close();
            }
            if(evento.type == Event::MouseButtonPressed){
                if(evento.mouseButton.button == Mouse::Left){
                    Vector2f Position(Mouse::getPosition(App));
                    if(Position.x>=400 && Set_Rep==true){
                        for(int i=0;i<7;i++){
                            if(Play[i].getGlobalBounds().contains(Position.x,Position.y)){
                                Pistas[i].play();
                            }
                            if(Stop[i].getGlobalBounds().contains(Position.x,Position.y)){
                                Pistas[i].stop();
                            }
                        }
                    }
                    //Fin if posicion
                    if(Repr[0].getGlobalBounds().contains(Position.x,Position.y)){
							if(Set_Rep==false){
								Set_Rep=true;
								for(int i=0;i<7;i++){
                                    if(!Canciones[i].getString().isEmpty())
                                        Pistas[i].openFromFile(String("Samples/")+String(Canciones[i].getString()));
								}
							}else{
								Set_Rep=false;
								for(int i=0;i<7;i++){
                                    Pistas[i].stop();
								}
							}
                    }//Fin if Modo reproductor
					if(Position.x>60 && Position.x<315){
						for(int i=0;i<7;i++){
							if(Label[i].getGlobalBounds().contains(Position.x,Position.y)){
								Sel_Lab[i] = true;
								if(Canciones[i].getString().isEmpty()){
                                    str=string();
                                }else{
                                    str=Canciones[i].getString();
                                }
							}else{
								Sel_Lab[i] = false;
							}
						}
					}
					//Fin if boton izquierdo
                }
                if(evento.mouseButton.button == Mouse::Right){
                    Vector2f Position(Mouse::getPosition(App));
                    if(Position.x>=400){
                        for(int i=0;i<7;i++){
                            if(Play[i].getGlobalBounds().contains(Position.x,Position.y)){
                                Pistas[i].setLoop(true);
                                Pistas[i].play();
                            }
                        }
                    }
                    //Fin if posicion
                }
                //Fin if boton derecho
            }
            //Fin if evento raton
            if(evento.type == Event::TextEntered){
                    if(evento.text.unicode < 128 && Set_Rep==false){
                        str += static_cast<char>(evento.text.unicode);
                    }
            }
            //Fin evento entrada por teclado
            if(Keyboard::isKeyPressed(Keyboard::Key::BackSpace)){
                for(int i=0;i<7;i++){
                    if(Sel_Lab[i]==true && Set_Rep == false){
                        str=string();
                    }
                }
            }
        }
        if(Set_Rep==false){
            for(int i=0;i<7;i++){
                if(Sel_Lab[i]==true){
                    Cancion = String(str);
                    Canciones[i].setFont(fuente);
                    Canciones[i].setString(String(str));
                    Canciones[i].setPosition(Label[i].getPosition().x+4,Label[i].getPosition().y+4);
                }
            }
        }
        //Fin eventos
        App.clear();
        App.draw(BG);
        for(int i=0;i<7;i++){
            App.draw(Play[i]);
            App.draw(Stop[i]);
            App.draw(Label[i]);
        }
        if(Set_Rep==true){
				App.draw(Repr[0]);
			}else{
				App.draw(Repr[1]);
			}
        for(int i=0;i<7;i++){
			if(Sel_Lab[i]==true)App.draw(SelLab[i]);
		}
		for(int i=0;i<7;i++){
            App.draw(Canciones[i]);
		}
        App.draw(Textos[0]);
		App.draw(Textos[1]);
		App.display();
    }
	return EXIT_SUCCESS;
}
