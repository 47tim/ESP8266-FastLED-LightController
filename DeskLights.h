#ifndef DESKLIGHTS_H
#define DESKLIGHTS_H

const char DeskLights_html[] PROGMEM = R"rawliteral(<!DOCTYPE HTML>
<html>
<head>
    <title>Light Controller</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body {
            text-align:center;
            background-color: #85DCBA;
            color: white;
        }
        .press {
            align-items: center;
            background-clip: padding-box;
            background-color: #fa6400;
            border: 1px solid transparent;
            border-radius: .25rem;
            box-shadow: rgba(0, 0, 0, 0.02) 0 1px 3px 0;
            box-sizing: border-box;
            color: #fff;
            cursor: pointer;
            display: inline-flex;
            font-family: system-ui,-apple-system,system-ui,"Helvetica Neue",Helvetica,Arial,sans-serif;
            font-size: 16px;
            font-weight: 600;
            justify-content: center;
            line-height: 1.25;
            margin: 0;
            min-height: 3rem;
            padding: calc(.875rem - 1px) calc(1.5rem - 1px);
            position: relative;
            text-decoration: none;
            transition: all 250ms;
            user-select: none;
            -webkit-user-select: none;
            touch-action: manipulation;
            vertical-align: baseline;
            width: 100%;
        }
        h1 {
            color: white;
        }
        .card {
            padding: 1rem;
            height: 1rem;
        }
        .card2 {
            height: 1rem;
        }
        .cards {
            max-width: 1200px;
            margin: 0 auto;
            display: grid;
            grid-gap: 1rem;
        }
        .cards2 {
            max-width: 1200px;
            margin: 0 auto;
            display: grid;
            grid-gap: 1rem;
        }
        .cards3 {
            margin: 0 auto;
            display: grid;
        }
        .top {
            top: 0px;
            width: 100%;
            position: fixed;
        }
        @media (min-width: 350px) {
            .cards {
                grid-template-columns: repeat(2, 1fr);
            }
            .cards2 {
                grid-template-columns: repeat(4, 1fr);
            }
            .cards3 {
                grid-template-columns: repeat(4, 1fr);
            }
        }
    </style>
</head>
<body>
<div class="top">
    <div class="cards3">
        <div class="card2">
            <form action="/get">
                <input type="submit" value="CL" name="clbtn" class="press" style="background-color: deepskyblue;">
            </form><br>
        </div>
        <div class="card2">
            <form action="/get">
                <input type="submit" value="DESK" name="deskbtn" class="press" style="background-color: deepskyblue;">
            </form><br>
        </div>
        <div class="card2">
            <form action="/get">
                <input type="submit" value="TREE" name="treebtn" class="press" style="background-color: deepskyblue;">
            </form><br>
        </div>
        <div class="card2">
            <form action="/get">
                <input type="submit" value="ALL" name="otherbtn" class="press" style="background-color: deepskyblue;">
            </form><br>
        </div>
</div>
    </div>
    <br>
    <h1 style="color: deepskyblue; font-size: 40px;">
        Desk Lights
    </h1>
    <hr style="color: black;">
    <h1>
        Brightness
    </h1>
    <div class="cards2">
        <div class="card">
            <form action="/get">
                <input type="submit" value="1" name="bbtn1" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="2" name="bbtn2" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="3" name="bbtn3" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="4" name="bbtn4" class="press">
            </form><br>
        </div>
    </div>
    <br>
    <h1> Patterns </h1>
    <div class="cards">
        <div class="card">
            <form action="/get">
                <input type="submit" value="OFF" name="btn6" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Red" name="btn3" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Blue" name="btn4" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Light Trail" name="btn5" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Rainbow Worm" name="btn7" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Sunset Shimmer" name="btn8" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Piano Lights" name="btn9" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Old Lights" name="btn10" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="Rainbow Fill" name="btn11" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="new1" name="btn12" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="new2" name="btn13" class="press">
            </form><br>
        </div>
        <div class="card">
            <form action="/get">
                <input type="submit" value="new3" name="btn14" class="press">
            </form><br>
        </div>
    </div>
</body>
</html>)rawliteral";

#endif
