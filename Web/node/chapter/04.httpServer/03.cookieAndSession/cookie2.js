const http = require('http');
const fs = require('fs').promises;
const path = require('path');
const parseCookies = (cookie = '') => 
	cookie.split(';').map(v => v.split('=')).reduce((acc, [k, v]) => {
		acc[k.trim()] = decodeURIComponent(v);
		return (acc);
	}, {});

http.createServer(async (request, response) => {
	const cookies = parseCookies(request.headers.cookie);

	if (request.url.startsWith('/login')) {
		const url = new URL(request.url, 'http://localhost:3434');
		const name = url.searchParams.get('name');
		const expires = new Date();

		expires.setMinutes(expires.getMinutes() + 5);
		response.writeHead(302, {
			Location: '/', 
			'Set-Cookie': `name=${encodeURIComponent(name)}; Expires=${expires.toGMTString()}; HttpOnly; Path=/`,
		});
		response.end();
	}
	else if (cookies.name) {
		response.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
		response.end(`Hello ${cookies.name}`);
	}
	else {
		try {
			const data = await fs.readFile(path.join(__dirname, 'cookie2.html'));

			response.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
			response.end(data);
		}
		catch (error) {
			response.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
			response.end(error.message);
		}
	}
})
	.listen(3434, () => {
		console.log('Server is waiting on 3434 port');
	});
