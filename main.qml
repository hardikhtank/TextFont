import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import CustomControls 1.0  // Add this import

ApplicationWindow {
    title: qsTr("Text Renderer Comparison")
    width: 1280
    height: 720
    visible: true
//    color:"black"
    Rectangle{
        anchors.fill: parent
        color:"black"
    }


    Row {
        anchors.fill: parent
        spacing: 10


        // Left column - QSGSimpleTextNode
        Column {
            width: parent.width / 3
            spacing: 10
            Repeater {
                model: 10
                Rectangle {
                    width: parent.width - 20
                    height: 60
                    border.width: 2
                    border.color: "white"
                    color: "transparent"

                    Text {
                        anchors.fill: parent
                        text: "Sample Text " + (index + 1)
                        font.family: testFonts[index % testFonts.length]
                        font.pixelSize: 12 + index * 2
                        color: testColors[index % testColors.length]
                        horizontalAlignment: textAlignments[index % textAlignments.length]
                        verticalAlignment: Text.AlignVCenter
                        renderType: Text.NativeRendering
                    }
                }
            }
        }

        // Middle column - QPainter
        Column {
            width: parent.width / 3
            spacing: 10
            Repeater {
                model: 10
                Rectangle {
                    width: parent.width - 20
                    height: 60
                    border.width: 2
                    border.color: "white"
                    color: "transparent"

                    CustomTextPainter {
                        anchors.fill: parent
                        text: "Sample Text " + (index + 1)
                        font.family: testFonts[index % testFonts.length]
                        font.pixelSize: 12 + index * 2
                        color: testColors[index % testColors.length]
                        alignment: testAlignments[index % testAlignments.length]
                    }
                }
            }
        }

        // Right column - Properties Description
        Column {
            width: parent.width / 3
            spacing: 10
            Repeater {
                model: 10
                Rectangle {
                    width: parent.width - 20
                    height: 60
                    radius: 5
                    border.width: 2
                    border.color: "white"
                    color:"black"

                    Text {
                        anchors.fill: parent
                        anchors.margins: 5
                        verticalAlignment: Text.AlignVCenter
                        wrapMode: Text.WordWrap
                        text: "Font: " + testFonts[index % testFonts.length] + " | " +
                              "Size: " + (12 + index * 2) + "px | " +
                              "Color: " + testColors[index % testColors.length] + " | " +
                              "Alignment: " + (testAlignments[index % testAlignments.length] & Qt.AlignHCenter ? "Center" :
                                             testAlignments[index % testAlignments.length] & Qt.AlignRight ? "Right" : "Left")
                        font.pixelSize: 12
                        color:"white"
                        renderType: Text.NativeRendering
                    }
                }
            }
        }
    }

    property var testFonts: ["beIN NEW Arabic font 2017", "beIN NEW Arabic font 2017 DemiBd", "beIN NEW Arabic font 2017 Light", "beIN NEW Arabic font 2017 Bold","Gotham Narrow Book","Gotham Narrow Medium","Gotham Narrow Light","Gotham Narrow Bold"]
    property var testColors: ["white", "blue", "red", "green"]
    property var testAlignments: [
        Qt.AlignLeft | Qt.AlignVCenter,
        Qt.AlignHCenter | Qt.AlignVCenter,
        Qt.AlignRight | Qt.AlignVCenter
    ]
    property var textAlignments: [
        Text.AlignLeft,
        Text.AlignHCenter,
        Text.AlignRight
    ]


}
