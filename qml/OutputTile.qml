import QtQuick 2.0

DropArea {
    property string label;
    property string icon: "videocam.svg";
    property int inputNumber: -1;

    signal inputDropped;

    id: dragTarget

    property alias dropProxy: dragTarget

    width: 90; height: 90
    keys: [ "inputTile" ]

    onDropped: {
        inputDropped();
    }

    MyPanel {
        id: dropRectangle

        anchors.fill: parent

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottom:nameText.top
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            smooth: true
            source: "../images/" + icon
            fillMode: Image.PreserveAspectFit
        }


        MyText {
            id: nameText

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            fontSize: 10
            text: dragTarget.label
        }

        states: [
            State {
                when: dragTarget.containsDrag
                PropertyChanges {
                    target: dropRectangle
                    borderColor: customColor.activeBorderColor
                }
            }
        ]
    }
}
