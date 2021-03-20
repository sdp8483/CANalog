#ifndef INC_FRAME_HTML_H_
#define INC_FRAME_HTML_H_

#include <Arduino.h>

const char PAGE_frame_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>CANalog Frame View</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <link rel="stylesheet" href="/style.css">
    <script src="/frame.js"></script>
</head>
<body>
    <section class="header">CANalog Frame View</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='frame.html'">View</button>
        <button onclick="document.location='analog.html'">Analog</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>

    <section class="main">
        <aside class="usrInput">
            <div class="formRow">
                <div class="label">Frame Data: </div>
                <div class="value"><output type="text" name="frame_data"></output></div>
            </div>
            <div class="formRow">
                <div class="label">Signal Data: </div>
                <div class="value"><output type="text" name="signal_data"></output></div>
            </div>
            <div class="formRow">
                <div class="label">Analog Output: </div>
                <div class="value"><output type="text" name="aout"></output></div>
            </div>
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