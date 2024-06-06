Algoritmo gestionarPartidos
	// Declaración de variables
	Definir opcionMenu Como Entero;
	// Menú principal
	Escribir 'Seleccione una opción:';
	Escribir '1. Ingresar como estudiante';
	Escribir '2. Ingresar como registrador de partidos';
	Leer opcionMenu;
	Segun opcionMenu Hacer
		1:
			// Ingresar como estudiante
			IngresarComoEstudiante();
		2:
			// Ingresar como registrador de partidos
			IngresarComoRegistrador();
		De Otro Modo:
			Escribir 'Opción no válida';
	FinSegun
FinAlgoritmo

// Función para ingresar como estudiante
Funcion IngresarComoEstudiante
	// Declaración de variables
	Definir nombreAlumno, cif, opcionPartido Como Cadena;
	Escribir 'Ingrese el nombre del alumno: ';
	Leer nombreAlumno;
	Escribir 'Ingrese el CIF del alumno: ';
	Leer cif;
	// Mostrar los partidos disponibles
	Escribir 'Partidos Disponibles:';
	Escribir '1. Partido 1';
	Escribir '2. Partido 2';
	Escribir '3. Partido 3';
	Escribir 'Seleccione el número del partido al que quiere asistir: ';
	Leer opcionPartido;
	// Marcar el partido seleccionado como asistido
	Escribir 'El alumno ', nombreAlumno, ' asistió al partido ', opcionPartido;
FinFuncion

// Función para ingresar como registrador de partidos
Funcion IngresarComoRegistrador
	// Declaración de variables
	Definir nombreRegistrador, cedulaRegistrador, fechaPartido, equipoRival Como Cadena;
	Definir puntuacionJaguares, puntuacionRival Como Entero;
	Escribir 'Ingrese el nombre del registrador: ';
	Leer nombreRegistrador;
	Escribir 'Ingrese la cedula del registrador: ';
	Leer cedulaRegistrador;
	Escribir 'Ingrese la fecha del partido (DIA/MES/AÑO): ';
	Leer fechaPartido;
	Escribir 'Ingrese el nombre del equipo rival: ';
	Leer equipoRival;
	Escribir 'Ingrese la puntuación final de los Jaguares UAM (SOLO EL NUMERO): ';
	Leer puntuacionJaguares;
	Escribir 'Ingrese la puntuación del equipo rival (SOLO EL NUMERO): ';
	Leer puntuacionRival;
	// Mostrar los datos del partido ingresado
	Escribir 'El partido ingresado es el siguiente:';
	Escribir 'Fecha: ', fechaPartido;
	Escribir 'Equipo rival: ', equipoRival;
	Escribir 'Puntuación de los Jaguares UAM: ', puntuacionJaguares;
	Escribir 'Puntuación del equipo rival: ', puntuacionRival;
FinFuncion
