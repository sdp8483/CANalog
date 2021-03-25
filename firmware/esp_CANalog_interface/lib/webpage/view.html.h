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
</head>
<body onload="initView()">
    <section class="header">CANalog View</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='view.html'">View</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>

    <section class="plot">
        <canvas id="lineChart"></canvas>
    </section>
</body>
</html>)=====";
#endif