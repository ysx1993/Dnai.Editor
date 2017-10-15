import DulyUtils 1.0
import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

Item {
    id: defaultPanel

    property string title: "Title"
    property alias consoleRef: textArea
    property alias consoleListDelegate: textArea.delegate
    property alias heightInfoPanel: mainColumn.height
    property alias widthInfoPanel: mainColumn.width
    property alias heightItem: defaultPanel.height

    Rectangle {
        id: rectangle
        color: "#303030"
        anchors.fill: parent
        border.color: "#3f3f46"
        border.width: 1
        Material.theme: Material.Dark
        Material.accent: Material.color(Material.DeepOrange, Material.Shade400)
        Grid {
            columns: 0
            anchors.fill: parent

            Column {
                id: column
                width: parent.width
                height: parent.height

                Rectangle {
                    id: mainColumn
                    color: "transparent"

                    width: parent.width
                    height: childrenRect.height + firstRow.anchors.topMargin * 2
                    border.color: "#3f3f46"
                    border.width: 1

                    Row {
                        spacing: 10
                        id: firstRow
                        x: 5
                        y: 10
                        anchors.left: parent.left
                        anchors.leftMargin: firstRow.spacing / 2
                        anchors.top: parent.top
                        anchors.topMargin: 8
                        Rectangle {
                            id: firstColumn
                            width: childrenRect.width
                            height: childrenRect.height
                            color: "transparent"

                            Label {
                                font.pixelSize: 12
                                text: defaultPanel.title
                                rightPadding: 10
                                textFormat: Text.PlainText
                                verticalAlignment: Text.AlignVCenter
                                bottomPadding: 0
                                topPadding: 0
                                renderType: Text.QtRendering
                                wrapMode: Text.NoWrap
                            }
                        }

                        Rectangle {
                            width: childrenRect.width
                            height: childrenRect.height
                            color: "transparent"
                            Image {
                                id: name
                                width: rectangle.width - firstColumn.width - firstRow.spacing * 2
                                height: 16
                                sourceSize.height: 16
                                sourceSize.width: 16
                                fillMode: Image.TileHorizontally
                                source: "../Images/WindowHandle.png"
                            }
                        }
                    }
                }
                Rectangle {
                    width: widthInfoPanel
                    height: heightItem - heightInfoPanel
                    color: "transparent"

                    Console {
                        id: cons
                    }

                    ListView {
                        id: textArea
                        anchors.rightMargin: 30
                        anchors.leftMargin: 30
                        anchors.bottomMargin: 10
                        anchors.topMargin: 30
                        anchors.fill: parent
                        model: cons.text
                    }
                }
            }
        }
    }
}
