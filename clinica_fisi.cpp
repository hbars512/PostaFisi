#include <iostream>
#include <string.h>
#define VALOR_CENTINELA -1
using namespace std;

struct Servicio {
  int codigo;
  char nombre[50];
  int duracion;
  double precio;
  char especialidad[50];
};

void menu_principal();
void limpiar_pantalla();
void pausar_pantalla();
void titulo_principal();
void menu_usuario();
void menu_especialidad();
void menu_servicios();
void menu_cita();
void menu_historial();
void menu_reportes();

int obtener_entero();
int obtener_entero(int, int);
bool es_entero_valido(string);
double obtener_flotante();
bool es_flotante_valido(string);

bool insertar_servicio_archivo(Servicio serv);
Servicio *obtener_st_archivo(int *n);

int main(void)
{
  menu_principal();

  return 0;
}

void menu_principal(void) {
  void menu_principal_opciones();
  bool se_repite = true;
  int opcion;

  do {
    menu_principal_opciones();
    opcion = obtener_entero();

    switch (opcion) {
      case 1:
        menu_usuario();
        break;
      case 2:
        menu_especialidad();
        break;
      case 3:
        menu_servicios();
        break;
      case 4:
        menu_cita();
        break;
      case 5:
        menu_historial();
        break;
      case 6:
        menu_reportes();
        break;
      case 7:
        se_repite = false;
        break;
    }
  } while (se_repite);
}

void menu_servicios() {
  bool se_repite = true;
  int opcion;
  void menu_servicios_opciones();
  void crear_servicio();
  void mostrar_servicio();
  void actualizar_servicio();
  void eliminar_servicio();

  do {
    menu_servicios_opciones();
    opcion = obtener_entero();

    switch (opcion) {
      case 1:
        crear_servicio();
        break;
      case 2:
        mostrar_servicio();
        break;
      case 3:
        actualizar_servicio();
        break;
      case 4:
        eliminar_servicio();
        break;
      case 5:
        se_repite = false;
        break;
    }
  } while (se_repite);
}

void menu_principal_opciones(void) {
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU PRINCIPAL\n";
  cout << "\n\t\t[1]. Usuarios\n";
  cout << "\t\t[2]. Especialidades\n";
  cout << "\t\t[3]. Servicios\n";
  cout << "\t\t[4]. Cita\n";
  cout << "\t\t[5]. Historial Medico\n";
  cout << "\t\t[6]. Reportes\n";
  cout << "\t\t[7]. Salir\n";
  cout << "\n\t\tIngrese una opcion: [ ]\b\b";
}

void menu_servicios_opciones(void) {
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU SERVICIOS\n";
  cout << "\n\t\t[1]. Crear servicio\n";
  cout << "\t\t[2]. Mostrar servicios\n";
  cout << "\t\t[3]. Actualizar servicios\n";
  cout << "\t\t[4]. Eliminar servicio\n";
  cout << "\t\t[5]. Volver al menu principal\n";
  cout << "\n\t\tIngrese una opcion: [ ]\b\b";
}

void menu_usuario() {
  int prueba;
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU USUARIOS\n";
  cout << "\t\tIngresar: ";
  cin >> prueba;
  cin.ignore();
}

void menu_especialidad() {
  int prueba;
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU USUARIOS\n";
  cout << "\t\tIngresar: ";
  cin >> prueba;
  cin.ignore();
}

void menu_cita() {
  int prueba;
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU CITA\n";
  cout << "\t\tIngresar: ";
  cin >> prueba;
  cin.ignore();
}

void menu_historial() {
  int prueba;
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU HISTORIAL\n";
  cout << "\t\tIngresar: ";
  cin >> prueba;
  cin.ignore();
}

void menu_reportes() {
  int prueba;
  limpiar_pantalla();
  titulo_principal();
  cout << "\n\t\t\t\tMENU REPORTES\n";
  cout << "\t\tIngresar: ";
  cin >> prueba;
  cin.ignore();
}

void titulo_principal(void) {
  cout << "\n     ======================================================================\n";
  cout << "\t\t\t\t CLINICA FISI\n";
  cout << "     ======================================================================\n";
}

int obtener_entero() {
  bool no_es_entero = true;
  string valor;

  while (no_es_entero) {
    try {
      getline(cin, valor);
      if (!es_entero_valido(valor)) {
        throw valor;
      }
    } catch(string e) {
      cout << "Por favor, ingrese un entero valido: ";
      continue;
    }
    no_es_entero = false;
  }
  return atoi(valor.c_str());
}

int obtener_entero(int inf, int sup) {
  bool no_aceptado = true;
  int numero;
  while (no_aceptado) {
    try {
      numero = obtener_entero();
      if (numero < inf || numero > sup) {
        throw numero;
      }
    }catch(int e) {
      cout << "\t\tPor favor, ingrese un numero entero entre " << inf << " y " << sup << ": [ ]\b\b";
      continue;
    }
    no_aceptado = false;
  }
  return numero;
}

bool es_entero_valido(string str) {
  int inicio = 0;
  int i;
  bool valido = true;
  bool signo = false;

  if (int(str.length()) == 0) {
    valido = false;
  }

  if (str.at(0) == '-' || str.at(0) == '+') {
    signo = true;
    inicio = 1;
  }
  if (signo && int(str.length()) == 1) {
    valido = false;
  }

  i = inicio;
  while (valido && i < int(str.length())) {
    if (!isdigit(str.at(i))) {
      valido = false;
    }
    i++;
  }

  return valido;
}

void limpiar_pantalla(void) {
  system("clear");
}

void crear_servicio(void) {
  bool existe_servicio(int codigo_servicio, Servicio *serv);
  Servicio serv;
  bool se_repite = true;
  string respuesta;
  int codigo;
  string nombre, especialidad;

  do {
    limpiar_pantalla();
    titulo_principal();
    cout << "\n\t\tCREAR NUEVO SERVICIO\n";

    cout << "\tIngresa el Codigo de servicio: ";
    cin >> codigo;
    cin.ignore();
    if (!existe_servicio(codigo, &serv)) {
      serv.codigo = codigo;

      cout << "\tNombre del servicio: ";
      getline(cin, nombre);
      strcpy(serv.nombre, nombre.c_str());
      cout << serv.nombre << endl;

      cout << "\tDuración del servicio: ";
      cin >> serv.duracion;
      cin.ignore();
      cout << "\tPrecio: ";
      serv.precio = obtener_flotante();
      especialidad = "pendiente";
      strcpy(serv.especialidad, especialidad.c_str());
      cout << serv.especialidad << endl;

      if (insertar_servicio_archivo(serv)) {
        cout << "\n\tEl servicio fue creado satisfactoriamente" << endl;
      } else {
        cout << "\n\tOcurrio un error al intentar crear el servicio" << endl;
        cout << "\tIntentelo nuevamente" << endl;
      }

    } else {
      cout << "\tEl servicio de codigo " << codigo << " ya existe.\n" << endl;
      cout << "\tNo puede ingresar dos servicios con el mismo codigo" << endl;
    }
    cout << "\n\tDesea seguir ingresando servicios? [S/n]: ";
    getline(cin, respuesta);
    if (!(respuesta.compare("s") == 0 || respuesta.compare("S") == 0)) {
      se_repite = false;
    }
  } while (se_repite);
}

bool existe_servicio(int codigo_servicio, Servicio *serv) {
  FILE *archivo;
  bool existe = false;

  archivo = fopen("servicios.dat", "rb");

  if (!(archivo == NULL)) {
    fread(&(*serv), sizeof(*serv), 1, archivo);
    while (!feof(archivo)) {
      if ((*serv).codigo == codigo_servicio) {
        existe = true;
        break;
      }
      fread(&(*serv), sizeof(*serv), 1, archivo);
    }
    fclose(archivo);
  }
  return existe;
}

double obtener_flotante(void) {
  bool no_es_flotante = true;
  string valor;

  while (no_es_flotante) {
    try {
      getline(cin, valor);
      if (!es_flotante_valido(valor)) {
        throw valor;
      }
    } catch(string e) {
      cout << "\t\tPor favor, ingrese un numero decimal valido: ";
      continue;
    }
    no_es_flotante = false;
  }
  return atof(valor.c_str());
}

bool es_flotante_valido(string str) {
  int inicio = 0;
  int i, n_puntos = 0;
  bool valido = true;
  bool signo = false;

  if (int(str.length()) == 0) {
    valido = false;
  }

  if (str.at(0) == '-' || str.at(0) == '+') {
    signo = true;
    inicio = 1;
  }

  if (str.at(1) == '.') {
    valido = false;
  }

  if (signo && int(str.length()) == 1) {
    valido = false;
  }

  i = inicio;
  while (valido && i < int(str.length())) {
    if (!isdigit(str.at(i))) {
      if (!(str.at(i) == '.')) {
        valido = false;
      }
    }
    if (str.at(i) == '.') {
      n_puntos++;
    }
    i++;
  }

  if (n_puntos > 1) {
    valido = false;
  }

  return valido;
}

bool insertar_servicio_archivo(Servicio serv) {
  FILE *archivo;
  bool insercion;

  archivo = fopen("servicios.dat", "ab");

  if (archivo == NULL) {
    insercion = false;
  } else {
    fwrite(&serv, sizeof(serv), 1, archivo);
    insercion = true;
    fclose(archivo);
  }

  return insercion;
}

void mostrar_servicio() {
  Servicio *servicios;
  int nro_servicios;

  limpiar_pantalla();
  titulo_principal();
  servicios = obtener_st_archivo(&nro_servicios);

  if (nro_servicios == 0) {
    cout << "\n\tEl archivo esta vacio" << endl;
    pausar_pantalla();
  } else {

    cout << "\n\t\t\t\tSERVICIOS REGISTRADOS\n";
    cout << "\n\t   ------------------------------------------------------------\n";
    for (int i = 0; i < nro_servicios; i++) {
      if (servicios[i].codigo != VALOR_CENTINELA) {
        cout << "\t\tCodigo: " << servicios[i].codigo << endl;
        cout << "\t\tNombre: " << servicios[i].nombre << endl;
        cout << "\t\tDuracion: " << servicios[i].duracion << endl;
        cout << "\t\tPrecio: " << servicios[i].precio << endl;
        cout << "\t\tEspecialidad: " << servicios[i].especialidad << endl;
      }
    cout << "\n\t   ------------------------------------------------------------\n";
    }
    pausar_pantalla();
  }
}

void actualizar_servicio(void) {
  int prueba;
  cout << "Ingrese valor: ";
  cin >> prueba;
  cin.ignore();
}

void eliminar_servicio(void) {
  int prueba;
  cout << "Ingrese valor: ";
  cin >> prueba;
  cin.ignore();
}

Servicio *obtener_st_archivo(int *n) {
  FILE *archivo;
  Servicio servicio;
  Servicio *servicios;
  int i;

  archivo = fopen("servicios.dat", "rb");

  if (archivo == NULL) {
    *n = 0;
    servicios = NULL;
  } else {
    fseek(archivo, 0, SEEK_END);
    *n = ftell(archivo) / sizeof(Servicio);
    servicios = (Servicio *)malloc((*n) * sizeof(Servicio));
    fseek(archivo, 0, SEEK_SET);
    fread(&servicio, sizeof(servicio), 1, archivo);
    i = 0;
    while (!feof(archivo)) {
      servicios[i] = servicio;
      fread(&servicio, sizeof(servicio), 1, archivo);
      i++;
    }
    fclose(archivo);
  }
  return servicios;
}

void pausar_pantalla() {
  char caracter;
  cout << "\n\tPresiona 'Enter' para continuar...";
  while (caracter != '\n') {
    cin.get(caracter);
  }
}

