var webSocket

function initView() {
    webSocket = new WebSocket('ws://' + window.location.hostname + '/ws');
    webSocket.onmessage = function (event) {
        var data = JSON.parse(event.data);
        console.log(data);
        document.getElementById('time').value = data.millis;
    }
}
