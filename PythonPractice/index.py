#!/usr/bin/python3


print("Content-Type: text/html\n")
import cgi
form = cgi.FieldStorage()
pageId = form.getvalue("id")
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
			<li><a href="index.py?id=HTML"">HTML</a></li>
			<li><a href="index.py?id=CSS">CSS</a></li>
			<li><a href="index.py?id=JavaScript">JavaScript</a></li>
		</ol>
		<h2>{title}</h2>
		<p>
			The World Wide Web (WWW or simply the Web) is an information system that enables content sharing over the Internet through user-friendly ways meant to appeal to users beyond IT specialists and hobbyists.[1] It allows documents and other web resources to be accessed over the Internet according to specific rules of the Hypertext Transfer Protocol (HTTP).[2]
		</p>
	</body>
</html>
'''.format(title=pageId))