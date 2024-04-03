#include<iostream>
#include<string>
#include<cstdlib>
//all func
void root_command(std::string &command);
void user_command(std::string &command);
int login_init();
void command_init(std::string &command);
int input_root(std::string &command);
int input_user(std::string &command);
//command
void whoami();
void passwd();
void all_user();
void help();
void quit_login(std::string &command);
void echo(std::string &command);
void exit();


//password and user
std::string root_user = "root";
std::string normal_user = "user";

std::string passwd_root = "root";
std::string passwd_user = "user";

//init login
bool login = false;
std::string user_init, password;

int main(){
	std::string command;
	login_init();
	if(login){
		command_init(command);
	}else{
		exit(0);
	}
}

//command init
void command_init (std::string &command){
	if (user_init == root_user){
		input_root(command);
	}else if(user_init == normal_user){
		input_user(command);
	}
}

//login
int login_init() {
	std::cout << "login: ";
	std::cin >> user_init;
	for(int i = 0; i < 5; i++) {
		std::cout << user_init << "@win32's password: ";
		std::cin >> password;

		if(user_init == root_user){
			if(password == passwd_root){
				std::cout << "Lost Login: " << user_init << std::endl;
				login = true;  
				break;
			} else {
				std::cout << "Access denied" << std::endl;
			}
		} else if(user_init == normal_user){
			if(password == passwd_user){
				std::cout << "Lost Login: " << user_init << std::endl;
				login = true;
				break;
			} else {
				std::cout << "Access denied" << std::endl;
			}
		} else {
			std::cout << "Access denied" << std::endl;
		}
		password = "";
	}
	return 0;
}

//user terminal
void root_command(std::string &command){
	do{
		if(command == "whoami"){
			whoami();
		}else if(command == "help"){
			help();
		}else if(command == "echo"){
			echo(command);
		}else if(command == "login"){
			quit_login(command);
		}else if(command == "exit"){
			exit();
		}else if(command == "passwd"){
			passwd();
		}else if(command == "cmd"){
			system("cmd");
		}else if(command == "user"){
			all_user();
		}else{
			std::cout << "\"" << command << "\" no command" << std::endl;
		}
			
		command = "";
		input_root(command);
	}while(!login);
}

//root terminal
void user_command(std::string &command){
	do{
		if(command == "whoami"){
			whoami();
		}else if(command == "help"){
			help();
		}else if(command == "echo"){
			echo(command);
		}else if(command == "login"){
			quit_login(command);
		}else if(command == "exit"){
			exit();
		}else if(command == "cmd"){
			system("cmd");
		}else{
			std::cout << "\"" << command << "\" no command" << std::endl;
		}
	
		command = "";
		input_user(command);
	}while(!login);
}

//input and root
int input_root(std::string &command){
	do{
		std::cout << "~# ";
		std::cin >> command;
		root_command(command);
	}while(!login);
	return 0;
}

//input and user
int input_user(std::string &command){
	do{
		std::cout << "~$ ";
		std::cin >> command;
		user_command(command);
	}while(!login);
	return 0;
}

//command

void whoami(){
	std::cout << user_init << std::endl;
}

void passwd(){
	std::cout << "all user password:" << std::endl;
	std::cout << "	" << passwd_user << std::endl;
	std::cout << "	" << passwd_root << std::endl;
}

void all_user(){
	std::cout << "all user:" << std::endl;
	std::cout << "	" << root_user << std::endl;
	std::cout << "	" << normal_user << std::endl;
}

void quit_login(std::string &command){
	user_init = "";
	password = "";
	login = false;
	login_init();
	command_init(command);
}

void echo(std::string &command){
	if (command.substr(0, 5) == "echo "){
		std::cout << command.substr(5);
		std::cout << command;
	}
}

void exit(){
	login = false;
	exit(0);
}

void help(){
	if(user_init == root_user){
		std::cout << "whoami, passwd, user, echo, login, exit, help" << std::endl;
	}else if(user_init == normal_user){
		std::cout << "whoami, echo, login, exit, help" << std::endl;
	}else{
		exit(0);
	}
}
