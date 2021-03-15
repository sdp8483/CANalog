#ifndef INC_LIBS_JS_H_
#define INC_LIBS_JS_H_

/* https://www.esp8266.com/viewtopic.php?p=60563 
 * https://techtutorialsx.com/2016/10/15/esp8266-http-server-serving-html-javascript-and-css/
 */

#include <Arduino.h>

const char PAGE_libs_js[] PROGMEM = R"=====(
function loadDoc() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 & this.status == 200) {
            setInputs(this.responseText);
            setBits();
        }
    };
    xhttp.open("GET", "data.txt", true);
    xhttp.send();
}

function loadID() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 & this.status == 200) {
            setIDInputs(this.responseText);
            assembleID();
        }
    };
    xhttp.open("GET", "data.txt", true);
    xhttp.send();
}

function loadAbout() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 & this.status == 200) {
            setInfo(this.responseText);
        }
    };
    xhttp.open("GET", "info.txt", true);
    xhttp.send();
}

function setInfo(data) {
    var obj = JSON.parse(data);
    document.getElementById("esp_fw").value = obj.esp_fw;
    document.getElementById("stm_fw").value = obj.stm_fw;
    document.getElementById("stm_hw").value = obj.stm_hw;
}

function setIDInputs(data) {
    var obj = JSON.parse(data);
    document.getElementById("priority").value = parseInt(obj.id, 16) >> 26;
    document.getElementById("pgn").value = (parseInt(obj.id, 16) >> 8) & (0x3FFFF);
    document.getElementById("sa").value = parseInt(obj.id, 16) & 0xFF;
}

function setInputs(data) {
    var obj = JSON.parse(data);

    document.getElementById("can_baud").value = obj.baud;
    document.getElementById("can_id_bit_len").value = obj.type;
    document.getElementById("can_id").value = obj.id;
    document.getElementById("can_signal_start_bit").value = obj.start_bit;
    document.getElementById("can_signal_bit_len").value = obj.bit_len;
    document.getElementById("can_endianness").value = obj.endianness;
    document.getElementById("can_signal_max").value = obj.max;
    document.getElementById("can_signal_min").value = obj.min;
}

function resetBits() {
    var table = document.getElementById('frame')
    var bitNumber = 0;

    for(var r=1; r<=8; r++) {
        for(var c=8; c>=1; c--) {
            table.rows[r].cells[c].style.backgroundColor = "white";
            table.rows[r].cells[c].style.color = "grey";
            table.rows[r].cells[c].innerHTML = bitNumber;
            bitNumber++;
        }
    }
}

function setBits() {
    var bitNumber = 0;
    var newBitNumber = 0;
    var endBit;
    var startBit = parseInt(document.getElementById("can_signal_start_bit").value);
    var canEndianness = document.getElementById("can_endianness").value;

    var table = document.getElementById('frame');

    resetBits();

    if (canEndianness == "12") {
        endBit = startBit + parseInt(document.getElementById("can_signal_bit_len").value) - 1;

        for (var r=1; r<=8; r++) {
            for (var c=8; c>=1; c--) {
                var cellObject = table.rows[r].cells[c]

                if (bitNumber >= startBit && bitNumber <= endBit) {
                    if (endBit < 64) {
                        cellObject.style.backgroundColor = "green";
                        cellObject.style.color = "black";
                        cellObject.innerHTML = newBitNumber;
                        document.getElementById("can_signal_start_bit").setCustomValidity("");
                        document.getElementById("can_signal_bit_len").setCustomValidity("");
                        newBitNumber++;
                    } else {
                        cellObject.style.backgroundColor = "red";
                        cellObject.style.color = "green";
                        cellObject.innerHTML = "X";
                        document.getElementById("can_signal_start_bit").setCustomValidity("Signal Out of Frame");
                        document.getElementById("can_signal_bit_len").setCustomValidity("Signal Out of Frame");
                    }
                }
                bitNumber++;
            }
        }
    } else {
        var startRow = 7 - Math.floor(startBit/8);
        var startCell = startBit % 8;
        startBit = (startRow * 8) + startCell;
        endBit = startBit + parseInt(document.getElementById("can_signal_bit_len").value) - 1;

        for (var r=8; r>0; r--) {
            for (var c=8; c>=1; c--) {
                var cellObject = table.rows[r].cells[c]

                if (bitNumber >= startBit && bitNumber <= endBit) {
                    if (endBit < 64) {
                        cellObject.style.backgroundColor = "green";
                        cellObject.style.color = "black";
                        cellObject.innerHTML = newBitNumber;
                        document.getElementById("can_signal_start_bit").setCustomValidity("");
                        document.getElementById("can_signal_bit_len").setCustomValidity("");
                        newBitNumber++;
                    } else {
                        cellObject.style.backgroundColor = "red";
                        cellObject.style.color = "green";
                        cellObject.innerHTML = "X";
                        document.getElementById("can_signal_start_bit").setCustomValidity("Signal Out of Frame");
                        document.getElementById("can_signal_bit_len").setCustomValidity("Signal Out of Frame");
                    }
                }
                bitNumber++;
            }
        }

    }
}

function validateID() {
    var stdCANid_max = 2**11;
    var CANid = parseInt(document.getElementById("can_id").value, 16);
    var CANlen = document.getElementById("can_id_bit_len").value;

    if(CANlen == 11) {
        if(CANid > stdCANid_max) {
            document.getElementById("can_id").setCustomValidity("CAN ID range 0 to 7FF");
            document.getElementById("can_id_bit_len").setCustomValidity("CAN ID range 0 to 7FF");
        } else {
            document.getElementById("can_id").setCustomValidity("");
            document.getElementById("can_id_bit_len").setCustomValidity("");
        }
    } else {
        document.getElementById("can_id").setCustomValidity("");
        document.getElementById("can_id_bit_len").setCustomValidity("");
    }
}

function validateMinMax() {
    var sigMax = parseInt(document.getElementById("can_signal_max").value);
    var sigMin = parseInt(document.getElementById("can_signal_min").value);

    if (sigMin >= sigMax) {
        document.getElementById("can_signal_max").setCustomValidity("min must be less than max");
        document.getElementById("can_signal_min").setCustomValidity("min must be less than max");
    } else {
        document.getElementById("can_signal_max").setCustomValidity("");
        document.getElementById("can_signal_min").setCustomValidity("");
    }
}

function assembleID() {
    var priority = document.getElementById("priority").value;
    var pgn = document.getElementById("pgn").value;
    var sourceAddress = document.getElementById("sa").value;
    var can_id = 0;

    can_id = (priority << 26) | (pgn << 8) | (sourceAddress);
    document.getElementById("can_id").value = can_id.toString(16).toUpperCase();
}
)=====";
#endif