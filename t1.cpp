#include <iostream>
#include <vector>

using namespace std;

class pregunta {
private:
    string encabezado;
    string respuesta;
    static int nextPid;
    int pid;
    string nivel;
public:
    string getEncabezado();
    string getRespuesta();
    int getPid();
    string getNivel();
    void setNivel(string nivel);
    void setPid(int pid);
    void setRespuesta(string respuesta);
    void setEncabezado(string encabezado);
    pregunta();
    pregunta(string encabezado, string respuesta, string nivel);
    pregunta(string encabezado, string respuesta, string nivel, int pid);
    ~pregunta();
};

class mainmenu: public pregunta{
  public:
    void mostrarMenu();
    void addPregunta();
    void removePregunta();
    void editPregunta();
    void mostrarPregunta();
    void byLevelSolicitud();
};
int pregunta :: nextPid= 1; 
vector<pregunta>preguntas;
vector<pregunta>::iterator it;

void mainmenu ::mostrarMenu(){
    cout << "Bienvenido al sistema de preguntas y respuestas" << endl;
    cout << "1. Agregar pregunta" << endl;
    cout << "2. Eliminar pregunta" << endl;
    cout << "3. Editar pregunta" << endl;
    cout << "4. Mostrar pregunta" << endl;
    cout << "5. Mostrar preguntas por nivel" << endl;
    cout << "5. Salir" << endl;
}
void mainmenu ::addPregunta(){
  cout << "..." << endl;
  string encabezado;
  string respuesta;
  string nivel;
  cout << "Pregunta :" << endl;
  getline(cin, encabezado); 
  cout << "Respuesta de la pregunta:" << endl;
  getline(cin, respuesta); 
  cout << "Nivel Taxonomico: " << endl;
  getline(cin, nivel);
  it = preguntas.end() - 1;
  int pid = it->getPid();
  pid++;
  pregunta nuevaPregunta(encabezado, respuesta, nivel, pid);
  preguntas.push_back(nuevaPregunta);    
}
void mainmenu ::removePregunta(){
  cout << "..." << endl;
  int pid;
  cout << "Ingrese el numero de la pregunta que desea eliminar: " << endl;
  cin >> pid;
  for (it= preguntas.begin(); it != preguntas.end(); it++){
    if (it->getPid() == pid){
      preguntas.erase(it);
      break;
    }
  }
  for (it= preguntas.begin(); it != preguntas.end(); it++){
    int x=1;
    it->setPid(x);
    x++;
  }
  cout << "..." << endl;
  cout << "Pregunta eliminada" << endl;
}
void mainmenu ::editPregunta(){
  int id;
  int choice;
  string encabezado;
  string respuesta;  
  string nivel;
  cout << "..." << endl;
  cout << "Elejir el numero de la pregunta que desea editar: " << endl;
  cin >> id;
  for (it= preguntas.begin(); it != preguntas.end(); it++)
    if (it->getPid() == id)
      do
      {
        cout << "Ingrese la opcion que desea editar: " << endl;
        cout << "1. Pregunta" << endl;
        cout << "2. Respuesta" << endl;
        cout << "3. Nivel" << endl;
        cout << "4. Salir" << endl;
        cin >> choice;
        switch(choice)
          {
            case 1:;
              cout << "Ingrese la nueva pregunta: " << endl;
              cin >> encabezado;
              it->setEncabezado(encabezado);
              break;
            case 2:;
              cout << "Ingrese la nueva respuesta: " << endl;
              cin >> respuesta;
              it->setRespuesta(respuesta);
              break;
            case 3:;
              cout << "Ingrese el nuevo nivel: " << endl;
              cin >> nivel;
              it->setNivel(nivel);
              break;
            case 4:
              cout << "Saliendo..." << endl;
              break;
            default:
              cout << "Opcion invalida" << endl;
              break;
          }
      }
      while(choice!=4);
}
void mainmenu ::mostrarPregunta(){
  cout << "..." << endl;
  int id;
  cout << "Ingrese el numero de la pregunta que desea mostrar: " << endl;
  cin >> id;
  for (it= preguntas.begin(); it != preguntas.end(); it++)
    if (it->getPid() == id)
      cout << "Pregunta: " << it->getEncabezado() << endl;
      cout << "Respuesta: " << it->getRespuesta() << endl;
      cout << "Nivel: " << it->getNivel() << endl;
      cout << "Pid: " << it->getPid() << endl;
      cout << "..." << endl;
}
void mainmenu ::byLevelSolicitud(){
  cout << "..." << endl;
  string nivel;
  cout << "Ingrese el nivel que desea mostrar: " << endl;
  cin >> nivel;
  for (it= preguntas.begin(); it != preguntas.end(); it++)
    if (it->getNivel() == nivel)
      cout << "Pregunta: " << it->getEncabezado() << endl;
      cout << "Respuesta: " << it->getRespuesta() << endl;
      cout << "Nivel: " << it->getNivel() << endl;
}
  

pregunta ::pregunta(string encabezado, string respuesta, string nivel){
    this->encabezado = encabezado;
    this->respuesta = respuesta;
    this->nivel = nivel;
    this->pid = nextPid++;
    this->nivel = nivel;
};
pregunta ::pregunta(string encabezado, string respuesta, string nivel, int pid){  
    this->encabezado = encabezado;
    this->respuesta = respuesta;
    this->nivel = nivel;
    this->pid = pid;
    this->nivel = nivel;
}
pregunta ::~pregunta(){}

string pregunta ::getEncabezado(){
    return this->encabezado;
}
string pregunta ::getRespuesta(){
    return this->respuesta;
}
int pregunta ::getPid(){
    return this->pid;
}
string pregunta ::getNivel(){
    return this->nivel;
}
void pregunta ::setNivel(string nivel){
    this->nivel = nivel;
}
void pregunta ::setPid(int pid){
    this->pid = pid;
}
void pregunta ::setRespuesta(string respuesta){
    this->respuesta = respuesta;
}
void pregunta ::setEncabezado(string encabezado){
    this->encabezado = encabezado;
}

int main(){
   mainmenu objeto;
    int choice;
    do{
      objeto.mostrarMenu();
      cin >> choice;
      switch(choice)
        {
          case 1:
            objeto.addPregunta();
            break;
          case 2:
            objeto.removePregunta();
            break;
          case 3:
            objeto.editPregunta();
            break;
          case 4:
            objeto.mostrarPregunta();
            break;
          case 5:
            objeto.byLevelSolicitud();
            break;
          case 6:
            cout << "Saliendo..." << endl;
            break;
          default:
            cout << "Opcion invalida" << endl;
            break;
        }
      }
      while(choice!=6);
  return 0;
}
