const http = require('http');
const fs = require('fs').promises;
const path = require('path');
const users = {};

http.createServer(async (request, response) => {
	try {
		console.log(request.method, request.url);
		if (request.method === 'GET') {
			if (request.url === '/') {
				const data = await fs.readFile(path.join(__dirname, 'restFront.html'));

				response.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
				return (response.end(data));
			}
			else if (request.url === '/about') {
				const data = await fs.readFile(path.join(__dirname, 'about.html'));
				
				response.writeHead(200,  { 'Content-Type': 'text/html; charset=utf-8' });
				return (response.end(data));
			}
			else if (request.url === '/users') {
				response.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });
				return (response.end(JSON.stringify(users)));
			}
			try {
				const data = await fs.readFile(path.join(__dirname, request.url));

				return (response.end(data));
			}
			catch (error) {
			}
		}
		else if (request.method === 'POST') {
			if (request.url === '/user') {
				let body = '';

				request.on('data', (data) => {
					body += data;
				});
				return (request.on('end', () => {
					console.log('POST bodyt:', body);
					const { name } = JSON.parse(body);
					const id = Date.now();

					users[id] = name;
					response.writeHead(201, { 'Content-type': 'text/plain; charset=utf-8' });
					response.end('Register Success');
				}));
			}
		}
		else if (request.method === 'PUT') {
			if (request.url.startsWith('/user/')) {
				const key = request.url.split('/')[2];
				let body = '';

				request.on('data', (data) => {
					body += data;
				});
				return (request.on('end', () => {
					console.log('PUT Body:', body);
					users[key] = JSON.parse(body).name;
					response.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });
					return (response.end(JSON.stringify(users)));
				}));
			}
		}
		else if (request.method === 'DELETE') {
			if (request.url.startsWith('/user/')) {
				const key = request.url.split('/');
				console.log("key:", key);

				delete users[key[2]];
				response.writeHead(200, { 'Content-Type': 'application;/json; charset=utf-8' });
				return (response.end(JSON.stringify(users)));
			}
		}
		response.writeHead(404);
		return (response.end('NOT FOUND'));
	}
	catch (error) {
		console.error(error);
		response.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
		response.end(error.message);
	}
})
	.listen(3434, () => {
		console.log('Server is waiting on 3434 port');
	});