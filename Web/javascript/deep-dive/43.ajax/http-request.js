const xhr = new XMLHttpRequest();

xhr.open('GET', 'https://jsonplaceholder.typicode.com/todos/1');

xhr.send();

console.log(XMLHttpRequest.DONE);
// xhr.onreadystatechange = () =>
// {
// 	console.log(xhr.readyState);
// 	if (xhr.readyState !== XMLHttpRequest.DONE)
// 		return ;
// 	if (xhr.status === 200)
// 	{
// 		console.log(xhr.status);
// 		console.log(JSON.parse(xhr.response));
// 	}
// 	else
// 		console.error('Error', xhr.status, xhr.statusText);
// };

xhr.onload = () =>
{
	console.log(xhr.readyState);
	if (xhr.status === 200)
	{
		console.log(xhr.status);
		console.log(JSON.parse(xhr.response));
	}
	else
		console.error('Err
	r', xhr.status, xhr.statusText);
};
