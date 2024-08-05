const fs = require('fs');

console.log('Start');
fs.readFile('./readme.txt', (error, data) => {
	if (error)
		throw error;
	console.log('First', data.toString());
	fs.readFile('./readme.txt', (error, data) => {
		if (error)
			throw error;
		console.log('Second', data.toString());
		fs.readFile('./readme.txt', (error, data) => {
			if (error)
				throw error;
			console.log('Third', data.toString());
			console.log('End');
		});
	});
});