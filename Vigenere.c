#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void printline(){
	int i;
	for(i = 0; i < 5; i++){
		printf("#####");
	}
	printf("\n");
}

int charInRange(char c){
	if(c >= 'a' && c <= 'z'){
		return 1;
	}
	else if(c >= 'A' && c <= 'Z'){
		return 0;
	}
	return -1;
}

int valid(char s[]){
	int i;
	for(i = 0; i < strlen(s); i++){
		if(charInRange(s[i]) == -1){
			return -1;
		}
	}
	return 0;
}

char nextchar(char c){
	int a = charInRange(c);
	if(a == 0){
		c = toupper(c);
		if(c == 'Z'){
			c = 'A';
		}
		else{
			c++;
		}
		return c;
	}
	else if(a == 1){
		c = tolower(c);
		if(c == 'z'){
			c = 'a';
		}
		else{
			c++;
		}
		return c;
	}
	return -1;
}

char beforechar(char c){
	int a = charInRange(c);
	if(a == 0){
		c = toupper(c);
		if(c == 'A'){
			c = 'Z';
		}
		else{
			c--;
		}
		return c;
	}
	else if(a == 1){
		c = tolower(c);
		if(c == 'a'){
			c = 'z';
		}
		else{
			c--;
		}
		return c;
	}
	return -1;
}

char decrypt(int a, int c){
	int b = charInRange(a);
	int i,diff,temp;
	if(b == 0){
		a = 26 - (toupper(a) - 'A');
		diff = toupper(c) - 'A';
		temp = 'A';
	}
	else if(b == 1){
		a = 26 - (tolower(a) - 'a');
		diff = tolower(c) - 'a';
		temp = 'a';
	}
	if(b >= 0){
		for(i = 0; i < a; i++){
			if((temp = beforechar(temp)) == -1){
				printline();
				printf("Error due getting beforechar!\n");
				exit(EXIT_FAILURE);
			}
		}
		for(i = 0; i < diff; i++){
			if((temp = beforechar(temp)) == -1){
				printline();
				printf("Error due getting beforechar!\n");
				exit(EXIT_FAILURE);
			}
		}
		return temp;
	}
	return -1;
}

int encrypt(int a, int c){
	int b = charInRange(a);
	int i,diff,temp;
	if(b == 0){
		a = toupper(a) - 'A';
		diff = toupper(c) - 'A';
		temp = 'A';
	}
	else if(b == 1){
		a = tolower(a) - 'a';
		diff = tolower(c) - 'a';
		temp = 'a';
	}
	if(b >= 0){
		for(i = 0; i < a; i++){
			if((temp = nextchar(temp)) == -1){
				printline();
				printf("Error due getting nextchar!\n");
				exit(EXIT_FAILURE);
			}
		}
		for(i = 0; i < diff; i++){
			if((temp = nextchar(temp)) == -1){
				printline();
				printf("Error due getting nextchar!\n");
				exit(EXIT_FAILURE);
			}
		}
		return temp;
	}
	return -1;
}

int main(int argc, char * argv[]){
	if(argc == 4){
		int counterPW = 0, c;
		char * pw = argv[3], filename[29];
		FILE * file;
		FILE * newFile;
		if(valid(pw) == -1){
			printline();
			printf("No valid password. Only use letters!");
			exit(EXIT_FAILURE);
		}
		if((file = fopen(argv[1],"r")) == NULL){
			printline();
			printf("Error due oppening file. Make sure this file exists!\n");
			printf("Use 'Vigenere.exe help' for more help.\n");
			exit(EXIT_FAILURE);
		}
		printf("File content:\n");
		printline();
		while((c = getc(file)) != EOF){
			putchar(c);
		}
		putchar('\n');
		fclose(file);
		printline();
		if(*argv[2] == 'e'){
			printf("Choose a filename for your encrypted text file (max 25 letters):\n");
		}
		else if(*argv[2] == 'd'){
			printf("Choose a filename for your decrypted text file (max 25 letters):\n");
		}
		else{
			printf("Mode does not exist.\n");
			exit(EXIT_FAILURE);
		}
		printline();
		if(*argv[2] == 'e'){
			printf("Start encryption...\n");
		}
		else if(*argv[2] == 'd'){
			printf("Start decryption...\n");
		}
		printline();
		scanf("%25s", filename);
		printline();
		sprintf(filename, "%s%s",filename, ".txt");
		if((newFile = fopen(filename, "w+")) == NULL){
			printline();
			printf("Error due oppening new file.\n");
			exit(EXIT_FAILURE);
		}
		if((file = fopen(argv[1],"r")) == NULL){
			printline();
			printf("Failure to read file.\n");
			exit(EXIT_FAILURE);
		}
		while((c = getc(file)) != EOF){
			if(charInRange(c) >= 0){
				if(*argv[2] == 'e'){
					c = encrypt(c, pw[counterPW]);
				}
				else{
					c = decrypt(c, pw[counterPW]);
				}
				if(c == -1){
					putchar('\n');
					printline();
					printf("Unexpected output.\n");
					exit(EXIT_FAILURE);
				}
				if(strlen(pw) > counterPW+1){
					counterPW++;
				}
				else{
					counterPW = 0;
				}
			}
			putchar(c);
			fprintf(newFile, "%c", c);
		}
		putchar('\n');
		fclose(newFile);
		fclose(file);
		if(*argv[2] == 'e'){
			printline();
			printf("Encryption done!\n");
		}
		else{
			printline();
			printf("Decryption done!\n");
		}
		exit(EXIT_SUCCESS);
	}
	else{
		if(argc == 2){
			if(strcmp(argv[1],"help") == 0){
				printline();
				printf("Syntax console command:\n");
				printf("> Vigenere.exe <filename> <mode> <password>\n");
				printline();
				printf("File:\n");
				printf("> Textfile in ANSI-Coding\n");
				printf("Mode:\n");
				printf("> 'e': encrypt\n");
				printf("> 'd': decrpyt\n");
				printline();
				exit(EXIT_SUCCESS);
			}
			else{
				printline();
				printf("Use 'Vigenere.exe help' for more help.");
				printline();
				exit(EXIT_FAILURE);
			}
		}
		else{
			printline();
			printf("Not enough arguments.\n");
			printf("Use 'Vigenere.exe help' for more help.\n");
			printline();
			exit(EXIT_FAILURE);
		}
	}
}

