
const char WEB_PAGE[] = R"=====(
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset='utf-8'>
      <meta name="keyword" content="html/css, JavaScript, Arduino/ESP8266">
      <title>ESPAP</title>
      <style type="text/css">
         h1 {
            color: #4863A0
         }
         body {
            background-color: #808080;
         }
         .fields p {
            font-size: 50px;
         }
      </style>
    </head>
    <body>
        <h1 align="center">Welcome to ESPAP</h1>
	      <div id="fields">
		      <p>Enter SSID:</p>
		      <input type="text" id="ssid"/><br/>
		      <p>Enter Password:</p>
		      <input type="text" id="pass"/>
	      </div>
        <script type="text/javascript">
            function getValues() {
              var ssid = document.getElementById("ssid");
              var password = document.getElementById("pass");

              document.write("SSID: ", ssid.value);
              document.write("Password: ", password.value);
            }
        </script>
        <button onclick="getValues()">Connect</button>
    </body>
  </html>
)=====";
