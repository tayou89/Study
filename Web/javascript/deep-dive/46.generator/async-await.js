const getGithubUserName = async id =>
{
	const res = await fetch(`https://api.github.com/users/${id}`);
	const { name } = await res.json();

	console.log(name);
};

getGithubUserName('tayou89');