import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 91*18
    height: 480
    title: qsTr("Video matrix controller")

    Item {
        id: customColor
        property color green: "#19ff00"
        property color red: "#ff3f00"
        property color yellow: "#A1A203"
        property color textColor: "#CCCCCC"
        property color background: "#303030"
        property color borderColor: "#202020"
        property color activeBorderColor: "#CCCCCC"
    }

    SettingsWindow {
        id: settings;
    }


    Rectangle {
        anchors.fill: parent

        color: customColor.background


        MyIconButton {
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: 10
            anchors.rightMargin: 10
            width: 40
            height: 40
            icon: "settings.svg"

            onClicked: {
                settings.visible = true
            }
        }
    }



    Grid {
        id: inputRow
        objectName: "inputRow"
        anchors.top: parent.top
        anchors.topMargin: 60
        rows: 1
        spacing: 1

       /* Repeater {
            model: 16

            InputSourceTile {

            }
        }*/
    }

    Canvas {
        id: mycanvas
        width: 100
        anchors.top: inputRow.bottom
        anchors.bottom: outputRow.top
        anchors.left: inputRow.left
        anchors.right:  inputRow.right
        onPaint: {
            var ctx = getContext("2d");
            ctx.lineWidth = 3

            ctx.strokeStyle = "#cccccc"
            ctx.beginPath()
            ctx.moveTo(30,0)
            ctx.lineTo(90,150)
            ctx.stroke()

            ctx.beginPath()
            ctx.moveTo(30,0)
            ctx.lineTo(150,150)
            ctx.stroke()

            ctx.beginPath()
            ctx.moveTo(30,0)
            ctx.lineTo(210,150)
            ctx.stroke()

            ctx.beginPath()
            ctx.moveTo(30+60*8,0)
            ctx.lineTo(30,150)
            ctx.stroke()

            ctx.beginPath()
            ctx.moveTo(30+60*8,0)
            ctx.lineTo(30+60*13,150)
            ctx.stroke()

            ctx.beginPath()
            ctx.moveTo(30+60*7,0)
            ctx.lineTo(30+60*14,150)
            ctx.stroke()

        }
    }

    Grid {
        id: outputRow
        objectName: "outputRow"
        anchors.top: inputRow.bottom
        anchors.topMargin: 150
        rows: 1
        spacing: 1


    }











}
