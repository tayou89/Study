// process.on('uncaughtException', (error) => {
// 	console.error('Unexpected error', error);
// });

setInterval(() => {
	throw new Error('I will break server!');
}, 1000);

setTimeout(() => {
	console.log('Executed!');
}, 2000);