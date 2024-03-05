#!/usr/bin/python3

print("Content-Type: text/html; charset=utf-8\n")
import cgi, os

files = os.listdir('data')
listStr = ''
for item in files:
	listStr = listStr + '<li><a href="index.py?id={name}">{name}</a></li>'.format(name=item)

form = cgi.FieldStorage()
if 'id' in form:
	pageId = form.getvalue("id")
	description = open('data/'+pageId, 'r', encoding='utf-8').read()
else:
	pageId = 'Welcome'
	description = 'Hello, web'

print('''
<!Doctype html>
<html>
	<head>
		<title>WEB1 - Welcome</title>
		<meta charset="utf-8">
	</head>
	<body>
		<h1><a href="index.py">WEB</a></h1>
		<ol>
			{listStr}
		</ol>
		<a href="create.py">create</a>
		<form action="process_create.py" method="POST">
			<p><input type="text" name="title" placeholder="title"></p>
			<p><textarea rows="4" name="description" placeholder="description"></textarea></p>
			<p><input type="submit"></p>
		</form>
		<h2>{title}</h2>
		<p>
			{desc}
		</p>
	</body>
</html>
'''.format(title=pageId, desc = description, listStr=listStr))