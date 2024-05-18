setTimeout(() => console.log('Hi!'), 1000);

setTimeout(name => console.log(`Hi! ${name}.`), 3000, 'Taegab');

const timerId = setTimeout(() => console.log('Hi!'), 1000);
console.log(timerId);
clearTimeout(timerId);

