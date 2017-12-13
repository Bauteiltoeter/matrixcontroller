import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtGraphicalEffects 1.0

ComboBox {
    id: cb

    width: 250


    style: ComboBoxStyle {
        dropDownButtonWidth : 20

        background: MyPanel {
            height: cb.height
            width: cb.width
        }

        label: MyText{
            text: control.currentText
            fontSize: 16
        }

        // drop-down customization here
            property Component __dropDownStyle: MenuStyle {
                __maxPopupHeight: 600
                __menuItemType: "comboboxitem"

                frame: Rectangle {              // background
                    radius: 10
                    border.color: customColor.borderColor
                    border.width: 4
                    color: "#303030"
                    LinearGradient {
                        anchors.fill: parent
                        anchors.margins: 3

                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "#404040" }
                            GradientStop { position: 1.0; color: "#202020" }
                        }
                    }
                }
                padding.top: 12
                padding.bottom: 12

                itemDelegate.label:             // an item text
                    Text
                    {
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                        font.family: "Courier"
                        font.capitalization: Font.SmallCaps
                        color: "white"
                        text: styleData.text
                    }

                itemDelegate.background: Rectangle {  // selection of an item
                    radius: 5
                    color: styleData.selected ? "#606060" : "transparent"
                }

                __scrollerStyle: ScrollViewStyle { }
            }

            property Component __popupStyle: Style {
                property int __maxPopupHeight: 400
                property int submenuOverlap: 100

                property Component menuItemPanel: Text {
                    text: "NOT IMPLEMENTED"
                    color: "red"
                    font {
                        pixelSize: 14
                        bold: true
                    }
                }

                property Component __scrollerStyle: null
                }

    }
}
