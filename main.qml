import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 500
    height: 325
    maximumWidth: 500
    maximumHeight: 325
    minimumWidth: 500
    minimumHeight: 325
    visible: true
    title: qsTr("Tic Tac Toe")

    Row {
        anchors.fill: parent
        padding: 10
        spacing: 10

        TicTacToeGrid {
            id: grid
            enabled: false
            Connections {
                target: game
                onGameStatusChanged: {
                    grid.enabled = started
                }
            }
        }
        Column {
            spacing: 5
            LabelledValue {
                id: currentPlayerLabel
                label: "Turno di:"
                text: "---"
                Connections {
                    target: currentPlayer
                    onTextChanged: {
                        currentPlayerLabel.text = playerName
                    }
                }
            }
            LabelledValue {
                id: winnerLabel
                label: "Vincitore:"
                text: "---"
                Connections {
                    target: winner
                    onTextChanged: {
                        winnerLabel.text = winnerName
                    }
                }
            }
            Button {
                text: "Nuovo gioco"
                onClicked: game.newGame()
            }
        }
    }
}
