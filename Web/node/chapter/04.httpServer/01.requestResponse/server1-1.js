const http = require('http');
const server = http.createServer((request, response) => {
	response.writeHead(200, { 'Content-type': 'text/html; charset=utf-9' });
	response.write('<h1>Hello Node!</h1>');
	response.end('<p>Hello Server!</p>');
});

server.listen(3434);
server.on('listening', () => {
	console.log('Server is waiting on 3434 port');
});
server.on('error', (error) => {
	console.error(error);
});