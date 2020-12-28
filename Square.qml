import QtQuick 2.0

Rectangle {
    property string text: ""
    property int boxNumber

    width: 100
    height: 100
    border.width: 1
    border.color: "gray"

    Text {
        id: txt
        text: parent.text
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (txt.text !== "") return
            game.move(boxNumber)
        }
    }
}
