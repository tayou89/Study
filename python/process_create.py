#!/usr/bin/python3

print("Content-Type: text/html\n")

import cgi
form = cgi.FieldStorage()
title = form.getvalue('title')
description = form.getvalue('description')

print(title)
print(description)