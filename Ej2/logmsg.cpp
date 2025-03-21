#include "logmsg.h"

void logMessage(string msg, levels level){
    //abro el archivo en modo append y escribo el mensaje con el prefijo correspondiente.
    ofstream log("Ej2/log.txt", ios::app);
    //no chequeo si existe ya que en este caso lo crea automaticamente.

    log << level_names[level] + " <" + msg + ">" << endl;
    log.close();
}

void logMessage(string msg, string file_name, int line){
    //no se chequea el level porque siempre entra en caso de error.
    ofstream log("Ej2/log.txt", ios::app);
    //no chequeo si existe ya que en este caso lo crea automaticamente.

    log << "[ERROR] " << file_name << ":" << to_string(line) << " - <" << msg << ">" << endl;
    log.close();
}

void logMessage(string msg, string username){
    //no se chequea el level porque siempre entra en caso de error.
    ofstream log("Ej2/log.txt", ios::app);
    //no chequeo si existe ya que en este caso lo crea automaticamente.   

    log << "[SECURITY] User: " << username << " - " << msg << endl;
    log.close();
}

int case_error(string msg){
    //se le pide al usuario si desea agregar unicamente un mensaje de error o si desea agregar un archivo en especifico con una linea. 
    //este segundo caso, a lo largo del homework, se maneja automaticamente pero no viene mal tenerlo en caso de encontrar futuros errores inesperados.
    cout << "Enter the file name (enter . to skip file snipping): ";
    string file_name;
    cin >> file_name;

    //si no desea agregar un archivo, se saltea el proceso y llamo a logMessage indicando [ERROR].
    if (file_name[0]=='.'){
        logMessage(msg, ERROR);
        cout << endl;
        return 0;
    };

    cout << "Enter the line number: ";
    int line;
    cin >> line;

    //si el usuario ingresa una linea negativa o 0, se devuelve la linea donde se lanza un error.
    //asimismo si se ingresa un char o string, se lanza un error.
    if (cin.fail() || line<1){
        cin.clear();
        cin.ignore(10000, '\n');
        return __LINE__+1;
    }
    logMessage(msg, file_name, line);
    return 0;
}

int case_user(string msg){
    cout << "Enter the username: ";
    string username;
    cin >> username;

    logMessage(msg, username);
    return 0;
}

int run_2(){
    cout << "volvio" << endl;
    cout << endl << "========== Ej 2: Log messages ==========" << endl;
    int error_line;
    try{
        while (true){
            cout << "Select the event level:" << endl;
            cout << "1. DEBUG\n2. INFO\n3. WARNING\n4. ERROR\n5. CRITICAL\n6. SECURITY\n7. Exit" << endl << "> ";
            int level_selected;
            cin >> level_selected;

            //si se ingresa un char o string, se lanza un error.
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                error_line=__LINE__+1;
                throw invalid_argument("ERROR - Invalid option.");
            }

            //solo si el level seleccionado es valido se pide un mensage.
            string msg;
            if (level_selected>0 && level_selected<=(int)level_names.size()){
                cout << "Enter the message: ";

                //se aceptan espacios en el mensaje.
                cin.ignore();
                getline(cin, msg);
            }

            //se elige el level indicado, si se ingresa uno que no existe se lanza un error.
            switch (level_selected){
                case DEBUG: logMessage(msg, DEBUG); break;
                case INFO: logMessage(msg, INFO); break;
                case WARNING: logMessage(msg, WARNING); break;
                case ERROR: if (case_error(msg)) throw invalid_argument("ERROR - Invalid input"); break;
                case CRITICAL: logMessage(msg, CRITICAL); break;
                case SECURITY: case_user(msg); break;
                case EXIT: return 0;
                default: error_line=__LINE__; throw invalid_argument("ERROR - Invalid option."); break;
            }
        }
    }

    //si detecto algun error lo informo, cierro el programa y loggeo el error.
    catch (runtime_error &e){
        cout << e.what() << endl;
        logMessage("File 'levels.txt' failed to open", __FILE__, error_line);
        return 1;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        logMessage("Invalid input recived", __FILE__, error_line);
        return 1;
    }
    catch (...){
        cout << "ERROR - Unexpected error." << endl;
        logMessage("Unexpected error", __FILE__, __LINE__);
        return 1;
    }
}