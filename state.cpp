#include "time.cpp"

using namespace std;

class state{
public:
	virtual void ejecuta_accion() = 0;
};

class red_light : public state{
private:
	static red_light *unico1;
public:
	static red_light* get_instance(){
		if(unico1 == NULL)
			unico1 = new red_light();
		return unico1;
	}

	void ejecuta_accion(){
		cout << "traffic_light: RED                   time: 5s" << endl;
		wait(5);
	}
};

class green_light : public state{
private:
	static green_light *unico2;
public:
	static green_light* get_instance(){
		if(unico2 == NULL)
			unico2 = new green_light();
		return unico2;
	}
	void ejecuta_accion(){
		cout << "traffic_light: GREEN                 time: 5s" << endl;
		wait(5);
	}
};

class yellow_light : public state{
private:
	static yellow_light *unico3;
public:
	static yellow_light* get_instance(){
		if(unico3 == NULL)
			unico3 = new yellow_light();
		return unico3;
	}
	void ejecuta_accion(){
		cout << "traffic_light: YELLOW                time: 2s" << endl;
		wait(2);
	}
};

class traffic_light{
private:
	static traffic_light *unico4;
	state *mi_state;
public:
	static traffic_light* get_instance(){
		if(unico4 == NULL)
			unico4 = new traffic_light();
		return unico4;
	}
	void set_state(state *e){
		this->mi_state = e;
	}
	void ejecutar_accion(){
		mi_state->ejecuta_accion();
	}
};

red_light *red_light::unico1 = NULL;
green_light *green_light::unico2 = NULL;
yellow_light *yellow_light::unico3 = NULL;
traffic_light *traffic_light::unico4 = NULL;


int main(int argc, char const *argv[]){
	
	traffic_light *traffic = traffic_light::get_instance();
	red_light *red = red_light::get_instance();
	green_light *green = green_light::get_instance();
	yellow_light *yellow = yellow_light::get_instance();
	
	int asd[10] = {1,2,3,4};
	int n = 10;
	int opcion;
	menu();
	int i = 0;
	do{
		opcion = asd[i];
		switch(opcion){
			case 1:
				traffic->set_state(red);
				traffic->ejecutar_accion();
				break;
			case 2:
				traffic->set_state(yellow);
				traffic->ejecutar_accion();	
				break;
			case 3:
				traffic->set_state(green);
				traffic->ejecutar_accion();	
				break;
			case 4:
				traffic->set_state(yellow);
				traffic->ejecutar_accion();	
				break;
		}
		i++;
		if(i > 3) i = 0;
	}
	while(opcion!=0);

	return 0;
}
