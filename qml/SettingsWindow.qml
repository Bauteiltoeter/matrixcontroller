import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtGraphicalEffects 1.0


Window {
    visible: false
    width: 400
    height: 400
    title: qsTr("Settings")


    Rectangle {
        anchors.fill: parent

        color: customColor.background


        MyText {
            id: inputText
            text: "Input configuration:"
            fontSize: 16

            anchors.top: parent.top
            anchors.topMargin: 20
        }


        MyComboBox {
            id: inputSelector
            anchors.top: inputText.bottom
            anchors.topMargin: 10
            model: ListModel {
                   id: cbItems
                   ListElement { text: "Cam 1 (In 1)" }
                   ListElement { text: "Cam 2 (In 2)" }
                   ListElement { text: "Krautsalat (In 3)" }
                   ListElement { text: "In 4" }
                   ListElement { text: "In 5" }
                   ListElement { text: "In 6" }
                   ListElement { text: "In 7" }
                   ListElement { text: "In 8" }
                   ListElement { text: "In 9" }
                   ListElement { text: "In 10" }
                   ListElement { text: "In 11" }
                   ListElement { text: "In 12" }
                   ListElement { text: "In 13" }
                   ListElement { text: "In 14" }
                   ListElement { text: "In 15" }
                   ListElement { text: "In 16" }
               }
        }

        MyIconButton {
            hasActiveLed: true
            activeLedColor: customColor.green
            isCheckable: true
            icon: "power.svg"
            anchors.left: inputSelector.right
            anchors.top: inputText.top
            anchors.leftMargin: 20
        }

        Grid {
            id: inputGrid
            columns: 2
            anchors.top: inputSelector.bottom
            anchors.topMargin: 10
            spacing: 5
            verticalItemAlignment: Grid.AlignVCenter

            MyText {
                id: inputNameText
                text: "Input name:"
                fontSize: 16
            }

            MyTextField {
                height: 30
                fontSize: 16
            }

            MyText {
                text: "Input type:"
                fontSize: 16

            }

            MyComboBox {
                model: ListModel {
                       ListElement { text: "Camera" }
                       ListElement { text: "Mixer" }
                       ListElement { text: "PC" }
                       ListElement { text: "VJ" }
                   }
            }
        }

        MyText {
            id: outputText
            text: "Output configuration:"
            fontSize: 16

            anchors.top: inputGrid.bottom
            anchors.topMargin: 50
        }


        MyComboBox {
            id: outputSelector
            anchors.top: outputText.bottom
            anchors.topMargin: 10
            model: ListModel {
                   ListElement { text: "Capture 0-00 (Out 1)" }
                   ListElement { text: "Capture 0-01 (Out 2)" }
                   ListElement { text: "Roland-1 (Out 3)" }
                   ListElement { text: "Roland-3 (Out 4)" }
                   ListElement { text: "Beamer 1 (Out 5)" }
                   ListElement { text: "Beamer 2 (Out 6)" }
                   ListElement { text: "Out 7" }
                   ListElement { text: "Out 8" }
                   ListElement { text: "Out 9" }
                   ListElement { text: "Out 10" }
                   ListElement { text: "Out 11" }
                   ListElement { text: "Out 12" }
                   ListElement { text: "Out 13" }
                   ListElement { text: "Out 14" }
                   ListElement { text: "Out 15" }
                   ListElement { text: "Out 16" }
               }
        }

        MyIconButton {
            hasActiveLed: true
            activeLedColor: customColor.green
            isCheckable: true
            icon: "power.svg"
            anchors.left: outputSelector.right
            anchors.top: outputText.top
            anchors.leftMargin: 20
        }

        Grid {
            columns: 2
            anchors.top: outputSelector.bottom
            anchors.topMargin: 10
            spacing: 5
            verticalItemAlignment: Grid.AlignVCenter

            MyText {
                id: outputNameText
                text: "Output name:"
                fontSize: 16
            }

            MyTextField {
                height: 30
                fontSize: 16
            }

            MyText {
                text: "Output type:"
                fontSize: 16

            }

            MyComboBox {
                model: ListModel {
                       ListElement { text: "Capture" }
                       ListElement { text: "Mixer" }
                       ListElement { text: "Monitor" }
                       ListElement { text: "Beamer" }
                       ListElement { text: "Recorder" }
                   }
            }
        }

    }
}
