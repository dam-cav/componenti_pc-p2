# Progetto Programmazione ad Oggetti, "Componenti PC"

Progetto per il corso di Programmazione ad Oggetti per la laurea triennale in Informatica presso [Università degli Studi di Padova](https://www.unipd.it/), estate 2017.



![](Screenshot/screenshot.png)



## Descrizione Progetto

*(per la descrizione completa vedi* [relazione](relazione.pdf)*)*

Il progetto consiste in un un programma con il quale l’utente finale possa visionare e scegliere componenti di pc desktop (fissi) da assemblare.

Le componenti presenti sono le principali parti che costituiscono un pc fisso: processore, scheda madre, memorie ram, scheda video, dissipatore, hard disk, alimentatore.

Ogni utente si può registrare autonomamente dalla finestra di login come utente comune senza particolari privilegi, una volta loggato ha una propria wishlist (letteralmente “lista dei desideri”) dove può annotare i componenti scelti da un catalogo completo mentre ne cerca altri da confrontare o da aggiungere; questa lista rimane salvata anche a chiusura del programma.

Per semplificare la ricerca delle componenti è possibile filtrare la lista per tipo di componente, cercare nomi specifici e ordinarla per nome o per prezzo.

Mentre ogni utente può aggiungere e rimuovere componenti dalla propria wishlist come vuole, per gestire il catalogo completo è necessario avere dei permessi.

![](Screenshot/screenshot2.png)

I permessi che distinguono gli utenti comuni dagli amministratori sono due:

- La possibilità di gestire il catalogo, posseduta da amministratori e tecnici, con la quale è possibile rimuovere e modificare componenti dal catalogo completo.
- La possibilità di gestire gli altri utenti, posseduta solo dagli amministratori, con la quale è possibile promuovere, declassare o eliminare gli altri utenti concedendo o togliendo loro i permessi (non è possibile però modificare i propri permessi o eliminare sé stessi); gli amministratori possono anche eventualmente modificare il loro profilo (ID, Nome, Cognome, Password - quest’ultima rimane comunque non visibile a nessuno -) qualora fosse necessario.

## Tecnologie utilizzate

- C++
- QT 5.9

