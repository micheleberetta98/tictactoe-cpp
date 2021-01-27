# TicTacToe in CPP

Questo progetto realizza il gioco del tris a due giocatori, sia con GUI sia con CLI.

## Struttura

I file nel progetto contengono, oltre all'interfaccia per terminale, anche la GUI realizzata con Qt.

Il file `CMakeLists.txt` individua il progetto di Qt, che fa uso di
- Il file `main.cpp`
- Tutti i file in `controllers`
- I file `.qml` e `.qrc`

La CLI è realizzata da
- Il file `main-cli.cpp`
- Tutti i file in `cli-ui`

I file sotto `lib` sono invece condivisi.

## Compilazione ed esecuzione

Per la GUI è necessario usare *Qt Creator*.
Per la CLI invece è presente lo script `build.sh`, in cui è usato `g++` per compilare in un file eseguibile
di nome `tictactoe`.
