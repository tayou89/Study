const promise = new Promise(resolve => resolve(1));

console.log(promise);
promise.then(console.log);