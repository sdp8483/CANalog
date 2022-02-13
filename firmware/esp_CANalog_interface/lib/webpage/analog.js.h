#ifndef INC_ANALOG_JS_H_
#define INC_ANALOG_JS_H_

#include <Arduino.h>

const char PAGE_analog_JS[] PROGMEM = R"=====(
var webSocket;

function initAnalog() {
    /* connect to websocket server */
    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');

    /* assign callbacks */
    webSocket.onopen = function(event) {wsOpen(event)};
    webSocket.onclose = function(event) {wsClose(event)};
    webSocket.onmessage = function(event) {wsReceive(event)};
    webSocket.onerror = function(event) {wsError(event)};
}

function wsOpen(event) {
    console.log("Connected");
}

function wsClose(event) {
    console.log("Disconnected");

    /* try to reconnect after a few seconds */
    setTimeout(function() {initIndex()}, 2000);
}

function wsError(event) {
    console.log("ERROR: " + event.data);
}

function wsReceive(event) {
    if ((event.data != null) && (event.data != undefined) && (event.data != "")) {
        if (event.data[0] == '{') {
            var data = JSON.parse(event.data);

            var m = (data.sMax - data.sMin)/(4095 - 0);
            var b = data.sMin
            
            document.getElementById("slider").value = parseInt((m*data.dac) + b);
            document.getElementById("nBox").value = parseInt((m*data.dac) + b);

            document.getElementById("slider").max = data.sMax;
            document.getElementById("nBox").max = data.sMax;

            document.getElementById("slider").min = data.sMin;
            document.getElementById("nBox").min = data.sMin;

            wsPause();
        }
    }
}

function wsSend(dac_val) {
    data = JSON.stringify({'action': 0,
                           'dac_out': dac_val});

    console.log("Sending: " + data);
    webSocket.send(data);

    wsResume();
}

function setAnalog(source) {
    var val;
    var sMax;
    var sMin;

    if(source == 0) {
        val = parseInt(document.getElementById("slider").value);
        sMax = parseInt(document.getElementById("slider").max);
        sMin = parseInt(document.getElementById("slider").min);
    } else {
        val = parseInt(document.getElementById("nBox").value);
        sMax = parseInt(document.getElementById("nBox").max);
        sMin = parseInt(document.getElementById("nBox").min);
    }

    var m = (4095 - 0)/(sMax - sMin);
    var b = -(sMin * m);

    wsSend(parseInt((m*val)+b));

    wsResume();
}

function wsPause() {
    data = JSON.stringify({'action': 1});

    console.log("Sending: " + data);
    webSocket.send(data);
}

function wsResume() {
    data = JSON.stringify({'action': 2});

    console.log("Sending: " + data);
    webSocket.send(data);
})=====";
#endif