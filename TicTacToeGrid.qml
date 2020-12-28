import QtQuick 2.0
import QtQml 2.12

Grid {
    property bool enabled: false

    columns: 3
    rows: 3
    spacing: 2

    Square {
        id: b0
        boxNumber: 0
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box0
            onTextChanged: {
                b0.text = text
            }
            onBackgroundChanged: {
                b0.background = backgroundColor
            }
        }
    }
    Square {
        id: b1
        boxNumber: 1
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box1
            onTextChanged: {
                b1.text = text
            }
            onBackgroundChanged: {
                b1.background = backgroundColor
            }
        }
    }
    Square {
        id: b2
        boxNumber: 2
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box2
            onTextChanged: {
                b2.text = text
            }
            onBackgroundChanged: {
                b2.background = backgroundColor
            }
        }
    }

    Square {
        id: b3
        boxNumber: 3
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box3
            onTextChanged: {
                b3.text = text
            }
            onBackgroundChanged: {
                b3.background = backgroundColor
            }
        }
    }
    Square {
        id: b4
        boxNumber: 4
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box4
            onTextChanged: {
                b4.text = text
            }
            onBackgroundChanged: {
                b4.background = backgroundColor
            }
        }
    }
    Square {
        id: b5
        boxNumber: 5
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box5
            onTextChanged: {
                b5.text = text
            }
            onBackgroundChanged: {
                b5.background = backgroundColor
            }
        }
    }

    Square {
        id: b6
        boxNumber: 6
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box6
            onTextChanged: {
                b6.text = text
            }
            onBackgroundChanged: {
                b6.background = backgroundColor
            }
        }
    }
    Square {
        id: b7
        boxNumber: 7
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box7
            onTextChanged: {
                b7.text = text
            }
            onBackgroundChanged: {
                b7.background = backgroundColor
            }
        }
    }
    Square {
        id: b8
        boxNumber: 8
        enabled: parent.enabled
        background: "darkgray"
        Connections {
            target: box8
            onTextChanged: {
                b8.text = text
            }
            onBackgroundChanged: {
                b8.background = backgroundColor
            }
        }
    }
}
