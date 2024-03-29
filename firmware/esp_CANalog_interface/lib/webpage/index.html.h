#ifndef INC_INDEX_HTML_H_
#define INC_INDEX_HTML_H_

#include <Arduino.h>

const char PAGE_index_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog Configuration</title>
    <link rel="stylesheet" href="/style.css">
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
    <script src="/index.js"></script>
</head>
<body onload="loadDoc()">
    <section class="header">CANalog Settings</section>

    <ul>
        <li><a href="index.html" class="active">Settings</a></li>
        <li><a href="analog.html">Analog</a></li>
        <li><a href="view.html">View</a></li>
        <li><a href="pgnid.html">PGN to ID</a></li>
        <li><a href="about.html">About</a></li>
    </ul>

    <section class="main">
        <aside class="usrInput">
            <form action="/save" method="POST">
                <div class="formRow">
                    <div class="label">Baud Rate</div>
                    <div class="value">
                        <select id="can_baud" name="can_baud">
                            <option value="10">10kbps</option>
                            <option value="20">20kbps</option>
                            <option value="50">50kbps</option>
                            <option value="83">83.333kbps</option>
                            <option value="100">100kbps</option>
                            <option value="125">125kbps</option>
                            <option value="250">250kbps</option>
                            <option value="500">500kbps</option>
                            <option value="800">800kbps</option>
                            <option value="1000">1Mbps</option>
                        </select>
                    </div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">ID Type</div>
                    <div class="value">
                        <select onchange="validateID()" id="can_id_bit_len" name="can_id_bit_len">
                            <option value="11">11bit</option>
                            <option value="29">29bit</option>   
                        </select>
                    </div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">CAN ID</div>
                    <div class="value"><input onchange="validateID()" type="text" id="can_id" name="can_id" pattern="[A-Fa-f0-9]{0,8}"></div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">Signal Start Bit</div>
                    <div class="value"><input onchange="setBits()" type="number" id="can_signal_start_bit" name="can_signal_start_bit" min="0" max="63"></div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">Signal Bit Length</div>
                    <div class="value"><input onchange="setBits()" type="number" id="can_signal_bit_len" name="can_signal_bit_len" min="1" max="64"></div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">Signal Endianness</div>
                    <div class="value">
                        <select onchange="setBits()" id="can_endianness" name="can_endianness">
                            <option value="12">little</option>
                            <option value="21">big</option>
                        </select>
                    </div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">Signal Max</div>
                    <div class="value"><input onchange="validateMinMax()" type="number" id="can_signal_max" name="can_signal_max" min=0 max=65535></div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">Signal Min</div>
                    <div class="value"><input onchange="validateMinMax()" type="number" id="can_signal_min" name="can_signal_min" min=0 max=65535></div>
                </div>
                <div class="line"></div>
                <div class="formRow">
                    <div class="label">CAN Termination</div>
                    <div class="value">
                        <div><input class="radio" type="radio" id="on" name="term" value="1"><label for="on">on</label></div>
                        <div><input class="radio" type="radio" id="off" name="term" value="0"><label for="off">off</label></div>
                    </div>
                </div>
                <div class="buttonRow">
                    <input type="submit" value="Save">
                </div>
            </form>
        </aside>

        <aside class="frameDisplay">
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
        </aside>
    </section>
</body>
</html>)=====";
#endif