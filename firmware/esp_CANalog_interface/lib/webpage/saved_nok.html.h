#ifndef INC_SAVED_NOK_HTML_H_
#define INC_SAVED_NOK_HTML_H_

#include <Arduino.h>

const char PAGE_saved_nok_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="CANalog Configuration (V0.0.1.0)">
    <meta name="author" content="Sam Perry">
    <title>CANalog Settings Save Error!</title>
    <link rel="stylesheet" href="/style.css">
    <link rel="icon" href="data:,"> <!-- disable favicon request -->
</head>
<body>
    <section class="header">CANalog Settings Saved</section>

    <section class="navigation">
        <button onclick="document.location='index.html'">Settings</button>
        <button onclick="document.location='view.html'">View</button>
        <button onclick="document.location='pgnid.html'">PGN to ID</button>
        <button onclick="document.location='about.html'">About</button>
    </section>

    <section class="savedOutput">
        <div>An error occurred and settings were not updated!</div>
        <div>Please go back and try again.</div>
        <div class="line"></div>
        <div class="line"></div>
        <div><button onclick="document.location='index.html'">back</button></div>
    </section>
    
</body>
</html>)=====";
#endif