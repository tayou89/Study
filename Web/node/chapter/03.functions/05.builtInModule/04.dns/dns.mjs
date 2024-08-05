import dns from 'dns/promises';

const ip = await dns.lookup('github.co.kr');
console.log('IP', ip);

const a = await dns.resolve('gilbut.co.kr', 'A');
console.log('A', a);