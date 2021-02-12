#ifndef INC_FRAME_HTML_H_
#define INC_FRAME_HTML_H_

const char PAGE_Frame_HTML[] = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>CANalog Frame Bitmap</title>
    <style>
        table, th, tr, td {
            border: 1px solid black;
            border-collapse: collapse;
            padding: 5px;
            text-align: center;
        }
    </style>
    <script>
        function resetBits() {
            var canEndianness = document.getElementById("can_endianness").value;
            var table = document.getElementById('frame')
            var bitNumber = 0;

            if (canEndianness == "12") {
                for(var r=1; r<=8; r++) {
                    for(var c=8; c>=1; c--) {
                        table.rows[r].cells[c].style.backgroundColor = "white";
                        table.rows[r].cells[c].style.color = "grey";
                        table.rows[r].cells[c].innerHTML = bitNumber;
                        bitNumber++;
                    }
                }
            } else {
                for(var r=8; r>=1; r--) {
                    for(var c=8; c>=1; c--) {
                        table.rows[r].cells[c].style.backgroundColor = "white";
                        table.rows[r].cells[c].style.color = "grey";
                        table.rows[r].cells[c].innerHTML = bitNumber;
                        bitNumber++;
                    }
                }
            }

        }

        function setBits() {
            var bitNumber = 0;
            var newBitNumber = 0;
            var startBit = parseInt(document.getElementById("can_signal_start_bit").value);
            var endBit = startBit + parseInt(document.getElementById("can_signal_bit_len").value) - 1;
            var canEndianness = document.getElementById("can_endianness").value;

            var table = document.getElementById('frame');

            resetBits();

            if (canEndianness == "12") {
                for (var r=1; r<=8; r++) {
                    for (var c=8; c>=1; c--) {
                        var cellObject = table.rows[r].cells[c]

                        if (bitNumber >= startBit && bitNumber <= endBit) {
                            if (endBit < 64) {
                                cellObject.style.backgroundColor = "green";
                                cellObject.style.color = "black";
                                cellObject.innerHTML = newBitNumber;
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
                for (var r=8; r>=1; r--) {
                    for (var c=8; c>=1; c--) {
                        var cellObject = table.rows[r].cells[c]

                        if (bitNumber >= startBit && bitNumber <= endBit) {
                            if (endBit < 64) {
                                cellObject.style.backgroundColor = "green";
                                cellObject.style.color = "black";
                                cellObject.innerHTML = newBitNumber;
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
    </script>
</head>
<body onload="setBits()">
    <label for="can_endianness">Signal Endianness: </label>
        <select onchange="setBits()" id="can_endianness" name="can_endianness">
            <option value="12">little</option>
            <option value="21">big</option>
        </select><br>
    <label for="can_signal_start_bit">Signal Start Bit: </label>
        <input onchange="setBits()" type="number" id="can_signal_start_bit" name="can_signal_start_bit" value="2" min="0" max="63" size="3"><br>
    <label for="can_signal_bit_len">Signal Bit Length: </label>
            <input onchange="setBits()" type="number" id="can_signal_bit_len" name="can_signal_bit_len" value="8" min="1" max="64" size="3"><br>
    <table id='frame'>
        <tr>
            <th></th>
            <th>bit 7</th>
            <th>bit 6</th>
            <th>bit 5</th>
            <th>bit 4</th>
            <th>bit 3</th>
            <th>bit 2</th>
            <th>bit 1</th>
            <th>bit 0</th>
        </tr>
        <tr>
            <th>Byte 0</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>

        </tr>
        <tr>
            <th>Byte 1</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 2</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 3</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 4</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 5</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 6</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <th>Byte 7</th>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
    </table>

</body>
</html>
)=====";

#endif