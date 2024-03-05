#!/usr/bin/python3

print("Content-Type: text/html; charset=utf-8\n")
import cgi, os, view

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
		<form action="process_update.py" method="POST">
			<input type="hidden" name="pageId" value="{form_default_title}">
			<p><input type="text" name="title" placeholder="title" value="{form_default_title}"></p>
			<p><textarea rows="4" name="description" placeholder="description">{form_default_description}</textarea></p>
			<p><input type="submit"></p>
		</form>
		<h2>{title}</h2>
		<p>
			{desc}
		</p>
	</body>
</html>
'''.format(title=pageId, desc = description, listStr=view.getList(), form_default_title=pageId, form_default_description=description))