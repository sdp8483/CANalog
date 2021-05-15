#ifndef INC_SAVED_OK_HTML_H_
#define INC_SAVED_OK_HTML_H_

#include <Arduino.h>

const char PAGE_saved_ok_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog Settings Saved</title>
    <link rel="stylesheet" href="/style.css">
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
</head>
<body>
    <section class="header">CANalog Settings Saved</section>

    <ul>
        <li><a href="index.html">Settings</a></li>
        <li><a href="view.html">View</a></li>
        <li><a href="pgnid.html">PGN to ID</a></li>
        <li><a href="about.html">About</a></li>
    </ul>

    <section class="savedOutput">
        <div>Settings Updated</div>
        <div class="line"></div>
        <div class="line"></div>
        <div><button onclick="document.location='index.html'">back</button></div>
    </section>
    
</body>
</html>)=====";
#endif