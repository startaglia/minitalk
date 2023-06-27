* STEPS.
	- imposta il progetto con il makefile correttamente													OK
	- imposta la ricezione del segnale sul file SERVER							
    	- il server prende solo un argomento da terminale
    	- crea una struttura di tipo sigaction 
		- prendi il pid e stampalo a schermo
    	- setta il gestore di segnale al valore sig_action della struttura ( che sarebbe il puntatore al gestore di segnale)
    	- azzera le maschere del segnale (sigemptyset(&act.sa_mask);) 
    	- in un ciclo infinito alla funzione sigaction() chiama il ricettore di segnale per SIGUSR1 e SIGUSR2, passa l'indirizzo di memoria della struttura e metti NULL all' ultimo parametro(che sarebbe il segnale ricevuto precedentemente, quasi sempre non si usa) poi metti in pausa altrimenti esci con errore
        	- la funzione che stampa il char, siccome l'ho settata su sa_sigaction prende tre parametri, il primo e' il segnale, il secondo e' un puntatore alla struttura siginfo_t e terzo il context. La struttura siginfo e' un tipo di struttura contenuto nella libreria sygnal che si riempie con le info, tra cui il PID, quando viene ricevuto un segnale (si riempie perche' nella struttura sig_action c'é un campo void     (*sa_sigaction)(int, siginfo_t *, void *));
        	-   in primo luogo se il segnale che arriva dal client e' 1 (quindi se arriva SIGUSR1), faccio il bitshifting su una maschera 0x01 per scorrere bit significativi e con il bitwise li sovrappongo/"assegno" al campo binario del char in questione, cosi facendo otterro' bit per bit il valore binario del char da stampare
            - ogni volta che assegno a res il valore bitwise di bitshifting incremento bit (res e bit sono due variabili statiche)
        	- alla fine controllo che bit sia == 8, se e' arrivato ad 8 prima cosa controllo che res non sia == 0, se é cosi significa che il char arrivato é \0 quindi il msg e' terminato e posso stampare il msg di ritorno al client.
        	- Sotto il controllo res == 0 stampo il valore del campo binario trovato, quindi il valore del char, prendo 8 come campo binario perche' in un campo binario di 8 bit posso avere 255 valori, che e' la nostra tabella ASCII
        	- azzero bit e res per assegnargli i valori del prossimo char
	- imposta l'invio del segnale sul file CLIENT
    	- il client prende 2 argomenti, il primo e' il PID del processo, il secondo e' la stringa da stampare
    	- controllo che gli argomenti siano 3, se sono tre faccio atoi del pid che ottengo dal server, quindi sarebbe av1
    	- ciclo finche il secondo parametro[i] esiste, quindi analizzo char per char
    	- chiamo una funzione che si occupera' di inviare il segnale al server, passandogli il pid e il char in questione
        	- finche' bit < 8 confronto bit a bit (&) il char in questione con una maschera binaria che shifta ogni volta a sinistra (c & (0x01 << bit))
          	- se il risultato e' 1 significa che nel suo campo binario in quel bit ce' un 1, quindi entra e puo' mandare al server con kill, sul segnale SIGUSR1, il bit trovato.
          	- altrimenti manda il bit trovato (che sarebbe 0) al server sul segnale SIGUSR2.
          	- fare un usleep(500) per evitare che due segnali si sovrappongano
          	- incrementa bit.
      	- Appena uscito dalla funzione vuol dire che il messaggio e' terminato quindi posso stampare il messaggio di ritorno al client agganciandolo al segnale SIGUSR2 (la scelta del segnale tra i due e' la stessa cosa, e' preferibile pero' che sia quello che conteneva gli 0), per fare ció utilizzo un altro gestore di segnale, in questo caso send_message che si occupera' semplicemente di mandare il messaggio di conferma
      	- Ultima cosa mando un char \0 per terminare il messaggio di conferma
* NOTIONS
  	- SIGACTION
		La funzione sigaction() e' una funzione che viene utilizzata per gestire i segnali di un programma