#ifndef INC_ANALOG_HTML_H_
#define INC_ANALOG_HTML_H_

#include <Arduino.h>

const char PAGE_analog_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>CANalog Analog Control</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <link rel="stylesheet" href="/style.css">
    <script src="/libs.js"></script>
</head>
<body>
    <section class="header">CANalog Analog Control</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='frame.html'">Frame</button>
        <button onclick="document.location='signal.html'">Signal</button>
        <button onclick="document.location='analog.html'">Analog</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>
    
</body>
</html>
)=====";
#endif