import QtQuick 2.0

Row {
    property string label: ""
    property string text: ""

    id: root

    Text {
        text: root.label
        width: 70
    }
    Text {
        text: root.text
        width: 100
    }
}
