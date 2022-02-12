var webSocket;
var dataPlot;
var maxDataPoints = 100;

// var frameString = "0123456789abcdef";
// var frameInt = parseHexString(frameString.split("").reverse().join(""));

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
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 & this.status == 200) {
            setColor(this.responseText);
        }
    };
    xhttp.open("GET", "data.txt", true);
    xhttp.send();

    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');
    dataPlot = new Chart(document.getElementById("lineChart"), config);
    
    webSocket.onmessage = function (event) {
        var data = JSON.parse(event.data);
        var today = new Date();
        var t = today.getHours() + ":" + minutesWithLeadingZeros(today) + ":" + secondsWithLeadingZeros(today);

        addData(t, data.value, data.dac);

        setBits(data.frame);
        document.getElementById("signal").value = data.value;
        document.getElementById("dac").value = data.dac;
        document.getElementById("fstr").value = data.frame;

        console.log(data);
    }

    // dataPlot.canvas.parentNode.style.width = "80%";
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

function setBits(frameString) {
    var table = document.getElementById('frame')
    var bitNumber = 0;

    var frameInt = frameToIntArray(frameString);

    for(var r=1; r<=8; r++) {
        for(var c=8; c>=1; c--) {
            // table.rows[r].cells[c].style.backgroundColor = "white";
            // table.rows[r].cells[c].style.color = "grey";
            if (bitNumber < 32) {
                table.rows[r].cells[c].innerHTML = (frameInt[1] >> bitNumber) & 1;
            } else {
                table.rows[r].cells[c].innerHTML = (frameInt[0] >> bitNumber) & 1;
            }
            
            bitNumber++;
        }
    }
}

function setColor(data) {
    var obj = JSON.parse(data);

    var bitNumber = 0;
    var newBitNumber = 0;
    var endBit;
    var startBit = obj.start_bit;
    var len = obj.bit_len;
    var canEndianness = obj.endianness;

    var table = document.getElementById('frame');

    // resetBits();

    if (canEndianness == "12") {
        endBit = startBit + parseInt(len) - 1;

        for (var r=1; r<=8; r++) {
            for (var c=8; c>=1; c--) {
                var cellObject = table.rows[r].cells[c]

                if (bitNumber >= startBit && bitNumber <= endBit) {
                    if (endBit < 64) {
                        cellObject.style.backgroundColor = "green";
                        cellObject.style.color = "black";
                        newBitNumber++;
                    } else {
                        cellObject.style.backgroundColor = "red";
                        cellObject.style.color = "green";
                        cellObject.innerHTML = "X";
                    }
                }
                bitNumber++;
            }
        }
    } else {
        var startRow = 7 - Math.floor(startBit/8);
        var startCell = startBit % 8;
        startBit = (startRow * 8) + startCell;
        endBit = startBit + parseInt(len) - 1;

        for (var r=8; r>0; r--) {
            for (var c=8; c>=1; c--) {
                var cellObject = table.rows[r].cells[c]

                if (bitNumber >= startBit && bitNumber <= endBit) {
                    if (endBit < 64) {
                        cellObject.style.backgroundColor = "green";
                        cellObject.style.color = "black";
                        newBitNumber++;
                    } else {
                        cellObject.style.backgroundColor = "red";
                        cellObject.style.color = "green";
                        cellObject.innerHTML = "X";
                    }
                }
                bitNumber++;
            }
        }

    }
}

function parseHexString(str) {
    // source: https://stackoverflow.com/questions/14603205/how-to-convert-hex-string-into-a-bytes-array-and-a-bytes-array-in-the-hex-strin
    var result = [];
    while (str.length >= 8) { 
        result.push(parseInt(str.substring(0, 8), 16));
		
        str = str.substring(8, str.length);
    }

    return result;
}

function frameToIntArray(str) {
    return parseHexString(str.split("").reverse().join(""));
}