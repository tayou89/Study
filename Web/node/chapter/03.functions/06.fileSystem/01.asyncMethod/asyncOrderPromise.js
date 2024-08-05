const fs = require('fs').promises;

console.log('Start');
fs.readFile('./readme.txt')
	.then((data) => {
		console.log('First', data.toString());
		return (fs.readFile('./readme.txt'));
	})
	.then((data) => {
		console.log('Second', data.toString());
		return (fs.readFile('./readme.txt'));
	})
	.then((data) => {
		console.log('Third', data.toString());
		console.log('End');
	})
	.catch((error) => {
		console.log(error);
	});