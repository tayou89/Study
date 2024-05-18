// new Promise((_, reject) => reject(new Error('rejected')))
// .then(v => console.log(v), e => console.error(e));

new Promise((_, reject) => reject(new Error('rejected')))
.catch(e => console.error(e));