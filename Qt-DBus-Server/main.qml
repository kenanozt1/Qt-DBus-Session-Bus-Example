import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.example.dbus 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600
    title: qsTr("D-Bus Server")
    color: "#f5f5f5"

    minimumWidth: 480
    minimumHeight: 400

    Controller {
        id: controller
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        Label {
            Layout.fillWidth: true
            text: qsTr("D-Bus Server")
            font.pixelSize: 24
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            color: "#2c3e50"
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: parent.height * 0.6
            radius: 8
            color: "#ffffff"
            border.color: "#e0e0e0"
            border.width: 1

            ScrollView {
                id: scrollView
                anchors.fill: parent
                anchors.margins: 10
                clip: true
                ScrollBar.vertical.policy: ScrollBar.AsNeeded

                Rectangle {
                    anchors.fill: parent
                    color: "transparent"

                    Text {
                        id: showDBusMessage
                        anchors.fill: parent
                        text: qsTr("Henüz mesaj alınmadı")
                        font.pixelSize: 18
                        wrapMode: Text.WordWrap
                        color: "#555555"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }
    }
    Connections {
        target: controller
        function onMessageReceived(msg) {
            showDBusMessage.text = msg
            console.log("Mesaj alındı: " + msg)
        }
    }
}
