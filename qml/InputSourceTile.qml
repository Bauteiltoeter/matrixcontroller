import QtQuick 2.0

Item {
    property string label;
    property string icon: "videocam.svg";
    property int inputNumber: -1;
    id: root

    width: 90; height: 90

    MouseArea {
        id: mouseArea

        width: 90; height: 90
        anchors.centerIn: parent

        drag.target: tile

        onReleased:{
            tile.Drag.drop();
            parent=root
        }

        MyPanel {
            id: tile

            width: 90; height: 90
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

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
                text: root.label
            }


            Drag.keys: [ "inputTile" ]
            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x: width/2
            Drag.hotSpot.y: height/2
            states: State {
                when: mouseArea.drag.active
                ParentChange { target: tile; parent: root }
                AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
            }

        }
    }
}
