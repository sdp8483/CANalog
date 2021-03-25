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
            borderColor: "rgb(54, 162, 235)",
            fill: false,
        }, {
            data: [],
            label: "DAC Output",
            borderColor: "rgb(255, 99, 132)",
            fill: false,
        }]
    },
    options: {
        responsive: true
    }
};

function initView() {
    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');
    dataPlot = new Chart(document.getElementById("lineChart"), config);
    
    webSocket.onmessage = function (event) {
        var data = JSON.parse(event.data);
        var today = new Date();
        var t = today.getHours() + ":" + minutesWithLeadingZeros(today) + ":" + secondsWithLeadingZeros(today);

        addData(t, data.value, data.dac);

        console.log(data);
    }

    dataPlot.canvas.parentNode.style.width = "80%";
}

function removeData() {
    dataPlot.data.labels.shift();
    dataPlot.data.datasets[0].data.shift();
    dataPlot.data.datasets[1].data.shift();
}

function addData(label, data, dac) {
    if(dataPlot.data.labels.length > maxDataPoints) removeData();
    dataPlot.data.labels.push(label);
    dataPlot.data.datasets[0].data.push(data);
    dataPlot.data.datasets[1].data.push(dac);
    dataPlot.update();
}

function minutesWithLeadingZeros(dt) {
    return (dt.getMinutes() < 10 ? '0': '') + dt.getMinutes();
}

function secondsWithLeadingZeros(dt) {
    return (dt.getSeconds() < 10 ? '0': '') + dt.getSeconds();
}