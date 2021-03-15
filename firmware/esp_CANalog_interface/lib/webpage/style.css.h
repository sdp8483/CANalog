#ifndef INC_STYLE_CSS_H_
#define INC_STYLE_CSS_H_

#include <Arduino.h>

const char PAGE_style_css[] PROGMEM = R"=====(
* {
    box-sizing: border-box
}
.header {
    width: 100%;
    background-color: darkorange;
    text-align: center;
    font-size: 30px;
    font-weight: 700;
    padding: 0;
}
.navigation {
    width: 100%;
    padding: 1%;
    text-align: center;
}
.main {
    width: 100%;
    clear: both;
    content: "";
    display: table;
}
.usrInput {
    padding-right: 1%;
    float: left;
    width: 50%;
    margin-left: auto;
    margin-right: auto;
}
.frameDisplay {
    font-size: 11px;
    padding-top: 50px;
    float: left;
    width: 50%;
}
.formRow {
    margin-bottom: 0;
    padding: 1px 0 1px 0;
    width: 100%;
    clear: both;
    content: "";
    display: table
}
.buttonRow {
    padding: 5% 0 0 0;
    width: 100%;
    clear: both;
    content: "";
    display: table
}
.label {
    padding-right: 15px;
    font-size: 20px;
    float: left;
    text-align: right;
    width: 60%
}
.value {
    font-size: 18px;
    float: left;
    text-align: left;
    width: 40%
}
.outputText {
    font-size: 18px;
    float: left;
    text-align: left;
    width: 40%;
}
.line {
    height: 1px;
    width: 100%;
}
.savedOutput {
    font-size: 18px;
    width: 100%;
    padding: 1%;
    text-align: center;
}
.infoText {
    font-size: 18px;
    font-family: monospace;
    width: 100%;
    padding: 1%;
    text-align: center;
}
select {
    font-size: inherit;
    width: 100%;
}
input {
    font-size: inherit;
    width: 100%;
}
input:invalid {
    border: red solid 3px;
  }
input[type=submit] {
    width: 100%;
    font-size: 20px;
}
table, th, tr, td {
    font-size: inherit;
    border: 2px solid black;
    border-collapse: collapse;
    padding: 5px;
    text-align: center;
    margin-left: auto;
    margin-right: auto;
}
th {
    font-weight: bold;
    background-color: darkorange;
}
@media (max-width: 650px) {
    .usrInput, .frameDisplay {
        width: 100%;
        height: auto;
    }
}
)=====";
#endif