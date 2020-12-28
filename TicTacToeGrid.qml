import QtQuick 2.0
import QtQml 2.12

Grid {
    columns: 3
    rows: 3
    spacing: 2

    Square {
        id: b0
        boxNumber: 0
        Connections {
            target: box0
            onTextChanged: {
                b0.text = text
            }
        }
    }
    Square {
        id: b1
        boxNumber: 1
        Connections {
            target: box1
            onTextChanged: {
                b1.text = text
            }
        }
    }
    Square {
        id: b2
        boxNumber: 2
        Connections {
            target: box2
            onTextChanged: {
                b2.text = text
            }
        }
    }

    Square {
        id: b3
        boxNumber: 3
        Connections {
            target: box3
            onTextChanged: {
                b3.text = text
            }
        }
    }
    Square {
        id: b4
        boxNumber: 4
        Connections {
            target: box4
            onTextChanged: {
                b4.text = text
            }
        }
    }
    Square {
        id: b5
        boxNumber: 5
        Connections {
            target: box5
            onTextChanged: {
                b5.text = text
            }
        }
    }

    Square {
        id: b6
        boxNumber: 6
        Connections {
            target: box6
            onTextChanged: {
                b6.text = text
            }
        }
    }
    Square {
        id: b7
        boxNumber: 7
        Connections {
            target: box7
            onTextChanged: {
                b7.text = text
            }
        }
    }
    Square {
        id: b8
        boxNumber: 8
        Connections {
            target: box8
            onTextChanged: {
                b8.text = text
            }
        }
    }
}
