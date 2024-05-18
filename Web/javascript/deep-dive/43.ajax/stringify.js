const object = 
{
	name: 'Taegab',
	age: 35,
	alive: true,
	hobby: ['programming', 'watching movie']
};

const json = JSON.stringify(object);

console.log(typeof json, json);

const prettyJson = JSON.stringify(object, null, 2);

console.log(typeof prettyJson, prettyJson);

function filter(key, value)
{
	return (typeof value === 'number' ? undefined : value);
}

const stringFilteredObject = JSON.stringify(object, filter, 2);

console.log(typeof stringFilteredObject, stringFilteredObject);

const parsed = JSON.parse(json);

console.log(typeof parsed, parsed);