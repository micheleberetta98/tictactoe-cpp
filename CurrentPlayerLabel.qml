import QtQuick 2.0
import QtQml 2.12

Row {
    Text {
        text: "Turno di: "
        width: 70
    }
    Text {
        id: player
        text: ""
        width: 100

        Connections {
            target: currentPlayer
            onTextChanged: {
                player.text = playerName
            }
        }
    }
}
