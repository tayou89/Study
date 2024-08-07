const cluster = require('cluster');
const http = require('http');
const CPUCount = require('os').cpus().length;

if (cluster.isMaster) {
	console.log(`Master Process ID:
}