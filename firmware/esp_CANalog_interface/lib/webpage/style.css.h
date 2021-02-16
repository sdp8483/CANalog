#ifndef INC_STYLE_CSS_H_
#define INC_STYLE_CSS_H_

#include <Arduino.h>

const char PAGE_style_css[] PROGMEM = R"=====(
    * {
        box-sizing: border-box
    }
    header {
        width: 100%;
        background-color: darkorange;
        text-align: center;
        font-size: 20px;
    }
    .main {
        width: 100%;
        clear: both;
        content: "";
        display: table;
    }
    .usrInput {
        padding: 15px;
        float: left;
        width: 50%;
    }
    .frameDisplay {
        font-size: 12px;
        padding: 25px;
        float: left;
        width: 50%;
    }
    .row {
        margin-bottom: 0;
        padding: 1px 0 1px 0;
        width: 100%;
        clear: both;
        content: "";
        display: table
    }
    .label {
        padding-right: 15px;
        font-size: 20px;
        display: inline-block;
        float: left;
        text-align: right;
        width: 60%
    }
    .value {
        font-size: 18px;
        display: inline-block;
        float: left;
        text-align: left;
        width: 40%
    }
    .line {
        border-bottom: 1px solid orange;
        padding-bottom: 1px;
        width: 90%;
    }
    select {
        font-size: inherit;
        width: 100%;
    }
    input {
        font-size: inherit;
        width: 100%;
    }
    input[type=submit] {
        width: 50%;
        font-size: 20px;
    }
    table, th, tr, td {
        font-size: inherit;
        border: 2px solid black;
        border-collapse: collapse;
        padding: 5px;
        text-align: center;
    }
    th {
        font-weight: bold;
        background-color: darkorange;
    }
    @media (max-width: 1250px) {
        .usrInput, .frameDisplay {
            width: 100%;
            height: auto;
        }
    }
)=====";
#endif