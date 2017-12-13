import QtQuick 2.0

DropArea {
    property string name: "Output 1"

    id: dragTarget

    property alias dropProxy: dragTarget

    width: 90; height: 90
    keys: [ "inputTile" ]

    onDropped: {
        console.log("Something dropped");
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
            source: "../images/monitor.svg"
            fillMode: Image.PreserveAspectFit
        }


        MyText {
            id: nameText

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            fontSize: 10
            text: dragTarget.name
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
