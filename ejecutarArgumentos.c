#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF_SIZE 255


int main(int argc, char **argv) {
	/* Error de uso en el archivo */
	if (argc < 2) {
		printf("MAL USO\n\t./ejecutarArgumentos <comando> [args..]\n");
		return 1;
	}

	int p[2]; // Pipe para la comunicación padre-proceso
	pid_t pid;

	char buffer[BUFF_SIZE]; // Buffer de lectura para el padre
	size_t n; // Cantidad de caracteres leídos


	pipe(p);
	argv++; // Omitimos el puntero al primer elemento de entrada (el nombre del programa) para poder ejecutar el resto

	if (!(pid = fork())) { // Proceso hijo, ejecuta los comandos y los transmite al pipe

		close(p[0]); // El proceso hijo no lee del pipe
		dup2(p[1], STDOUT_FILENO); // Redirigimos la salida estandar al pipe
		close(p[1]); // Una vez redirigida la salida al pipe, podemos cerrar su referencia

		// Ejecución desde el hijo
		execvp(argv[0], argv);

		perror("'execvp' en Hijo");
		return 2;

	} else {  // Proceso padre, lee cada salida del hijo por el pipe
		close(p[1]);

		while((n=read(p[0], buffer, BUFF_SIZE-1)) > 0) {
			buffer[n] = '\0';
			printf("Padre lee de [%d]: %s\n", pid, buffer);
		}

		close(p[0]);
		waitpid(pid, 0, 0);
	}

	return 0;
}
