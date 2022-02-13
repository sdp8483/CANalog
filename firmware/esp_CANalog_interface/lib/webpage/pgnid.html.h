#ifndef INC_PGNID_HTML_H_
#define INC_PGNID_HTML_H_

#include <Arduino.h>

const char PAGE_pgnid_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog PGN to ID</title>
    <link rel="stylesheet" href="/style.css">
    <script src="/pgnid.js"></script>
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
</head>
<body onload="loadID()">
    <section class="header">CAN PGN to ID</section>

    <ul>
        <li><a href="index.html">Settings</a></li>
        <li><a href="analog.html">Analog</a></li>
        <li><a href="view.html">View</a></li>
        <li><a href="pgnid.html" class="active">PGN to ID</a></li>
        <li><a href="about.html">About</a></li>
    </ul>

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
</html>)=====";
#endif