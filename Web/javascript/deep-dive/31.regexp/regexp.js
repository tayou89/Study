const target = 'Is this all there is?';

const regexp = /is/g;

console.log(regexp.test(target));
console.log(regexp.exec(target));
console.log(target.match(regexp));