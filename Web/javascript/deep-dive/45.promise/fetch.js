// fetch('https://jsonplaceholder.typicode.com/todos/1')
// 	.then(response => response.json())
// 	.then(json => console.log(json));

// const wrongUrl = 'https://jsonplaceholder.typicode.com/XXX/1';

// const result = fetch(wrongUrl);
// console.log(result);
// // result
// // 	.then(() => console.log('ok'))
// // 	.catch(() => console.log('error'));

// result
// 	.then(response => 
// 		{
// 			if (!response.ok)
// 				throw (new Error(response.statusText));
// 			return (reponse.json);
// 		})
// 	.then(todo => console.log(todo))
// 	.catch(error => console.error(error));

const request = 
{
	get(url)
	{
		return (fetch(url));
	},
	post(url, payload)
	{
		return (fetch(url, 
			{
				method: 'POST',
				headers: { 'content-type': 'application/json' },
				body: JSON.stringify(payload)
			}));
	},
	patch(url, payload)
	{
		return (fetch(url, 
			{
				method: 'PATCH',
				headers: { 'content-type': 'application/json' },
				body: JSON.stringify(payload)
			}));
	},
	delete(url)
	{
		return (fetch(url, { method: 'DELETE' }));
	}
};

request.get('https://jsonplaceholder.typicode.com/todos/1')
	.then(response => 
		{
			if (!response.ok)
				throw (new Error(response.statusText));
			return (response.json());
		})
	.then(todos => console.log(todos))
	.catch(error => console.error(error));

request.post('https://jsonplaceholder.typicode.com/todos', 
{
	userId: 1,
	title: 'JavaScript',
	completed: false
})
	.then(response => 
		{
			if (!response.ok)
				throw (new Error(response.statusText));
			return (response.json());
		})
	.then(todos => console.log(todos))
	.catch(error => console.error(error));

request.patch('https://jsonplaceholder.typicode.com/todos/1', 
{
	completed: true 
})
	.then(response => 
		{
			if (!response.ok)
				throw (new Error(response.statusText));
			return (response.json());
		})
	.then(todos => console.log(todos))
	.catch(error => console.error(error));

request.delete('https://jsonplaceholder.typicode.com/todos/1')
	.then(response => 
		{
			if (!response.ok)
				throw (new Error(response.statusText));
			return (response.json());
		})
	.then(todos => console.log(todos))
	.catch(error => console.error(error));

