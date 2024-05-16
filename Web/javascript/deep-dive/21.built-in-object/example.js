const x = 1;

function foo() 
{
	'use strict';
	eval('var x = 2; console.log(x)');
	console.log(x);
}

foo();

console.log(x);

const uri = 'http://example.com?name=유태갑&job=programmer&teacher';

const encode = encodeURI(uri);
console.log(encode);

const encode_query = encodeURIComponent(uri);
console.log(encode_query);

const decode = decodeURI(encode);
console.log(decode);

const decode_query = decodeURIComponent(encode_query);
console.log(decode_query);