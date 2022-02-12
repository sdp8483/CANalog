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

function setIDInputs(data) {
    var obj = JSON.parse(data);
    document.getElementById("priority").value = parseInt(obj.id, 16) >> 26;
    document.getElementById("pgn").value = (parseInt(obj.id, 16) >> 8) & (0x3FFFF);
    document.getElementById("sa").value = parseInt(obj.id, 16) & 0xFF;
}

function assembleID() {
    var priority = document.getElementById("priority").value;
    var pgn = document.getElementById("pgn").value;
    var sourceAddress = document.getElementById("sa").value;
    var can_id = 0;

    can_id = (priority << 26) | (pgn << 8) | (sourceAddress);
    document.getElementById("can_id").value = can_id.toString(16).toUpperCase();
}