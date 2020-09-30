const net = require("net");

const CRLF = "\r\n";
const D_CRLF = "\r\n\r\n";
const MIME_SEP = ": ";

const MIME_TYPES = {
  TEXT: 'text/plain',
  HTML: 'text/html',
  JSON: 'application/json',
  IMAGE: 'image/*'
};

const CONFIG = {
  PORT: 3000,
};

const server = net.createServer(socket => {
  socket.setEncoding("utf8");
  socket.on("data", data => {

    const [request, body] = data.split(D_CRLF);
    const [request_line, ...headers] = request.split(CRLF);
    const [method, uri, protocol] = request_line.split(" ");
    const header_lines = headers.map(line => {
      const [key, value] = line.split(MIME_SEP);
      return { key, value };
    });

    console.log({
      request_line: {
        method,
        uri,
        protocol
      },
      header_lines,
      body
    });

    socket.write("HTTP/1.1 200 OK\r\n");
    socket.end();
  });
});

server.listen(3000, "0.0.0.0");
