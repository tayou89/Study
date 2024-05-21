const foo = async () => 
{
	try
	{
		const wrongUrl = 'https://wrong.url';
		const response = await fetch(wrongUrl);
		const data = await response.json();

		console.log(data);
	}
	catch (error)
	{
		console.error(error);
	}
};

foo();