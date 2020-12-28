import QtQuick 2.0

Rectangle {
    property string text: ""
    property int boxNumber

    width: 100
    height: 100
    color: "lightgray"

    Text {
        id: txt
        text: parent.text
        color: "#333"
        anchors.centerIn: parent
        font.family: "Helvetica"
        font.pointSize: 50
        font.weight: Font.Bold
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (txt.text !== "") return
            game.move(boxNumber)
        }
    }
}
