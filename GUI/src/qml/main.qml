import QtQuick 2.7
import QtQuick.Controls 2.7
import QtQuick.Window 2.2

import "Button"
import "CheckBox"
import "TaskInput" 

ApplicationWindow {
    visible: true
    title: "To-Do List"
    width: Screen.width
    height: Screen.height

    ListModel {
        id: nameModel
        objectName: "nameModel"
        ListElement {
            name: "Task 1"
            __checked: false
            __delete: false
            textOpacity: 1.0
            originalIndex: 0
            notes: ""
            email: ""
            date: ""
            time: ""
        }
    }


    property int clickedIndex: -1
    property bool isPressed: false

    Component {
        id: nameDelegate

        Column {
            Rectangle {
                id: nameRect
                width: 650
                height: 60
                color: "lightblue"
                border.color: "black"
                border.width: 1
                radius: 10
                CheckBox {
                    text: model.name
                    anchors {
                        left: parent.left
                        top: parent.top
                        topMargin: 10
                    }
                    z: 1
                    id: myCheckBox

                    __checked: model.__checked
                    __delete: model.__delete
                    textOpacity: model.textOpacity

                    onChecked: {
                        var element = nameModel.get(index);
                        var popupText = element.notes;
                        console.log(popupText)
                        var __originalIndex = index;

                        if (__checked) {
                            var updatedElement = {
                                name: element.name,
                                __checked: __checked,
                                __delete: true,
                                textOpacity: 0.5,
                                originalIndex: __originalIndex,
                                notes: element.notes,
                                date: element.date,
                                time: element.time,
                                email: element.email
                            };
                            nameModel.append(updatedElement);
                            nameModel.remove(index);
                        } else {
                            var element = nameModel.get(index);
                            var updatedElement = {
                                name: element.name,
                                __checked: __checked,
                                __delete: false,
                                textOpacity: 1,
                                originalIndex: __originalIndex,
                                notes: element.notes,
                                date: element.date,
                                time: element.time,
                                email: element.email
                            };
                            nameModel.insert(originalIndex, updatedElement);
                            nameModel.remove(index);
                        }
                    }
                }

                Image {
                    id: arrowImage
                    width: 20
                    height: 10
                    source: "../assests/images/arrow-down.png"
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 10
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: arrowImage

                    onClicked: {
                        clickedIndex = index
                        isPressed = !isPressed
                        popdownRect.width = isPressed ? 650 : 0
                        popdownRect.height = isPressed ? 240 : 0
                        textInput.focus = isPressed ? true : false
                        textInput.placeholderText =  isPressed ? "Enter notes here" : ""
                        arrowImage.source = isPressed ? "../assests/images/arrow-up.png" : "../assests/images/arrow-down.png"
                        emailLable.text = isPressed ? "Enter email" : ""
                        dateText.text = isPressed ? "Enter date" : ""
                        notifyTime.text = isPressed ? "Notify Time" : ""
                        notifyTime.visible = isPressed ? true : false
                        timeInput.visible = isPressed ? true : false    
                        emailInput.visible = isPressed ? true : false
                        dateInput.visible = isPressed ? true : false   
                        dateInput.focus = isPressed ? true : false
                        timeInput.focus = isPressed ? true : false
                        emailInput.focus = isPressed ? true : false
                        
                    }
                }
            }

            Rectangle {
                id: popdownRect
                color: "#b8b8b8"
                height: 0
                width: 0
                radius: 10

                Rectangle {
                    width: popdownRect.width / 2
                    height: popdownRect.height
                    radius: 10
                    color: "#b8b8b8"
                    anchors.margins: 12

                    TextArea {
                        id: textInput
                        width: parent.width - 20
                        height: popdownRect.height - 80
                        text: model.notes
                        wrapMode: TextArea.Wrap
                        onTextChanged: {
                            nameModel.setProperty(index, "notes", text);
                        }
                    }
                }

                Rectangle {
                    width: popdownRect.width / 2
                    height: popdownRect.height
                    radius: 10
                    color: "#b8b8b8"
                    anchors.top: popdownRect.top
                    anchors.right: popdownRect.right

                    Column {
                        width: parent.width
                        spacing: 10

                        Label {
                            id: emailLable
                            color: "black"
                        }

                        Rectangle {
                            width: parent.width - 20  
                            height: 40  
                            color: "white"  
                            radius: 5  

                            TextInput {
                                id: emailInput
                                anchors.fill: parent  
                                text: model.email  
                                color: "black" 
                                font.pixelSize: 16 
                                wrapMode: TextInput.Wrap  
                                horizontalAlignment: TextInput.AlignLeft 
                                verticalAlignment: TextInput.AlignTop 

                                onTextChanged: {
                                    nameModel.setProperty(index, "email", text);
                                }
                            }
                        }

                        Label {
                            id:dateText
                            color: "black"
                        }

                        Rectangle {
                            width: parent.width - 20
                            height: 40
                            color: "white"
                            radius: 5

                            TextInput {
                                id: dateInput
                                anchors.fill: parent
                                text: model.date
                                color: "black"
                                font.pixelSize: 16
                                wrapMode: TextInput.Wrap
                                horizontalAlignment: TextInput.AlignLeft
                                verticalAlignment: TextInput.AlignTop

                                onTextChanged: {
                                    nameModel.setProperty(index, "date", text);
                                }
                            }
                        }

                        Label {
                            id:notifyTime
                            color: "black"
                        }

                        Rectangle {
                            width: parent.width - 20
                            height: 40
                            color: "white"
                            radius: 5

                            TextInput {
                                id: timeInput
                                anchors.fill: parent
                                text: model.time
                                color: "black"
                                font.pixelSize: 16
                                wrapMode: TextInput.Wrap
                                horizontalAlignment: TextInput.AlignLeft
                                verticalAlignment: TextInput.AlignTop

                                onTextChanged: {
                                    nameModel.setProperty(index, "time", text);
                                }
                            }
                        }

                        // Add a delete button

                    }
                }
                Rectangle {
                    width: parent.width - 450
                    height: 40
                    color: "red"
                    radius: 5
                    y:190
                    x:30
                    Text {
                        anchors.centerIn: parent
                        color: "white"
                        text: "Delete"
                        font.pixelSize: 16
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            // Remove the task from the model
                            nameModel.remove(index);
                        }
                    }
                }
            }
        }
    }

    ListView {
        id: listView
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 40
        }
        width: 650
        height: 6 * 60  
        model: nameModel
        delegate: nameDelegate
        spacing: 10
        clip: true
        interactive: true 
    }

    TaskInput {
        id: taskInput
        x: 360
        y: Screen.height - 300
        taskInputwidth: 650
        opacity: 0.7888
        textInputText: ""
        
        handler: function() {
            /**/
            if (taskInput.textInputText !== "") {
                nameModel.append({
                    name: taskInput.textInputText,
                    __checked: false,
                    __delete: false,
                    textOpacity: 1.0,
                    originalIndex: nameModel.count,
                    notes: "",
                    email: "",
                    date: "",
                    time: ""
                });
                taskInput.textInputText = ""; 
            }
        }
        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return) {
                if (handler) {
                    handler();
                }
            }
        }
    }
}
