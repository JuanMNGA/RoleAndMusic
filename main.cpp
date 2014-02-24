#include <iostream>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

template <typename T>
void write(std::ofstream& stream, const T& t) {
  stream.write((const char*)&t, sizeof(T));
}

template <typename SampleType>
void writeWAVData(const char* outFile, SampleType* buf, size_t bufSize,
                  int sampleRate, short channels)
{
  std::ofstream stream(outFile, std::ios::binary);
  stream.write("RIFF", 4);
  write<int>(stream, 36 + bufSize);
  stream.write("WAVE", 4);
  stream.write("fmt ", 4);
  write<int>(stream, 16);
  write<short>(stream, 1);                                        // Format (1 = PCM)
  write<short>(stream, channels);                                 // Channels
  write<int>(stream, sampleRate);                                 // Sample Rate
  write<int>(stream, sampleRate * channels * sizeof(SampleType)); // Byterate
  write<short>(stream, channels * sizeof(SampleType));            // Frame size
  write<short>(stream, 8 * sizeof(SampleType));                   // Bits per sample
  stream.write("data", 4);
  stream.write((const char*)&bufSize, 4);
  stream.write((const char*)buf, bufSize);
}

string itoa(int num)
{
  stringstream s;
  s<<num;
  return s.str();
}

int main(){
	//Cargar ventana renderizada
	RenderWindow App(VideoMode(600,500,32),"Role&Music v1.0.0",sf::Style::Close);
	//Variables
	bool Set_Rep=false;
	bool Sel_Lab[7];
	//bool Load_Sou[7];
    //Inicializacion de variables
    for(int i=0;i<7;i++){
        Sel_Lab[i]=false;
        //Load_Sou[i]=false;
    }
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
	Sound Pistas[7];
	SoundBuffer Pistas_[7];
	String Cancion;
	Text Canciones[7];
	Text Volumen[7];
	int volumen_[7];
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
        for(int i=0;i<7;i++){
            volumen_[i] = 50;
            Pistas[i].setVolume(volumen_[i]);
            Volumen[i].setFont(fuente);
            Volumen[i].setColor(Color::Black);
            Volumen[i].setPosition(Stop[i].getPosition()+Vector2f(64,4));
            Volumen[i].setString(String());
        }

    //Inicio lazo principal
    while(App.isOpen()){
        Event evento;
        if(App.pollEvent(evento)){
            if(evento.type == Event::Closed){
                App.close();
            }
            //Botones teclado
            if(Set_Rep==true){
            if(Keyboard::isKeyPressed(Keyboard::Key::Q)){
                if(volumen_[0]<100){
                    Pistas[0].setVolume(volumen_[0]+1);
                    volumen_[0]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::A)){
                if(volumen_[0]>0){
                    Pistas[0].setVolume(volumen_[0]+1);
                    volumen_[0]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::W)){
                if(volumen_[1]<100){
                    Pistas[1].setVolume(volumen_[1]+1);
                    volumen_[1]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::S)){
                if(volumen_[1]>0){
                    Pistas[1].setVolume(volumen_[1]+1);
                    volumen_[1]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::E)){
                if(volumen_[2]<100){
                    Pistas[2].setVolume(volumen_[2]+1);
                    volumen_[2]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::D)){
                if(volumen_[2]>0){
                    Pistas[2].setVolume(volumen_[2]+1);
                    volumen_[2]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::R)){
                if(volumen_[3]<100){
                    Pistas[3].setVolume(volumen_[3]+1);
                    volumen_[3]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::F)){
                if(volumen_[3]>0){
                    Pistas[3].setVolume(volumen_[3]+1);
                    volumen_[3]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::T)){
                if(volumen_[4]<100){
                    Pistas[4].setVolume(volumen_[4]+1);
                    volumen_[4]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::G)){
                if(volumen_[4]>0){
                    Pistas[4].setVolume(volumen_[4]+1);
                    volumen_[4]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::Y)){
                if(volumen_[5]<100){
                    Pistas[5].setVolume(volumen_[5]+1);
                    volumen_[5]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::H)){
                if(volumen_[5]>0){
                    Pistas[5].setVolume(volumen_[5]+1);
                    volumen_[5]-=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::U)){
                if(volumen_[6]<100){
                    Pistas[6].setVolume(volumen_[6]+1);
                    volumen_[6]+=1;
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::J)){
                if(volumen_[6]>0){
                    Pistas[6].setVolume(volumen_[6]+1);
                    volumen_[6]-=1;
                }
            }
            //Quickplay
            if(Keyboard::isKeyPressed(Keyboard::Key::Z)){
                Pistas[0].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::X)){
                Pistas[1].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::C)){
                Pistas[2].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::V)){
                Pistas[3].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::B)){
                Pistas[4].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::N)){
                Pistas[5].play();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::M)){
                Pistas[6].play();
            }
            /*if(Keyboard::isKeyPressed(Keyboard::Key::I)){
                size_t cont=0;
                for(int i=0;i<7;i++){
                    if(Load_Sou[i]){
                        cont += Pistas_[i].getSampleCount();
                    }
                }
                short *samples = new short[cont];

            }*/
            //Fin Botones teclado
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
                                        if(Pistas_[i].loadFromFile(String("Samples/")+String(Canciones[i].getString())));
                                            //Load_Sou[i]=true;
                                        Pistas[i].setBuffer(Pistas_[i]);
                                        Pistas[i].setVolume(50);
								}
							}else{
								Set_Rep=false;
								for(int i=0;i<7;i++){
                                    Pistas[i].stop();
                                    Pistas_[i] = SoundBuffer();
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
            //Borrar toda la cadena
            if(Keyboard::isKeyPressed(Keyboard::Key::Delete)){
                for(int i=0;i<7;i++){
                    if(Sel_Lab[i]==true && Set_Rep == false){
                        str=string();
                    }
                }
            }
            //Borrar solo un caracter
            if(Keyboard::isKeyPressed(Keyboard::Key::BackSpace)){
                for(int i=0;i<7;i++){
                    if(Sel_Lab[i]==true && Set_Rep == false && str.length()>0){
                        str.erase((str.length()-1),1);
                    }
                }
            }
        }
        for(int i=0;i<7;i++){
            Volumen[i].setString(itoa(Pistas[i].getVolume()));
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
            App.draw(Volumen[i]);
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
