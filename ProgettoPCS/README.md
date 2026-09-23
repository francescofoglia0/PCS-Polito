# C++ Object-Oriented Circuit Solver

Un simulatore di circuiti elettrici basato su architettura Object-Oriented e scritto in **C++17 moderno**. 

Questo progetto analizza topologie di circuiti elettrici utilizzando l'**Analisi Nodale Modificata (MNA)** per assemblare il sistema lineare sottostante (Ax = b). Il sistema viene poi risolto in modo efficiente utilizzando un'implementazione personalizzata dell'algoritmo del **Gradiente Coniugato (CG)**, ottimizzato tramite le strutture dati della libreria **Eigen3**.

## Funzionalità Principali

*   **Paradigma RAII e Memory Safety:** Gestione dinamica dei componenti del circuito tramite `std::unique_ptr`. La memoria viene allocata e deallocata automaticamente, garantendo l'assenza totale di memory leak (validato tramite AddressSanitizer).
*   **Architettura Object-Oriented:** Design polimorfico con una classe base `Component` facilmente estendibile per supportare resistori, condensatori, induttori e generatori.
*   **Risolutore Numerico Custom:** Implementazione da zero del metodo iterativo del Gradiente Coniugato per la risoluzione del sistema lineare, ideale per matrici di grandi dimensioni (sparse).
*   **Build System Robusto:** Configurato con **CMake**, include opzioni per la compilazione con massima ottimizzazione (`-O3`) e profiling della memoria (`-fsanitize=address`).

## Prerequisiti

Per compilare ed eseguire il progetto, assicurati di avere installati nel tuo sistema:

*   Un compilatore che supporti **C++17** (GCC, Clang o MSVC)
*   **CMake** (versione 3.20 o superiore)
*   Libreria **Eigen3** (per l'algebra lineare)

## Compilazione ed Esecuzione

Il progetto utilizza CMake come sistema di build. Segui questi step per compilare il codice:

1. Clona il repository e naviga nella cartella del progetto:
   ```bash
   git clone [https://github.com/tuo-username/circuit-solver.git](https://github.com/tuo-username/circuit-solver.git)
   cd circuit-solver
