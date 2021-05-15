#ifndef INC_VIEW_HTML_H_
#define INC_VIEW_HTML_H_

#include <Arduino.h>

const char PAGE_view_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog View</title>
    <link rel="stylesheet" href="/style.css">
    <script src="/view.js"></script>
    <script src="/Chart.min.js"></script>
    <link rel="icon" href="data:,"> <!-- disable favicon request -->

    <style>
        .plot {
            float: left;
            width: 70%;
        }
        .side {
            float: left;
            padding-left: 5px;
        }
        .clearfix::after {
            content: "";
            clear: both;
            display: table;
        }
        .dataRow {
            background-color: cadetblue;
            padding: 3px;
            margin: auto;
        }
    </style>

</head>
<body onload="initView()">
    <section class="header">CANalog View</section>

    <ul>
        <li><a href="index.html">Settings</a></li>
        <li><a href="view.html" class="active">View</a></li>
        <li><a href="pgnid.html">PGN to ID</a></li>
        <li><a href="about.html">About</a></li>
    </ul>

    <div class="clearfix">
        <div class="plot">
            <canvas id="lineChart"></canvas>
        </div>

        <div class="side">
            <div class="dataRow"><label for="signal">CAN Signal: <output type="text" id="signal"></output></div>
            <div class="dataRow"><label for="dac">DAC Output: <output type="text" id="dac"></output></div>
            <div class="dataRow"><label for="fstr">CAN Frame: <output type="text" id="fstr"></output></div>
            <div></div>
            <div>
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
            </div>
        </div>
    </div>
</body>
</html>)=====";
#endif