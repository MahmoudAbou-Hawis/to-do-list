import QtQuick 2.7

Item
{
    property var onClickHandler: null
    Image {
        id: image
        source: "../../assests/images/add.png"
        width: 30
        height: 30

    }

    MouseArea {
        id: mouseArea
        anchors.fill: image
        onClicked: {
            if (onClickHandler) {
                onClickHandler();
            } else {
                console.warn("No click handler defined for this button.");
            }
        }

    }
}