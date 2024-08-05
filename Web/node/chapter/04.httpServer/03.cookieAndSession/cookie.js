const http = require('http');

http.createServer((request, response) => {
	console.log(request.url, request.headers.cookie);
	response.writeHead(200, { 'Set-Cookie': 'mycookie=test' });
	response.end('Hello Cookie');
})
	.listen(3434, () => {
		console.log('Server is waiting on 3434 port');
	});
