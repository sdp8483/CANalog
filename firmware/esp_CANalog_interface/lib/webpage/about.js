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