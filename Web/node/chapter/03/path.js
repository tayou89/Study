const path = require('path');
const string = __filename;

console.log('path.sep:', path.sep);
console.log('path.delimeter:', path.delimiter);
console.log('-----------------------------------');
console.log('string:', string);
console.log('path.dirname():', path.dirname(string));
console.log('path.extname():', path.extname(string));
console.log('path.basename():', path.basename(string));
console.log('path.basename - extname:', path.basename(string, path.extname(string)));
console.log('-----------------------------------');
console.log('path.parse():', path.parse(string));
console.log('path.format():', path.format({
	dir: '/Hello',
	name: 'path',
	ext: '.js',
}));
console.log('path.normalize()', path.normalize('/////hello////path.js'));
console.log('-----------------------------------');