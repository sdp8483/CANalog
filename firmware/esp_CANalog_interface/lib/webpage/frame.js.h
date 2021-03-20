#ifndef INC_FRAME_JS_H_
#define INC_FRAME_JS_H_

#include <Arduino.h>

const char PAGE_frame_JS[] PROGMEM = R"=====(
function loadDoc() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 & this.status == 200) {
            setInputs(this.responseText);
            // setBits();
        }
    };
    xhttp.open("GET", "data.txt", true);
    xhttp.send();
}

function setInputs(data) {
    var obj = JSON.parse(data);

    document.getElementById("frame_data").value = obj.frame;
    document.getElementById("signal_data").value = obj.value;
    document.getElementById("aout").value = obj.dac_out;
})=====";
#endif