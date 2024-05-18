const promiseGet = url => 
{
	const promise = new Promise((resolve, reject) => 
	{
		const xhr = new XMLHttpRequest();

		xhr.open('GET', url); 
		xhr.send();
		xhr.onload = () =>
		{
			if (xhr.status === 200)
				resolve(JSON.parse(xhr.response));
			else
				reject(new Error(xhr.status));
		};
	});
	return (promise);
};

promiseGet('https://jsonplaceholder.typicode.com/posts/1')
.then(result => console.log(result))
.catch(error => console.error(error))
.finally(() => console.log('Bye!'));