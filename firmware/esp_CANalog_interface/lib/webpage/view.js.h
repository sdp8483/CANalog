#ifndef INC_VIEW_JS_H_
#define INC_VIEW_JS_H_

#include <Arduino.h>

const char PAGE_view_JS[] PROGMEM = R"=====(
var webSocket;
var dataPlot;
var maxDataPoints = 100;

var config = {
    type: 'line',
    data: {
        labels: [],
        datasets: [{
            data: [],
            label: "CAN Signal",
            borderColor: "#3e95cd",
            fill: false
        }]
    },
    options: {
        maintainAspectRation: false,
        responsive: true,
        tooltips: {
            mode: 'index',
            intersect: true
        },
        hover: {
            mode: 'nearest',
            intersect: true
        }
    }
};

function initView() {
    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');
    dataPlot = new Chart(document.getElementById("lineChart"), config);
    
    webSocket.onmessage = function (event) {
        var data = JSON.parse(event.data);
        var today = new Date();
        var t = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();

        addData(t, data.value);
    }

    // dataPlot.canvas.parentNode.style.height = "40%";
    dataPlot.canvas.parentNode.style.width = "80%";
}

function removeData(){
    dataPlot.data.labels.shift();
    dataPlot.data.datasets[0].data.shift();
}

function addData(label, data) {
    if(dataPlot.data.labels.length > maxDataPoints) removeData();
    dataPlot.data.labels.push(label);
    dataPlot.data.datasets[0].data.push(data);
    dataPlot.update();
})=====";
#endif