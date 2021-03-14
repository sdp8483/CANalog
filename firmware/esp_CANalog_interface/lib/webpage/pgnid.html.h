#ifndef INC_PGNID_HTML_H_
#define INC_PGNID_HTML_H_

#include <Arduino.h>

const char PAGE_pgnid_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <title>CANalog PGN to ID</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <link rel="stylesheet" href="/style.css">
    <script src="/libs.js"></script>
</head>
<body onload="loadID()">
    <section class="header">CAN PGN to ID</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='frame.html'">Frame</button>
        <button onclick="document.location='signal.html'">Signal</button>
        <button onclick="document.location='analog.html'">Analog</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>

    <section class="main">
        <aside class="usrInput">
            <div class="formRow">
                <div class="label">Priority</div>
                <div class="value"><input onchange="assembleID()" type="number" id="priority" name="priority" min="0" max="7"></div>
            </div>
            <div class="line"></div>
            <div class="formRow">
                <div class="label">PGN</div>
                <div class="value"><input onchange="assembleID()" type="number" id="pgn" name="pgn" min="0" max="262143"></div>
            </div>
            <div class="line"></div>
            <div class="formRow">
                <div class="label">Source Address</div>
                <div class="value"><input onchange="assembleID()" type="number" id="sa" name="sa" min="0" max="255"></div>
            </div>
            <div class="line"></div>
            <div class="line"></div>
            <div class="line"></div>
            <div class="line"></div>
            <div class="formRow">
                <div class="label">CAN ID</div>
                <div class="outputText"><output type="text" id="can_id" name="can_id"></div>
            </div>
        </aside>
    </section>
</body>
</html>
)=====";
#endif