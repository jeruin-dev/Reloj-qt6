import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true

    title: qsTr("Reloj")

    Text {
        anchors.centerIn: parent
        text: "Hola Mundo!"
        font.pixelSize: 24
        font.family: "JetBrains Mono"
        font.italic: true
        objectName: "miTexto"
    }
}
