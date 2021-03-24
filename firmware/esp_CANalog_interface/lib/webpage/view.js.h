#ifndef INC_VIEW_JS_H_
#define INC_VIEW_JS_H_

#include <Arduino.h>

const char PAGE_view_JS[] PROGMEM = R"=====(
var webSocket

function initView() {
    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');
    webSocket.onmessage = function (event) {
        var data = JSON.parse(event.data);
        console.log(data);
        document.getElementById('time').value = data.millis;
    }
}

// webSocket.onmessage  = function(event) {
//     var data = JSON.parse(event.data);
//     console.log(data.value);
// }
)=====";
#endif