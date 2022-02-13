#ifndef INC_ANALOG_HTML_H_
#define INC_ANALOG_HTML_H_

#include <Arduino.h>

const char PAGE_analog_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog Analog</title>
    <link rel="stylesheet" href="/style.css">
    <script src="/analog.js"></script>
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
</head>
<body onload="initAnalog()">
    <section class="header">CANalog Analog</section>

    <ul>
        <li><a href="index.html">Settings</a></li>
        <li><a href="analog.html" class="active">Analog</a></li>
        <li><a href="view.html">View</a></li>
        <li><a href="pgnid.html">PGN to ID</a></li>
        <li><a href="about.html">About</a></li>
    </ul>
    
    <section class="box">
        <h2>Analog Output Control</h2>
        <div>
            Disconnect CAN network for manual analog control to work.
        </div>
        <div>
            <button type="button" onclick="wsSend(4095)">Aout Max</button>
            <button type="button" onclick="wsSend(0)">Aout Min</button>
        </div>
        <div>
            <input type="range" onchange="setAnalog(0)" id="slider" name="slider">
            <input type="number" onchange="setAnalog(1)" id="nBox" name="nBox">
        </div>
    </section>
</body>
</html>)=====";
#endif