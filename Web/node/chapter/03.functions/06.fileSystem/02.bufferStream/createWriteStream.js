const fs = require('fs');
const writeStream = fs.createWriteStream('./writeme.txt');

writeStream.on('finish', () => {
	console.log('Finish writing');
});

writeStream.write('Hello\n');
writeStream.write('My name is tayou\n');
writeStream.end();
