#ifndef INC_ABOUT_HTML_H_
#define INC_ABOUT_HTML_H_

#include <Arduino.h>

const char PAGE_about_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog About</title>
    <link rel="stylesheet" href="/style.css">
    <script src="/about.js"></script>
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
</head>
<body onload="loadAbout()">
    <section class="header">CANalog About</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='view.html'">View</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>
    
    <section class="infoText">
        <div>
            WiFi Adapter Firmware Version
            <pre><output type="text", id="esp_fw", name="esp_fw"></output></pre>
        </div>
        <div class="line"></div>
        <div>
            CAN Adapter Firmware Version
            <pre><output type="text", id="stm_fw", name="stm_fw"></output></pre>
        </div>
        <div class="line"></div>
        <div>
            Hardware Version
            <pre><output type="text", id="stm_hw", name="stm_hw"></output></pre>
        </div>
        <div class="line"></div>
        <div>
            <a href="https://github.com/sdp8483/CANalog">github.com/sdp8483/CANalog</a>
        </div>
    </section>
</body>
</html>)=====";
#endif